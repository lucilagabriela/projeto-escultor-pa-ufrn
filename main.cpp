#include "sculptor.h"
#include <iostream>

int main() {
  /*Sculptor write(15,30,12);
  write.setColor(1, 1, 0, 1);
  write.putEllipsoid(3, 3, 3, 3, 3, 3);
  write.putBox(0, 3, 19, 4, 8, 10);*/

  int nx = 21;
  int ny = 22;
  int nz = 21;

  Sculptor sculptor(nx, ny, nz);
  float alpha = 1.0;
  sculptor.setColor(1, 1, 0, alpha);
  sculptor.putBox(0, 20, 0, 21, 0, 20);
  sculptor.cutBox(0, 0, 0, 7, 0, 20);
  sculptor.cutBox(1, 1, 0, 5, 0, 20);
  sculptor.cutBox(2, 2, 0, 3, 0, 20);
  sculptor.cutBox(3, 3, 0, 2, 0, 20);
  sculptor.cutBox(4, 4, 0, 1, 0, 20);
  sculptor.cutBox(5, 5, 0, 1, 0, 20);
  sculptor.cutBox(6, 7, 0, 0, 0, 20);
  sculptor.cutBox(14, 15, 0, 0, 0, 20);
  sculptor.cutBox(16, 20, 0, 1, 0, 20);
  sculptor.cutBox(18, 20, 0, 2, 0, 20);
  sculptor.cutBox(19, 20, 0, 3, 0, 20);
  sculptor.cutBox(12, 20, 9, 9, 0, 20);
  sculptor.cutBox(13, 20, 8, 8, 0, 20);
  sculptor.cutBox(15, 20, 7, 7, 0, 20);
  sculptor.cutBox(17, 20, 6, 6, 0, 20);
  sculptor.cutBox(19, 20, 5, 5, 0, 20);
  sculptor.cutBox(14, 20, 10, 10, 0, 20);
  sculptor.cutBox(16, 20, 11, 11, 0, 20);
  sculptor.cutBox(18, 20, 12, 12, 0, 20);
  sculptor.cutBox(20, 20, 13, 13, 0, 20);
  sculptor.cutBox(20, 20, 4, 4, 0, 20);
  sculptor.cutBox(0, 0, 14, 21, 0, 20);
  sculptor.cutBox(1, 1, 16, 21, 0, 20);
  sculptor.cutBox(2, 2, 18, 21, 0, 20);
  sculptor.cutBox(3, 3, 19, 21, 0, 20);
  sculptor.cutBox(4, 5, 20, 21, 0, 20);
  sculptor.cutBox(6, 7, 21, 21, 0, 20);
  sculptor.cutBox(14, 15, 21, 21, 0, 20);
  sculptor.cutBox(16, 17, 20, 21, 0, 20);
  sculptor.cutBox(18, 18, 19, 21, 0, 20);
  sculptor.cutBox(19, 19, 18, 21, 0, 20);
  sculptor.cutBox(20, 20, 16, 21, 0, 20);

  sculptor.setColor(0, 0, 0, alpha);
  sculptor.putBox(12, 13, 14, 15, 20, 20);

  sculptor.writeOFF("write.off");

  // std::cout << "desenho concluido" << std::endl;

  return 0;
}
