#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "find_area_visitor.h"
class Shape {
public:
  Shape(){};
  virtual void accept(FindAreaVisitor * fav){}
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual std::string info() const = 0;
  virtual std::string type() const = 0;
  virtual Shape * getChild(int index) const;
  virtual int numberOfChild() const;
  virtual ~Shape() = default;

private:
  std::string _id,_color;

};
#endif
