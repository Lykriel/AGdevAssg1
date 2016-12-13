#pragma once
#include "../GenericEntity.h"
#include "../GroundEntity.h"
#include "MeshBuilder.h"

class Mesh;

class CEnemy :
	public GenericEntity
{
protected:
	Vector3 defaultPosition, defaultTarget, defaultUp;
	Vector3 target, up;
	Vector3 maxBoundary, minBoundary;
	GroundEntity* m_pTerrain;

	double m_dSpeed;
	double m_dAcceleration;

public:
	CEnemy(void);
	virtual ~CEnemy();

	void Init(void);
	//reset this player instance to dafault
	void Reset(void);

	//Set position
	void SetPos(const Vector3& pos);
	//Set Target
	void SetTarget(const Vector3& target);
	//Set Up
	void SetUp(const Vector3& up);
	//Set the boundary for the player info
	void SetBoundary(Vector3 max, Vector3 min);
	//Set the terrain for the player info
	void SetTerrain(GroundEntity* m_pTerrain);

	//Get position
	Vector3 GetPos(void) const;
	//Get Target
	Vector3 GetTarget(void) const;
	//Get Up
	Vector3 GetUp(void) const;
	//Get the terrain for the plater info
	GroundEntity* GetTerrain(void);

	//Update
	void Update(double dt = 0.0333f);

	//Constrain in the position within the borders
	void Constrain(void);
	//Render
	void Render(void);
};
