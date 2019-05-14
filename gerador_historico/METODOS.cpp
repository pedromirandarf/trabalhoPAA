#include "CLASSE.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
using namespace std;

DISCIPLINA::DISCIPLINA(){//!CONSTRUTOR DA CLASSE "DISCIPLINA".
    strcpy(nomed,"");/*!< Nome completo da matéria. */
    strcpy(sigla,"");/*!< Sigla da matéria. */
    strcpy(cargaH,"");/*!< Carga horaria da matéria. */
    strcpy(nota,"");/*!< Nota na matéria. */
    strcpy(situacao,"");/*!< Situacao na matéria. */
    strcpy(frequencia,"");/*!< Frequencia na matéria. */
 }

DISCIPLINA::~DISCIPLINA(){//!DESTRUTOR DA CLASSE "DISCIPLINA".
    strcpy(nomed,"");
    strcpy(sigla,"");
    strcpy(cargaH,"");
    strcpy(nota,"");
    strcpy(situacao,"");
    strcpy(frequencia,"");
 }
void DISCIPLINA::destroi(){//!DESTRUTOR DA CLASSE "DISCIPLINA".
    strcpy(nomed,"");
    strcpy(sigla,"");
    strcpy(cargaH,"");
    strcpy(nota,"");
    strcpy(situacao,"");
    strcpy(frequencia,"");
 }
 void DISCIPLINA::imprime_disciplina()//!METODO QUE IMPRIME CADA DISCIPLINA NA TELA -- PRONTA
{
    int i=0;
   cout << "DADOS DA DISCIPLINA " << nomed << "  " << endl;
   cout << "--------------------------------------" << endl;
   cout<<"SIGLA: "<<sigla<<endl;
   cout<<"CARGA HORARIA SEMESTRAL: "<<cargaH<<endl;
   cout << "NOTA NA DISCIPLINA: " << nota << endl;
   cout << "SITUACAO DO ALUNO: " << situacao << endl;
   cout << "FREQUENCIA DO ALUNO: " << frequencia << endl;
}


void DISCIPLINA::edita_disciplina()//!METODO QUE CADASTRA CADA DISCIPLINA -- PRONTA
{
   int i=0, op=-1;
   char key[] = "CURSANDO";
   cout << "CADASTRO DE DISCIPLINA " << endl;
   cout << "--------------------------------------" << endl;
   cout << "DIGITE O NOME DA DISCIPLINA: "<<endl;
    fflush(stdin);
    gets(this->nomed);
    cout << "DIGITE A SIGLA DA DISCIPLINA: "<<endl;
    fflush(stdin);
    gets(this->sigla);
   cout<<"DIGITE A CARGA HORARIA SEMESTRAL: "<<endl;
    fflush(stdin);
    gets(this->cargaH);
    cout << "A SITUACAO DO ALUNO: (APROVADO/REPROVADO/CURSANDO/NAO-FEITA)" <<endl;
    fflush(stdin);
    gets(this->situacao);
    if(!strcmp(situacao,key))
    {
        strcpy(nota,"");
        strcpy(situacao,"");
    }else{
    cout<<"DIGITE A NOTA DA DISCIPLINA: "<<endl;
    fflush(stdin);
    gets(this->nota);
    cout<<"DIGITE A FREQUENCIA DO ALUNO: "<<endl;
    fflush(stdin);
    gets(this->frequencia);
    }

   //! FIM INSERCAO DE DADOS

}
