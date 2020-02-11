#ifndef GRAPHRENDERER_H
#define GRAPHRENDERER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "graph.h"
#include <stdlib.h>
#include "csv.h"
#include <QGraphicsView>

class GraphRenderer
{
public:
    GraphRenderer(vector<vector<string>>dat, QGraphicsView * view);
    ~GraphRenderer();
    void setAllNodesCoordonates(Graph *g);
    void drawNode(Node *n, QGraphicsScene *s);
    void drawEdge(Edge *e, QGraphicsScene *s);
    void drawText(Node $n, QGraphicsScene *s);

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsTextItem *text;
    QGraphicsLineItem *line;
};

#endif // GRAPHRENDERER_H
