
#include "gtest/gtest.h"

#include <cmath>

#include "../../const_math.h"

TEST(ConstMathApprox, NormalUse) {
	EXPECT_NEAR(sqrt(0.5), const_math::square_root(0.5), 0.000001);
	EXPECT_NEAR(sqrt(10.0), const_math::square_root(10.0), 0.000001);
	EXPECT_NEAR(sqrt(1000.0), const_math::square_root(1000.0), 0.000001);
	EXPECT_NEAR(sqrt(30000.0), const_math::square_root(30000.0), 0.000001);
}
