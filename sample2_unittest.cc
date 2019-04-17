
#include "sample2.h"
#include "weeklater.h"
#include "gtest/gtest.h"



TEST(Date, DefaultConstructor) {
  Date test;
  //

  EXPECT_EQ(test.get_day(), 1);
  EXPECT_EQ(test.get_month(), 1);
  EXPECT_EQ(test.get_year(), 1900);
}

TEST(Date, nextDay) {
  Date test(17,4,2019);
  test.next_day();

  //

  EXPECT_EQ(test.get_day(), 18);
  EXPECT_EQ(test.get_month(), 4);
  EXPECT_EQ(test.get_year(), 2019);
}

TEST(Date, leapYear) {
  Date test(28,2,1992);
  test.next_day();

  //

  EXPECT_EQ(test.get_day(), 29);
  EXPECT_EQ(test.get_month(), 2);
  EXPECT_EQ(test.get_year(), 1992);
}

TEST(Date, leapYearShouldFail) {
  Date test(28,2,1993);
  test.next_day();

  //

  EXPECT_EQ(test.get_day(), 29);
  EXPECT_EQ(test.get_month(), 2);
  EXPECT_EQ(test.get_year(), 1993);
}

TEST(Date, monthChange) {
  Date test(28,2,1993);
  test.next_day();

  //

  EXPECT_EQ(test.get_day(), 1);
  EXPECT_EQ(test.get_month(), 3);
  EXPECT_EQ(test.get_year(), 1993);
}

TEST(Date, yearChange) {
  Date test(31,12,1996);
  test.next_day();

  //

  EXPECT_EQ(test.get_day(), 1);
  EXPECT_EQ(test.get_month(), 1);
  EXPECT_EQ(test.get_year(), 1997);
}

TEST(Date, weekLater) {
  Date test(1,7,1986);
  Date test2 = week_later(test);

  //

  EXPECT_EQ(test2.get_day(), 8);
  EXPECT_EQ(test2.get_month(), 7);
  EXPECT_EQ(test2.get_year(), 1986);
}


TEST(Date, daysBetween) {
  Date test(1,1,1994);
  int days = test.days_between(8,1,1994);

  //

  EXPECT_EQ(days, 7);
  EXPECT_EQ(test.get_day(), 1);
  EXPECT_EQ(test.get_month(), 1);
  EXPECT_EQ(test.get_year(), 1994);
}

TEST(Date, daysSinceNewyear) {
  Date test(26,1,1992);
  int days = test.days_since_newyear();

  //

  EXPECT_EQ(days, 25);
  EXPECT_EQ(test.get_day(), 26);
  EXPECT_EQ(test.get_month(), 1);
  EXPECT_EQ(test.get_year(), 1992);
}

  // namespace
