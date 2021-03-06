#include <string>
#include <vector>
#include <QColor>

#ifndef GRAPH_H
#define GRAPH_H

#include <QGraphicsItem>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QRectF>
#include <QGraphicsScene>
class Edge;

class Node : public QGraphicsItem{
    public:
        explicit Node(std::string id, int ponderation);
        std::string getId(){return _nameId;};
        double getY(){return y();};
        double getX(){return x();};
        void setPos(double x, double y){setX(x); setY(y);};
        int getPonderation(){return _ponderation;};
        void setPonderation(int value){_ponderation = value;};
        void setColor(int r, int g, int b){_color.setRgb(r, g, b, 255);}
        void setColorFromColor(QColor c){_color = c;}
        void select(){_selected = 1;}
        void unselect(){_selected = 0;}
        int getSelection(){return _selected;}
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
        QRectF boundingRect() const override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
        QColor getColor(){return _color;}

    private:
        std::string _nameId;
        int _ponderation;
        QColor _color;
        int _selected = 0;
        double _XOnMousePressed;
        double _YOnMousePressed;
};

class Edge:public QGraphicsItem{
    public:
        explicit Edge(Node *n1, Node *n2);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
        QRectF boundingRect() const override;
        Node* getNode1(){return _node1;};
        Node* getNode2(){return _node2;};

    private:
        Node* _node1;
        Node* _node2;
};

class Graph{
    public:
        explicit Graph(std::vector<std::vector<std::string>> &csvData);
        explicit Graph(std::vector<std::vector<std::string>> &nodeData,
                       std::vector<std::vector<std::string>> &edgeData,
                       std::vector<std::vector<std::string>> &metaNodeData);
        ~Graph();
        void addToScene(QGraphicsScene *scene);
        void setAllNodesCoordonates();
        Node* getNodeByName(std::string name);
        Edge* getEdgeByNodes(std::string n1, std::string n2);
        Node* mergeNodes();
        void cleanBadEdges();
        const std::vector<Edge*> getEdges(){return edgeList;}
        const std::vector<Node*> getNodes(){return nodeList;}
        std::vector<Node*> getSelectedNodes();
        void colorationSelectedNodes(QColor c);
        void printSelectedNodes();
        int getSelectionState(){return selection_state;}
        int changeSelectionState();
        int isPartOfNodelist(std::vector<Node*> list, Node* n);
        void printGraph();
        std::vector<Node*> getNodeList() {return nodeList;}
        std::vector<Edge*> getEdgeList() {return edgeList;}

    private:
        std::vector<Node*> nodeList;
        std::vector<Edge*> edgeList;
        int selection_state;
        QGraphicsScene* _scene;
};

#endif
