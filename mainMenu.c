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
*     1.00    Bruce	06/10/2017	Revis�o/finaliza��o
*     0.05    Bruce	05/10/2017	Modulo professor
*     0.04    Matheus   04/10/2017  	Revis�o menu
*     0.03    Bruno	02/10/2017	Menu professor
*     0.02    Fl�vio	02/10/2017  	Revis�o
*     0.01    Matheus	01/10/2017	In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa o Menu do Sistema Acad�mico a ser desenvolvido.
*     O Principal � a chamada dos modulos.
***************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

/***************************************************************************
*
*  Fun��o: MEN_menuInicial
*  ****/

int main(void)
{	
	CDO_cria();
	CDI_cria();
	MEN_menuInicial();
	return 0;
}
