#include "RenderGame.h"
#include "Models.h"

//Render Engine classes are view classes, V in MVC

RenderGame::RenderGame(void)
{
	gameWorld = new RenderWorld();

	if(!gameWorld->initWorld())
		printf("Game World initialization failed");

	gameCollision = new Collision(gameWorld->getGameCamera(), gameWorld->getGameObjects(), gameWorld->getGameTerrain());
}

void RenderGame::run()
{
   GLUTBackendRun(this);
}

void RenderGame::RenderSceneCB(void)
{
	//Render logics

	if(!gameWorld->checkGameObjects())
		printf("game objects and objects scale and objects position sizes are not the same");
	
	gameWorld->getGameCamera()->OnRender();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gameWorld->getGameLighting()->Enable();

	Pipeline p;
	p.SetCamera(gameWorld->getGameCamera()->GetPos(), gameWorld->getGameCamera()->GetTarget(), gameWorld->getGameCamera()->GetUp());
	p.SetPerspectiveProj(gameWorld->getCameraProjection());

	renderGameObjects(p, gameWorld->getGameObjects(), gameWorld->getObjectPositions(), gameWorld->getObjectScale());
	renderTerrain(p);
	renderFence(p);

	gameWorld->getGameSkybox()->Render();

	//Game logics

	//gameCollision->getTerrainData()->writeToFile(gameWorld->getGameCamera()->GetPos());

	glutSwapBuffers();
}

void RenderGame::renderGameObjects(Pipeline p, vector<Mesh*> gameObjects, vector<Vector3f> objectPositions, vector<Vector3f> objectScale)
{
	for (int i = 0; i < gameObjects.size(); i++ )
	{
		p.Scale(objectScale.at(i).x, objectScale.at(i).y, objectScale.at(i).z);
		p.WorldPos(objectPositions.at(i).x, objectPositions.at(i).y, objectPositions.at(i).z);
		gameWorld->getGameLighting()->SetWVP(p.GetWVPTrans());
		gameWorld->getGameLighting()->SetWorldMatrix(p.GetWorldTrans());
		gameObjects.at(i)->Render();
	}
}

void RenderGame::renderTerrain(Pipeline p)
{
	p.Scale(Models::terrainScale.x, Models::terrainScale.y, Models::terrainScale.z);
	p.WorldPos(Models::terrainWorldPos.x, Models::terrainWorldPos.y, Models::terrainWorldPos.z);
	gameWorld->getGameLighting()->SetWVP(p.GetWVPTrans());
	gameWorld->getGameLighting()->SetWorldMatrix(p.GetWorldTrans());
	gameWorld->getGameTerrain()->Render();
	
}

void RenderGame::renderFence(Pipeline p)
{
	// Render all 28 fences
	for( int i = 0; i < Models::FenceAmount; i++)
	{
		p.Scale(Models::FenceScale.x, Models::FenceScale.y, Models::FenceScale.z);
		p.WorldPos(Models::FenceWorldPos[i].x, Models::FenceWorldPos[i].y, Models::FenceWorldPos[i].z);
		p.Rotate(Models::FenceRotate[i].x, Models::FenceRotate[i].y, Models::FenceRotate[i].z);
		gameWorld->getGameLighting()->SetWVP(p.GetWVPTrans());
		gameWorld->getGameLighting()->SetWorldMatrix(p.GetWorldTrans());
		gameWorld->getGameFences()->Render();
	}

}

void RenderGame::IdleCB()
{
   RenderSceneCB();
}

void RenderGame::KeyboardCB(unsigned char Key, int x, int y)
{
	char oppositeKey = 's';

	if( Key == 's')
		oppositeKey = 'w';
	else if ( Key == 'a')
		oppositeKey = 'd';
	else if ( Key == 'd' )
		oppositeKey = 'a';

	printf("%d, %d\n", (int)gameWorld->getGameCamera()->GetPos().x, (int)gameWorld->getGameCamera()->GetPos().z );
	if(gameCollision->terrainCollision(gameWorld->getGameCamera()->OnKeyboard(Key)) || (int)gameWorld->getGameCamera()->GetPos().z < -60 || (int)gameWorld->getGameCamera()->GetPos().z > 17 )
	{
		gameWorld->getGameCamera()->OnKeyboard(oppositeKey);
	}


}

void RenderGame::SpecialKeyboardCB(int Key, int x, int y)
{
}
void RenderGame::PassiveMouseCB(int x, int y)
{
	//Change the number 40 to increase/decrease mouse sensitivity
	//Can't turn if mouse click held, which needs to be addressed in the future

   bool mousemoved = false;

   if(x < glutGet(GLUT_WINDOW_WIDTH) / 2)
   {
	   gameWorld->getGameCamera()->OnMouse(-1 * Models::mouseSensitivity,0);
	   mousemoved = true;
   }

   if(x > glutGet(GLUT_WINDOW_WIDTH) / 2)
   {
	   gameWorld->getGameCamera()->OnMouse(Models::mouseSensitivity,0);
	   mousemoved = true;
   }

   if(y < glutGet(GLUT_WINDOW_HEIGHT) / 2)
   {
	   gameWorld->getGameCamera()->OnMouse(0, -1 * Models::mouseSensitivity);
	   mousemoved = true;
   }

   if(y > glutGet(GLUT_WINDOW_HEIGHT) / 2)
   {
	   gameWorld->getGameCamera()->OnMouse(0, Models::mouseSensitivity);
	   mousemoved = true;
   }

   if(mousemoved)
   {
	   glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2); 
   }
}


bool RenderGame::addGameObject(string filePath, Vector3f objectPosition, Vector3f objectScale)
{
	gameWorld->getGameObjects().push_back(new Mesh());
	if(!(gameWorld->getGameObjects().at(gameWorld->getGameObjects().size() - 1)->LoadMesh(filePath)))
		return false;

	gameWorld->getObjectPositions().push_back(objectPosition);
	gameWorld->getObjectScale().push_back(objectScale);		

	return true;
}

RenderWorld* RenderGame::getGameWorld()
{
	return gameWorld;
}

RenderGame::~RenderGame(void)
{
	SAFE_DELETE(gameWorld);
}
