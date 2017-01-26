#include "Data.h"


Data::Data(string fileName)
{
	this->fileName = fileName;
	tempStoreX = 0;
	tempStoreZ = 0;
}

vector<Vector2f> Data::ReadFromFile(void)
{
	terrainInput.open(fileName);

	string line;
	vector<Vector2f>terrainCoord;

	while( getline(terrainInput, line) )
	{
		int xCoord = atoi(line.substr(0, line.find(",")).c_str());
		int zCoord = atoi(line.substr(line.find(",")+1, line.length() - 1).c_str());

		terrainCoord.push_back(Vector2f(xCoord,zCoord));
		printf("%d, %d\n", xCoord, zCoord); 
	}

	return terrainCoord;
}

void Data::writeToFile(Vector3f coordinate)
{
	if(!terrainOutput.is_open())
		terrainOutput.open("Collision Data/terrain.txt");

	if( ( ( coordinate.x - tempStoreX) * ( coordinate.x - tempStoreX) + ( coordinate.z - tempStoreZ) * ( coordinate.z - tempStoreZ) ) >= 100 )
	{
		printf("%i, %i\n", (int)coordinate.x, (int)coordinate.z );
		terrainOutput << (int)coordinate.x <<","<< (int)coordinate.z<<endl;
		tempStoreX = (int)coordinate.x;
		tempStoreZ = (int)coordinate.z;
	}
}

Data::~Data(void)
{
	if(terrainInput.is_open())
		terrainInput.close();
	if(terrainOutput.is_open())
		terrainOutput.close();
}
