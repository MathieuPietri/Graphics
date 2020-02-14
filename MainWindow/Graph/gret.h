#ifndef GRET_H
#define GRET_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "graph.h"

using namespace std;

Graph * openFromGRET(const string & fileName);
string generateGRET(const Graph & g);


#endif // GRET_H