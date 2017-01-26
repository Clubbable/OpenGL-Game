#include "Collision.h"


Collision::Collision(Camera* gameCamera, vector<Mesh*>gameObjects, Mesh* gameTerrain)
{
	this->gameCamera = gameCamera;
	this->gameObjects = gameObjects;
	this->gameTerrain = gameTerrain;

	terrainData = new Data("Collision Data/terrain.txt");
	terrainCoord = terrainData->ReadFromFile();
}


bool Collision::terrainCollision(Vector3f objectCoord)
{
	int crossCount = 0;

	for( int i = 0; i < terrainCoord.size(); i++ )
	{
		if( i != terrainCoord.size() - 1 )
		{
			if( didCross( terrainCoord.at(i), terrainCoord.at(i+1), 
				Vector2f(objectCoord.x, objectCoord.z), Vector2f(-100, 100) ))
				crossCount++;
		}
	}

	if( crossCount % 2 == 0 || crossCount == 0 )
		return true;
	else
		return false;
}


Camera* Collision::getCollisionCamera(void)
{
	return gameCamera;
}

vector<Mesh*> Collision::getCollisionObjects(void)
{
	return gameObjects;
}

Data* Collision::getTerrainData(void)
{
	return terrainData;
}
Mesh* Collision::getCollisionTerrain(void)
{
	return gameTerrain;
}

Collision::~Collision(void)
{
	SAFE_DELETE(terrainData);
	SAFE_DELETE(gameCamera);
	gameObjects.clear();
	SAFE_DELETE(gameTerrain);
}

bool Collision::didCross( Vector2f CoordStart, Vector2f CoordEnd, Vector2f CameraStart, Vector2f CameraEnd)
{
	float m1, c1, m2, c2;
    float x1, y1, x2, y2;
    float dx, dy;
    float intersection_X, intersection_Y;
 
    x1 = CoordStart.x;
	y1 = CoordStart.y;
 
    x2 = CoordEnd.x;
	y2 = CoordEnd.y;
 
    dx = x2 - x1;
    dy = y2 - y1;
 
    m1 = dy / dx;
    // y = mx + c
    // intercept c = y - mx
    c1 = y1 - m1 * x1; // which is same as y2 - slope * x2

    x1 = CameraStart.x;
	y1 = CameraStart.y;
 
    x2 = CameraEnd.x;
	y2 = CameraEnd.y;
 
    dx = x2 - x1;
    dy = y2 - y1;
 
    m2 = dy / dx;
    c2 = y2 - m2 * x2; // which is same as y2 - slope * x2
 
    intersection_X = (c2 - c1) / (m1 - m2);
    intersection_Y = m1 * intersection_X + c1;

	if( CoordStart.x < CoordEnd.x && CoordStart.y < CoordEnd.y )
	{
		if( intersection_X >= CoordStart.x && intersection_X <= CoordEnd.x )
		{
			if( intersection_Y >= CoordStart.y && intersection_Y <= CoordEnd.y )
				return true;
		}
		return false;
	}

	if(CoordStart.x < CoordEnd.x && CoordStart.y < CoordEnd.y )
	{
		if( intersection_X >= CoordStart.x && intersection_X <= CoordEnd.x )
		{
			if( intersection_Y >= CoordEnd.y && intersection_Y <= CoordStart.y )
				return true;
		}
		return false;
	}

	if(CoordStart.x < CoordEnd.x && CoordStart.y > CoordEnd.y )
	{
		if( intersection_X >= CoordStart.x && intersection_X <= CoordEnd.x )
		{
			if( intersection_Y >= CoordEnd.y && intersection_Y <= CoordStart.y )
				return true;
		}
		return false;
	}

	if( intersection_X >= CoordStart.x && intersection_X <= CoordEnd.x )
	{
		if( intersection_Y >= CoordStart.y && intersection_Y <= CoordEnd.y )
			return true;
	}
	return false;

}