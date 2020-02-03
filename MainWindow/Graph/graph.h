#include <string>
#include <vector>

#ifndef GRAPH_H
#define GRAPH_H

class Node{
    public:
        explicit Node(std::string id, int ponderation);
        std::string getId(){return _nameId;};
        double getY(){return _yPos;};
        double getX(){return _xPos;};
        void setPos(double x, double y){_xPos = x; _yPos = y;};
        int getPonderation(){return _ponderation;};
        void setPonderation(int value){_ponderation = value;};
        
    private:
        std::string _nameId;
        int _ponderation;
        double _xPos = 0.0;
        double _yPos = 0.0;
};

class Edge{
    public:
        explicit Edge(Node *n1, Node *n2);
        Node* getNode1(){return _node1;};
        Node* getNode2(){return _node2;};
    
    private:
        Node* _node1;
        Node* _node2;
};

class Graph{
    public:
        explicit Graph(std::vector<std::vector<std::string>> &csvData);
        ~Graph();
        Node* getNodeByName(std::string name);
        Edge* getEdgeByNodes(std::string n1, std::string n2);
        //Node mergeNodes(Node* n1, Node* n2);
        const std::vector<Edge*> getEdges(){return edgeList;};
        const std::vector<Node*> getNodes(){return nodeList;};
        
    private:
        std::vector<Node*> nodeList;
        std::vector<Edge*> edgeList;
};

#endif