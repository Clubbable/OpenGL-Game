#pragma once

#include <Header files\Header.h>

class Data
{

public:

	Data(string fileName);
	vector<Vector2f> ReadFromFile(void);
	void writeToFile(Vector3f coordinate);
	~Data(void);

private:

	ofstream terrainOutput;
	ifstream terrainInput;
	string fileName;
	int tempStoreX;
	int tempStoreZ;
};

