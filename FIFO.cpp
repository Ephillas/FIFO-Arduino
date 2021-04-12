#include <iostream>
#include <string.h>
#define buffer_size 300

using namespace std;
struct fila{
    int first = 0;
    int last =0 ;
    int nItens =0;
    char *data[buffer_size];
    
} fifo;
void insert(struct fila *f, char *c, int size){
    char *ptr = (char*) malloc(size * sizeof(char));
    strcpy(ptr,c);
    f->data[f->last] = ptr;
    f->nItens++;
    f->last++;
}

char *get(struct fila *f){
    char *ptr = f->data[f->first];
    f->first++;
    f->nItens--;
    return ptr;
}
int main() {
    char a[] = "ABC";
    char b[] = "DEF";
    char c[] = "GHI";
    
    insert(&fifo,&a[0], sizeof(a));
    insert(&fifo,&b[0], sizeof(b));
    insert(&fifo,&c[0], sizeof(c));
    cout <<get(&fifo) << endl;
    cout <<"first: "<< fifo.first<< endl;
    cout <<"last: "<< fifo.last<< endl;
    cout << "Hello world!";
    

    return 0;
}
