#include "../src/shape.h"
#include "../src/ellipse.h"
#include "../src/complex_shape.h"
#include "../src/find_area_visitor.h"
#include <vector>
class findAreaVisitorTest : public ::testing::Test {
protected:
  void SetUp() override {
    e43 = new Ellipse(7.0,3.0);
    shapeVector.push_back(e43);
    mbox = new ComplexShapes(shapeVector);
  }

  void TearDown() override {
    delete e43;
    delete mbox;
  }

  Shape * e43;
  Shape * mbox;
  std::vector<Shape *> shapeVector ;
};


TEST_F(findAreaVisitorTest, createComplexShapeTest){
  FindAreaVisitor fm(3.0,70.0);
  e43->accept(&fm);
  Shape * s = fm.getResult();
  ASSERT_EQ(e43,s);
}
