#pragma once

//Render Engine classes are view classes, V in MVC

#include "RenderWorld.h"
#include "Collision.h"

class RenderGame: public ICallbacks
{
public:
	RenderGame(void);

	void run(void);

	void renderTerrain(Pipeline p);
	void renderFence(Pipeline p );
	void renderGameObjects(Pipeline p, vector<Mesh*> gameObjects, vector<Vector3f> objectPositions, vector<Vector3f> objectScale);

	bool addGameObject(string filePath, Vector3f objectPosition, Vector3f objectScale);

	virtual void RenderSceneCB(void);
	virtual void IdleCB();
	virtual void KeyboardCB(unsigned char Key, int x, int y);
	virtual void PassiveMouseCB(int x, int y);
	virtual void SpecialKeyboardCB(int Key, int x, int y);

	~RenderGame(void);

	RenderWorld* getGameWorld();

private:
	RenderWorld* gameWorld;
	Collision* gameCollision;
};

