#include "array.h"
#include <stdexcept>
#include <algorithm>

array::array() : p_{nullptr}, n_{0}
{
}

array::array(int size, double value) : p_{new double[size]}, n_{size}
{
  std::fill_n(p_, size, value);
}

array::array(const array& other) : array(other.n_, other.at(0))
{
}

array::array(array&& other) noexcept : p_{other.p_}, n_{other.n_}
{
  other.p_ = nullptr;
  other.n_ = 0;
}

array::~array()
{
  delete[] p_;
  p_ = nullptr;
}

int array::size() const
{
  return n_;
}

double array::at(int index) const
{
  if (index < 0 || index >= n_) throw std::out_of_range("Index is out of range");
  return p_[index];
}

array& array::operator=(const array& other)
{
  if(this != &other)
  {
    delete[] p_;    
    n_ = other.n_;
    p_ = new double[n_];

    std::fill_n(p_, n_, other.at(0));
  };

  return *this;
}
