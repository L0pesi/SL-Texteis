/* «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««
 *
 * ++++     Trabalho Prático 1 - Estrutura de Dados Avançada    ++++
 *
 * Developer: Sérgio Lopes @Ipca-Est  </copyright>
 *
 * <author>Lopesi</author>
 * <email>a8390@alunos.ipca.pt</email>
 * <date>11/4/2022 22:10:34 PM</date>
 * <version>1.3</version>
 *
 * <description> Solução Digital para o problema de escalonamento de uma unidade de produção têxtil </description>
 *
 * »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»
 **/


#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <locale.h>   //ASCII SET    ...caracteres portugueses
#include "Struct.h"


 //ver onde vou colocar  _CRT_SECURE_NO_WARNINGS


   /// <summary>
   /// Purpose: Este é o Main onde executo o programa e testo as funções
   /// Created by: Lopesi
   /// Created on: 11/4/2022 22:10:34 PM
   /// </summary>
   /// <remarks>Na 3ª versão final.... e dar em doido!!!</remarks>


void main()
{

#pragma region VARIAVEIS

    // Criar Maquinas
    Maquina* m1 = CriaMaquina(1);
    Maquina* m2 = CriaMaquina(2);
    Maquina* m3 = CriaMaquina(3);


    //Criar Operações
    Operacao* op1 = CriaOperacao(1, 4);      //problema: tendo o time nas operações como achei que era suposto cria-me o problema de não ser único!! ver alternativa de adaptar time para as maquinas


    //Criar Jobs
    Job* j1 = CriaJob(1);
    auxJ = InsereJob(auxJ, j1);




#pragma endregion


#pragma region FICHEIROS
    /*
    * Aplicar as funções de Ficheiros
    */

    // bool ficheiro = saveFile(char* "jobs.bin", Job* topJob);

    // tempJ = readFile(char* "jobs.bin");


#pragma endregion


/* TESTE VERSÃO ANTIGA - APAGAR

#pragma region TESTE VERSÃO ANTIGA - APAGAR

#pragma region CRIAR

    struct Maquina m1, m2, m3, m4, m5, m6, m7, m8;
    struct Job j1;
    //struct Operacao* op1 = (Operacao*)malloc(sizeof(Operacao)*2);
    struct Operacao op1, op2, op3, op4, op5, op6, op7;

    Job* tempJ = NULL;

#pragma endregion


#pragma region DECLARAR OPERAÇÕES

    op1.id = 1;
    op1.machine = (Maquina*)malloc(sizeof(Maquina) * 2);
    op1.time = (int*)malloc(sizeof(int) * 2);

    op2.id = 2;
    op2.machine = (Maquina*)malloc(sizeof(Maquina) * 2);
    op2.time = (int*)malloc(sizeof(int) * 2);

    op3.id = 3;
    op3.machine = (Maquina*)malloc(sizeof(Maquina) * 2);
    op3.time = (int*)malloc(sizeof(int) * 2);

    op4.id = 4;
    op4.machine = (Maquina*)malloc(sizeof(Maquina) * 5);
    op4.time = (int*)malloc(sizeof(int) * 5);

    op5.id = 5;
    op5.machine = (Maquina*)malloc(sizeof(Maquina) * 2);
    op5.time = (int*)malloc(sizeof(int) * 2);

    op6.id = 6;
    op6.machine = (Maquina*)malloc(sizeof(Maquina) * 2);
    op6.time = (int*)malloc(sizeof(int) * 2);

    op7.id = 7;
    op7.machine = (Maquina*)malloc(sizeof(Maquina) * 2);
    op7.time = (int*)malloc(sizeof(int) * 2);

#pragma endregion


#pragma region ATRIBUIR

#pragma region Maquinas

    m1.num = 1;
    m2.num = 2;
    m3.num = 3;
    m4.num = 4;
    m5.num = 5;
    m6.num = 6;
    m7.num = 7;
    m8.num = 8;

#pragma endregion

#pragma region Operações
    op1.machine[0] = m1;
    op1.time[0] = 4;
    op1.machine[1] = m3;
    op1.time[1] = 5;

    op2.machine[0] = m2;
    op2.time[0] = 4;
    op2.machine[1] = m4;
    op2.time[1] = 5;

    op3.machine[0] = m3;
    op3.time[0] = 5;
    op3.machine[1] = m5;
    op3.time[1] = 6;

    op4.machine[0] = m4;
    op4.time[0] = 5;
    op4.machine[1] = m5;
    op4.time[1] = 5;
    op4.machine[2] = m6;
    op4.time[2] = 4;
    op4.machine[3] = m7;
    op4.time[3] = 5;
    op4.machine[4] = m8;
    op4.time[4] = 9;

#pragma endregion

#pragma region Jobs

    j1.operacao = (Operacao*)malloc(sizeof(Operacao) * 4);
    j1.operacao[0] = op1;
    j1.operacao[1] = op2;
    j1.operacao[2] = op3;
    j1.operacao[3] = op4;

#pragma endregion

#pragma endregion


#pragma region TESTAR


    printf(" OPERATION       |          MACHINE           |\n\n");
    printf("    %d            |            (%d,%d)           |\n", j1.operacao[0].id, j1.operacao[0].machine[0].num, j1.operacao[0].machine[1].num);
    printf("                 |            [%d,%d]           |\n\n", j1.operacao[0].time[0], j1.operacao[0].time[1]);
    printf("    %d            |            (%d,%d)           |\n", j1.operacao[1].id, j1.operacao[1].machine[0].num, j1.operacao[1].machine[1].num);
    printf("                 |            [%d,%d]           |\n\n", j1.operacao[1].time[1], j1.operacao[1].time[1]);
    printf("    %d            |            (%d,%d)           |\n", j1.operacao[2].id, j1.operacao[2].machine[0].num, j1.operacao[2].machine[1].num);
    printf("                 |            [%d,%d]           |\n\n", j1.operacao[2].time[1], j1.operacao[1].time[1]);
    printf("    %d            |            (%d,%d)           |\n", j1.operacao[3].id, j1.operacao[3].machine[0].num, j1.operacao[3].machine[1].num);
    printf("                 |            [%d,%d]           |\n\n", j1.operacao[3].time[1], j1.operacao[3].time[1]);
    printf("\n\n\n\n");

#pragma endregion


#pragma endregion

*/



    printf("\n");
    ListarJobs(auxJ);
    printf("\n\n\n");




    return 0;
}



/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
*           ENUNCIADO DO TRABALHO PRÁTICO
*
* >>>>    Fase 1    >>>>
*
* [FEITO]       1. Definição de uma estrutura de dados dinâmica para a representação de um job com um
*               conjunto finito de n operações;
*
* [FEITO]       2. Armazenamento/leitura de ficheiro de texto com representação de um job;
*
* [FEITO]       3. Inserção de uma nova operação;
*
* [INCOMPLETO]  4. Remoção de uma determinada operação;
*
* [INCOMPLETO]  5. Alteração de uma determinada operação;
*
* [POR FAZER]   6. Determinação da quantidade mínima de unidades de tempo necessárias para completar
*               o job e listagem das respetivas operações;
*
* [POR FAZER]   7. Determinação da quantidade máxima de unidades de tempo necessárias para completar
*               o job e listagem das respetivas operações;
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/