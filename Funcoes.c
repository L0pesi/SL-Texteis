/* «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««
 * ++++     Trabalho Prático 1 - Estrutura de Dados Avançada    ++++
 * 
 * Developer: Sérgio Lopes @Ipca-Est  </copyright>
 * <version>1.3</version>
 *
 * <description> Solução Digital para o problema de escalonamento de uma unidade de produção têxtil </description>
 * »»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»
 **/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <locale.h>   //ASCII SET    ...caracteres portugueses
#include "Struct.h"


 /// <summary>
 /// Purpose: Espaço onde determino as funções que usarei
 /// Created by: Lopesi
 /// Created on: 11/4/2022 23:16:34 PM
 /// </summary>
 /// <remarks>Organização plena das funções de implementação</remarks>



#pragma region FUNÇÕES MAQUINAS
 /*
 * Funções para manipular máquinas
 */

Maquina* CriaMaquina(int id) { //cria uma máquina

    Maquina* aux;
    //criar espaço para a memoria
    aux = (Maquina*)malloc(sizeof(Maquina));
    if (aux == NULL) return NULL; //se n tiver memoria

    aux->id = id;
    return aux;

}


Maquina* InsereMaquinaInicioLista(Maquina* nova, Maquina* inicio) {   //insere máquina no inicio da lista

    if (inicio == NULL)			//Lista tá vazia
        inicio = nova;
    else {
        nova->nextM = inicio;
        inicio = nova;
    }
    return inicio;
}


Maquina* InsereMaquinaFimLista(Maquina* nova, Maquina* inicio) {   //insere máquina no fim da lista

    if (inicio == NULL)			//Lista tá vazia
        inicio = nova;
    else {
        //procurar o fim
        Maquina* aux = inicio;
        while (aux->nextM != NULL) aux = aux->nextM;
        //Ligar a nova
        aux->nextM = nova;

    }
    return inicio;
}


Maquina* InsereMaquinaLista(Maquina* nova, Maquina* inicio) {    //insere máquina na lista posiç correcta

    if (inicio == NULL)			//Lista tá vazia
        inicio = nova;
    else {

        if (ExisteMaquina(nova->id, inicio) == true)
            return inicio;

        //procurar a posição correcta
        Maquina* aux = inicio;
        Maquina* ant = inicio;
        while ((aux->nextM != NULL) && (aux->id < nova->id)) {
            ant = aux;
            aux = aux->nextM;
        }
        //ligar a nova
        nova->nextM = aux;
        ant->nextM = nova;

    }
    return inicio;
}


bool ExisteMaquina(int id, Maquina* inicio) {     //verificação se existe x máquina - devolve True/false

    if (inicio == NULL) return false;
    Maquina* aux = inicio;
    while ((aux != NULL && (aux->id != id))) {
        aux = aux->nextM;
    }
    if (aux != NULL)  // && aux->cod == cod) return true;
        return true;

    return false;
    //return((aux != NULL));

}


Maquina* ExisteMaquinaII(int id, Maquina* inicio) {    //verifica se existe x máquina - devolve a propria

    if (inicio == NULL)
        return NULL;

    Maquina* aux = inicio;
    while ((aux != NULL && (aux->id != id))) {
        aux = aux->nextM;
    }
    if (aux != NULL)
        return aux;

    return NULL;

    //return aux;
}

// +++++ Fazer Remover Máquina +++++

// +++++ Fazer Alterar Máquina +++++

/*
* Função para Listar as Maquinas
*/
void ListarMaquinas(ListaMaquinas* auxM) {
    ListaMaquinas* aux = auxM;
    printf("Maquinas:\n");
    while (aux != NULL) {
        printf("ID: %d\n", aux->maquina.id);
        aux = aux->nextLM;
    }
}


#pragma endregion


#pragma region FUNÇÕES OPERAÇÕES
/*
* Funções para manipular Operações
*/

Operacao* CriaOperacao(int id, int time) {    //cria uma operação
    Operacao* novaOp = (Operacao*)malloc(sizeof(Operacao));
    if (novaOp == NULL) return NULL;  //se n tiver memoria

    novaOp->id = id;
    novaOp->time;
    novaOp->maquinas = NULL;

    return novaOp;
}

// +++++ Fazer Remover Operação +++++

// +++++ Fazer Alterar Operações +++++

/*
* Função para Listar as operações
*/
void ListarOperacoes(ListaOperacoes* auxOp) {
    ListaOperacoes* aux = auxOp;
    printf("Operacoes:\n");
    while (aux != NULL) {
        printf("ID: %d\n", aux->operacao.id);
        printf("TIME: %p\n", aux->operacao.time);
        ListarMaquinas(auxOp->operacao.maquinas);
        aux = aux->nextLOp;
    }
}



#pragma endregion


#pragma region FUNÇÕES JOBS

/*
* Função para criar jobs
*/
Job* CriaJob(int id) {        //cria um Job
    Job* newJob = (Job*)malloc(sizeof(Job));
    if (newJob == NULL) return NULL; //se n tiver memoria

    newJob->id;
    newJob->operacoes = NULL; //meter =NULL para começar vazio?
    newJob->nextJ = NULL;     //meter =NULL para começar vazio?

    return newJob;
}

/*
* Função para inserir um job na estrutura
*/
Job* InsereJob(Job* primeJob, Job* newJob) {
    if (primeJob == NULL) {
        primeJob = newJob;    //se for o primeiro
    }
    else
    {
        Job* auxJ = primeJob;
        Job* beforeJ = NULL;

        while (auxJ && auxJ->id < newJob->id) {     //dúvidas aqui!!!!!
            beforeJ = auxJ;
            auxJ = auxJ->nextJ;

        }
        if (beforeJ == NULL) {
            newJob->nextJ = primeJob;
            primeJob = newJob;
        }
        else {
            beforeJ->nextJ = newJob;
            newJob->nextJ = auxJ;
        }

    }
    return primeJob;
}

/*
* Função para Listar os jobs
*/
void ListarJobs(Job* auxJ) {
    Job* aux = auxJ;
    printf("Jobs:\n");
    while (aux != NULL) {
        printf("ID: %d\n", aux->id);
        ListarOperacoes(auxJ->operacoes);
        aux = aux->nextJ;
    }
}


#pragma endregion


#pragma region FUNÇÕES FICHEIROS
//
// /*
// * Funções para manipular ficheiros
// */
//
//bool saveFile(char* ficheiro, Job* topJob)   //Gravar para Ficheiro os jobs
//{
//    if (topJob == NULL) return false; //se estiver vazia aborta
//    FILE* bd;
//    if ((bd = fopen(ficheiro, "wb")) == NULL) return false;  //se erro aborta & wb (write + binario)
//
//    Job* auxJ = topJob;
//    xFile auxFile;
//
//    while (auxJ != NULL) //percorrer todos na estrutura
//    {
//        auxFile.id = auxJ->id;
//        fwrite(&auxFile, sizeof(xFile), 1, bd);    //size_t fwrite(void * dados, size_t tamanho, size_t numero_itens, FILE * fluxo);
//        auxJ = auxJ->nextJ;
//    }
//    fclose(bd);
//
//    return true;    //retorna sucesso
//
//}
//
//Job* readFile(char* ficheiro) {   //ler jobs do ficheiro
//    FILE* bp;
//    Job* topJob = NULL; //cria vazio
//    Job* auxJob;
//
//    if ((bp = fopen(ficheiro, "rb")) == NULL) return NULL;    //se erro aborta & rb (read + binario)
//    xFile auxFile;
//    while (fread(&auxFile, sizeof(Job), 1, bp)) {
//        auxJob = CriaJob(auxFile.id);   //cria o job lido
//        topJob = InsereJob(topJob, auxJob);   //insere o job lido
//    }
//    fclose(bp);
//
//    return topJob;  //retorna elemento
//}
//
///*
//* 
//* 
//* referencias:  http://wiki.icmc.usp.br/images/8/82/Manipulacao_arquivos.pdf 
//*
//*/
//
#pragma endregion



