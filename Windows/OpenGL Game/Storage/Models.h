#pragma once

#include <Header files\Header.h>

#define WINDOW_WIDTH  1150	
#define WINDOW_HEIGHT 900

namespace Models
{

//Mouse sensitivity and camera movement speed
	static float mouseSensitivity = 40;
	static float speed = 1;

//RenderWorld

	//Light

	static float lightAmbientIntensity = 0.2f;
	static float lightDiffuseIntensity = 0.6f;
	static Vector3f lightColor = Vector3f(1.0f, 1.0f, 1.0f);
	static Vector3f lightDirection = Vector3f(1.0, -1.0f, 0.0f);

	//Camera Projection

	static float cameraProjectionFOV = 60.0f;
	static float cameraProjectionHeight = WINDOW_HEIGHT;
	static float cameraProjectionWidth = WINDOW_WIDTH;
	static float cameraProjectionZNear = 1.0f;
	static float cameraProjectionZFar = 100.0f;

	//Game Object Amount

	static int ObjectAmount = 3;

	//Game Object Positions, from 1 to N

	static Vector3f ObjectPosition[] = {Vector3f(-6.0f, 0.0f, 10.0f),
										Vector3f(6.0f, 0.0f, 10.0f),
										Vector3f(0.0f, 10.0f, 5.0f)};

	//Game Object Scale, from 1 to N

	static Vector3f ObjectScale[] = {Vector3f(0.1f, 0.1f, 0.1f),
									Vector3f(0.01f, 0.01f, 0.01f),
									Vector3f(0.03f, 0.03f, 0.03f)};

	//Game Object Models

	static string objectFile[] = {"Models/phoenix tank/phoenix_ugv.md2", "Models/jeep/jeep.OBJ", "Models/helicopter/hheli.OBj" };

	//Game Camera

	static Vector3f cameraPos = Vector3f(5.0f, 3.0f, -12.0f);
	static Vector3f cameraTarget = Vector3f(0.0f, -0.2f, 1.0f);
	static Vector3f cameraUp = Vector3f(0.0f, 1.0f, 0.0f);
	
	//Environment Models

	static string terrainFile = "Models/terrain/infinitewave_terrain_011.OBJ";
	static string fenceFile = "Models/fence/Fence_BS.OBJ";

	//Skybox

	static string skyBoxRight = "Models/skybox/sp3right.jpg";
	static string skyBoxLeft = "Models/skybox/sp3left.jpg";
	static string skyBoxTop = "Models/skybox/sp3top.jpg";
	static string skyBoxBot = "Models/skybox/sp3bot.jpg";
	static string skyBoxFront = "Models/skybox/sp3front.jpg";
	static string skyBoxBack = "Models/skybox/sp3back.jpg";

//RenderGame

	//Terrain
	static Vector3f terrainScale = Vector3f(25.0f, 25.0f, 25.0f);
	static Vector3f terrainWorldPos = Vector3f(0.0f, 0.0f, -15.0f);

	//Fences, from 1 to 28

	static int FenceAmount = 28;

	static Vector3f FenceScale = Vector3f(1.0f, 1.0f, 1.0f);

	static Vector3f FenceWorldPos[] = {Vector3f(67.0f, 0.0f, -45.0f),
									   Vector3f(82.0f, 0.0f, -50.0f),
									   Vector3f(84.0f, 0.0f, -60.0f),
									   Vector3f(76.0f, 0.0f, -63.0f),
									   Vector3f(65.0f, 0.0f, -63.0f),
									   Vector3f(54.0f, 0.0f, -63.0f),
									   Vector3f(43.0f, 0.0f, -63.0f),
									   Vector3f(38.0f, 0.0f, -61.0f),
									   Vector3f(31.0f, 0.0f, -53.0f),
									   Vector3f(24.0f, 0.0f, -45.0f),
									   Vector3f(17.0f, 0.0f, -37.0f),
									   Vector3f(10.0f, 0.0f, -29.0f),
									   Vector3f(3.0f, 0.0f, -21.0f),
									   Vector3f(-2.0f, 0.0f, -7.0f),
									   Vector3f(-9.5f, 0.0f, -2.0f),
									   Vector3f(-13.0f, 0.0f, 1.5f),
									   Vector3f(-19.0f, 0.0f, 11.0f),
									   Vector3f(-21.0f, 0.0f, 20.0f),
									   Vector3f(-7.0f, 0.0f, 20.0f),
									   Vector3f(2.1f, 0.0f, 14.9f),
									   Vector3f(8.0f, 0.0f, 6.5f),
									   Vector3f(16.5f, 0.0f, 0.5f),
									   Vector3f(25.5f, 0.0f, -5.0f),
									   Vector3f(32.0f, -0.5f, -13.0f),
									   Vector3f(40.5f, -1.0f, -20.0f),
									   Vector3f(48.0f, 0.0f, -28.0f),
									   Vector3f(57.0f, 0.0f, -33.5f),
									   Vector3f(63.0f, 0.0f, -42.0f)};

	static Vector3f FenceRotate[] = {Vector3f(0.0f, 0.0f, 0.0f),
									Vector3f(0.0f, 140.0f, 0.0f),
									Vector3f(0.0f, 90.0f, 0.0f),
									Vector3f(0.0f, 0.0f, 0.0f),
									Vector3f(0.0f, 0.0f, 0.0f),
									Vector3f(0.0f, 0.0f, 0.0f),
									Vector3f(0.0f, 0.0f, 0.0f),
									Vector3f(0.0f, 130.0f, 0.0f),
									Vector3f(0.0f, 130.0f, 0.0f),
									Vector3f(0.0f, 130.0f, 0.0f),
									Vector3f(0.0f, 130.0f, 0.0f),
									Vector3f(0.0f, 130.0f, 0.0f),
									Vector3f(0.0f, 130.0f, 0.0f),
									Vector3f(0.0f, 260.0f, 0.0f),
									Vector3f(0.0f, 340.0f, 0.0f),
									Vector3f(0.0f, 120.0f, 0.0f),
									Vector3f(0.0f, 120.0f, 0.0f),
									Vector3f(0.0f, 30.0f, 0.0f),
									Vector3f(0.0f, 150.0f, 0.0f),
									Vector3f(0.0f, 150.0f, 0.0f),
									Vector3f(0.0f, 120.0f, 0.0f),
									Vector3f(0.0f, 150.0f, 0.0f),
									Vector3f(0.0f, 150.0f, 0.0f),
									Vector3f(0.0f, 120.0f, 0.0f),
									Vector3f(0.0f, 150.0f, 0.0f),
									Vector3f(0.0f, 130.0f, 0.0f),
									Vector3f(0.0f, 150.0f, 0.0f),
									Vector3f(0.0f, 120.0f, 0.0f)};
}


