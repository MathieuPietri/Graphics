#include "graph.h"

Edge::Edge(Node *n1, Node *n2):QGraphicsItem(){
    _node1 = n1;
    _node2 = n2;
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    painter->drawLine(getNode1()->getX() + getNode1()->getPonderation()*7.5
                      , getNode1()->getY() + getNode1()->getPonderation()*7.5
                      , getNode2()->getX() + getNode2()->getPonderation()*7.5
                      , getNode2()->getY() + getNode2()->getPonderation()*7.5
                      );
    scene()->update();
}

QRectF Edge::boundingRect() const{
    double dx = (_node2->getX() - _node1->getX());
    double dy = (_node2->getY() - _node1->getY());

    return QRectF(_node1->getX(), _node1->getY(), dx, dy);
}
