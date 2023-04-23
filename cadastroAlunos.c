#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h> //função sleep
#include "cadastroAlunos.h"
#define TAMANHO_TURMA 15 //numero de alunos 
#define TOTAL_AULAS 45
#define MAX_FALTAS_APROVACAO 11
#define MAX_FALTAS_REPROVACAO 18
#define TOTAL_NOTAS 3
#define MEDIA_APROVACAO 6


void mensagembemvindo(){
    printf("╔═════════════════════════════════════╗\n");
    printf("║                                     ║\n");
    printf("║      BEM-VINDO AO SISTEMA DE        ║\n");
    printf("║                                     ║\n");
    printf("║         CADASTRO DE ALUNOS          ║\n");
    printf("║                                     ║\n");
    printf("╚═════════════════════════════════════╝\n");

    printf("--------------------------------------\n");
    printf("-- Carregando menu de funcionalidades--\n");
    printf("--------------------------------------\n");

    sleep(1);
}

void selecionamenu(int *ptr_opcao, int * qtdAlunos){
    printf("\n╔═══════════════════════════════════════╗\n");
    printf("║                                       ║\n");
    printf("║    MENU - SISTEMA DE CADASTRO DE      ║\n");
    printf("║                 ALUNOS                ║\n");
    printf("║                                       ║\n");
    printf("╠═══════════════════════════════════════╣\n");
    printf("║ Digite:                               ║\n");
    printf("║ 1 - Cadastrar novo aluno.             ║\n");
    printf("║ 2 - Alterar dados de alunos.          ║\n");
    printf("║ 3 - Buscar aluno.                     ║\n");
    printf("║ 4 - Listar total de alunos aprovados. ║\n");
    printf("║ 5 - Listar total de alunos reprovados.║\n");
    printf("║     por média.                        ║\n");
    printf("║ 6 - Listar total de alunos reprovados ║\n");
    printf("║     por falta.                        ║\n");
    printf("║ 7 - Listar turma.                     ║\n");
    printf("║ 0 - Sair do programa.                 ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    
    
    printf("\nCapacidade da turma = %d / %d\n",*qtdAlunos, TAMANHO_TURMA);
    
    int opcaoInvalida = 1;
    do{
        opcaoInvalida = 0;
        scanf("%d", ptr_opcao);

        if(*ptr_opcao == 0){
            printf("\nEncerrando. . .\n");
            sleep(1);
            break;
        }
        if(*qtdAlunos >= TAMANHO_TURMA && *ptr_opcao == 1){
            printf("\nTurma preenchida, não é possível cadastrar mais alunos.\n");
            opcaoInvalida = 1;
        }
        if(*qtdAlunos == 0 && *ptr_opcao != 1 ){
            printf("\nCadastre um novo aluno para utilizar outras funcionalidades.\n");
            opcaoInvalida = 1;
        }

    }while(opcaoInvalida);
    
    
}

// Direcionar para cada função do menu
void funcionalidades(int * ptr_opcao, ALUNO * alunos, int * qtdAlunos){
    switch (*ptr_opcao)
    {
    case 1:
        // Verificar se há vagas
        if(*qtdAlunos < TAMANHO_TURMA){
            cadastraraluno(alunos, qtdAlunos);
            (*qtdAlunos)++;
        }
        else{
            printf("Quantidade máxima de alunos já foi preenchida.\n");
        }
        break;
    case 2: //alterar dados de alunos já cadastrados
        alteraAluno(alunos, qtdAlunos);
        break;
    case 3:
        buscarAluno(alunos, qtdAlunos);
        break;
    case 4:
        buscarAprovados(alunos, qtdAlunos);
        break;
    case 5:
        buscarReprovadosMedia(alunos, qtdAlunos);
        break;
    case 6:
        buscarReprovadosFalta(alunos, qtdAlunos);
        break;
    case 7:
        buscarTodosAlunos(alunos, qtdAlunos);
        break;
    }
}

void buscarTodosAlunos(ALUNO* alunos, int * posicao){
    printf("╔═══════════════════════════════════════╗\n");
    printf("║ 7- Buscar todos os alunos cadastrados ║\n");
    printf("╚═══════════════════════════════════════╝\n");

    for(int i = 0 ; i < *posicao; i++){
        exibirDadosAluno(&alunos[i]);
    }

    retornarMenu();
}

void buscarReprovadosFalta(ALUNO* alunos, int * posicao){
    printf("╔═══════════════════════════════════════╗\n");
    printf("║ 6- Alunos reprovados por falta        ║\n");
    printf("╚═══════════════════════════════════════╝\n");

    int contadorReprovados = 0;
    for(int i = 0 ; i < *posicao; i++){
        if(alunos[i].faltas > MAX_FALTAS_REPROVACAO){
            exibirDadosAluno(&alunos[i]);
            contadorReprovados++;
        }
        printf("\n");
    }
    
    if(contadorReprovados == 0){
        printf("Não há alunos reprovados por falta nessa turma.\n");
    }   

    retornarMenu();
}

void buscarReprovadosMedia(ALUNO* alunos, int * posicao){
    printf("╔═══════════════════════════════════════╗\n");
    printf("║ 5- Alunos reprovados por média        ║\n");
    printf("╚═══════════════════════════════════════╝\n");

    int contadorReprovados = 0;
    for(int i = 0 ; i < *posicao; i++){
        if(alunos[i].media < MEDIA_APROVACAO && alunos[i].faltas <= MAX_FALTAS_APROVACAO){
            exibirDadosAluno(&alunos[i]);
            contadorReprovados++;
        }
        printf("\n");
    }

    if(contadorReprovados == 0){
        printf("Não há alunos reprovados por média nessa turma.\n");
    }

    retornarMenu();
}

void buscarAprovados(ALUNO* alunos, int * posicao){
    printf("╔═══════════════════════════════════════╗\n");
    printf("║ 4 - Alunos aprovados                  ║\n");
    printf("╚═══════════════════════════════════════╝\n");

    int contadorAprovados = 0;
    for(int i = 0 ; i < *posicao; i++){
        if(alunos[i].media >= MEDIA_APROVACAO && alunos[i].faltas <= MAX_FALTAS_APROVACAO){
            exibirDadosAluno(&alunos[i]);
            contadorAprovados++;
        }
        printf("\n");
    }

    if(contadorAprovados == 0){
        printf("Não há alunos aprovados nessa turma.\n");
    }

    retornarMenu();
}

void retornarMenu(){
    int opcao;
    printf("╔═══════════════════════════════════════╗\n");
    printf("║Digite:                                ║\n");
    printf("║ 1 - Retornar para o menu.             ║\n");
    printf("║ 0 - Encerrar programa.                ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    scanf("%d",&opcao);

    if(opcao == 0){
        printf("\nEncerrando. . .\n");
        sleep(2);
        exit(0);
    }
}

int matriculaExiste(ALUNO* alunos, int* posicao){
    int matricula;
    printf("Digite a matrícula do aluno que deseja realizar a operação: ");

    int existeMatricula = 0;
    do{
        existeMatricula = 1;
        scanf("%d", &matricula);

        existeMatricula = verificaMatricula(alunos,posicao,matricula);
        if(existeMatricula == 0){
            printf("Essa matrícula não existe. Digite uma matrícula válida.\n");
        }

    }while(existeMatricula == 0); 
    return matricula; 
}

int verificaMatricula(ALUNO*alunos, int *posicao, int matricula){
    for(int i = 0 ; i < *posicao;i++){
        if(alunos[i].matricula == matricula){
            return 1; //se existe
        }
    }
    return 0; // se não existe
}

int verificaPosicao(ALUNO* alunos, int * posicao, int matricula){
    int contador = 0;

    for(int i = 0; i < *posicao; i++){
        if(alunos[i].matricula == matricula){
            contador = i;
            break;
        }
    }
    return contador;
}

void exibirDadosAluno(ALUNO* alunos){
    printf("\n Matrícula = %d \n", alunos->matricula);

    for(int i=0; i < TOTAL_NOTAS; i++){
        printf("Notas %d = %.1f \n", i+1, alunos->notas[i]);
    }

    printf("Média = %.1f \n", alunos->media);
    printf("Faltas = %d \n", alunos->faltas);

    printf("\n");
}

//case3
void buscarAluno(ALUNO* alunos, int* posicao){
    printf("╔═══════════════════════════════════════╗\n");
    printf("║ 3 - Buscar dados de alunos.           ║\n");
    printf("╚═══════════════════════════════════════╝\n");

    int matricula = matriculaExiste(alunos,posicao);

    int posicaoDesejada = verificaPosicao(alunos, posicao, matricula);

    exibirDadosAluno(&alunos[posicaoDesejada]); //passou o ponteiro alunos
    
    retornarMenu();
}

//case 2
void alteraAluno(ALUNO* alunos, int* posicao){
    printf("╔═══════════════════════════════════════╗\n");
    printf("║ 2 - Alterar dados de alunos.          ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    
    int matricula = matriculaExiste(alunos,posicao);

    int posicaoDesejada = verificaPosicao(alunos, posicao, matricula);

    coletaNotas(alunos, &posicaoDesejada);

    coletaFaltas(alunos, &posicaoDesejada);

    printf("**************************************\n");
    printf("* Aluno alterado com sucesso!        *\n");    
    printf("**************************************\n");
    sleep(1);
}


//coletar faltas na função cadastra aluno
void coletaFaltas(ALUNO* alunos, int * posicao){
    int faltas;

    do{
        printf("\nDigite o número de faltas: ");
        scanf("%d", &faltas);

        if(faltas < 0 || faltas > 45){
            printf("Número de faltas inválido. O número deve estar entre 0 e 45.\n");
        }

    }while( faltas < 0 ||  faltas > TOTAL_AULAS);
    alunos[*posicao].faltas = faltas;
}


//coletar notas na função cadastra aluno
void coletaNotas(ALUNO* alunos, int * posicao){
    float soma = 0;
    for(int i = 0; i < TOTAL_NOTAS; i++)
    {
        printf("\nDigite a %d nota: ", i+1);

        int notaInvalida = 1;
        do{
           notaInvalida = 0; 
           scanf(" %f",&alunos[*posicao].notas[i]);

           if(alunos[*posicao].notas[i] < 0 || alunos[*posicao].notas[i] > 10 ){
            printf("Nota inválida, digite um número entre 0 e 10.\n");
            notaInvalida = 1;
           }
        }while(notaInvalida);
        soma += alunos[*posicao].notas[i];
    }
    alunos[*posicao].media = soma / TOTAL_NOTAS;
}

//coletar matrículas na função de cadastro do aluno
void coletaMatricula(ALUNO * alunos, int * posicao){
    int matricula;

    printf("\nDigite o número de matrícula: "); //verificar se a matrícula já existe   &alunos[*posicao].matricula

    int existeMatricula = 1; //inicializar o do uma vez pelo menos

    do{
        existeMatricula = 0;  
        scanf("%d", &matricula);

        existeMatricula = verificaMatricula(alunos, posicao, matricula);
            if(existeMatricula == 1){
                printf("Essa matrícula já existe.\n");
                printf("Digite novamente a matrícula do aluno.\n");
            }
 
    } while(existeMatricula);

    alunos[*posicao].matricula = matricula; //adicionar matrícula na struct do aluno
}


// CADASTRA ALUNO
void cadastraraluno(ALUNO * alunos, int * posicao){ //posição corresponde a quantidade de alunos

    printf("╔═══════════════════════════════════════╗\n");
    printf("║ 1 - Cadastrar novo aluno.             ║\n");
    printf("╚═══════════════════════════════════════╝\n");

    coletaMatricula(alunos, posicao);

    coletaNotas(alunos, posicao);
    
    coletaFaltas(alunos, posicao);

    printf("**************************************\n");
    printf("* Novo aluno cadastrado com sucesso! *\n");    
    printf("**************************************\n");
    sleep(1);
    printf("--------------------------------------\n");
    printf("-- Carregando menu de funcionalidades--\n");
    printf("--------------------------------------\n");

    sleep(1);
}


int main(){
    ALUNO alunos[TAMANHO_TURMA];
    int opcao;
    int qtdAlunos = 0; //definir quantos alunos já foram alocados

    mensagembemvindo();

    do{  //fazer uma funcionalidade e retornar para o menu de escolha
        
        system("clear"); //limpar console
        selecionamenu(&opcao, &qtdAlunos); //capturar opção do menu
        system("clear"); //limpar console

        funcionalidades(&opcao, alunos, &qtdAlunos); //direcionar para a função escolhda no menu
        
    }while( opcao != 0);

    return 0;
}