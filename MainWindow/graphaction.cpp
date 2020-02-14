#include "graphaction.h"
#include <iostream>

GraphAction::GraphAction(){}
GraphAction::~GraphAction(){}

//METHODS FOR COLORCHANGED ACTION
ColorChangedAction::ColorChangedAction(std::vector<Node*> nodes, QColor to){
    _colorTo = to;
    for(unsigned int i = 0; i < nodes.size(); i++){
        QColor prevColor;
        prevColor.setRgb(nodes[i]->getColor().red(), nodes[i]->getColor().green(), nodes[i]->getColor().blue());
        _affectedNodes.push_back(nodes[i]);
        _colorsFrom.push_back(prevColor);
    }
}

void ColorChangedAction::undo(){
    for(unsigned int i = 0; i < _affectedNodes.size(); i++){
        if(_affectedNodes[i] != nullptr){
            _affectedNodes[i]->setColor(_colorsFrom[i].red(), _colorsFrom[i].green(), _colorsFrom[i].blue());
        }
    }
}

void ColorChangedAction::redo(){
    for(Node* n:_affectedNodes){
        if(n != nullptr){
            n->setColorFromColor(_colorTo);
        }
    }
}

ColorChangedAction::~ColorChangedAction(){}

//METHODS FOR NODE MOVED ACTION
//FOR FUTURE FEATURE, NODE CAN'T ADD THIS TO THE TAB YET
NodeMovedAction::NodeMovedAction(Node* node, double fromX, double fromY, double toX, double toY){
    _affectedNode = node;
    _fromX = fromX;
    _fromY = fromY;
    _toX = toX;
    _toY = toY;
}

void NodeMovedAction::undo(){
    if(_affectedNode != nullptr){
        _affectedNode->setPos(_fromX, _fromY);
    }
}

void NodeMovedAction::redo(){
    if(_affectedNode != nullptr){
        _affectedNode->setPos(_toX, _toY);
    }
}

NodeMovedAction::~NodeMovedAction(){
}
