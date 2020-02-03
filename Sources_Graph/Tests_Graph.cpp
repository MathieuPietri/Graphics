#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "graph.h"

/* quand extends : 
    public : on garde les regles d'accessibilite 
    protected : on descend tout d'un cran
    private : tout est prive
*/

using namespace std;

vector<vector<string>> openFromCSV(string fileName){

    ifstream myFile;

    myFile.open(fileName);
    if(!myFile.is_open()){
        throw runtime_error("File not found");
    }

    vector<vector<string>> result;

    string line;
    int n = 1;
    while(getline(myFile, line)){
        vector<string> vectorLine;
        cout << "Importing line " << n << endl;
        stringstream ss(line);
        ss >> std::noskipws;
        string value = "";
        bool quote = false;
        for(char c; ss >> c;){
            if(c == ',' && !quote){
                vectorLine.push_back(value);
                value = "";
                continue;
            }else if(c == '\"'){
                quote = !quote;
                continue;
            }
            if(c == ' ' && value == ""){
                continue;
            }
            value = value + c;
        }
        vectorLine.push_back(value);
        result.push_back(vectorLine);
        n++;
    }
    return result;
}

int main(int argc, char* argv[]){
    vector<vector<string>>dat = openFromCSV("notes.csv");
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