#ifndef CLASSE_H
#define CLASSE_H
#include <cstring>
#include<string>
#include<iostream>

typedef struct {
char s_disc[10];
}PRE;
//! \class Disciplina.
/**
	\brief Armazena as informações da disciplina.

	Armazena as informações da disciplina, armazenando o nome, sigla,
	periodo, os seus pré-requisitos totais, parciais, e co-requisto e carga horaria
*/
class DISCIPLINA{   //! CLASSE GERAL DISCIPLINA--
    public:
    char nomed[50];
    char sigla[10];
    char cargaH[3];
    int qnt[3];
    char periodo[2];
    PRE preTOTAL[5];
    PRE prePARCIAL[5];
    PRE coREQ[2];
    DISCIPLINA(); 
    void imprime_disciplina(); 
    void edita_disciplina(); 
    ~DISCIPLINA(); 
    void destroi();
};

#endif //! CLASSE_H
