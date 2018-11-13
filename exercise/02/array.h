#pragma once

// do not use standard container as member or base class
class array
{
private:
  double* p_;
  int n_;

public:
  array();
  array(int size, double value);
  array(const array& other);
  array(array&& other) noexcept;
  ~array();

  int size() const;
  double at(int index) const;

  array& operator=(const array& other);
  array& operator=(array&& other) noexcept;
};
