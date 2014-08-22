
#include "gtest/gtest.h"

#include <array>
#include <cstdint>
#include <cmath>

#include "../../const_math.h"

TEST(ConstMathBasic, NormalUse) {

	EXPECT_EQ(-1, const_math::minimum(-1, 1));
	EXPECT_EQ(-1, const_math::minimum(1, -1));
	EXPECT_EQ(1, const_math::maximum(-1, 1));
	EXPECT_EQ(1, const_math::maximum(1, -1));

	EXPECT_EQ(2, const_math::abs_value(2));
	EXPECT_EQ(2, const_math::abs_value(-2));

	EXPECT_NEAR(0.5, const_math::reciprocal(2.0), 0.0000001);

	EXPECT_EQ(4, const_math::square(2));
	EXPECT_EQ(8, const_math::cube(2));

	EXPECT_TRUE(const_math::is_even(2));
	EXPECT_TRUE(const_math::is_odd(3));
	EXPECT_TRUE(const_math::is_even(-2));
	EXPECT_TRUE(const_math::is_odd(-1));

	EXPECT_EQ(256, const_math::pow_n(2, 8));
	EXPECT_EQ(512, const_math::pow_n(2, 9));
	EXPECT_EQ(1, const_math::pow_n(1024, 0));
	EXPECT_EQ(0, const_math::pow_n(1024, -1)); //Degenerate case, since value type is int, division (1 / x) where x > 1 yields 0

	
	//EXPECT_NEAR(0.25, const_math::pow_n(2.0, -2), 0.000001); //Doesn't compile with VS 2013 CTP

}