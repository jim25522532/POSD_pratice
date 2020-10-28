#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <math.h>
#include <string>
#include <iomanip>
#include <sstream>
#include "shape.h"
#include "find_area_visitor.h"

class Ellipse: public Shape {
public:
    Ellipse(double semiMajorAxes, double semiMinorAxes):_semiMajorAxes(semiMajorAxes),_semiMinorAxes(semiMinorAxes){

        if(semiMajorAxes<=0.0 || semiMinorAxes<=0.0 || semiMajorAxes < semiMinorAxes){
          throw std::string("This is not an ellipse!");
        }

    }
    double area() const {
        // return the area of the Ellipse.
        return M_PI * this->_semiMajorAxes * this->_semiMinorAxes;
    }

    double perimeter() const {
        // return the perimeter of the Ellipse.
        //std::cout << 2 * M_PI * sqrt(((_semiMajorAxes * _semiMajorAxes) + (_semiMinorAxes * _semiMinorAxes))/( 2.0)) << std::endl;
        return 2.0 * M_PI * this->_semiMinorAxes + 4.0 * ( this->_semiMajorAxes  - this->_semiMinorAxes );
    }

    std::string info() const {
      std::stringstream ss;
      ss << "Ellipse (" << std::setprecision(3) << std::fixed << this->_semiMajorAxes << ", " << std::setprecision(3) << std::fixed << this->_semiMinorAxes << ")";

      return ss.str();
    }

    std::string type() const {
      return std::string("Ellipse");
    }

    Shape * getChild(int index) const {
      throw std::string("no member function");
    }

    int  getChild() const {
      throw std::string("no member function");
    }

    void accept(FindAreaVisitor * ffv){
      ffv->visitEllipse(this);
    }
private:
  double _semiMajorAxes , _semiMinorAxes;

};
#endif
