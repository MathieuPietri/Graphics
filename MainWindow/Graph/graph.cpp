#include "graph.h"
using namespace std;
#include <iostream>
#include <vector>
#include <QtAlgorithms>

void Graph::addToScene(QGraphicsScene *scene){
    for(int i=0 ; i<(int)edgeList.size() ; i++)
        scene->addItem(edgeList[i]);

    for(int j=0 ; j<(int)nodeList.size() ; j++)
        //drawNode(myGraph->getNodes()[j], scene);
        scene->addItem(nodeList[j]);
    _scene = scene;
    cout << "added to scene" << endl;
}

void Graph::setAllNodesCoordonates(){
    int available[nodeList.size()/2][nodeList.size()/2];
    for(int i=0 ; i<(int)nodeList.size()/2; i++)
        for(int j=0 ; j<(int)nodeList.size()/2; j++)
            available[i][j] = 1;
    int x;
    int y;
    for(int k=0 ; k<(int)nodeList.size() ; k++){
        int success = 0;
        while (success == 0){
            x = rand() % nodeList.size()/2;
            y = rand() % nodeList.size()/2;
            if(available[x][y]){
                nodeList[k]->setPos(x * 100 + 100, y * 100 + 100);
                available[x][y]--;
                success ++;
            }
        }
    }
}

void Graph::changeSelectionState(){
    if(selection_state == 0) selection_state = 1;
    else selection_state = 0;
}

void Graph::cleanBadEdges(){
    for(int i=0 ; i<(int)edgeList.size() ; i++){
        if( edgeList[i]->getNode1() == nullptr || edgeList[i]->getNode2() == nullptr){
            _scene->removeItem(edgeList[i]);
            edgeList.erase(edgeList.begin() + i);
        }
    }
}

/*
Node* Graph::mergeNodes(){
    vector<Node*> selectedNodes;
    selectedNodes.clear();
    selectedNodes = getSelectedNodes();
    vector<Node*> enteringNodes;
    enteringNodes.clear();

    //listing of all entering nodes (nodes that will be connected to metaNode

}*/


Node* Graph::mergeNodes(){
    vector<Node*> selectedNodes;
    selectedNodes.clear();
    vector<Node*> enteringNodes;
    enteringNodes.clear();
    for(int i=0 ; i<(int)nodeList.size() ; i++)
        _scene->removeItem(nodeList[i]);
    for(int i=0 ; i<(int)edgeList.size() ; i++)
        _scene->removeItem(edgeList[i]);

    for(int i=0 ; i<(int)getSelectedNodes().size() ; i++){
        selectedNodes.push_back(getSelectedNodes()[i]);
    }

    //listing of entering nodes and deleting the edges
    for(int y=0 ; y<(int)edgeList.size() ; y++){
        //checking if nodes are in selectedNodes
        int check1 = 0;
        int check2 = 0;
        for(int k=0 ; k<(int)selectedNodes.size() ; k++){
            if(selectedNodes[k] == edgeList[y]->getNode1()) check1++;
            if(selectedNodes[k] == edgeList[y]->getNode2()) check2++;
        }
        //if both, we delete
        if(check1 == 1 && check2 == 1){
            for(int i=0 ; i<(int)edgeList.size() ; i++){
                if(edgeList[y] == edgeList[i]){
                    edgeList.erase(edgeList.begin() + i);
                }
            }
        }

        //if only one, we save the entering node and delete the edge
        //case if we have nodeToFuse -> enteringNode
        else if(check1 == 1 && check2 == 0){
            //first we check if we didn't already save the entering node
            int isSaved = 0;
            for(unsigned int i=0 ; i<enteringNodes.size() ; i++)
                if(enteringNodes[i] == edgeList[y]->getNode2()) isSaved++;
            //then if we didn't we save the guy
            if (isSaved == 0)
                enteringNodes.push_back(edgeList[y]->getNode2());
            //then we look for the edge in the graph to delete him and remove him from the scene
            for(int i=0 ; i<(int)edgeList.size() ; i++){
                if(edgeList[y] == edgeList[i]){
                    edgeList.erase(edgeList.begin() + i);
                }
            }
        }
        //case if we have enteringNode -> nodeToFuse
        else if(check1 == 0 && check2 == 1){
            //first we check if we didn't already save the entering node
            int isSaved = 0;
            for(unsigned int i=0 ; i<enteringNodes.size() ; i++)
                if(enteringNodes[i] == edgeList[y]->getNode1()) isSaved++;
            //then if we didn't we save the guy
            if (isSaved == 0)
                enteringNodes.push_back(edgeList[y]->getNode1());
            //then we look for the edge in the graph to delete him and remove him from the scene
            for(int i=0 ; i<(int)edgeList.size() ; i++){
                if(edgeList[y] == edgeList[i]){
                    edgeList.erase(edgeList.begin() + i);
                }
            }
        }
    }
    //saving the intel
    string metaName = "";
    int metaPonderation = 0;
    double metaCoordX = 0;
    double metaCoordY = 0;
    for(int i=0 ; i<(int)selectedNodes.size() ; i++){
        metaName += selectedNodes[i]->getId() + " ";
        metaPonderation += selectedNodes[i]->getPonderation();
        metaCoordX += selectedNodes[i]->getX();
        metaCoordY += selectedNodes[i]->getY();
    }
    //creating the metaNode
    Node *metaNode = new Node(metaName, metaPonderation);
    metaNode->setPos(metaCoordX/selectedNodes.size(), metaCoordY/selectedNodes.size());
    nodeList.push_back(metaNode);
    //creating the edges from the entering nodes to the metaNode
    for(int i=0 ; i<(int)enteringNodes.size() ; i++){
        Edge *e = new Edge(enteringNodes[i], metaNode);
        edgeList.push_back(e);
    }
    //deleting the selected nodes in the graph
    for(int j=0 ; j<(int)selectedNodes.size() ; j++){
        for(int i=0 ; i<(int)nodeList.size() ; i++){
            if (selectedNodes[j] == nodeList[i]){
                nodeList.erase(nodeList.begin() + i);
            }
         }
    }
    addToScene(_scene);
    //cleanBadEdges();
    _scene->update();
    return metaNode;
}
vector<Node*> Graph::getSelectedNodes(){
    vector<Node*> selectedNodes;
    for(int i=0 ; i<(int)nodeList.size() ; i++){
        if(nodeList[i]->getSelection())
            selectedNodes.push_back(nodeList[i]);
    }
    return selectedNodes;
}

void Graph::printSelectedNodes(){
    for(Node* n : getSelectedNodes())
        cout << n->getId() << endl;
}

void Graph::colorationSelectedNodes(QColor c){
    for(Node* n : getSelectedNodes()){
        n->setColor(c.red(), c.green(), c.blue());
    }

}

Node* Graph::getNodeByName(string name){

    for(int i = 0; i <(int)nodeList.size(); i++){
        if(nodeList[i]->getId() == name)
            return nodeList[i];
    }
    return nullptr;
}

Edge* Graph::getEdgeByNodes(string n1, string n2){
    for(int i=0 ; i<(int)edgeList.size() ; i++){
        std::string id1 = edgeList  [i]->getNode1()->getId();
        std::string id2 = edgeList[i]->getNode2()->getId();
        if( id1 == n1 && id2 == n2 ) return edgeList[i];
        else if (id1 == n2 && id2 == n1) return edgeList[i];
    }
    return nullptr;
}

Graph::Graph(vector<vector<string>> &csvData){
    cout << "doot"<<endl;
    for(int i=0 ; i<(int)csvData.size() ; i++){
        std::vector<std::string> nodeLinked;
        nodeLinked.clear();
        for(int j=0 ; j<(int)csvData[i].size() ; j++){
            Node* currentNod = getNodeByName( csvData[i][j] );
            nodeLinked.push_back(csvData[i][j]);
            if( currentNod == nullptr )
                nodeList.push_back(new Node(csvData[i][j], 1));
            else { currentNod->setPonderation(currentNod->getPonderation()+1); }
        }
        if (nodeLinked.size() >= 2){
            for(int k=0 ; k<(int)nodeLinked.size()-1 ; k++){
                for(int j=k+1 ; j<(int)nodeLinked.size() ; j++){
                    if(getEdgeByNodes(nodeLinked[k], nodeLinked[j]) == nullptr){
                        edgeList.push_back(new Edge(getNodeByName(nodeLinked[k]), getNodeByName(nodeLinked[j])));
                    }
                }
            }
        }
    }
    setAllNodesCoordonates();
}

Graph::~Graph(){
    while(nodeList.size() > 0){
        Node* tmp = nodeList.back();
        nodeList.pop_back();
        delete tmp;
        tmp = nullptr;
    }

    while(edgeList.size() > 0){
        Edge* tmp = edgeList.back();
        edgeList.pop_back();
        delete tmp;
        tmp = nullptr;
    }
}


/*
Node* Graph::mergeNodes(){
    vector<Node*> selectedNodes = getSelectedNodes();
    vector<Node*> enteringNodes;
    enteringNodes.clear();

    //listing of entering nodes
    for(Edge *e : edgeList){
        //checking if nodes are in selectedNodes
        vector<Node*>::iterator it1 = find(selectedNodes.begin(), selectedNodes.end(), e->getNode1());
        vector<Node*>::iterator it2 = find(selectedNodes.begin(), selectedNodes.end(), e->getNode2());
        //if both, we delete
        if(it1 != selectedNodes.end() && it2 != selectedNodes.end()){
            vector<Edge*>::iterator it3 = find(edgeList.begin(), edgeList.end(), e);
            edgeList.erase(it3);
            _scene->removeItem(e);
        }
        //if only one, we save the entering node and delete the edge
        else if(it1 != selectedNodes.end() && it2 == selectedNodes.end()){
            vector<Node*>::iterator it3 = find(enteringNodes.begin(), enteringNodes.end(), e->getNode2());
            if(it3 == enteringNodes.end()) enteringNodes.push_back(e->getNode2());
            _scene->removeItem(e);
        }
        else if(it1 == selectedNodes.end() && it2 != selectedNodes.end()){
            vector<Node*>::iterator it3 = find(enteringNodes.begin(), enteringNodes.end(), e->getNode1());
            if(it3 == enteringNodes.end()) enteringNodes.push_back(e->getNode1());
            _scene->removeItem(e);
        }
    }
    //saving the intel
    string metaName = "";
    int metaPonderation = 0;
    double metaCoordX = 0;
    double metaCoordY = 0;
    for(Node *n : selectedNodes){
        metaName += n->getId() + " ";
        metaPonderation += n->getPonderation();
        metaCoordX += n->getX();
        metaCoordY += n->getY();
    }
    //creating the metaNode
    Node *metaNode = new Node(metaName, metaPonderation);
    metaNode->setPos(metaCoordX/selectedNodes.size(), metaCoordY/selectedNodes.size());
    nodeList.push_back(metaNode);
    //creating the edges to the node
    for(Node *n2 : enteringNodes){
        Edge *e = new Edge(n2, metaNode);
        edgeList.push_back(e);
        _scene->addItem(e);
    }
    //deleting the selected nodes
    for(Node *n3 : selectedNodes){
        vector<Node*>::iterator it4 = find(nodeList.begin(), nodeList.end(), n3);
        nodeList.erase(it4);
        _scene->removeItem(n3);
    }
    selectedNodes.clear();
    _scene->addItem(metaNode);
    cleanBadEdges();
    _scene->update();
    return nullptr;


}*/
