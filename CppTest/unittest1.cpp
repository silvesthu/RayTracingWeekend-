#include "stdafx.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../RayTracingWeekend/material.h"

#include <ppl.h>
using namespace concurrency;

namespace CppTest
{		
	TEST_CLASS(_vec3)
	{
	public:		
		TEST_METHOD(_size)
		{
			Assert::AreEqual(sizeof(vec3), 3 * sizeof(float));
		}

		TEST_METHOD(_dot)
		{
			auto d = dot(vec3(1, 1, 0), vec3(1, 1, 0));
			Assert::AreEqual(d, 2.0f);
		}

		TEST_METHOD(_cross)
		{
			auto c = cross(vec3(1, 0, 0), vec3(0, 1, 0));
			Assert::AreEqual(c.x, 0.0f);
			Assert::AreEqual(c.y, 0.0f);
			Assert::AreEqual(c.z, 1.0f);
		}

		TEST_METHOD(_ctor)
		{
			auto r = ray(vec3(1, 1, 1), vec3(2, 2, 2));
			Assert::AreEqual(r.point_at_parameter(3).x, 7.0f);
			Assert::AreEqual(r.point_at_parameter(3).y, 7.0f);
			Assert::AreEqual(r.point_at_parameter(3).z, 7.0f);
		}
	};

	TEST_CLASS(_ppl)
	{
	public:
		TEST_METHOD(_reduce)
		{
			std::vector<int> i = { 1, 2, 30, 10, 4, 3, 1 };
			int int_min = INT_MIN;
			auto max_i = parallel_reduce(i.begin(), i.end(), int_min, [&](int result, int& next)
			{
				return std::max(result, next);
			});
			Assert::AreEqual(max_i, 30);
		}
	};

	TEST_CLASS(_random)
	{
	public:
		TEST_METHOD(_reduce)
		{
			std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
			Assert::AreEqual(distribution.min(), 0.0f);
			Assert::AreEqual(distribution.max(), 1.0f);
		}
	};
}