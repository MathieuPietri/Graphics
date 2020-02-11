#include "graphrenderer.h"
#include "graph.h"
#include <stdlib.h>
#include "csv.h"
#include "QGraphicsItem"

using namespace std;

GraphRenderer::GraphRenderer(vector<vector<string>>dat, QGraphicsView * view)
{
    this->view = view;

    Graph* myGraph = new Graph(dat);

    srand(time(NULL));

    scene = new QGraphicsScene(view);
    this->view->setScene(scene);

   /*Node *n = new Node("id", 15);
   n->setPos(50, 50);

   Node *n2 = new Node("id2", 25);
   n2->setPos(150, 150);

   Edge *e = new Edge(n, n2);

   drawEdge(*e, scene);
   drawNode(*n, scene);
   drawNode(*n2, scene);*/
   setAllNodesCoordonates(myGraph);
   for(int i=0 ; i<(int)myGraph->getEdges().size() ; i++)
       drawEdge(myGraph->getEdges()[i], scene);
   for(int j=0 ; j<(int)myGraph->getNodes().size() ; j++)
       drawNode(myGraph->getNodes()[j], scene);
   ellipse = new QGraphicsEllipseItem();
           //->setFlag(QGraphicsItem::ItemIsMovable);
}

void GraphRenderer::setAllNodesCoordonates(Graph *g){
    int available[g->getNodes().size()][g->getNodes().size()];
    for(int i=0 ; i<(int)g->getNodes().size() ; i++)
        for(int j=0 ; j<(int)g->getNodes().size(); j++)
            available[i][j] = 1;
    int x;
    int y;
    for(int k=0 ; k<(int)g->getNodes().size() ; k++){
        int success = 0;
        while (success == 0){
            x = rand() % g->getNodes().size();
            y = rand() % g->getNodes().size();
            if(available[x][y]){
                g->getNodes()[k]->setPos(x * 100 + 100, y * 100 + 100);
                available[x][y]--;
                success ++;
            }
        }
    }
}

void GraphRenderer::drawNode(Node *n, QGraphicsScene *s){
   QColor c;
   c.setRgb(rand() % 256, rand() % 256, rand() % 256, 255);
   n->setColorFromColor(c);
   QBrush coloredBrush(c);
   QPen outlinePen(Qt::black);
   if (n->getSelection() == 0) outlinePen.setWidth(2);
   else outlinePen.setWidth(4);
   ellipse = s->addEllipse(n->getX(), n->getY(), n->getPonderation()*15, n->getPonderation()*15, outlinePen, coloredBrush);
   ellipse->setFlag(QGraphicsItem::ItemIsMovable);
   text = s->addText(QString::fromStdString(n->getId()), QFont("Arial", 10));
   text->setPos(n->getX() + n->getPonderation()*15 +5, n->getY());
}

void GraphRenderer::drawEdge(Edge *e, QGraphicsScene *s){
    double x1 = e->getNode1()->getX() + e->getNode1()->getPonderation()*15/2;
    double x2 = e->getNode1()->getY() + e->getNode1()->getPonderation()*15/2;
    double y1 = e->getNode2()->getX() + e->getNode2()->getPonderation()*15/2;
    double y2 = e->getNode2()->getY() + e->getNode2()->getPonderation()*15/2;
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    line = s->addLine(x1, x2, y1, y2, outlinePen);
}
