#include <FIFO.h>

void FIFO :: inserir(char *c, int size){
  if(f->primeiro == buffer_size){
    f->primeiro = 0;
  }
  char *ptr = (char*) malloc(size * sizeof(char));
  strcpy(ptr, c);
  f->dados[f->ultimo] = ptr;
  f-> nItens++;
  f->ultimo++;
}

char* FIFO :: retirar(){
  if(f->ultimo == buffer_size){
    f->ultimo = 0;
  }
  char *ptr = f->dados[f->primeiro];
  if(f->primeiro > 0){
    free(f->dados[f->primeiro -1]);
  }
  f-> primeiro++;
  f->nItens--;
}

bool FIFO:: cheia(){
  return f->nItens == buffer_size;
}

int FIFO:: tamanho(){
  return f->nItens;
}
