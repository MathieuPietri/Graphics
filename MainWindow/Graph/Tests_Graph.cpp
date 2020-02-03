#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "graph.h"
#include "csv.h"
/* quand extends : 
    public : on garde les regles d'accessibilite 
    protected : on descend tout d'un cran
    private : tout est prive
*/

using namespace std;


int main(int argc, char* argv[]){
    vector<vector<string>>dat = openFromCSV("test.csv");
    Graph* myGraph = new Graph(dat);
    
    cout << "NODES : " << endl;
    
    for(int i = 0; i < myGraph->getNodes().size(); i++){
        cout << myGraph->getNodes()[i]->getId() << endl;
    }

    cout << endl << "EDGES :" << endl;

    for(int i = 0; i < myGraph->getEdges().size(); i++){
        cout << myGraph->getEdges()[i]->getNode1()->getId();
        cout << " <---> ";
        cout << myGraph->getEdges()[i]->getNode2()->getId() << endl;
    }

    delete myGraph;
}