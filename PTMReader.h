#pragma once
#include "Image.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class PTMReader
{	
public:
	PTMReader();
	~PTMReader();
	Image* PTMToImage(string file);
	vector<string> split(string str, char delimiter);
};

