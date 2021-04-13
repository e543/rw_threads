#pragma once
#include <limits> 
#include <Math.h>

template<typename F> struct Vec3
{
	F x = 0, y = 0, z = 0;
	Vec3()  {}
	Vec3(F vx, F vy, F vz) : x(vx), y(vy), z(vz) {}

	IL F dot(const Vec3<F>& v) const
	{
		return (F)(x * v.x + y * v.y + z * v.z);
	}

	IL Vec3 Cross(const Vec3<F>& v) const
	{
		return Vec3<F>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	IL F GetDistance(const Vec3<F>& v) const
	{
		return sqrtf(GetSquaredDistance(v));
	}

	IL F GetSquaredDistance(const Vec3<F>& v) const
	{
		return (x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z);
	}

	IL Vec3<F>& Flip()
	{
		x = -x;
		y = -y;
		z = -z;
		return *this;
	}

	IL Vec3<F>& Set(F sx, F sy, F sz)
	{
		x = sx;
		y = sy;
		z = sz;
		return *this;
	}

	IL F Max(F a, F b) {
		return (((a) > (b)) ? (a) : (b));
	};

	IL F Min(F a, F b) {
		return (((a) < (b)) ? (a) : (b));
	};

	IL Vec3<F> operator-(const Vec3<F>& v) const
	{
		return Vec3<F>(x - v.x, y - v.y, z - v.z);
	}

	IL Vec3<F> operator+(const Vec3<F>& v) const
	{
		return Vec3<F>(x + v.x, y + v.y, z + v.z);
	}

	IL Vec3<F> operator*(const Vec3<F>& v) const
	{
		return Vec3<F>(x * v.x, y * v.y, z * v.z);
	}

	IL Vec3<F> operator*(F val) const
	{
		return Vec3<F>(x * val, y * val, z * val);
	}

	IL Vec3<F> operator/(F val) const
	{
		return Vec3<F>(x / val, y / val, z / val);
	}
	IL Vec3<F>& normalize()
	{
		F len2 = sqrtf(x * x + y * y + z * z);
		if (len2 > (F)1e-20f)
		{
			F rlen = 1/len2;
			x *= rlen;
			y *= rlen;
			z *= rlen;
		}
		else
			Set(0, 0, 1);
		return *this;
	}

	IL void CheckMin(const Vec3<F>& other)
	{
		x = Min(other.x, x);
		y = Min(other.y, y);
		z = Min(other.z, z);
	}

	IL void CheckMax(const Vec3<F>& other)
	{
		x = Max(other.x, x);
		y = Max(other.y, y);
		z = Max(other.z, z);
	}

	IL void setMin() {
		x = -std::numeric_limits<F>::max();
		y = -std::numeric_limits<F>::max();
		z = -std::numeric_limits<F>::max();
	}
	IL void setMax() {
		x = std::numeric_limits<F>::max();
		y = std::numeric_limits<F>::max();
		z = std::numeric_limits<F>::max();
	}
};

