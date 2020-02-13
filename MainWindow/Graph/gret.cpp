#include "gret.h"
#include <QTime>
#include <qglobal.h>

Graph * openFromGRET(const string & fileName, vector<vector<string>> * csv_result) {

    ifstream myFile;

    myFile.open(fileName);
    if(!myFile.is_open()){
        throw runtime_error("File not found");
    }

    vector<vector<string>> node_list;
    vector<vector<string>> edge_list;
    vector<vector<string>> metanode_list;

    string line;
    int n = 1;
    while(getline(myFile, line)){
        vector<string> vectorLine;
        cout << "Importing line " << n << endl;
        stringstream ss(line);
        ss >> std::noskipws;
        string value = "";
        string sharpValue = "";
        bool quote = false;
        int mode = 0; // 0 for csv, 1 for node list, 2 for edge list, 3 for meta-node list, 4 while parsing sharp value.
        for(char c; ss >> c;) {
            if (c == '#' && !quote) {
                mode = 4;
                continue;
            }
            switch (mode) {
            case 4:
                if(c != ' ') {
                    sharpValue += c;
                }
                continue;
            default: // case 0, 1, 2, and 3
                if (c == ',' && !quote) {
                    vectorLine.push_back(value);
                    value = "";
                    continue;
                } else if(c == '\"') {
                    quote = !quote;
                    continue;
                } else if(c == ' ' && value == ""){
                    continue;
                } else {
                    value = value + c;
                    continue;
                }
            }

        }

        /* Fin de la ligne */

        switch (mode) {
        case 0:
            vectorLine.push_back(value);
            csv_result->push_back(vectorLine);
            n++;
            break;
        case 1:
            vectorLine.push_back(value);
            node_list.push_back(vectorLine);
            break;
        case 2:
            vectorLine.push_back(value);
            edge_list.push_back(vectorLine);
            break;
        case 3:
            vectorLine.push_back(value);
            metanode_list.push_back(vectorLine);
            break;
        case 4:
            if (sharpValue == "nodelist") {
                mode = 1;
                break;
            } else if (sharpValue == "edgelist") {
                mode = 2;
                break;
            } else if (sharpValue == "metanodelist") {
                mode = 3;
                break;
            } else {
                cerr << "Invalid # found while parsing .gret file." << endl;
                mode = 0;
                break;
            }
        }
    }

    for (auto vect : node_list)
        for (auto str : vect)
            cout << str << endl;
    for (auto vect : edge_list)
        for (auto str : vect)
            cout << str << endl;
    for (auto vect : metanode_list)
        for (auto str : vect)
            cout << str << endl;
    //Graph * g = new Graph();
}


string generateGRET(const Graph & g) {

}
