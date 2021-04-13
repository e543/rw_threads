#pragma once
#include "Methods.h";
#include "ConsoleHelper.h";
#include <list>
#define tmList std::list<TestMethod>

class TestsRunner
{
	IMessage* _msg = nullptr;
	PointState result = Error;
	std::string str;
	public: 
		TestsRunner(IMessage* msg) : _msg(msg) {
			_msg->Greeting();
		}
		~TestsRunner() {
			if (_msg) {
				_msg->Parting();
				delete _msg;
			}
		}


		

		void RunTests(size_t n, tmList test_methods) {


			if (n > 0)
			{
				Vec3f v1, v2, v3, v4, r5;
				r5 = Vec3f(1, -2, -7);
				while (checkCompl(v1, v2, v3, v4)) {
					v1 = Vec3f(-1, 4, 0);
					v2 = Vec3f(6, 1, 0);
					v3 = Vec3f(5, 1, -2);
					v4 = Vec3f(3, -1, 0);
				}

				_msg->sendMsg("Name:\t\tState:\t\tTime:");
				_msg->sendMsg("------------------------------------------------");

				for (TestMethod tm : test_methods) {



					double t1 = getCPUTime();
					for (size_t N = n; --N > 0 && tm.RunTest(v1, v2, v3, v4, r5););
					double t2 = getCPUTime();



					result = tm.RunTest(v1, v2, v3, v4, r5);
					send_methodName(tm);
					send_result();
					if (result != Error)
						str += (std::to_string(t2 - t1) + " sec");
					_msg->sendMsg(str);
					str = "";
				}

				_msg->sendMsg("------------------------------------------------");
			}
			else _msg->sendMsg("N error");
		}

		IL void send_result() {
			if (_msg)
			{
				switch (result)
				{
				case (InSphere):
					str += "InSphere\t";
					break;
				case (OutOfSphere):
					str += "OutOfSphere\t";
					break;
				case (OnSphere):
					str += "OnSphere\t";
					break;
				case (Error):
					str += "State error\t";
					break;
				default:
					str += "State error\t";
					break;
				}
			}
		}

		IL void send_methodName(TestMethod& test_method) {
			if (_msg)
			{
				switch (test_method.getName())
				{
				case (MethodMaur1):
					str += "Maur1\t\t";
					break;
				case (MethodMaur2):
					str += "Maur2\t\t";
					break;
				case (_Method3):
					str += "Method3\t\t";
					break;
				case (_Method4):
					str += "Method4\t\t";
					break;
				case (_Method5):
					str += "Method5\t\t";
					break;
				case (_Method6):
					str += "Method6\t\t";
					break;
				case (UNDEF):
					str += "Name error!\t\t";
					break;
				default:
					str += "Name error!\t\t";
					break;
				}
			}
		}


};

