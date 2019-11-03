#ifndef POINT_H
#define POINT_H

#include <math.h>
/*
class Point {
  int x;
  int y;
public:
  Point():x(0),y(0){  }
  Point(int x, int y):x(x),y(y) { }
  Point(const Point& p):x(p.x),y(p.y) { }

  //snake
  bool operator ==(const Point& p) const{
    return this->getX() == p.getX() && this->getY() == p.getY();
  }

  Point operator +(const Point &p) const{
      return Point(this->getX() + p.getX(), this->getY() + p.getY());
  }

  bool operator < (const Point& p) const{
      //int first = sqrt(pow(this->getX(), 2) + pow(this->getY(), 2));
      //int second = sqrt(pow(p.getX(), 2) + pow(p.getY(), 2));
      return this->getX() < p.getX() || (this->getX() == p.getX() && this->getY() < p.getY());
  }

  Point operator =(const Point& p) {
        this->x = p.x;
        this->y = p.y;
        return *this;
  }

  int getX() const{
      return x;
  }

  int getY() const{
      return y;
  }
  void setPoint(const Point& p){
      this->x = p.x;
      this->y = p.y;
  }
};*/

struct Point{
    int x;
    int y;

    Point(){
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    bool operator ==(const Point& p) const{
      return this->x == p.x && this->y == p.y;
    }

    Point operator +(const Point &p) const{
        return {this->x + p.x, this->y + p.y};
    }

    bool operator < (const Point& p) const{
        return this->x < p.x || (this->x == p.x && this->y < p.y);
    }
};

#endif // POINT_H
