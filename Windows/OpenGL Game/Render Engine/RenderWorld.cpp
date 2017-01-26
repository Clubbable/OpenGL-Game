#include "RenderWorld.h"
#include "Models.h"

//Render Engine classes are model classes, M in MVC

RenderWorld::RenderWorld(void)
{
	gameLighting = new LightingTechnique();
	gameTerrain = new Mesh();
	gameFences = new Mesh();

	setGameCamera();
	setSkyBox();
	setLight();
	setCameraProj();
	setObjectPositions();
	setObjectScale();
}

RenderWorld::RenderWorld(vector<Mesh*> gameObjects, LightingTechnique* gameLighting, DirectionalLight light, PersProjInfo cameraProjection, SkyBox* gameSkybox, vector<Vector3f> objectPositions, vector<Vector3f> objectScale, Mesh* gameTerrain, Mesh* gameFences)
{
	setGameLighting(gameLighting);
	setGameCamera();
	setSkyBox(gameSkybox); 
	setLight(light);
	setCameraProj(cameraProjection);
	setObjectPositions(objectPositions);
	setObjectScale(objectScale);
	setGameObjects(gameObjects);
	setTerrain(gameTerrain);
	setFences(gameFences);
}

void RenderWorld::setLight(void)
{
	light.AmbientIntensity = Models::lightAmbientIntensity;
	light.DiffuseIntensity = Models::lightDiffuseIntensity;
	light.Color = Models::lightColor;
	light.Direction = Models::lightDirection;
}

void RenderWorld::setLight(DirectionalLight light)
{
	this->light.AmbientIntensity = light.AmbientIntensity;
	this->light.DiffuseIntensity = light.DiffuseIntensity;
	this->light.Color = light.Color;
	this->light.Direction = light.Direction;
}

void RenderWorld::setCameraProj(void)
{
	cameraProjection.FOV = Models::cameraProjectionFOV;
	cameraProjection.Height = WINDOW_HEIGHT;
	cameraProjection.Width = WINDOW_WIDTH;
	cameraProjection.zNear = Models::cameraProjectionZNear;
	cameraProjection.zFar = Models::cameraProjectionZFar;
}

void RenderWorld::setCameraProj(PersProjInfo cameraProjection)
{
	this->cameraProjection.FOV = cameraProjection.FOV;
	this->cameraProjection.Height = cameraProjection.Height;
	this->cameraProjection.Width = cameraProjection.Width;
	this->cameraProjection.zNear = cameraProjection.zNear;
	this->cameraProjection.zFar = cameraProjection.zFar;
}

void RenderWorld::setObjectPositions(void)
{
	for( int i = 0; i < Models::ObjectAmount; i++ )
		objectPositions.push_back(Models::ObjectPosition[i]);

}

void RenderWorld::setObjectPositions(vector<Vector3f> objectPositions)
{
	this->objectPositions = objectPositions;
}

void RenderWorld::setObjectScale(void)
{
	for( int i = 0; i < Models::ObjectAmount; i++ )
		objectScale.push_back(Models::ObjectScale[i]);
}

void RenderWorld::setObjectScale(vector<Vector3f> objectScale)
{
	this->objectScale = objectScale;
}

void RenderWorld::setGameObjects(vector<Mesh*> gameObjects)
{
	this->gameObjects = gameObjects;
}

void RenderWorld::setGameLighting(LightingTechnique* gameLighting)
{
	this->gameLighting = gameLighting;
}

void RenderWorld::setSkyBox(void)
{
	gameSkybox = new SkyBox(gameCamera, cameraProjection);
}

void RenderWorld::setSkyBox(SkyBox* gameSkybox)
{
	this->gameSkybox = gameSkybox;
}

void RenderWorld::setTerrain(Mesh* gameTerrain)
{
	this->gameTerrain = gameTerrain;
}

void RenderWorld::setFences(Mesh* gameFences)
{
	this->gameFences = gameFences;
}

void RenderWorld::setGameCamera(void)
{
	gameCamera = new Camera(WINDOW_WIDTH, WINDOW_HEIGHT, Models::cameraPos, Models::cameraTarget, Models::cameraUp);
}

void RenderWorld::setGameCamera(Camera* gameCamera)
{
	this->gameCamera = gameCamera;
}

bool RenderWorld::initWorld(void)
{
	if(!initGameLighting())
	{
		return false;
	}
	if(!initGameObjects())
	{
		return false;
	}
	if(!initSkyBox())
	{
		return false;
	}
	if(!initTerrain())
	{
		return false;
	}
	if(!initFences())
	{
		return false;
	}
	return true;
}

bool RenderWorld::initGameLighting(void)
{
	if(!gameLighting->Init())
	{
		printf("Error initializing the lighting technique\n");
		return false;
	}

	gameLighting->Enable();
	gameLighting->SetDirectionalLight(light);
	gameLighting->SetTextureUnit(0);

	return true;
}

bool RenderWorld::initTerrain(void)
{
	if(!gameTerrain->LoadMesh(Models::terrainFile))
		return false;

	return true;
}

bool RenderWorld::initFences(void)
{

	if(!gameFences->LoadMesh(Models::fenceFile))
			return false;

	return true;
}

bool RenderWorld::initGameObjects(void)
{
	for( int i = 0; i < Models::ObjectAmount; i++ )
	{
		gameObjects.push_back(new Mesh());
		if(!(gameObjects.at(i))->LoadMesh(Models::objectFile[i]))
			return false;
	}

	return true;
}

bool RenderWorld::initSkyBox(void)
{
	if(!gameSkybox->Init(".",
			Models::skyBoxRight,
			Models::skyBoxLeft,
			Models::skyBoxTop,
			Models::skyBoxBot,
			Models::skyBoxFront,
			Models::skyBoxBack)) {
            return false;
        }
        
        return true;
}

bool RenderWorld::checkGameObjects(void)
{
	if(gameObjects.size() == objectPositions.size())
	{
		if(objectPositions.size() == objectScale.size())
			return true;
	}

	return false;
}

LightingTechnique* RenderWorld::getGameLighting()
{
	return gameLighting;
}

Camera* RenderWorld::getGameCamera()
{
	return gameCamera;
}

DirectionalLight RenderWorld::getLight()
{
	return light;
}

vector<Mesh*> RenderWorld::getGameObjects()
{
	return gameObjects;
}

vector<Vector3f> RenderWorld::getObjectPositions()
{
	return objectPositions;
}

vector<Vector3f> RenderWorld::getObjectScale()
{
	return objectScale;
}

PersProjInfo RenderWorld::getCameraProjection()
{
	return cameraProjection;
}

SkyBox* RenderWorld::getGameSkybox()
{
	return gameSkybox;
}

Mesh* RenderWorld::getGameTerrain()
{
	return gameTerrain;
}

Mesh* RenderWorld::getGameFences()
{
	return gameFences;
}

RenderWorld::~RenderWorld(void)
{
	SAFE_DELETE(gameLighting);
	SAFE_DELETE(gameCamera);
	SAFE_DELETE(gameSkybox);
	SAFE_DELETE(gameTerrain);
	SAFE_DELETE(gameFences);
	gameObjects.clear();
	objectPositions.clear();
	objectScale.clear();
}
