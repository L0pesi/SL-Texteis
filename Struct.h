/* «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««
 * ++++     Trabalho Prático 1 - Estrutura de Dados Avançada    ++++
 *
 * Developer: Sérgio Lopes @Ipca-Est  </copyright>
 * <version>1.3</version>
 *
 * <description> Solução Digital para o problema de escalonamento de uma unidade de produção têxtil </description>
 * »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»
 **/


#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>


/// <summary>
/// Purpose: No Header file, determino as minhas estructuras e utilizo ainda para a assinatura das funções
/// Created by: Lopesi
/// Created on: 12/4/2022 00:41:22 AM
/// </summary>
/// <remarks>Organização das estruturas e assinatura das funções</remarks>


#ifndef X

#define X 1

#define MAXIMO 100 //apenas para textos longos não serem tao longos


#pragma warning(disable : 4996)   //apontado do slide

#pragma region ESTRUTURAS

typedef struct Maquina
{
    int id;
    //int time;
    char nome[MAXIMO];
    struct Maquina* nextM;

}Maquina;

typedef struct ListaMaquinas {
    struct Maquina maquina;
    struct ListaMaquinas* nextLM;
}ListaMaquinas;

ListaMaquinas* auxM;


typedef struct Operacao
{
    int id;
    //Maquina* maquina;
    int* time;
    struct ListaMaquinas* maquinas;

}Operacao;

typedef struct ListaOperacoes {
    struct Operacao operacao;
    struct ListaMaquinas* maquinas;
    struct ListaOperacoes* nextLOp;
}ListaOperacoes;

ListaOperacoes* auxOp;


typedef struct Job
{
    int id;
    //Operacao* operacao;
    struct Job* nextJ;
    struct ListaOperacoes* operacoes;
}Job;

Job* auxJ;


typedef struct xFile {
    int id;
}xFile;

#pragma endregion


#pragma region ASSINATURAS


//Funções para Gerir Máquinas
Maquina* CriaMaquina(int id);
Maquina* InsereMaquinaInicioLista(Maquina* nova, Maquina* inicio);
Maquina* InsereMaquinaFimLista(Maquina* nova, Maquina* inicio);
Maquina* InsereMaquinaLista(Maquina* nova, Maquina* inicio);
bool ExisteMaquina(int cod, Maquina* inicio);
Maquina* ExisteMaquinaII(int cod, Maquina* inicio);
// +++++ Fazer Remover Máquina +++++
// +++++ Fazer Alterar Máquina +++++
void ListarMaquinas(ListaMaquinas* auxM);



//Funções para Gerir Operações
Operacao* CriaOperacao(int id, int time);
// +++++ Fazer Remover Operação +++++
// +++++ Fazer Alterar Operações +++++
void ListarOperacoes(ListaOperacoes* auxOp);



//Funções para Gerir Jobs
Job* CriaJob(int id);
Job* InsereJob(Job* primeJob, Job* newJob);
void ListarJobs(Job* auxJ);



////Funções para manipular ficheiros
//bool saveFile(char* ficheiro, Job* topJob);
//Job* readFile(char* ficheiro);

#pragma endregion



#endif