#include "graph.h"
using namespace std;


Node* Graph::getNodeByName(string name){

    for(int i = 0; i <nodeList.size(); i++){
        if(nodeList[i]->getId() == name)
            return nodeList[i];
    }
    return nullptr;
}

Edge* Graph::getEdgeByNodes(string n1, string n2){
    for(int i=0 ; i<edgeList.size() ; i++){
        std::string id1 = edgeList[i]->getNode1()->getId();
        std::string id2 = edgeList[i]->getNode2()->getId();
        if( id1 == n1 && id2 == n2 ) return edgeList[i];
        else if (id1 == n2 && id2 == n1) return edgeList[i];
    }
    return nullptr;
}

Graph::Graph(vector<vector<string>> &csvData){
    
    for(int i=0 ; i<csvData.size() ; i++){
        std::vector<std::string> nodeLinked;
        nodeLinked.clear();        
        for(int j=0 ; j<csvData[i].size() ; j++){
            Node* currentNod = getNodeByName( csvData[i][j] );
            nodeLinked.push_back(csvData[i][j]);
            if( currentNod == nullptr )
                nodeList.push_back(new Node(csvData[i][j], 1));
            else { currentNod->setPonderation(currentNod->getPonderation()+1); }
        }
        if (nodeLinked.size() >= 2){   
            for(int k=0 ; k<nodeLinked.size()-1 ; k++){
                for(int j=k+1 ; j<nodeLinked.size() ; j++){
                    if(getEdgeByNodes(nodeLinked[k], nodeLinked[j]) == nullptr){
                        edgeList.push_back(new Edge(getNodeByName(nodeLinked[k]), getNodeByName(nodeLinked[j])));
                    }
                }
            }
        }
    }
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