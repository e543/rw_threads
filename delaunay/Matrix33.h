#pragma once
#define IL inline
#include "Vec3.h"

template<typename F> struct Matrix33
{
	F m00, m01, m02;
	F m10, m11, m12;
	F m20, m21, m22;

	IL Matrix33<F>(F x00, F x01, F x02, F x10, F x11, F x12, F x20, F x21, F x22)
	{
		m00 = x00;
		m01 = x01;
		m02 = x02;
		m10 = x10;
		m11 = x11;
		m12 = x12;
		m20 = x20;
		m21 = x21;
		m22 = x22;
	}

	IL Matrix33<F>(Vec3<F> v1, Vec3<F> v2, Vec3<F> v3)
	{
		m00 = v1.x;
		m01 = v1.y;
		m02 = v1.z;
		m10 = v2.x;
		m11 = v2.y;
		m12 = v2.z;
		m20 = v3.x;
		m21 = v3.y;
		m22 = v3.z;
	}

	IL void SetIdentity(void)
	{
		m00 = 1;
		m01 = 0;
		m02 = 0;
		m10 = 0;
		m11 = 1;
		m12 = 0;
		m20 = 0;
		m21 = 0;
		m22 = 1;
	}

	IL F Determinant(void) {
		Matrix33<F> m = *this;

		m.m00 = m22 * m11 - m12 * m21;
		m.m01 = m02 * m21 - m22 * m01;
		m.m02 = m12 * m01 - m02 * m11;
		m.m10 = m12 * m20 - m22 * m10;
		m.m11 = m22 * m00 - m02 * m20;
		m.m12 = m02 * m10 - m12 * m00;
		m.m20 = m10 * m21 - m20 * m11;
		m.m21 = m20 * m01 - m00 * m21;
		m.m22 = m00 * m11 - m10 * m01;

		F det = (m.m00 * m00 + m.m10 * m01 + m.m20 * m02);
		return det;
	}
};

