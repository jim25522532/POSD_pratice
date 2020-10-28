#ifndef COMPLEX_SHAPE_H
#define COMPLEX_SHAPE_H

#include "shape.h"
#include <vector>
#include <iterator>
#include <sstream>
#include <string>
class ComplexShapes : public Shape {
public:

  ComplexShapes(std::vector<Shape*> shapes) {
    if(shapes.size()==0){
      throw std::string("This is not a compound shape!");
    }

    std::vector<Shape *> ::iterator begin = shapes.begin();
    std::vector<Shape *> ::iterator end = shapes.end();
    std::vector<Shape *>::iterator it;

    for(it = begin;it!=end;++it){
      _shapes.push_back(*it);
    }
  }

  void add(Shape * s){
    _shapes.push_back(s);
  }

  double area() const {
    double totalArea = 0.0;

    std::vector<Shape *> ::const_iterator begin = _shapes.begin();
    std::vector<Shape *> ::const_iterator end = _shapes.end();
    std::vector<Shape *>::const_iterator it;

    for(it = begin;it!=end;++it){
      totalArea += (*it)->area();
    }
    
    return totalArea;
  }

  double perimeter() const {
    double totalPermiter = 0.0;
    std::vector<Shape *> ::const_iterator begin = _shapes.begin();
    std::vector<Shape *> ::const_iterator end = _shapes.end();
    std::vector<Shape *>::const_iterator it;
    for(it = begin;it!=end;++it){
      totalPermiter += (*it)->perimeter();
    }

    return totalPermiter;
  }

  std::string info() const {
    std::stringstream ss;

    return ss.str();
  }

  std::string type() const {
    return std::string("ComplexShape");
  }

  Shape * getChild(int index) const {
    return _shapes[index];
  }

  int  numberOfChild() const {
    return _shapes.size();
  }

  void accept(FindAreaVisitor * ffv){
    ffv->visitComplexShape(this);
  }


private:
  std::vector<Shape *> _shapes;
};

#endif
