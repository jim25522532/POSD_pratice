#include "../src/shape.h"
#include "../src/ellipse.h"
#include "../src/complex_shape.h"
#include <vector>
class ComplexShapeTest : public ::testing::Test {
protected:
  void SetUp() override {
    e43 = new Ellipse(4.0,3.0);
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


TEST_F(ComplexShapeTest, createComplexShapeTest){
  ASSERT_EQ(e43, mbox->getChild(0));
}

TEST_F(ComplexShapeTest, ComplexShapeNumberOfSizeTest){
  ASSERT_EQ(1, mbox->numberOfChild());
}
