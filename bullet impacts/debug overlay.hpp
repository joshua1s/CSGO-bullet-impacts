#pragma once
#include "virtual method.hpp"
#include "vector.hpp"

class DebugOverlay
{
public:
	virtual void fn0() = 0;
	virtual void addBoxOverlay(const Vector& vecOrigin, const Vector& vecAbsMin, const Vector& vecAbsMax, const QAngle& angOrientation, int r, int g, int b, int a, float flDuration) = 0;

	//VIRTUAL(void, addBoxOverlay, 2, (const Vector& vecOrigin, const Vector& vecAbsMin, const Vector& vecAbsMax, const QAngle& angOrientation, int r, int g, int b, int a, float flDuration),
	//	(this, vecOrigin, vecAbsMin, vecAbsMax, angOrientation, r, g, b, a, flDuration))
};