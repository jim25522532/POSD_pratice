#ifndef FIND_AREA_VISITOR
#define FIND_AREA_VISITOR

class Shape;
class ComplexShapes;
class Ellipse;


class FindAreaVisitor{
public:
  FindAreaVisitor(double min,double max):_min(min),_max(max){

  }
  void visitComplexShape(ComplexShapes *cm);
  void visitEllipse(Ellipse * el);
  Shape * getResult();
private:
  double _min,_max;
  Shape * _result;

};

#endif
