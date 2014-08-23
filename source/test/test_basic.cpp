
#include "gtest/gtest.h"
#include <iostream>
#include <limits>

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

}