#include "../src/ellipse.h"

//test driven first not implement code first
//用ASSERT_TRUE不好,蓋房子要搭鷹架 ,軟體的鷹架即是測試 call "scafolding"
TEST(Shapes, CreateEllipse){
  Ellipse(2.0, 1.0);
  ASSERT_NO_THROW(Ellipse(4.0, 3.0));
}


TEST(Shapes, EllipsePermiterTest){
  Ellipse ellipse(3.712, 2.556);
  ASSERT_NEAR(20.683,ellipse.perimeter(),0.001);
}

TEST(Shapes, EllipseAreaTest){
  Ellipse ellipse(3.712, 2.556);
  ASSERT_NEAR(29.807,ellipse.area(),0.001);
}
