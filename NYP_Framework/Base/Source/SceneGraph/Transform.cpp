#include "Transform.h"
#include <iostream>

using namespace std;

// Default Constructor
CTransform::CTransform(void)
{
	Mtx.SetToIdentity();
	DefaultMtx.SetToIdentity();
}

// Overloaded Constructor
CTransform::CTransform(const float dx, const float dy, const float dz)
{
}

// Destructor
CTransform::~CTransform(void)
{
}

// Apply a translation to the Transformation Matrix
void CTransform::ApplyTranslate(const float dx, const float dy, const float dz)
{
}
// Get the translation from the Transformation Matrix
void CTransform::GetTranslate(float& x, float& y, float& z)
{
}
// Apply a rotation to the Transformation Matrix
void CTransform::ApplyRotate(const float angle, const float rx, const float ry, const float rz)
{
}
// Get the rotation from the Transformation Matrix
float CTransform::GetRotate(const AXIS theAxis)
{
	return 0.0f;
}
// Set the scale of the Transformation Matrix
void CTransform::SetScale(const float sx, const float sy, const float sz)
{
}
// Get the scale from the Transformation Matrix
void CTransform::GetScale(float& x, float& y, float& z)
{
}

// Apply a Transformation Matrix to the Transformation Matrix here
void CTransform::ApplyTransform(Mtx44 newMTX)
{
}

// Reset the transformation matrix to identity matrix
void CTransform::Reset(void)
{
}

// Get the transformation matrix
Mtx44 CTransform::GetTransform(void)
{
	return Mtx;
}

// Print Self
void CTransform::PrintSelf(void) const
{
}
