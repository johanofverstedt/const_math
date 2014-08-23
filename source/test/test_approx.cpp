
#include "gtest/gtest.h"

#include <cmath>

#include "../../const_math.h"

TEST(ConstMathApprox, Helpers) {
	
	EXPECT_NEAR(0.25, const_math::modulo(1.25, 0.5), 0.00001);
	EXPECT_NEAR(0.30, const_math::modulo(-1.20, 0.5), 0.00001);

}

TEST(ConstMathApprox, SquareRoot) {

	const double tolerance = 0.000000000001;

	EXPECT_NEAR(sqrt(0.5), const_math::square_root(0.5), tolerance);
	EXPECT_NEAR(sqrt(10.0), const_math::square_root(10.0), tolerance);
	EXPECT_NEAR(sqrt(1000.0), const_math::square_root(1000.0), tolerance);
	EXPECT_NEAR(sqrt(30000.0), const_math::square_root(30000.0), tolerance);
}

TEST(ConstMathApprox, Sin) {

	const double tolerance = 0.00000000000001;

	EXPECT_NEAR(sin(0.0), const_math::sin(0.0), tolerance);
	EXPECT_NEAR(sin(const_math::PI), const_math::sin(const_math::PI), tolerance);
	EXPECT_NEAR(sin(const_math::pi_mult(2.0)), const_math::sin(const_math::pi_mult(2.0)), tolerance);
	EXPECT_NEAR(sin(-const_math::pi_mult(2.0)), const_math::sin(-const_math::pi_mult(2.0)), tolerance);
	EXPECT_NEAR(sin(-const_math::PI), const_math::sin(-const_math::PI), tolerance);
	EXPECT_NEAR(sin(const_math::pi_mult(-0.5)), const_math::sin(const_math::pi_mult(-0.5)), tolerance);
}

TEST(ConstMathApprox, Cos) {

	const double tolerance = 0.00000000000001;
	
	EXPECT_NEAR(cos(0.0), const_math::cos(0.0), tolerance);
	EXPECT_NEAR(cos(const_math::PI), const_math::cos(const_math::PI), tolerance);
	EXPECT_NEAR(cos(const_math::pi_mult(2.0)), const_math::cos(const_math::pi_mult(2.0)), tolerance);
	EXPECT_NEAR(cos(-const_math::pi_mult(2.0)), const_math::cos(-const_math::pi_mult(2.0)), tolerance);
	EXPECT_NEAR(cos(-const_math::PI), const_math::cos(-const_math::PI), tolerance);
	EXPECT_NEAR(cos(const_math::pi_mult(-0.5)), const_math::cos(const_math::pi_mult(-0.5)), tolerance);

}
