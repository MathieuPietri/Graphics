#include "graph.h"
using namespace std;
#include <iostream>
#include <vector>

void Graph::addToScene(QGraphicsScene *scene){
    cout << "tzqt" << endl;
    for(int i=0 ; i<(int)edgeList.size() ; i++)
        scene->addItem(edgeList[i]);

    for(int j=0 ; j<(int)nodeList.size() ; j++)
        //drawNode(myGraph->getNodes()[j], scene);
        scene->addItem(nodeList[j]);
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

/*Node Graph::mergeNodes(vector<Node*> selectedNodes){
    vector<Node*> enteringNodes;
    //listing of entering nodes
    for(Edge *e : edgeList){
        //checking if nodes are in selectedNodes
        vector<Node*>::iterator it1 = find(selectedNodes.begin(), selectedNodes.end(), e->getNode1());
        vector<Node*>::iterator it2 = find(selectedNodes.begin(), selectedNodes.end(), e->getNode2());
        //if both, we delete
        if(it1 != selectedNodes.end() && it2 != selectedNodes.end()){
            vector<Edge*>::iterator it3 = find(edgeList.begin(), edgeList.end(), e);
            edgeList.erase(it3);
        }
        //if only one, we save the entering node
        else if(it1 != selectedNodes.end() && it2 == selectedNodes.end()){
            enteringNodes.push_back(e->getNode1());
        }
        else if(it1 == selectedNodes.end() && it2 != selectedNodes.end()){
            enteringNodes.push_back(e->getNode2());
        }
    }

}*/

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
