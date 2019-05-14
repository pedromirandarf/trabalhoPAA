#include "CLASSE.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
using namespace std;

//! \class Disciplina.
/**
	\brief Armazena as informações da disciplina.

	Armazena as informações da disciplina, armazenando o nome, sigla,
	periodo, os seus pré-requisitos totais, parciais, e co-requisto e carga horaria
*/

DISCIPLINA::DISCIPLINA(){//! constructor.
		/*! Inicializa os valores como nulos. */
    strcpy(nomed,"");/*!< Nome completo da matéria. */
    strcpy(sigla,"");/*!< Sigla da matéria. */
    strcpy(cargaH,"");/*!< Carga horaria da matéria. */
    strcpy(periodo,"");/*!< Periodo oficial da matéria. */
    qnt[0]=qnt[1]=qnt[2] =0;
    for(int i=0; i<5;i++)
    {
        strcpy(preTOTAL[i].s_disc,"");/*!< Pré-requisito total. */
        strcpy(prePARCIAL[i].s_disc,"0");/*!< Pré-requisito parcial. */
        if(i<2){strcpy(coREQ[i].s_disc,"0");}/*!< Co-requisitos. */
    }
 }

DISCIPLINA::~DISCIPLINA(){//! Destrutor da Classe.
		
    strcpy(nomed,"");
    strcpy(sigla,"");
    strcpy(cargaH,"");
    strcpy(periodo,"");
    qnt[0]=qnt[1]=qnt[2] =0;
    for(int i=0; i<5;i++)
    {
        strcpy(preTOTAL[i].s_disc,"0");
        strcpy(prePARCIAL[i].s_disc,"0");
        if(i<2){strcpy(coREQ[i].s_disc,"0");}
    }
 }
void DISCIPLINA::destroi(){//! DESTRUTOR DA CLASSE "DISCIPLINA".
    strcpy(nomed,"");
    strcpy(sigla,"");
    strcpy(cargaH,"");
    strcpy(periodo,"");
    qnt[0]=qnt[1]=qnt[2] =0;
    for(int i=0; i<5;i++)
    {
        strcpy(preTOTAL[i].s_disc,"0");
        strcpy(prePARCIAL[i].s_disc,"0");
        if(i<2){strcpy(coREQ[i].s_disc,"0");}
    }
 }
 //! Função para a imprimir as informações da disciplina.
		/*!
			Imprime todo o conteúdo contido na disciplina, sigla, nome, período, lista
		de pré-requisitos totais e parciais, lista de co-requisitos e a quantidade
		de horas da disciplina.
		*/
 void DISCIPLINA::imprime_disciplina()//!METODO QUE IMPRIME CADA DISCIPLINA NA TELA -- PRONTA
{
    int i=0;
   cout << "DADOS DA DISCIPLINA " << nomed << "  " << endl;
   cout << "--------------------------------------" << endl;
   cout<<"SIGLA: "<<sigla<<endl;
   cout<<"CARGA HORARIA SEMESTRAL: "<<cargaH<<endl;
   cout<<"PERIODO DA DISCIPLINA: "<<periodo<<endl;
   if(qnt[0]!=0){
   /** do{
        cout << "PRE-REQUISTO TOTAL: " << preTOTAL[i] << " " << endl;
        i = i+1;
    }while(preTOTAL[i]!="0"); */

    while(i<qnt[0])
    {
        cout << "PRE-REQUISTO TOTAL: " << preTOTAL[i].s_disc << " " << endl;
        i = i+1;
    }
   }else
   {
       cout << "ESSA DISCIPLINA NAO TEM PRE-REQUISITOS TOTAIS" << endl;
   }
   i=0;

   ///-----------------------------------------------------------------

   if(qnt[1]!=0){
   /** do{
        cout << "PRE-REQUISTO TOTAL: " << preTOTAL[i] << " " << endl;
        i = i+1;
    }while(preTOTAL[i]!="0"); */

    while(i<qnt[1])
    {
        cout << "PRE-REQUISTO PARCIAL: " << prePARCIAL[i].s_disc << " " << endl;
        i = i+1;
    }
   }else
   {
       cout << "ESSA DISCIPLINA NAO TEM PRE-REQUISITOS PARCIAIS" << endl;
   }
    /// ---------------------------------------------------------------
    i=0;
    if(qnt[2]!=0){
   /** do{
        cout << "PRE-REQUISTO TOTAL: " << preTOTAL[i] << " " << endl;
        i = i+1;
    }while(preTOTAL[i]!="0"); */

    while(i<qnt[2])
    {
        cout << "CO-REQUISTOS: " << coREQ[i].s_disc << " " << endl;
        i = i+1;
    }
   }else
   {
       cout << "ESSA DISCIPLINA NAO TEM CO-REQUISTOS" << endl;
   }
   ///--------------------------------------------------------------------

}

//! Função para a inserir as informações da disciplina.
		/*!
			Insere as informações da disciplina no formato SIGLA NOME_SEM_ESPAÇO
			PERÍODO PRÉ-REQUISITOS_TOTAIS PRÉ-REQUISITOS_PARCIAIS CO-REQUISITOS HORAS
			\param origem string contendo informações da disciplina.
		*/
void DISCIPLINA::edita_disciplina()//!METODO QUE CADASTRA CADA DISCIPLINA -- PRONTA
{
   int i=0, op=-1;
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
   cout<<"DIGITE O PERIODO DA DISCIPLINA: "<<endl;
    fflush(stdin);
    gets(this->periodo);

   //! CADASTRA CADA PRE-REQUISITO TOTAL NA DISCIPLINA

   cout << "ESSA DISCIPLINA POSSUI PRE-REQUISITOS TOTAIS? (1-SIM / 0-NAO)" << endl;
   cin >> op;
   if(op==1){
        op =-1;
    cout << "QUANTOS PRE-REQUISITOS TOTAIS?" << endl;
    cin >> qnt[0];
    while(i<qnt[0])
    {
        cout << "DIGITE A SIGLA DA DISCIPLINA: " << endl;
        fflush(stdin);
        gets(this->preTOTAL[i].s_disc);
        i = i+1;
    }
   }else
   {
       cout << "ESSA DISCIPLINA NAO TEM PRE-REQUISITOS TOTAIS" << endl;
       cout << endl;
   }
   i=0;
   op=-1;

   //! CADASTRA CADA PRE-REQUISITO PARCIAL NA DISCIPLINA

   cout << "ESSA DISCIPLINA POSSUI PRE-REQUISITOS PARCIAL? (1-SIM / 0-NAO)" << endl;
   cin >> op;
   if(op==1){
        op =-1;
    cout << "QUANTOS PRE-REQUISITOS PARCIAIS?" << endl;
    cin >> qnt[1];
    while(i<qnt[1])
    {
        cout << "DIGITE A SIGLA DA DISCIPLINA: " << endl;
        fflush(stdin);
        gets(this->prePARCIAL[i].s_disc);
        i = i+1;
    }
   }else
   {
       cout << "ESSA DISCIPLINA NAO TEM PRE-REQUISITOS PARCIAIS" << endl;
       cout << endl;
   }

    //! CADASTRA CADA CO-REQUISITO NA DISCIPLINA

    i=0;
    op=-1;
    cout << "ESSA DISCIPLINA POSSUI CO-REQUISITO? (1-SIM / 0-NAO)" << endl;
    cin >> op;
   if(op==1){
        op =-1;
    qnt[2] = 1;
    while(i<qnt[2])
    {
        cout << "DIGITE A SIGLA DA DISCIPLINA: " << endl;
        fflush(stdin);
        gets(this->coREQ[i].s_disc);
        i = i+1;
    }
   }else
   {
       cout << "ESSA DISCIPLINA NAO TEM CO-REQUISTOS" << endl;
       cout << endl;
   }

   //! FIM INSERCAO DE DADOS

}
