/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Menu
*
*  Arquivo gerado:              menu.c
*  Letras identificadoras:      MEN
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 2/ Grupo 1
*  Autores:   Bruce Marcellino
*	      Bruno Miranda Marinho
*             Flávio Thiago Franco Vaz
*             João Victor Cerqueira
*             Matheus Henrique Branco Zeitune
*             Vinícius Cortat
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data			Observações
*     1.00    Bruce	06/10/2017	Revisão/finalização
*     0.05    Bruce	05/10/2017	Modulo professor
*     0.04    Matheus   04/10/2017  	Revisão menu
*     0.03    Bruno	02/10/2017	Menu professor
*     0.02    Flávio	02/10/2017  	Revisão
*     0.01    Matheus	01/10/2017	Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa o Menu do Sistema Acadêmico a ser desenvolvido.
*     O Principal é a chamada dos modulos.
***************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

/***************************************************************************
*
*  Função: MEN_menuInicial
*  ****/

int main(void)
{	
	CDO_cria();
	CDI_cria();
	MEN_menuInicial();
	return 0;
}
