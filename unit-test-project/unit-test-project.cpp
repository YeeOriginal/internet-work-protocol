#include "pch.h"
#include "CppUnitTest.h"

#include "../main-project/internet_work_protocol.h"
#include "../main-project/process.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			internet_work_protocol* testProtocols[3];
			testProtocols[0] = new internet_work_protocol{ {10, 20, 30}, {20, 30, 40}, 5456, 2343, "Spotify" };
			testProtocols[1] = new internet_work_protocol{ {9, 25, 33}, {10, 20, 30}, 7546, 5443, "Skype" };
			testProtocols[2] = new internet_work_protocol{ {15, 11, 34}, {21, 34, 22}, 9956, 7543, "Google_Chrome" };

			int skypeTime = timeOnInternet(testProtocols, "Skype", 3, 5);
			Assert::AreEqual(3297, skypeTime);

			for (int i = 0; i < 3; ++i) 
			{
				delete testProtocols[i];
			}
		}

		TEST_METHOD(TestMethod2)
		{
			internet_work_protocol* testProtocols[3];
			testProtocols[0] = new internet_work_protocol{ {10, 20, 30}, {20, 30, 40}, 5456, 2343, "Spotify" };
			testProtocols[1] = new internet_work_protocol{ {9, 25, 33}, {10, 20, 30}, 7546, 5443, "Skype" };
			testProtocols[2] = new internet_work_protocol{ {0, 0, 0}, {1, 10, 0}, 9956, 7543, "Skype" };

			int skypeTime = timeOnInternet(testProtocols, "Skype", 3, 5);
			Assert::AreEqual(7497, skypeTime);

			for (int i = 0; i < 3; ++i)
			{
				delete testProtocols[i];
			}
		}

		TEST_METHOD(TestMethod3)
		{
			internet_work_protocol* testProtocols[3];
			testProtocols[0] = new internet_work_protocol{ {10, 20, 30}, {20, 30, 40}, 5456, 2343, "Spotify" };
			testProtocols[1] = new internet_work_protocol{ {9, 25, 33}, {10, 20, 30}, 7546, 5443, "Google_Chrome" };
			testProtocols[2] = new internet_work_protocol{ {0, 0, 0}, {1, 10, 0}, 9956, 7543, "Spotify" };

			int skypeTime = timeOnInternet(testProtocols, "Skype", 3, 5);
			Assert::AreEqual(0, skypeTime);

			for (int i = 0; i < 3; ++i)
			{
				delete testProtocols[i];
			}
		}
	};
}
