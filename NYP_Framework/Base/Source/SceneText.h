#ifndef SCENE_TEXT_H
#define SCENE_TEXT_H

#include "Scene.h"
#include "Mtx44.h"
#include "PlayerInfo/PlayerInfo.h"
#include "GroundEntity.h"
#include "FPSCamera.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "GenericEntity.h"
#include "SceneGraph/UpdateTransformation.h"


class CEnemy;
class ShaderProgram;
class SceneManager;
class TextEntity;
class Light;
class EyeBall;

enum STATE
{
	ONE,
	TWO
};

class SceneText : public Scene
{
public:
	SceneText();
	~SceneText();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:
	SceneText(SceneManager* _sceneMgr); // This is used to register to SceneManager

	ShaderProgram* currProg;
	CPlayerInfo* playerInfo;
	GroundEntity* groundEntity;
	FPSCamera camera;
	TextEntity* textObj[3];
	Light* lights[2];

	GenericEntity* theCube;
	EyeBall* theEnemy[15];
    EyeBall* theBoss;

	static SceneText* sInstance; // The pointer to the object that gets registered
    Vector3 ReturnRandomXZPos(float Y_Pos);//returns random xz coord betw -499 and 499
};

#endif