#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include "CLASSE.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <iostream>
#include <vector>
using namespace std;
vector <DISCIPLINA> AUXSEM;
struct SEME  //! ESTRUTURA DOS SEMESTRES
{
    char semestre[10];
    vector <DISCIPLINA> sem;
};

vector <SEME> HISTORICO; //! ESTRUTURA DO HISTORICO

void gera_xml()
{
    SEME SEMESTRE, TEST;
    DISCIPLINA AUX;
    char sigla[3];/*!< Sigla da matéria. */
    char grade[15];/*!< Grade */
    char matricula[20];/*!< Matricula da matéria. */
    char pinicio[10];/*!< periodo da matéria. */
    char patual[10];/*!< periodo atual da matéria. */
    //! INICIO INSERCAO DE DADOS
    cout << "DIGITE A SIGLA DO CURSO: " <<endl;
    fflush(stdin);
    gets(sigla);
    cout << "DIGITE A GRADE: " <<endl;
    fflush(stdin);
    gets(grade);
    cout << "DIGITE O NUMERO DE MATRICULA:  " <<  endl;
    fflush(stdin);
    gets(matricula);
    cout << "DIGITE O PERIODO INICIAL: (201X/X) " <<  endl;
    fflush(stdin);
    gets(pinicio);
    cout << "DIGITE O PERIODO ATUAL: (201X/X) " <<  endl;
    fflush(stdin);
    gets(patual);
    //! FIM INSERCAO DE DADOS

    //! CONSTRUCAO DO XML
    TiXmlDocument doc;
    TiXmlElement* aux;
    TiXmlElement* aux1;

    TiXmlElement * disciplina;

    TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
    doc.LinkEndChild( decl );

    TiXmlElement * root = new TiXmlElement( "HISTORICOCURICULAR" );
    doc.LinkEndChild( root );

    TiXmlElement * cursoxml = new TiXmlElement( "CURSO" );
    cursoxml->LinkEndChild( new TiXmlText( "ENGENHARIA DA COMPUTACAO" ));
    root->LinkEndChild( cursoxml );

    TiXmlElement * S_curso = new TiXmlElement( "SIGLACURSO" );
    S_curso->LinkEndChild( new TiXmlText( sigla ));
    root->LinkEndChild( S_curso );

    TiXmlElement * gradexml = new TiXmlElement( "GRADE" );
    gradexml->LinkEndChild( new TiXmlText( grade ));
    root->LinkEndChild( gradexml );

    TiXmlElement * matriculaxml = new TiXmlElement( "MATRICULA" );
    matriculaxml->LinkEndChild( new TiXmlText( matricula ));
    root->LinkEndChild( matriculaxml );

    TiXmlElement * pinicialxml = new TiXmlElement( "PERIODOINICIAL" );
    pinicialxml->LinkEndChild( new TiXmlText( pinicio ));
    root->LinkEndChild( pinicialxml );

    TiXmlElement * patualxml = new TiXmlElement( "PERIODOATUAL" );
    patualxml->LinkEndChild( new TiXmlText( patual ));
    root->LinkEndChild( patualxml );

    TiXmlElement * semestresxml = new TiXmlElement( "SEMESTRE" );
    root->LinkEndChild( semestresxml );

    //! TALVEZ UM FOR
    for(int i=0; i<HISTORICO.size(); i++)
    {
        SEMESTRE = TEST;
        SEMESTRE = HISTORICO.at(i);
        cout << "SEMESTRE: " << SEMESTRE.semestre << endl;
        //! criar um role
       TiXmlElement * semestrexml = new TiXmlElement( SEMESTRE.semestre );

        for(int k=0; k<SEMESTRE.sem.size(); k++)
        {
            AUX.destroi();
            AUX = SEMESTRE.sem.at(k);
            cout << "MATERIA: " << AUX.nomed << endl;


            disciplina = new TiXmlElement( "DISCIPLINA" ); //! ABRE O DISCIPLINA

            aux = new TiXmlElement( "NOME" ); //! CRIA O NOME
            aux->LinkEndChild( new TiXmlText( AUX.nomed )); //! ESCREVE DENTRO DO NOME
            disciplina->LinkEndChild(aux); //! FECHA O NOME

            aux = new TiXmlElement( "SIGLA" );
            aux->LinkEndChild( new TiXmlText( AUX.sigla ));
            disciplina->LinkEndChild(aux);

            aux = new TiXmlElement( "CARGAHORARIA" );
            aux->LinkEndChild( new TiXmlText( AUX.cargaH ));
            disciplina->LinkEndChild(aux);

            aux = new TiXmlElement( "NOTA" );
            aux->LinkEndChild( new TiXmlText( AUX.nota ));
            disciplina->LinkEndChild(aux);

            aux = new TiXmlElement( "FREQUENCIA" );
            aux->LinkEndChild( new TiXmlText( AUX.frequencia ));
            disciplina->LinkEndChild(aux);

            aux = new TiXmlElement( "SITUACAO" );
            aux->LinkEndChild( new TiXmlText( AUX.situacao ));
            disciplina->LinkEndChild(aux);

            semestrexml->LinkEndChild( disciplina ); //! FECHA DISCIPLINA
        }

        semestresxml->LinkEndChild( semestrexml ); //! FECHA DISCIPLINA
    }


    doc.SaveFile( "historico.xml" );

}




int main()
{
     /*! Menu de cadastro/impressao/geração de XML */
    DISCIPLINA DIS, AUX;
    SEME SEMESTRE, TEST;
    int opmenu=-1;
    int op=-1;
    char procurar[10];
    do
    {
        cout<<"-----------------SELECIONE O ITEM PARA EDICAO---------------"<<endl;
        cout<<" 1 - CADASTRO DE SEMESTRE : "<<endl;
        cout<<" 2 - IMPRIME SEMESTRE : "<<endl;
        cout<<" 3 - IMPRIME HISTORICO : "<<endl;
        cout<<" 4 - GERA XML HISTORICO: "<<endl;
        cout<<" 7 - SAIR" << endl;
        fflush(stdin);
        cin >>opmenu;
        switch(opmenu)
        {
        case 1: /* Caso 1 cadastro de semestre*/
            SEMESTRE = TEST;
            DIS.destroi();
            op=-1;
            cout << "DIGITE O SEMESTRE QUE DESEJA CADASTRAR: (201X/X)"<< endl;
            fflush(stdin);
            gets(SEMESTRE.semestre);
            while(op!=2)
            {
                DIS.edita_disciplina();
                SEMESTRE.sem.push_back(DIS);

                cout << "DESEJA ADICIONAR MAIS UMA DISCIPLINA? (1-SIM/2-NAO)" << endl;
                cin >> op;
            }
            HISTORICO.push_back(SEMESTRE);

            // cout << "qnt de disciplinas  "<< GRADE.size() << endl;
            system("pause");
            system("cls");
            break;
        case 2: /* Caso 1 Impressao de Semestres*/
            SEMESTRE = TEST;
            cout << "DIGITE O SEMESTRE QUE DESEJA IMPRIMIR: " << endl;
            fflush(stdin);
            gets(procurar);
            for(int j=0; j<HISTORICO.size(); j++)
            {
                SEMESTRE = HISTORICO.at(j);
                if(!strcmp(SEMESTRE.semestre,procurar))
                {
                    j= HISTORICO.size();
                }
            }
            cout << "IMPRIMINDO O SEMESTRE  " << SEMESTRE.semestre << endl;
            cout << "----------------------------------------------------" <<endl;
            DIS.destroi();
            for(int j=0; j<SEMESTRE.sem.size(); j++)
            {
                DIS = SEMESTRE.sem.at(j);
                DIS.imprime_disciplina();
                DIS.destroi();
                cout << "-----------------------------------------------" <<endl;

            }
            system("pause");
            system("cls");
            break;

        case 3: /* Caso 3 imprime grade curricular */
            cout << "IMPRIMINDO GRADE: " << endl;
            DIS.destroi();
            for(int j=0; j<HISTORICO.size(); j++)
            {
                SEMESTRE = TEST;
                SEMESTRE = HISTORICO.at(j);
                cout << "SEMESTRE: " << SEMESTRE.semestre << endl;
                for(int k=0; k<SEMESTRE.sem.size(); k++)
                {
                    DIS = SEMESTRE.sem.at(k);
                    DIS.imprime_disciplina();
                    DIS.destroi();
                    cout << "-----------------------------------------------" <<endl;
                }
            }
            system("pause");
            system("cls");
            break;

        case 4: /* Caso 3 Gera XML da grade curricular */
            gera_xml();
            break;
        case 7:

            break;
        default:/* Caso de invalidez */
            cout<<"OPERACAO INVALIDA!"<<endl;
            system("pause");
            system("cls");
        }
    }
    while(opmenu!=7);
}
