//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
// Updated by Gary Chang on 14/1/15
//
// Copyright (c) 2014-2015 Concordia University. All rights reserved.
//

#pragma once

#include "ParsingHelper.h"
#include <vector>

class Camera;
class Model;
class Path;
class BSpline;
class SkyboxModel;

class World
{
public:
	World();
	~World();
	
    static World* GetInstance();

	void Update(float dt);
	void Draw();
	void DrawMainMenu();
	void DrawPauseMenu();
	void DrawOptionsMenu();
	void DrawScreenshotsMenu();

	void LoadScene(const char * scene_path);
    void LoadCameras();

    Path* FindPath(ci_string pathName);
    BSpline* FindSpline(ci_string pathName);
    BSpline* FindSplineByIndex(unsigned int index);
    Model* FindModelByIndex(unsigned int index);

private:
    static World* instance;

	std::vector<Model*> mModel;
	std::vector<Model*> mSkybox;
    std::vector<Path*> mPath;
    std::vector<BSpline*> mSpline;
	std::vector<Camera*> mCamera;
	unsigned int mCurrentCamera;
	int score;
	SkyboxModel* groundDay;
	SkyboxModel* skyboxDay;
	SkyboxModel* groundNight;
	SkyboxModel* skyboxNight;


	void setUpLightingShader();
	void setUpTextureShader();
	void setUpSkyboxShader();
};
