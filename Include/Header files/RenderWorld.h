//Render Engine classes are view classes, V in MVC

#pragma once

#include <math.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <Header files\Header.h>
#include <iostream>


class RenderWorld
{
public:

	RenderWorld(void);
	RenderWorld(vector<Mesh*> gameObjects, LightingTechnique* gameLighting, DirectionalLight light, PersProjInfo cameraProjection, SkyBox* gameSkybox, vector<Vector3f> objectPositions, vector<Vector3f> objectScale, Mesh* gameTerrain, Mesh* gameFences);
	
	void setLight(void);
	void setLight(DirectionalLight light);

	void setCameraProj(void);
	void setCameraProj(PersProjInfo cameraProjection);

	void setObjectPositions(void);
	void setObjectPositions(vector<Vector3f> objectPositions);

	void setObjectScale(void);
	void setObjectScale(vector<Vector3f> objectScale);

	void setGameObjects(vector<Mesh*> gameObjects);
	bool initGameObjects(void);

	void setGameLighting(LightingTechnique* gameLighting);
	bool initGameLighting(void);

	void setSkyBox(void);
	void setSkyBox(SkyBox* gameSkybox);
	bool initSkyBox(void);

	void setTerrain(Mesh* gameTerrain);
	bool initTerrain(void);

	void setFences(Mesh* gameFences);
	bool initFences(void);

	void setGameCamera(void);
	void setGameCamera(Camera* gameCamera);

	LightingTechnique* getGameLighting();
	Camera* getGameCamera();
	DirectionalLight getLight();
	vector<Mesh*> getGameObjects();
	vector<Vector3f> getObjectPositions();
	vector<Vector3f> getObjectScale();
	PersProjInfo getCameraProjection();
	SkyBox* getGameSkybox();
	Mesh* getGameTerrain();
	Mesh* getGameFences();

	bool initWorld(void);
	bool checkGameObjects(void);
	

	~RenderWorld(void);

private:
	LightingTechnique* gameLighting;
	Camera* gameCamera;
	DirectionalLight light;
	vector<Mesh*> gameObjects;
	vector<Vector3f> objectPositions;
	vector<Vector3f> objectScale;
	PersProjInfo cameraProjection;
	SkyBox* gameSkybox;
	Mesh* gameTerrain;
	Mesh* gameFences;
};

