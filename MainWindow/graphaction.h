#ifndef GRAPHACTION_H
#define GRAPHACTION_H

#include "Graph/graph.h"
#include <QColor>
enum ActionType{
    changeColorAction,
    mergeAction,

};
class GraphAction
{
public:
    GraphAction();
    virtual void undo()=0;
    virtual void redo()=0;
    virtual ~GraphAction();
};

class ColorChangedAction:public GraphAction
{
public:
    ColorChangedAction(std::vector<Node*> nodes, QColor to);
    void undo() override;
    void redo() override;
    ~ColorChangedAction();
private:
    std::vector<QColor> _colorsFrom;
    QColor _colorTo;
    std::vector<Node*> _affectedNodes;

};

#endif // GRAPHACTION_H
