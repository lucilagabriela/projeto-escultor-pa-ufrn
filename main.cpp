#include "sculptor.h"
#include <iostream>

int main() {
  /*Sculptor write(15,30,12);
  write.setColor(1, 1, 0, 1);
  write.putEllipsoid(3, 3, 3, 3, 3, 3);
  write.putBox(0, 3, 19, 4, 8, 10);*/

  int nx = 20;
  int ny = 21;
  int nz = 20;

  Sculptor sculptor(nx, ny, nz);
  float alpha = 1.0;
  sculptor.setColor(1, 1, 0, alpha);
  sculptor.putBox(0, nx, 0, ny, 0, nz);

  sculptor.writeOFF("write.off");

  // std::cout << "desenho concluido" << std::endl;

  return 0;
}
