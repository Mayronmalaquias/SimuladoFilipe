#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct presente{
    int valor;
    struct presente *prox;
}presente;

typedef struct pilha{
    int qtd;
    presente *topo;
}pilha;

presente* criaPresente(){
    presente *p;
    p = (presente*)malloc(sizeof(presente));
    p->valor = 0;
    p->prox = NULL;
    return p;
}

pilha* criaPilha() {
    pilha *p;
    p = (pilha*)malloc(sizeof(pilha));
    p->qtd = 0;
    p->topo = NULL;
    return p;
}

void push(int novo, pilha *a){
    if(a == NULL){
        printf("pilha não existe");
    }
    presente *aux;
    aux = criaPresente();
    aux->valor = novo;
    if(a->topo == NULL){
        a->topo = aux;
        a->qtd++;
    } else{
        aux->prox = a->topo;
        a->topo = aux;
        a->qtd++;
    }
}

void pop(pilha *a){
    if(a == NULL){
        printf("pilha não existe");
    }
    presente *aux;
    if(a->topo == NULL){
        printf("não ha elementos para remover");
        return;
    }
    aux = a->topo;
    a->topo = aux->prox;
    a->qtd--;
}

void MIN(pilha *a){
    if(a == NULL){
        printf("PILHA NAO EXISTE");
    }
    int mini;
    presente *aux;
    aux  = a->topo;
    if(a->topo == NULL){
        printf("pilha vazia");
        return;
    }
    while(aux != NULL){
        if(a->topo == aux){
            mini = aux->valor;
        }
        if(mini > aux->valor){
            mini = aux->valor;
        }
        aux  = aux->prox;
    }
    printf("%d\n", mini);
}

int main(){
    pilha *a;
    a = criaPilha();
    char opcao[100];
    int valor;
    while (scanf("%s", opcao) != EOF) {
        if (strcmp(opcao, "PUSH") == 0) {
            scanf("%d", &valor);
            push(valor, a);
        } else if (strcmp(opcao, "POP") == 0) {
            pop(a);
        } else if (strcmp(opcao, "MIN") == 0) {
            MIN(a);
        }
    }
    return 0;
}



