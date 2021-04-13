#pragma once
#define IL inline
#include "Vec3.h"

template<typename F> struct AABB {

	Vec3<F> min;
	Vec3<F> max;

	IL AABB(){
		min.setMin();
		max.setMax();
	}
	IL AABB(const Vec3<F>& v1, const Vec3<F>& v2 , const Vec3<F>& v3){
		Add(v1), Add(v2), Add(v3);
	}

	IL void Add(const Vec3<F>& v)
	{
		min.CheckMin(v);
		max.CheckMax(v);
	}

	bool IsContainPoint(const Vec3<F>& pos) const
	{
		if (pos.x < min.x) return false;
		if (pos.y < min.y) return false;
		if (pos.z < min.z) return false;
		if (pos.x > max.x) return false;
		if (pos.y > max.y) return false;
		if (pos.z > max.z) return false;
		return true;
	}
};
