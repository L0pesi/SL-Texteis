/* �����������������������������������������������������������������������������������������������������������������
 * ++++     Trabalho Pr�tico 1 - Estrutura de Dados Avan�ada    ++++
 *
 * Developer: S�rgio Lopes @Ipca-Est  </copyright>
 * <version>1.3</version>
 *
 * <description> Solu��o Digital para o problema de escalonamento de uma unidade de produ��o t�xtil </description>
 * ������������������������������������������������������������������������������������������������������������������
 **/


#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>


/// <summary>
/// Purpose: No Header file, determino as minhas estructuras e utilizo ainda para a assinatura das fun��es
/// Created by: Lopesi
/// Created on: 12/4/2022 00:41:22 AM
/// </summary>
/// <remarks>Organiza��o das estruturas e assinatura das fun��es</remarks>


#ifndef X

#define X 1

#define MAXIMO 100 //apenas para textos longos n�o serem tao longos


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


//Fun��es para Gerir M�quinas
Maquina* CriaMaquina(int id);
Maquina* InsereMaquinaInicioLista(Maquina* nova, Maquina* inicio);
Maquina* InsereMaquinaFimLista(Maquina* nova, Maquina* inicio);
Maquina* InsereMaquinaLista(Maquina* nova, Maquina* inicio);
bool ExisteMaquina(int cod, Maquina* inicio);
Maquina* ExisteMaquinaII(int cod, Maquina* inicio);
// +++++ Fazer Remover M�quina +++++
// +++++ Fazer Alterar M�quina +++++
void ListarMaquinas(ListaMaquinas* auxM);



//Fun��es para Gerir Opera��es
Operacao* CriaOperacao(int id, int time);
// +++++ Fazer Remover Opera��o +++++
// +++++ Fazer Alterar Opera��es +++++
void ListarOperacoes(ListaOperacoes* auxOp);



//Fun��es para Gerir Jobs
Job* CriaJob(int id);
Job* InsereJob(Job* primeJob, Job* newJob);
void ListarJobs(Job* auxJ);



////Fun��es para manipular ficheiros
//bool saveFile(char* ficheiro, Job* topJob);
//Job* readFile(char* ficheiro);

#pragma endregion



#endif