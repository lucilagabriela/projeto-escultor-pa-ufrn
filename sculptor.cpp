// 1. contrutuor
// 2. destrutor
// 3. set color()
// 4. put voxel()
// 5. write OFF()

// incluir bibliotecas
#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;


Sculptor::Sculptor(int _nx, int _ny, int _nz) { // construtor
  // Incializacao das matrizes de voxel
  this->nx = _nx;
  this->ny = _ny;
  this->nz = _nz;
  this->r = 0;
  this->g = 0;
  this->b = 0;
  this->a = 0;

  // Alocacao dinamica
  v = new Voxel **[nx]; // Alocar matriz 3D
  for (int i = 0; i < nx; i++) {
    v[i] = new Voxel *[ny];
    for (int j = 0; j < ny; j++) {
      v[i][j] = new Voxel[nz];
    }
  }
  
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        v[i][j][k].show = false;
        v[i][j][k].r = 0;
        v[i][j][k].g = 0;
        v[i][j][k].b = 0;
      }
    }
  }
}

Sculptor::~Sculptor() { // destrutor - liberar memoria
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      delete[] v[i][j];
    }
  }
  for (int i = 0; i < nx; i++) {
    delete[] v[i];
  }
  delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a) { // metodo setColor
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) { // metodo putVoxel
  this->v[x][y][z].show = true;
  this->v[x][y][z].r = this->r;
  this->v[x][y][z].g = this->g;
  this->v[x][y][z].b = this->b;
  this->v[x][y][z].a = this->a;
}

void Sculptor::cutVoxel(int x, int y, int z) {
  v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        putVoxel(i, j, k);
      }
    }
  }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        cutVoxel(i, j, k);
      }
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (((pow((i - xcenter), 2) / (pow(radius, 2))) +
             (pow((j - ycenter), 2) / (pow(radius, 2))) +
             (pow((k - zcenter), 2) / (pow(radius, 2)))) <= 1) {
          putVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (((pow((i - xcenter), 2) / (pow(radius, 2))) +
             (pow((j - ycenter), 2) / (pow(radius, 2))) +
             (pow((k - zcenter), 2) / (pow(radius, 2)))) <= 1) {
          cutVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (((pow((i - xcenter), 2) / (pow(rx, 2))) +
             (pow((j - ycenter), 2) / (pow(ry, 2))) +
             (pow((k - zcenter), 2) / (pow(rz, 2)))) <= 1) {
          putVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (((pow((i - xcenter), 2) / (pow(rx, 2))) +
             (pow((j - ycenter), 2) / (pow(ry, 2))) +
             (pow((k - zcenter), 2) / (pow(rz, 2)))) <= 1) {
          cutVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::writeOFF(const char *filename) {
  // abrir o fluxo de saido p o arquivo

  // varrer a matriz v
  int nvertices, nfaces;
  int vOn = 0;
  
  for (int i = 0; i < nx; i++) {  // laço triplamente alinhado
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show == true) {
          vOn++;
        }
      }
    }
  }
  std::ofstream arquivo_off;
  arquivo_off.open(filename);
  
  if (!arquivo_off.is_open()) {
    cout << "Erro ao abrir o arquivo " << endl;
  }
  arquivo_off << "OFF" << std::endl;
  arquivo_off << (vOn * 8) << " "
              << (vOn * 6) << " " << 0 << " "
              << std::endl;

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show == true) {
          arquivo_off << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
                      << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl
                      << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
                      << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
                      << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl
                      << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl
                      << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl
                      << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
        }
      }
    }
  }

  int contadorFace = 0;
  
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show == true) {
          arquivo_off << "4"
                      << " " << contadorFace + 0 << " "
                      << contadorFace + 3 << " " << contadorFace + 2
                      << " " << contadorFace + 1 << " " << std::fixed
                      << std::setprecision(1) << v[i][j][k].r << " "
                      << v[i][j][k].g << " " << v[i][j][k].b << " "
                      << v[i][j][k].a << "\n"
                      << "4"
                      << " " << contadorFace + 4 << " "
                      << contadorFace + 5 << " " << contadorFace + 6
                      << " " << contadorFace + 7 << " " << v[i][j][k].r
                      << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                      << v[i][j][k].a << "\n"
                      << "4"
                      << " " << contadorFace + 0 << " "
                      << contadorFace + 1 << " " << contadorFace + 5
                      << " " << contadorFace + 4 << " " << v[i][j][k].r
                      << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                      << v[i][j][k].a << "\n"
                      << "4"
                      << " " << contadorFace + 0 << " "
                      << contadorFace + 4 << " " << contadorFace + 7
                      << " " << contadorFace + 3 << " " << v[i][j][k].r
                      << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                      << v[i][j][k].a << "\n"
                      << "4"
                      << " " << contadorFace + 7 << " "
                      << contadorFace + 6 << " " << contadorFace + 2
                      << " " << contadorFace + 3 << " " << v[i][j][k].r
                      << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                      << v[i][j][k].a << "\n"
                      << "4"
                      << " " << contadorFace + 1 << " "
                      << contadorFace + 2 << " " << contadorFace + 6
                      << " " << contadorFace + 5 << " " << v[i][j][k].r
                      << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                      << v[i][j][k].a << std::endl; 
          contadorFace = contadorFace + 8;
        }
      }
    }
  }

  arquivo_off.close();
}
