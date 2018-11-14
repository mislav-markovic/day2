#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "point.h"
TEST_CLASS(test_1_operators)
{
public:
  TEST_METHOD(point_default_constructor)
  {
    Assert::IsTrue(point(0, 0) == point());
  }

  TEST_METHOD(points_equal)
  {
    Assert::IsTrue(point(1, 2) == point(1, 2));
    Assert::IsTrue(point(-12, -34) == point(-12, -34));
  }

  TEST_METHOD(points_not_equal)
  {
    Assert::IsTrue(point(1, 2) != point(2, 1));
    Assert::IsTrue(point(-1, -2) != point(1, 2));
  }

  TEST_METHOD(points_sorted_by_first_coordinate_then_second)
  {
    Assert::IsTrue(point(1, 2) < point(1, 3));
    Assert::IsTrue(point(1, 2) < point(2, 2));
    Assert::IsFalse(point(1, 2) < point(1, 2));
  }

  TEST_METHOD(points_less_or_equal)
  {
    Assert::IsTrue(point(3, 4) <= point(3, 4));
    Assert::IsTrue(point(3, 4) <= point(4, 4));
    Assert::IsTrue(point(2, 5) <= point(3, 4));
    Assert::IsTrue(point(3, 4) <= point(3, 5));
  }

  TEST_METHOD(points_greater_or_equal)
  {
    Assert::IsTrue(point(3, 4) >= point(3, 4));
    Assert::IsTrue(point(3, 4) >= point(2, 4));
    Assert::IsTrue(point(4, 3) >= point(3, 4));
    Assert::IsTrue(point(3, 4) >= point(3, 3));

  }

  TEST_METHOD(points_greater_than)
  {
    Assert::IsFalse(point(3, 4) > point(3, 4));
    Assert::IsTrue(point(3, 4) > point(2, 4));
    Assert::IsTrue(point(4, 3) > point(3, 4));
    Assert::IsTrue(point(3, 6) > point(3, 5));
  }
};
