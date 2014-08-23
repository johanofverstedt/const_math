
#include "gtest/gtest.h"
#include <iostream>
#include <limits>

#include "../../const_math.h"

TEST(ConstMathAlgorithms, PowerN) {

	EXPECT_EQ(256, const_math::power_n(2, 8));
	EXPECT_EQ(512, const_math::power_n(2, 9));
	EXPECT_EQ(4294967296LL, const_math::power_n(2LL, 32ULL));

	EXPECT_EQ(1, const_math::power_n(1024, 0)); //Test for zero exponent
	EXPECT_EQ(0, const_math::power_n(1024, -1)); //Degenerate case, since value type is int, division (1 / x) where x > 1 yields 0

	//Test some floating point calculations

	const double tolerance = 0.0000001;

	EXPECT_NEAR(256.0, const_math::power_n(2.0, 8), tolerance);
	EXPECT_NEAR(0.0, const_math::power_n(0.999999, std::numeric_limits<std::size_t>::max()), tolerance); //Test with huge exponent (max value of std::size_t) to verify efficiency
	EXPECT_NEAR(0.25, const_math::power_n(2.0, -2), tolerance); //Test negative exponent

}
