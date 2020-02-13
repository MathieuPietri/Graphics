#include "graph.h"
using namespace std;
#include <iostream>
Node::Node(string id, int ponderation):QGraphicsItem(){

    _nameId = id;
    _ponderation = ponderation;
    setColor(rand()%256, rand()%256, rand()%256);
    setFlag(QGraphicsItem::ItemIsMovable);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QBrush coloredBrush(_color);
    QPen outlinePen(Qt::black);
    if (getSelection() == 0) outlinePen.setWidth(2);
    else outlinePen.setWidth(4);
    painter->setBrush(coloredBrush);
    painter->setPen(outlinePen);
    painter->drawEllipse(getX()/110, getY()/110, (int)getPonderation()*15, (int)getPonderation()*15);
    painter->drawText(getX()/110 + 15*getPonderation(), getY()/110, QString::fromStdString(getId()));
    scene()->update();
}

QRectF Node::boundingRect() const{

    return QRectF(x()/110, y()/110, _ponderation*15, _ponderation*15);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(getSelection()) unselect();
    else select();
    update();
    QGraphicsItem::mouseReleaseEvent(event);

}
