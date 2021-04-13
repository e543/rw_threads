#include "MethodName.h"
#include "PointState.h"
#include "IMethod.h"
#include "ITest.h"
#include "timer.h"

class TestMethod : public ITest
{
	IMethod* _test_method = 0;
public:
	TestMethod() {}
	~TestMethod() {
		//delete _test_method; ???
	}

	TestMethod(IMethod* method, IMessage* msg) {
		_test_method = method;
		method->_msg = msg;
	}
	MethodName getName() {
		return _test_method->method_name;
	}
	

	virtual PointState RunTest(const  Vec3f&, const  Vec3f&, const Vec3f&, const Vec3f&, const Vec3f&) const override;
};


PointState TestMethod::RunTest(const  Vec3f& v1, const  Vec3f& v2, const Vec3f& v3, const Vec3f& v4, const Vec3f& r5) const
{
	return _test_method->getResult(v1, v2, v3, v4, r5);
}
