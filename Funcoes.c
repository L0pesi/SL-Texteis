/* �����������������������������������������������������������������������������������������������������������������
 * ++++     Trabalho Pr�tico 1 - Estrutura de Dados Avan�ada    ++++
 * 
 * Developer: S�rgio Lopes @Ipca-Est  </copyright>
 * <version>1.3</version>
 *
 * <description> Solu��o Digital para o problema de escalonamento de uma unidade de produ��o t�xtil </description>
 * ������������������������������������������������������������������������������������������������������������������
 **/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <locale.h>   //ASCII SET    ...caracteres portugueses
#include "Struct.h"


 /// <summary>
 /// Purpose: Espa�o onde determino as fun��es que usarei
 /// Created by: Lopesi
 /// Created on: 11/4/2022 23:16:34 PM
 /// </summary>
 /// <remarks>Organiza��o plena das fun��es de implementa��o</remarks>



#pragma region FUN��ES MAQUINAS
 /*
 * Fun��es para manipular m�quinas
 */

Maquina* CriaMaquina(int id) { //cria uma m�quina

    Maquina* aux;
    //criar espa�o para a memoria
    aux = (Maquina*)malloc(sizeof(Maquina));
    if (aux == NULL) return NULL; //se n tiver memoria

    aux->id = id;
    return aux;

}


Maquina* InsereMaquinaInicioLista(Maquina* nova, Maquina* inicio) {   //insere m�quina no inicio da lista

    if (inicio == NULL)			//Lista t� vazia
        inicio = nova;
    else {
        nova->nextM = inicio;
        inicio = nova;
    }
    return inicio;
}


Maquina* InsereMaquinaFimLista(Maquina* nova, Maquina* inicio) {   //insere m�quina no fim da lista

    if (inicio == NULL)			//Lista t� vazia
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


Maquina* InsereMaquinaLista(Maquina* nova, Maquina* inicio) {    //insere m�quina na lista posi� correcta

    if (inicio == NULL)			//Lista t� vazia
        inicio = nova;
    else {

        if (ExisteMaquina(nova->id, inicio) == true)
            return inicio;

        //procurar a posi��o correcta
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


bool ExisteMaquina(int id, Maquina* inicio) {     //verifica��o se existe x m�quina - devolve True/false

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


Maquina* ExisteMaquinaII(int id, Maquina* inicio) {    //verifica se existe x m�quina - devolve a propria

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

// +++++ Fazer Remover M�quina +++++

// +++++ Fazer Alterar M�quina +++++

/*
* Fun��o para Listar as Maquinas
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


#pragma region FUN��ES OPERA��ES
/*
* Fun��es para manipular Opera��es
*/

Operacao* CriaOperacao(int id, int time) {    //cria uma opera��o
    Operacao* novaOp = (Operacao*)malloc(sizeof(Operacao));
    if (novaOp == NULL) return NULL;  //se n tiver memoria

    novaOp->id = id;
    novaOp->time;
    novaOp->maquinas = NULL;

    return novaOp;
}

// +++++ Fazer Remover Opera��o +++++

// +++++ Fazer Alterar Opera��es +++++

/*
* Fun��o para Listar as opera��es
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


#pragma region FUN��ES JOBS

/*
* Fun��o para criar jobs
*/
Job* CriaJob(int id) {        //cria um Job
    Job* newJob = (Job*)malloc(sizeof(Job));
    if (newJob == NULL) return NULL; //se n tiver memoria

    newJob->id;
    newJob->operacoes = NULL; //meter =NULL para come�ar vazio?
    newJob->nextJ = NULL;     //meter =NULL para come�ar vazio?

    return newJob;
}

/*
* Fun��o para inserir um job na estrutura
*/
Job* InsereJob(Job* primeJob, Job* newJob) {
    if (primeJob == NULL) {
        primeJob = newJob;    //se for o primeiro
    }
    else
    {
        Job* auxJ = primeJob;
        Job* beforeJ = NULL;

        while (auxJ && auxJ->id < newJob->id) {     //d�vidas aqui!!!!!
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
* Fun��o para Listar os jobs
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


#pragma region FUN��ES FICHEIROS
//
// /*
// * Fun��es para manipular ficheiros
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



