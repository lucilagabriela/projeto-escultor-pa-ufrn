#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
  float r, g, b; // coloração
  float a;       // transparencia
  bool show;     // objeto incluido ou nao
};

/**
@brief A classe Sculptor implementa os métodos para a modelagem do desenho.
*/

class Sculptor {
private:
  Voxel ***v;                          // 3D matrix
  int nx, ny, nz;                      // dimencoes
  float r, g, b, a;                    // cor e transparencia
public:                                // metodos:
  Sculptor(int _nx, int _ny, int _nz); // construtor - alocacao dinamica
  ~Sculptor();                         // destrutor
  void setColor(float r, float g, float b, float a); // escolha da cor - ok
  void putVoxel(int x, int y, int z);                // criar quadrado - ok
  void cutVoxel(int x, int y, int z);                // deletar quadrado - ok
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1); // ok
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); // ok
  void putSphere(int xcenter, int ycenter, int zcenter,
                 int radius); // cria esfera
  void cutSphere(int xcenter, int ycenter, int zcenter,
                 int radius); // apaga esfera
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry,
                    int rz); // cria elipse
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry,
                    int rz);           // apaga elipse
  void writeOFF(const char *filename); // cria arquivo.off - ok
};

#endif

// Fazer ate a parte 4.1: Criação de um programa de testes