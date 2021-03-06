/*
 * Created By: Marcus Swift
 * Created On: November 20th, 2017
 * Description: Unit tests for EKF
 */

#include <EKF.h>
#include <cmath>
#include <gtest/gtest.h>

TEST(EKF, AngleReboundingZeroCases) {
    EXPECT_DOUBLE_EQ(0, EKF::constrainAngleInBounds(-4. * M_PI));
    EXPECT_DOUBLE_EQ(0, EKF::constrainAngleInBounds(-2. * M_PI));
    EXPECT_DOUBLE_EQ(0, EKF::constrainAngleInBounds(2. * M_PI));
    EXPECT_DOUBLE_EQ(0, EKF::constrainAngleInBounds(4. * M_PI));
    EXPECT_DOUBLE_EQ(0, EKF::constrainAngleInBounds(0));
}

TEST(EKF, AngleReboundingM_PICases) {
    EXPECT_DOUBLE_EQ(M_PI, EKF::constrainAngleInBounds(-M_PI));
    EXPECT_DOUBLE_EQ(M_PI, EKF::constrainAngleInBounds(M_PI));
    EXPECT_DOUBLE_EQ(M_PI, EKF::constrainAngleInBounds(-3. * M_PI));
    EXPECT_DOUBLE_EQ(M_PI, EKF::constrainAngleInBounds(3. * M_PI));
}

TEST(EKF, AngleReboundingNegHalfM_PICases) {
    EXPECT_DOUBLE_EQ(-(M_PI / 2.),
                     EKF::constrainAngleInBounds((7. / 2.) * M_PI));
    EXPECT_DOUBLE_EQ(-(M_PI / 2.),
                     EKF::constrainAngleInBounds((-5. / 2.) * M_PI));
    EXPECT_DOUBLE_EQ(-(M_PI / 2.),
                     EKF::constrainAngleInBounds((3. / 2.) * M_PI));
    EXPECT_DOUBLE_EQ(-(M_PI / 2.),
                     EKF::constrainAngleInBounds((-1. / 2.) * M_PI));
}

TEST(EKF, AngleReboundingHalfM_PICases) {
    EXPECT_DOUBLE_EQ(M_PI / 2., EKF::constrainAngleInBounds((1. / 2.) * M_PI));
    EXPECT_DOUBLE_EQ(M_PI / 2., EKF::constrainAngleInBounds((-3. / 2.) * M_PI));
    EXPECT_DOUBLE_EQ(M_PI / 2., EKF::constrainAngleInBounds((5. / 2.) * M_PI));
    EXPECT_DOUBLE_EQ(M_PI / 2., EKF::constrainAngleInBounds((-7. / 2.) * M_PI));
}

TEST(EKF, AngleReboundingMiddleCases) {
    EXPECT_DOUBLE_EQ(-3. * M_PI / 4.,
                     EKF::constrainAngleInBounds((-3. / 4.) * M_PI));
    EXPECT_DOUBLE_EQ(M_PI / 3., EKF::constrainAngleInBounds((1. / 3.) * M_PI));
    EXPECT_DOUBLE_EQ(-M_PI / 3.,
                     EKF::constrainAngleInBounds((-1. / 3.) * M_PI));
    EXPECT_DOUBLE_EQ(2. * M_PI / 3.,
                     EKF::constrainAngleInBounds((2. / 3.) * M_PI));
    EXPECT_DOUBLE_EQ(-2. * M_PI / 3.,
                     EKF::constrainAngleInBounds((-2. / 3.) * M_PI));
    EXPECT_DOUBLE_EQ(-2. * M_PI / 3.,
                     EKF::constrainAngleInBounds((4. / 3.) * M_PI));
    EXPECT_DOUBLE_EQ(2. * M_PI / 3.,
                     EKF::constrainAngleInBounds((-4. / 3.) * M_PI));
    EXPECT_DOUBLE_EQ(1, EKF::constrainAngleInBounds(1));
    EXPECT_DOUBLE_EQ(-1, EKF::constrainAngleInBounds(-1));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}