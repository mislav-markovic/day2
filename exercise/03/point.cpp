#include "point.h"

point::point() : point(0, 0)
{
}

point::point(int x, int y) : x_{x}, y_{y}
{
}

bool point::operator==(const point& other) const
{
  return x_ == other.x_ && y_ == other.y_;
}

bool point::operator!=(const point& other) const
{
  return !(*this == other);
}

bool point::operator<(const point& other) const
{
  return x_ == other.x_ ? y_ < other.y_ : x_ < other.x_;
}

bool point::operator>=(const point& other) const
{
  return !(*this < other);
}

bool point::operator>(const point& other) const
{
  return !(*this < other || *this == other);
}

bool point::operator<=(const point& other) const
{
  return !(*this > other);
}
