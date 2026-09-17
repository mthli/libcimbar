#pragma once
#include "unittest.h"

#include <opencv2/opencv.hpp>
#include "serialize/format.h"
#include <string>
#include <vector>

namespace TestCimbar
{
	// float matrices differ in the last couple of digits between x86 and arm, so don't compare them as strings
	inline void assertMatxApprox(const std::vector<float>& expected, const cv::Matx<float, 3, 3>& actual, float epsilon=1e-4f)
	{
		REQUIRE(expected.size() == 9);
		for (unsigned i = 0; i < 9; ++i)
		{
			INFO("element " << i);
			REQUIRE(actual.val[i] == Approx(expected[i]).epsilon(epsilon).margin(1e-6));
		}
	}

	inline std::string getSample(std::string filename)
	{
		return std::string(LIBCIMBAR_PROJECT_ROOT) + "/samples/" + filename;
	}

	inline cv::Mat loadSample(std::string filename)
	{
		cv::Mat mat = cv::imread(getSample(filename));
		cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
		return mat;
	}

	inline std::string getProjectDir()
	{
		return std::string(LIBCIMBAR_PROJECT_ROOT);
	}
}

