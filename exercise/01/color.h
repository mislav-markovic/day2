#pragma once

class color
{
private:
  double red_;
  double green_;
  double blue_;

public:
  color();
  color(double red, double green, double blue);

  double get_red() const;
  double get_green() const;
  double get_blue() const;

  void set_red(double red);
  void set_green(double green);
  void set_blue(double blue);

  unsigned long get_color_ref() const;
  double get_luminance() const;

  friend bool operator==(const color&, const color&);
};

bool operator==(const color& lhs, const color& rhs);