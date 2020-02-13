#include "graphaction.h"
#include <iostream>

GraphAction::GraphAction(){}
GraphAction::~GraphAction(){}


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
