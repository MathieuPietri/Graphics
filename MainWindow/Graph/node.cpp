#include "graph.h"
#include "../toolbar.h"

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
    painter->drawEllipse(getX()/scene()->sceneRect().x(), getY()/scene()->sceneRect().y(), (int)getPonderation()*15, (int)getPonderation()*15);
    painter->drawText(getX()/scene()->sceneRect().x() + 15*getPonderation(), getY()/scene()->sceneRect().y(), QString::fromStdString(getId()));
    scene()->update();
}

QRectF Node::boundingRect() const{
    return QRectF(x()/100, y()/100, _ponderation*15, _ponderation*15);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(_YOnMousePressed == getY() && _XOnMousePressed == getX()){
        if(getSelection()) unselect();
        else select();
    }
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event){
    _XOnMousePressed = getX();
    _YOnMousePressed = getY();
    QGraphicsItem::mousePressEvent(event);
}

