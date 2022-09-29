#pragma once

#include "objectbase.hpp"

namespace RT
{
	class ObjSphere : public ObjectBase
	{
	public:
		ObjSphere();
		virtual ~ObjSphere() override;

		virtual bool TestIntersection(const Ray& castRay, qbVector<double>& intPoint, qbVector<double>& localNormal, qbVector<double>& localColor);
	private:

	};
}