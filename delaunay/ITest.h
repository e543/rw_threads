#pragma once
struct ITest
{
	virtual ~ITest() {}
	virtual PointState RunTest(const  Vec3f&, const  Vec3f&, const Vec3f&, const Vec3f&, const Vec3f&) const = 0;
};