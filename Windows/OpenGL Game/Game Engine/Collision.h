#pragma once

#include <Header files\Header.h>
#include "Data.h"

class Collision
{
public:
	Collision(Camera* gameCamera, vector<Mesh*>gameObjects, Mesh* gameTerrain);

	bool terrainCollision(Vector3f objectCoord);
	void cameraObjectCollision(void);
	void objectTerrainCollision(void);

	Camera* getCollisionCamera(void);
	vector<Mesh*> getCollisionObjects(void);
	Mesh* getCollisionTerrain(void);
	Data* getTerrainData(void);

	~Collision(void);

private:
	Camera* gameCamera;
	vector<Mesh*> gameObjects;
	Mesh* gameTerrain;

	Data* terrainData;

	vector<Vector2f> terrainCoord;

	bool didCross( Vector2f CoordStart, Vector2f CoordEnd, Vector2f CameraStart, Vector2f CameraEnd);
	
};

