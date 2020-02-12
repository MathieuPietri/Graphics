#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "tabcontentwidget.h"

using namespace std;

vector<vector<string>> openFromCSV(string fileName);
string translateToGret(TabContentWidget &);
string protectValue(string & value);
vector<vector<string>> createCSV();
