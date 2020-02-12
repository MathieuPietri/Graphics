#include "csv.h"
#include "tabcontentwidget.h"
#include <QTime>
#include <qglobal.h>

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

vector<vector<string>> createCSV(){
    vector<vector<string>> result;

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    string line;
    int colonne = qrand() % (10) + 1;
    int ligne = qrand() % (10) + 1;
    int i = 0;

    while(i < ligne){
        vector<string> vectorLine;
        cout << "Importing line " << i << endl;
        i++;
        string value = "";
        for(int i = 0; i < colonne - 1;){
          value += to_string(qrand() % (10) + 1) + ", ";
        }
        value += to_string(qrand() % (10) + 1);
        vectorLine.push_back(value);
        result.push_back(vectorLine);
    }
    return result;
}

string translateToGret(TabContentWidget & tabContent) {

    string result = "unimplemented";

    return result;
}


string protectValue(string value) {
    return '"' + value + '"';
}


