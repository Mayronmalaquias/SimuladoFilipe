#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

typedef struct fila{
    int qtd;
    registro *inicio;
    registro *fim;
}fila;

registro* criaRegistro(){
    registro *p;
    p = (registro *)malloc(sizeof(registro));
    p->valor = 0;
    p->prox = NULL;
    return p;
}

fila* criaFila(){
    fila *p;
    p = (fila *)malloc(sizeof(fila));
    p->qtd = 0;
    p->inicio = NULL;
    p->fim = NULL;
    return p;
}

void push(int novo, fila *a){
    if (a == NULL){
        printf("fila não existe");
        return;
    }
    registro *aux;
    aux = criaRegistro();
    aux->valor = novo;
    if( a->inicio == NULL && a->fim == NULL){
        a->fim = aux;
        a->inicio = aux;
        return;
    } else {
        a->fim->prox = aux;
        a->fim = aux;
    }
}

void pop(fila *a){
    if(a ==  NULL){
        printf("fila não existe");
        return;
    }
    registro *aux;
    if(a->inicio == NULL && a->fim == NULL){
        printf("fila vazia");
        return;
    } else {
        aux = a->inicio;
        a->inicio = aux->prox;
        free(aux);
        if(a->inicio == a->fim){
            a->fim = NULL;
            a->inicio = NULL;
        }
    }
}

void stackpop(fila *a){
    if(a == NULL){
        printf("Fila não existe");
        return;
    }
    registro *aux;
    if(a->inicio == NULL && a->fim == NULL){
        printf("fila vazia");
    } else {
        aux = a->inicio;
        while(aux != NULL){
            printf("%d", aux->valor);
            aux = aux->prox;
        }
    }

}

void removerTudo(fila *a){
    if(a  == NULL){
        printf("Fila não existe");
    }
    registro *aux;
    aux = a->inicio;
    while(a->inicio != NULL & a->fim != NULL){
        if(a->fim == a->inicio){
            a->fim = NULL;
            a->inicio = NULL;
        } else {
            a->inicio = aux->prox;
            aux = aux->prox;
        }
    }
}

void removerTuudo(fila *a){
    while(a->inicio != NULL && a->fim != NULL){
        pop(a);
    }
}

void invererFila(fila *a){
    registro *aux, *ant, *pro;
    aux = a->inicio;
    pro = aux->prox;
    while(aux != NULL){
        pro = aux->prox;
        aux->prox = ant;
        ant = aux;
        aux = pro;
    }
    a->inicio = ant;

    aux = a->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    a->fim = aux;
}

int main(){
    fila *a;
    a = criaFila();
    push(2, a);
    push(5, a);
    push(9, a);
    push(6, a);
    push(4, a);
    push(3, a);
    stackpop(a);
    invererFila(a);
    stackpop;
    return 0;
}