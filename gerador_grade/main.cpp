/*!
	\mainpage PADCTG - Programa de Análise de Discente Contextualizada por Teoria de Grafos
	\section	grup_sec	Grupo:
            Bruno Antunes Meazini - 31299\n
			Rodolfo Constancio de Almeida Lage - 2016017890\n
			Pedro Celso Miranda Rocha Filho - 2017001769\n
            Tadeu Rangel Silva de Abreu - 2017011531\n
            Leonardo Souza Coelho - 2016015400\n

	\section intro_sec Introdução
	Visto que muitos alunos cursando o ensino superior normalmente passam dificuldades ao se deparar com a matricula semestral, sendo o maior problema, a escolha das matérias a serem cursadas no semestre. Assim a disciplina de Projeto e Analise de Algoritmos, propõem formas de ajudar o aluno na hora da escolha, utilizando teoria de grafos.
    É observado uma grande evasão de alunos nas universidades e este fato ocorre por diversos motivos. Dentre os motivos desta evasão o mais comum ocorre quando o discente não acompanha a grade curricular, devido a reprovações e então isso acarreta em uma grande dificuldade nas escolhas das disciplinas a serem cursadas nos próximos semestres. Este problema ocorre devido a dependência que certas matérias possuem, ou seja, matérias que possuem pré-requisitos para serem cursadas. As instituições de ensino superior não direcionam os discentes na escolha das melhores disciplinas que visariam minimizar o atraso acarretado pelas reprovações anteriores.
    Este problema acaba por tornar o período da universidade cansativo e desestimulante, fazendo com que parte de alunos recém ingressados acabem por abandonar o curso.
	Atualmente, profissionais ingressados na área, procuram por desenvolver maneiras que melhor auxiliariam os alunos, procurando entender os motivos de reprovação e trancamentos a partir de analises estatísticas. Dessa forma os estudos se limitam a identificar os percentuais de desempenho obtidos pelos alunos, com o intuito de identificar as matérias com maiores índices de reprovação, como visto no estudo feito por Yorah e Marco Aurélio(2015).
    Com o intuito de auxiliar os alunos de uma forma mais eficaz é proposto a criação de um algoritmo baseado em teoria de grafos para guiar os discentes, visando diminuir o impacto das reprovações em suas matrículas futuras


	\section prop_sec Proposta
	Neste trabalho da disciplina de Projeto e An´alise de Algoritmos ´e proposto o desenvolvimento de
    uma metodologia que realize a modelagem do hist´orico curricular do aluno associado com sua grade
    curricular com o objetivo de auxiliar o coordenador do curso na tomada de decis˜ao quanto as ofertas
    de disciplinas para o pr´oximo semestre, verificar o estado atual de cada discente em rela¸c˜ao a sua
    grade curricular e tamb´em modelar o perfil do aluno egresso do curso.

*/
/*! \file main.cpp
    \brief PADCTG - Programa de Análise de Discente Contextualizada por Teoria de Grafos

		 Grupo:
		 Bruno Antunes Meazini - 31299\n
		Rodolfo Constancio de Almeida Lage - 2016017890
		Pedro Celso Miranda Rocha Filho - 2017001769
        Tadeu Rangel Silva de Abreu - 2017011531
        Leonardo Souza Coelho - 2016015400
		 30/05/2019
*/

#include <iostream> /*!< Input e output */
#include <stdio.h> /*!< Cabeçalho padrão de entrada/saída */
#include <cstring> /*!< Standart library */
#include <cstdlib> /*!< String */
#include "CLASSE.h" /*!< Classe de criação */
#include "tinystr.h" /*!< Gerador xml */
#include "tinyxml.h" /*!< Gerador xml */
#include <vector> /*!< Vector */
using namespace std;
vector <DISCIPLINA> GRADE;

/*!
	\fn void gera_xml1()
	\brief Função de exportação XML.

	Nessa função é onde acontece todo a exportação do programa para XML.

*/
void gera_xml1()
{
    DISCIPLINA AUX;
    char curso[30];
    char sigla[3];
    char ano[5];
    char qnt_dis[5];
    cout << "DIGITE O CURSO DA GRADE: " <<endl;
    fflush(stdin);
    gets(curso);
    cout << "DIGITE A SIGLA DO CURSO: " <<endl;
    fflush(stdin);
    gets(sigla);
    cout << "DIGITE O ANO DA GRADE: " <<endl;
    fflush(stdin);
    gets(ano);
    cout << "DIGITE A QUANTIDADE DE MATERIAS DA GRADE: " << GRADE.size() << endl;
    fflush(stdin);
    gets(qnt_dis);
    /*! CONSTRUCAO DO XML*/
    TiXmlDocument doc;
    TiXmlElement* aux;
    TiXmlElement* prerequisitototal;
    TiXmlElement* prerequisitoparcial;
    TiXmlElement* coreq;
    TiXmlElement * disciplina;
    TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( decl );

    TiXmlElement * root = new TiXmlElement( "GRADE" );
    doc.LinkEndChild( root );

    TiXmlElement * cursoxml = new TiXmlElement( "CURSO" );
    cursoxml->LinkEndChild( new TiXmlText( curso ));
    root->LinkEndChild( cursoxml );

    TiXmlElement * S_curso = new TiXmlElement( "SIGLA-CURSO" );
    S_curso->LinkEndChild( new TiXmlText( sigla ));
    root->LinkEndChild( S_curso );

    TiXmlElement * anoxml = new TiXmlElement( "ANO" );
    anoxml->LinkEndChild( new TiXmlText( ano ));
    root->LinkEndChild( anoxml );

    TiXmlElement * n_dis = new TiXmlElement( "N-DIS" );
    n_dis->LinkEndChild( new TiXmlText( qnt_dis ));
    root->LinkEndChild( n_dis );

    TiXmlElement * disciplinas = new TiXmlElement( "DISCIPLINAS" );
    root->LinkEndChild( disciplinas );
    /// TALVEZ UM FOR
    for(int i=0; i<GRADE.size(); i++)
    {
    AUX.destroi();
    AUX = GRADE.at(i);
    disciplina = new TiXmlElement( "DISCIPLINA" ); /*! ABRE O DISCIPLINA*/

    aux = new TiXmlElement( "NOME" ); /*! CRIA O NOME*/
    aux->LinkEndChild( new TiXmlText( AUX.nomed )); /*! ESCREVE DENTRO DO NOME*/
    disciplina->LinkEndChild(aux); /*! FECHA O NOME*/

    aux = new TiXmlElement( "SIGLA" );
    aux->LinkEndChild( new TiXmlText( AUX.sigla ));
    disciplina->LinkEndChild(aux);

    aux = new TiXmlElement( "PERIODO" );
    aux->LinkEndChild( new TiXmlText( AUX.periodo ));
    disciplina->LinkEndChild(aux);

    aux = new TiXmlElement( "CARGA-HORARIA" );
    aux->LinkEndChild( new TiXmlText( AUX.cargaH ));
    disciplina->LinkEndChild(aux);

    if(AUX.qnt[0]!=0)
    {
        TiXmlElement * prerequisitototal = new TiXmlElement( "PRE-REQUISITO-TOTAL" ); /*! ABRE PREREQUISITO TOTAL*/

        for(int j=0; j<AUX.qnt[0]; j++)
        {
             aux = new TiXmlElement( "SIGLA" );
             aux->LinkEndChild( new TiXmlText( AUX.preTOTAL[j].s_disc));
             prerequisitototal->LinkEndChild(aux);
        }
        disciplina->LinkEndChild( prerequisitototal ); /*! FECHA PREREQUISITO TOTAL*/
    }
    if(AUX.qnt[1]!=0)
    {
        TiXmlElement * prerequisitoparcial = new TiXmlElement( "PRE-REQUISITO-PARCIAL" ); /*! ABRE PREREQUISITO PARCIAL*/

        for(int j=0; j<AUX.qnt[1]; j++)
        {
             aux = new TiXmlElement( "SIGLA" );
             aux->LinkEndChild( new TiXmlText( AUX.prePARCIAL[j].s_disc));
             prerequisitoparcial->LinkEndChild(aux);
        }
        disciplina->LinkEndChild( prerequisitoparcial ); /*!FECHA PREREQUISITO PARCIAL*/
    }
    if(AUX.qnt[2]!=0)
    {
        TiXmlElement * coreq = new TiXmlElement( "CO-REQUISITO" ); /*! ABRE CO-REQUISITO */

        for(int j=0; j<AUX.qnt[2]; j++)
        {
             aux = new TiXmlElement( "SIGLA" );
             aux->LinkEndChild( new TiXmlText( AUX.coREQ[j].s_disc));
             coreq->LinkEndChild(aux);
        }
        disciplina->LinkEndChild( coreq ); /*!FECHA CO-REQUISITO*/
    }

    disciplinas->LinkEndChild( disciplina ); /*!FECHA DISCIPLINA*/
    AUX.destroi();
    }


    doc.SaveFile( "grade.xml" );

}




int main()
{
    /*! Menu de cadastro/impressao/geração de XML */
    DISCIPLINA DIS, AUX;
    int opmenu=-1;
    do{
               cout<<"-----------------SELECIONE O ITEM PARA EDICAO---------------"<<endl;
                cout<<" 1 - CADASTRO DE DISCIPLINA : "<<endl;
                cout<<" 2 - IMPRIME DISCIPLINA : "<<endl;
                cout<<" 3 - GERA XML DA GRADE : "<<endl;
                cout<<" 7 - SAIR" << endl;
                fflush(stdin);
                cin >>opmenu;
                switch(opmenu){
                case 1: /* Caso 1 cadastro de nova disciplina*/
                    DIS.destroi();
                    DIS.edita_disciplina();
                    GRADE.push_back(DIS);
                    cout << "qnt de disciplinas  "<< GRADE.size() << endl;
                    system("pause");
                    system("cls");
                break;
                case 2:/* Caso 2 Impressão de todas disciplinas*/
                    for(int i=0; i<GRADE.size();i++)
                    {
                        AUX.destroi();
                        AUX = GRADE.at(i);
                        AUX.imprime_disciplina();
                    }
                    system("pause");
                    system("cls");
                break;
                case 3:/* Caso 3 Gera XML da grade curricular */
                    gera_xml1();
                break;
                case 7:

                break;
                default: /* Caso de invalidez */
                cout<<"OPERACAO INVALIDA!"<<endl;
                system("pause");
                system("cls");
                }
    }while(opmenu!=7);
}
