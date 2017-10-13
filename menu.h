/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Menu
*
*  Arquivo gerado:              menu.c
*  Letras identificadoras:      MEN
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acad�mico da turma 3WB
*  Gestor:  Grupo 2/ Grupo 1
*  Autores:   Bruce Marcellino
*	      Bruno Miranda Marinho
*             Fl�vio Thiago Franco Vaz
*             Jo�o Victor Cerqueira
*             Matheus Henrique Branco Zeitune
*             Vin�cius Cortat
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data			Observa��es
*     1.01    Bruce	07/10/2017	Reestrutura��o
*     1.00    Bruce	06/10/2017	Revis�o/finaliza��o
*     0.05    Bruce	05/10/2017	Modulo professor
*     0.04    Matheus   04/10/2017  	Revis�o menu
*     0.03    Bruno	02/10/2017	Menu professor
*     0.02    Fl�vio	02/10/2017  	Revis�o
*     0.01    Matheus	01/10/2017	In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa o Menu do Sistema Acad�mico a ser desenvolvido.
*     O menu � a chamada dos modulos por interface.
***************************************************************************/

/***********************************************************************
*
*  $FC Fun��o: MEN_loginAdministrativo
*
*  $ED Descri��o da fun��o
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: Rertona 1, se os dados s�o validos.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/
int MEN_loginAdministrativo();

/***********************************************************************
*
*  $FC Fun��o: MEN_loginProfessor.
*
*  $ED Descri��o da fun��o
*		Realiza a busca no corpo docente, se a matricula.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: Retorna 1, caso econtre e 0, senao.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

int MEN_loginProfessor();
/***********************************************************************
*
*  $FC Fun��o: MEN_loginAluno
*
*  $ED Descri��o da fun��o
*		Realiza a busca da matricula do aluno. (n�o implementado)
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: Rertona 1, se foi encontrado a matricula.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/


int MEN_loginAluno();

/***********************************************************************
*
*  $FC Fun��o: MEN_menuAluno
*
*  $ED Descri��o da fun��o
*		Mostra o menu Aluno.
*
***********************************************************************/

void MEN_adicionaAluno();

/***********************************************************************
*
*  $FC Fun��o: MEN_menuAluno
*
*  $ED Descri��o da fun��o
*		Mostra o menu Aluno.
*
***********************************************************************/

void MEN_modificaAluno();

/***********************************************************************
*
*  $FC Fun��o: MEN_menuProfessor
*
*  $ED Descri��o da fun��o
*		Mostra o menu Professor.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_adicionaProfessor();

/***********************************************************************
*
*  $FC Fun��o: MEN_menuProfessor
*
*  $ED Descri��o da fun��o
*		Mostra o menu Professor.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_modificaProfessor();


void MEN_menuGradeCurricular();

