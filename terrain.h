#pragma once
#include <string>
using namespace ::std;

class Terrain
{
public:

	string typeTerrain;
	string nomTerrain;

	Terrain(string typeTerrain, string nomTerrain) {
		this -> typeTerrain = typeTerrain;
		this->nomTerrain = nomTerrain;
	}

};

