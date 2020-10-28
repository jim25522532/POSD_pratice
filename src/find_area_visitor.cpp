#include "complex_shape.h"
#include "shape.h"
#include "ellipse.h"
#include <iostream>
void FindAreaVisitor::visitComplexShape(ComplexShapes *ms){

  if(ms->area()<=_max && ms->area()>=_min){
    _result = ms;
  }

}

void FindAreaVisitor::visitEllipse(Ellipse *ms){
  
  if(ms->area()<=_max && ms->area()>=_min){
    _result = ms;
  }

}
Shape * FindAreaVisitor::getResult(){
  return _result;
}
