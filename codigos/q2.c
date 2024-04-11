#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

heap* heap_cria(){
    heap* novo = (heap *)malloc(sizeof(heap));
    novo->max = MAX;
    novo->pos = 0;
    novo->pacientes = (paciente *)malloc(MAX*sizeof(paciente));
    return novo;
}

static void trocar(paciente* l, int a, int b){
    paciente c = l[a];
    l[a] = l[b];
    l[b] = c;
}

static void subir(heap* hospital, int pos){
    int pai;
    int i = 0;
    while (pos > 0){
        pai = (pos-1)/2;
        while(hospital->pacientes[pai].urgencia[i] == hospital->pacientes[pos].urgencia[i]) i++;
        if (hospital->pacientes[pai].urgencia[i] > hospital->pacientes[pos].urgencia[i]){
            trocar(hospital->pacientes, pos, pai);
        }
        else break;
        pos = pai;
    }
}

int inserir(heap* hospital, paciente novo){
    if (hospital->pos < hospital->max){
        hospital->pacientes[hospital->pos] = novo;
        subir(hospital,hospital->pos);
        hospital->pos++;
        return 1;
    }
    else{
        printf("Heap CHEIO!\n");
        return 0;
    }
}

static int descer(paciente* pessoas, int atual, int tam){
    int pai = atual, filho_esq = 2*pai+1, filho_dir = 2*pai+2, filho, i = 0;
    if(filho_dir >= tam && filho_esq >= tam) return 0;
    if(filho_dir >= tam) filho_dir = filho_esq;
    if(filho_esq <= filho_dir) filho = filho_esq;
    else filho = filho_dir;
    while(pessoas[pai].urgencia[i] == pessoas[filho].urgencia[i]) i++;
    if(pessoas[pai].urgencia[i] > pessoas[filho].urgencia[i]){
        trocar(pessoas, pai, filho);
        descer(pessoas, filho, tam);
    }
    return 0;
}

paciente heap_remove(heap* hospital){
    paciente retorno;
    if (hospital->pos > 0) {
        paciente topo = hospital->pacientes[0];
        hospital->pacientes[0] = hospital->pacientes[hospital->pos-1];
        hospital->pos--;
        descer(hospital->pacientes, 0, hospital->pos);
        return topo;
    }
    else {
        printf("Heap VAZIO!");
        return retorno;
    }
}

void print_heap(heap* hospital){
    int i;
    printf("\nnome\turgencia");
    for(i = 0; i < hospital->pos; i++){
        printf("\n%s\t%d", hospital->pacientes[i].nome, hospital->pacientes[i].urgencia[0]);
    }
    printf("\n");
}
