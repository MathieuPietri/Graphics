#include "csv.h"

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

string translateToGret(vector<vector<string>> table) {

    string result = "";

    for (vector<string> line : table) {
        for (string value : line) {
            result.append(protectValue(value));
        }

    }

    return result;
}


string protectValue(string value) {
    return value;
}


