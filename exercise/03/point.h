class point
{
private:
  int x_;
  int y_;
public:
  point();
  point(int x, int y);
  bool operator==(const point& other) const;
  bool operator!=(const point& other) const;
  bool operator<(const point& other) const;
  bool operator>=(const point& other) const;
  bool operator>(const point& other) const;
  bool operator<=(const point& other) const;
};
