#include <iostream>
#include <stdlib.h>
#include <string.h>
#define buffer_size 300

using namespace std;

class fila{
    private:
    struct fifo{
      int nItens = 0;
      int primeiro =0;
      int ultimo = 0;
      char *dados[buffer_size];
    } a;
    struct fifo *f = &a;

    public:
    void insere(char *, int);
    char *retira();
    bool cheia();
};
void fila::insere(char *c, int size){
    char* ptr = (char*) malloc (size *sizeof(char));
    strcpy(ptr,c);
    f->dados[f->ultimo] = ptr;
    f->nItens++;
    f->ultimo++;
}
char* fila::retira(){
    char *ptr = f->dados[f->primeiro];
    if(f->primeiro > 0){
        free(f->dados[f->primeiro-1]);
        }
    f->primeiro++;
    f->nItens--;
    return ptr;
}

bool fila::cheia(){
    return f->nItens == buffer_size;
}

int main(){
    char a[] = "Oi eu sou o goku";
    char b[] = "SAVASDSADAS ";
    char c[] = "sdas";
    fila fila_fifo;
    fila_fifo.insere(&a[0], sizeof(a));
    fila_fifo.insere(&b[0], sizeof(b));
    fila_fifo.insere(&c[0], sizeof(c));
    cout << fila_fifo.retira()<<endl;
    cout << fila_fifo.retira()<<endl;
    cout << fila_fifo.retira()<<endl;
    return 0;
}
