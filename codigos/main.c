#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "q2.h"

int main(){
    setlocale(LC_ALL, "portuguese");
    int result = 1;
    int c = 1;
    paciente novo;
    printf("criar lista de pacientes?  (1/0)");
    scanf("%d", &c);
    if(1 == 1){
        heap *hospital = heap_cria();
        while(result > 0 && result < 4){
            printf("\n============== ATENDIMENTO AO PACIENTE ===============");
            printf("\nO que deseja fazer? \n1 - Adicionar paciente\n2 - Atender paciente\n3 - Finalizar processo\n");
            scanf("%d", &result);
            switch (result){
            case 1:
                system("cls");
                fflush(stdin);
                printf("\n Qual o nome do paciente? ");
                gets(novo.nome);
                do{
                    printf("\nQual a urgencia do paciente? \n1 - vermelho\n2 - laranja\n3 - amarelo\n4 - verde\n5 - azul\n");
                    scanf(" %d", &novo.urgencia[0]);
                    if(novo.urgencia[0] < 1 || novo.urgencia[0] > 5) printf("\nO valor nao se enquadra. Digite novamente.");
                } while(novo.urgencia[0] < 1 || novo.urgencia[0] > 5);
                printf("\nQue horas o paciente entrou? ");
                scanf(" %d", &novo.urgencia[1]);
                printf("\ncom quantos minutos? ");
                scanf(" %d", &novo.urgencia[2]);
                printf("\nCom quantos segundos? ");
                scanf(" %d", &novo.urgencia[3]);
                inserir(hospital, novo);
                system("cls");
                printf("\nPaciente adicionado com sucesso!");
                break;
            case 2:
                system("cls");
                heap_remove(hospital);
                printf("\nO paciente foi atendido");
                break;
            default:
                printf("\nprograma encerrado.");
                return 0;
                break;
            }
            print_heap(hospital);
         }   
    }
}