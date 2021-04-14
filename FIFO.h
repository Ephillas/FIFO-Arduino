
#ifndef _FIFO_h_
#include <Arduino.h>
#define _FIFO_h_
#define buffer_size 300
class FIFO{
  private:
    struct fila{
      int primeiro = 0;
      int ultimo = 0;
      int nItens = 0;
      char *dados[buffer_size];
    } a;
    struct fila *f = &a;

  public:
    void inserir(char *, int);
    char* retirar();
    bool cheia();
    int tamanho();
};
#endif
