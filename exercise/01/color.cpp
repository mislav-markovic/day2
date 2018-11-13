#include "stdafx.h"
#include "color.h"

namespace
{
  double value_cutoff(double value)
  {
    return value > 0 ? std::min(value, 1.) : std::max(value, 0.);
  }

  long scale_color(double value)
  {
    return 255 * value;
  }
}

color::color() : color{0, 0, 0}
{
}

color::color(const double red, const double green, const double blue)
{
  set_red(red);
  set_green(green);
  set_blue(blue);
}

void color::set_red(double red)
{
  red_ = value_cutoff(red);
}

void color::set_green(double green)
{
  green_ = value_cutoff(green);
}

void color::set_blue(double blue)
{
  blue_ = value_cutoff(blue);
}

double color::get_red() const
{
  return red_;
}

double color::get_green() const
{
  return green_;
}

double color::get_blue() const
{
  return blue_;
}

unsigned long color::get_color_ref() const
{
  return scale_color(red_) + scale_color(green_) * 256 + scale_color(blue_) * 65536;
}

double color::get_luminance() const
{
  return 0.2126 * red_ + 0.7152 * green_ + 0.0722 * blue_;
}

bool operator==(const color& lhs, const color& rhs)
{
  return lhs.red_ == rhs.red_ && lhs.green_ == rhs.green_ && lhs.blue_ == rhs.blue_;
}
