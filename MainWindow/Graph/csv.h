#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> openFromCSV(string fileName);
string translateToGret(vector<vector<string>> table);
string protectValue(string & value);
