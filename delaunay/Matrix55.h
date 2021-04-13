#pragma once
#define IL inline
#include "Matrix44.h"


template<typename F> struct Matrix55
{

	F m00, m01, m02, m03, m04;
	F m10, m11, m12, m13, m14;
	F m20, m21, m22, m23, m24;
	F m30, m31, m32, m33, m34;
	F m40, m41, m42, m43, m44;

	IL Matrix55()
	{
		m00 = 0;
		m01 = 0;
		m02 = 0;
		m03 = 0;
		m04 = 0;
		m10 = 0;
		m11 = 0;
		m12 = 0;
		m13 = 0;
		m14 = 0;
		m20 = 0;
		m21 = 0;
		m22 = 0;
		m23 = 0;
		m24 = 0;
		m30 = 0;
		m31 = 0;
		m32 = 0;
		m33 = 0;
		m34 = 0;
		m40 = 0;
		m41 = 0;
		m42 = 0;
		m43 = 0;
		m44 = 0;
	}

	IL Matrix55(F v00, F v01, F v02, F v03, F v04,
		        F v10, F v11, F v12, F v13, F v14,
		        F v20, F v21, F v22, F v23, F v24,
		        F v30, F v31, F v32, F v33, F v34,
		        F v40, F v41, F v42, F v43, F v44 )
	{
		m00 = v00;
		m01 = v01;
		m02 = v02;
		m03 = v03;
		m04 = v04;
		m10 = v10;
		m11 = v11;
		m12 = v12;
		m13 = v13;
		m14 = v14;
		m20 = v20;
		m21 = v21;
		m22 = v22;
		m23 = v23;
		m24 = v24;
		m30 = v30;
		m31 = v31;
		m32 = v32;
		m33 = v33;
		m34 = v34;
		m40 = v40;
		m41 = v41;
		m42 = v42;
		m43 = v43;
		m44 = v44;
	}
	IL void SetIdentity()
	{
		m00 = 1;
		m01 = 0;
		m02 = 0;
		m03 = 0;
		m04 = 0;
		m10 = 0;
		m11 = 1;
		m12 = 0;
		m13 = 0;
		m14 = 0;
		m20 = 0;
		m21 = 0;
		m22 = 1;
		m23 = 0;
		m24 = 0;
		m30 = 0;
		m31 = 0;
		m32 = 0;
		m33 = 1;
		m34 = 0;
		m40 = 0;
		m41 = 0;
		m42 = 0;
		m43 = 0;
		m44 = 1;
	}

	IL Matrix55& Transpose(const Matrix55& m)
	{
		m00 = m.m00;
		m01 = m.m10;
		m02 = m.m20;
		m03 = m.m30;
		m04 = m.m40;
		m10 = m.m01;
		m11 = m.m11;
		m12 = m.m21;
		m13 = m.m31;
		m14 = m.m41;
		m20 = m.m02;
		m21 = m.m12;
		m22 = m.m22;
		m23 = m.m32;
		m24 = m.m42;
		m30 = m.m03;
		m31 = m.m13;
		m32 = m.m23;
		m33 = m.m33;
		m34 = m.m43;
		m40 = m.m04;
		m41 = m.m14;
		m42 = m.m24;
		m43 = m.m34;
		m44 = m.m44;
		return *this;
	}
	IL void Transpose()
	{
		Transpose(Matrix55(*this));
	}

	F Determinant() const
	{
		Matrix44<F> 
		 mtr1(
			m11, m12, m13, m14,
			m21, m22, m23, m24,
			m31, m32, m33, m34,
			m41, m42, m43, m44),
		 mtr2(
			m10, m12, m13, m14,
			m20, m22, m23, m24,
			m30, m32, m33, m34,
			m40, m42, m43, m44),
		 mtr3(
			m10, m11, m13, m14,
			m20, m21, m23, m24,
			m30, m31, m33, m34,
			m40, m41, m43, m44),
		 mtr4(
			m10, m11, m12, m14,
			m20, m21, m22, m24,
			m30, m31, m32, m34,
			m40, m41, m42, m44),
		 mtr5(
			m10, m11, m12, m13,
			m20, m21, m22, m23,
			m30, m31, m32, m33,
			m40, m41, m42, m43);

		F det = m00*mtr1.Determinant() - m01 * mtr2.Determinant() + m02 * mtr3.Determinant() 
			- m03 * mtr4.Determinant() + m04 * mtr5.Determinant();

		return det;
	}
};
