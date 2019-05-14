#ifndef CLASSE_H
#define CLASSE_H
#include <cstring>
#include<string>
#include<iostream>

//! \class Disciplina.
/**
	\brief Armazena as informações da disciplina mais situação do semestre. 

	Armazena as informações da disciplina, armazenando o nome, sigla,
	periodo, os seus pré-requisitos totais, parciais, e co-requisto e carga horaria
*/

class DISCIPLINA{   //! CLASSE GERAL DISCIPLINA--
    public:
    char nomed[50];
    char sigla[10];
    char cargaH[3];
    char nota[5];
    char situacao[10];
    char frequencia[5];
    DISCIPLINA();
    void imprime_disciplina();
    void edita_disciplina();
    ~DISCIPLINA();
    void destroi();
};

#endif //! CLASSE_H
