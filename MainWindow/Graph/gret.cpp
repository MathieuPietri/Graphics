#include "gret.h"
#include <QTime>
#include <qglobal.h>
#include "graph.h"

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
    int mode = 0;
    while(getline(myFile, line)){
        vector<string> vectorLine;
        cout << "Importing line " << n << " in mode " << mode << endl;
        stringstream ss(line);
        ss >> std::noskipws;
        string value = "";
        string sharpValue = "";
        bool quote = false;
        // 0 for csv, 1 for node list, 2 for edge list, -1 while parsing sharp value.
        for(char c; ss >> c;) {
            if (c == '#' && !quote) {
                mode = -1;
                continue;
            }
            if (mode == -1) {
                if(c != ' ') {
                    sharpValue += c;
                    continue;
                }
            } else {
                if (c == ',' && !quote) {
                    vectorLine.push_back(value);
                    value = "";
                    continue;
                } else if(c == '\"') {
                    quote = !quote;
                    continue;
                } else if((c == ' ' && value == "") || (c == '\t' && value == "")){
                    continue;
                } else {
                    value = value + c;
                    continue;
                }
            }
        }

        /* Fin de la ligne */
        n++;
        switch (mode) {
        case 0:
            vectorLine.push_back(value);
            csv_result->push_back(vectorLine);
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
        case -1:
            if (sharpValue.compare("nodelist") == 0) {
                mode = 1;
                break;
            } else if (sharpValue.compare("edgelist") == 0) {
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

    int cnt = 0;
    int cnt_2 = 0;
    cout << "csv data : " << endl << "[";
    for (auto vect : * csv_result) {
        cnt = 0;
        if (cnt_2 > 0)
            cout << "]," << endl;
        cnt_2++;
        cout << "[";
        for (auto str : vect) {
            cout << ((cnt > 0)?", ":"") << str;
            cnt++;
        }
    }
    cout << "]]" << endl;

    cnt_2 = 0;
    cout << "node list : " << endl << "[";
    for (auto vect : node_list) {
        cnt = 0;
        if (cnt_2 > 0)
            cout << "]," << endl;
        cnt_2++;
        cout << "[";
        for (auto str : vect) {
            cout << ((cnt > 0)?", ":"") << str;
            cnt++;
        }
    }
    cout << "]]" << endl;

    cnt_2 = 0;
    cout << "edge list : " << endl << "[";
    for (auto vect : edge_list) {
        cnt = 0;
        if (cnt_2 > 0)
            cout << "]," << endl;
        cnt_2++;
        cout << "[";
        for (auto str : vect) {
            cout << ((cnt > 0)?", ":"") << str;
            cnt++;
        }
    }
    cout << "]]" << endl;
    for (auto vect : metanode_list)
        for (auto str : vect)
            cout << str << endl;

    vector<vector<string>> & node_ref = node_list;
    vector<vector<string>> & edge_ref = edge_list;
    vector<vector<string>> & metanode_ref = metanode_list;

    Graph * g = new Graph(node_ref, edge_ref, metanode_ref);
    return g;
}

string replace(string s) {
  replace(s.begin(), s.end(), ',', '.');
  return s;
}

string generateGRET(QTableWidget & table, Graph & graph) {
    string result = "";

    for (int i = 0; i < table.rowCount() ; i++) {
        for (int j = 0; j < table.columnCount() ; j++) {
            result.append("\"" + table.item(i, j)->text().toStdString() + (j!=table.columnCount()-1?"\", ":"\""));
        }
        result.append("\n");
    }

    result.append("#nodelist\n");
    for (Node * node : graph.getNodes()) {
        int r, g, b;
        node->getColor().getRgb(&r, &g, &b);

        string x, y;
        x = to_string(node->getX());
        y = to_string(node->getY());
        result.append("\"" + node->getId() + "\", " + replace(x) + ", " + replace(y)
                      + ", " + to_string(r) + ", " + to_string(g) + ", " + to_string(b)
                      + ", " + to_string(node->getPonderation()));
        result.append("\n");
    }

    result.append("#edgelist\n");
    for (Edge * edge : graph.getEdgeList()) {
        result.append("\"" + edge->getNode1()->getId() + "\", " + "\"" + edge->getNode2()->getId() + "\"" );
        result.append("\n");
    }

    return result;
}
