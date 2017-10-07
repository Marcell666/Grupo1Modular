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
*     O meu é a chamada dos modulos por interface gráfica.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "corpodiscente.h"
#include "corpoDocente.h"
#include "aluno.h"


/***** Declarações encapsuladas pelo módulo *****/

#define MEN_TAM_STRING 80

/***********************************************************************
*
*  $FC Função: MEN_menuInicial
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
***********************************************************************/

void MEN_menuInicial()
{
	int opcao = 0;

	while(opcao != 4)
	{
		printf("\nMenu SAU\n");
		printf("\nDigite 1: ir menu Aluno");
		printf("\nDigite 2: ir menu Professor");
		printf("\nDigite 3: ir menu Administrativo");
		printf("\nDigite 4: para sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				MEN_menuAluno();
				break;
			case 2:
				system("cls");
				 MEN_menuProfessor();
				// Ir menu Professor. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				MEN_menuPAdministrativo();
				// Ir menu Administrado. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");printf("\n\nFechando programa...\n\n");
				exit(0);
				break;
			default:
				if(opcao != 4)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
}


/***********************************************************************
*
*  $FC Função: MEN_menuAluno.
*
*  $ED Descrição da função
*		Mostra o menu para o aluno.
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_menuAluno()
{
	int opcao = 0, rg, numero;
	char nome[81], cpfS[10], email[50], pais[50], rua[50], cidade[50], bairro[50], compl[20], uf[50];
	unsigned int mat, telefone, dia, mes, ano;
	Data nasc; 
	Endereco end;
	CPF cpf;

	if(MEN_loginAluno() == 1) // Se volta 1, ok.

	while(opcao != 2)
	{
		printf("\nMenu Aluno\n");
		//printf("\nDigite 1: ver disciplinas");
		//printf("\nDigite 2: ver horarios");
		//printf("\nDigite 3: ver nota");
		//printf("\nDigite 4: ver historico");
		printf("\nDigite 1: modificar dados pessoais");
		//printf("\nDigite 6: cancelar disciplina");
		//printf("\nDigite 7: trancar a faculdade");
		printf("\nDigite 2: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				printf("\nDigite o nome do aluno: \n");
				scanf(" %s", nome);
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				printf("\nDigite a telefone: \n");
				scanf("%d", &telefone);
				printf("\nDigite a data de nacimento: \n");
					printf("\ndia"); 
					printf("\nmes"); 
					printf("\nano\n"); 
					scanf("%d", &nasc.dia);
					scanf("%d", &nasc.mes);
					scanf("%d", &nasc.ano);
				while(!(nasc.dia > 0 && nasc.dia < 31 || nasc.mes > 0 && nasc.mes < 13 || nasc.ano > 1900 && nasc.ano < 2010))
				{
					printf("\nDigite a data de nacimento: \n");
					printf("\ndia"); 
					printf("\nmes"); 
					printf("\nano\n");
					scanf("%d", &nasc.dia);
					scanf("%d", &nasc.mes);
					scanf("%d", &nasc.ano);
				}
				printf("\nDigite o cpf: \n");
				scanf("%d", &cpf.dig1);
				scanf("%d", &cpf.dig2);
				scanf("%d", &cpf.dig3);
				scanf("%d", &cpf.cod);
				while(!(cpf.dig1 > 0 && cpf.dig1 < 1000 || cpf.dig2 > 0 && cpf.dig2 < 1000 || cpf.dig3 > 0 && cpf.dig3 < 1000 || cpf.cod > 0 && cpf.cod < 100))
				{
					printf("\nDigite o cpf: \n");
					scanf("%d", &cpf.dig1);
					scanf("%d", &cpf.dig2);
					scanf("%d", &cpf.dig3);
					scanf("%d", &cpf.cod);
				}
				printf("\nDigite o estado\n");
				scanf(" %s", end.estado);
				printf("\nDigite a cidade\n");
				scanf(" %s", end.cidade);
				printf("\nDigite o bairro\n");
				scanf(" %s", end.bairro);
				printf("\nDigite a rua\n");
				scanf(" %s", end.rua);
				printf("\nDigite o comp\n");
				scanf(" %s", end.comp);
				CDI_altera(mat, nome, mat, &cpf, telefone, &nasc, &end);
				break;
			default:
				if(opcao != 8)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
}

/***********************************************************************
*
*  $FC Função: MEN_loginAluno
*
*  $ED Descrição da função
*		Realiza a busca da matricula do aluno. (não implementado)
*
***********************************************************************/
/*Assertivas: Retorno da função: Rertona 1, se foi encontrado a matricula.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/
int MEN_loginAluno()
{
	int mat;

	printf("\nLogin Aluno\n");

	printf("\nDigite a matricula: ");
	scanf("%d", &mat);
	
	system("cls");
	return 1;
}

/***********************************************************************
*
*  $FC Função: MEN_loginProfessor.
*
*  $ED Descrição da função
*		Realiza a busca no corpo docente, se a matricula.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retorna 1, caso econtre e 0, senao.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/
int MEN_loginProfessor()
{
	int mat;

	printf("\nLogin Professor\n");

	printf("\nDigite a matricula: ");
	scanf("%d", &mat);
	if(CDO_buscaPorMatricula(mat) == CDO_CondRetOk)
	{
		system("cls");
		return 1;
	}

	return 0;
}

/***********************************************************************
*
*  $FC Função: MEN_menuProfessor
*
*  $ED Descrição da função
*		Mostra o menu Professor.
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_menuProfessor()
{
	int opcao = 0;

	/* variaveis usadas para corpo docente */
	int cdoInt, cdoDia, cdoMes, cdoAno;
	char cdoString[MEN_TAM_STRING];
	char cdoPais[MEN_TAM_STRING], cdoUf[MEN_TAM_STRING], cdoCidade[MEN_TAM_STRING], cdoBairro[MEN_TAM_STRING], cdoRua[MEN_TAM_STRING], cdoComplemento[MEN_TAM_STRING];
	int cdoNumero;
	CDO_tpCondRet cdoRet;

	if(MEN_loginProfessor() == 1) // Se volta 1, ok.

	while(opcao != 6)
	{
		printf("\nMenu Professor\n");
		//printf("\nDigite 1: ver disciplinas");
		//printf("\nDigite 2: ver horarios");
		//printf("\nDigite 3: ver nota");
		//printf("\nDigite 4: ver turmas");
		printf("\nDigite 1: modificar dados pessoais");
		printf("\nDigite 2: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 2:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 5:
				system("cls");
				printf("Digite a matrícula do professor que deseja modificar:\n");
				scanf("%d", &cdoInt);
				if(CDO_buscaPorMatricula(cdoInt)!=CDO_CondRetOk){
					printf("Não existe professor cadastrado com este numero de matricula %d, por favor tente novamente\n", cdoInt);
					break;
				}
				
				printf("\nModificando Professor\n");
				printf("\nDigite 1: alterar nome");
				printf("\nDigite 2: alterar Rg");
				printf("\nDigite 3: alterar CPF");
				printf("\nDigite 4: alterar matricula");
				printf("\nDigite 5: alterar email");
				printf("\nDigite 6: alterar Telefone");
				printf("\nDigite 7: alterar data de nascimento\n");
				printf("\nDigite 8: alterar endereco\n");
				printf("\nDigite 9: sair\n");

				CDO_mostraAtual();
				scanf("%d", &opcao);
				switch(opcao){
					case 1:
						printf("digite o novo nome\n");
						scanf(" %s", cdoString);
						cdoRet = CDO_alteraNome(cdoString);
						if(cdoRet!=CDO_CondRetOk){
							printf("Erro.\n");
							if(cdoRet==CDO_CondRetFormatoInvalido)
								printf("Formato de dados nao suportado.\n");
								
							else if(cdoRet==CDO_CondRetIdJaCriado)
								printf("Já existe outro professor com esse valor de identificacao.\n Não pode haver dois professores com o mesmo valor de identificacao\n");
							break;
						}
						printf("Nome alterado com sucesso!\n");
						break;
					case 2:
						printf("digite o novo RG\n");
						scanf("%d", &cdoInt);
						cdoRet = CDO_alteraRg(cdoInt);
						if(cdoRet!=CDO_CondRetOk){
							printf("Erro.\n");
							if(cdoRet==CDO_CondRetFormatoInvalido)
								printf("Formato de dados nao suportado.\n");
								
							else if(cdoRet==CDO_CondRetIdJaCriado)
								printf("Já existe outro professor com esse valor de identificacao.\n Não pode haver dois professores com o mesmo valor de identificacao\n");
							break;
						}
						printf("RG alterado com sucesso!\n");
						break;
					case 3:
						printf("digite o novo CPF\n");
						scanf(" %s", cdoString);
						cdoRet = CDO_alteraCpf(cdoString);
						if(cdoRet!=CDO_CondRetOk){
							printf("Erro.\n");
							if(cdoRet==CDO_CondRetFormatoInvalido)
								printf("Formato de dados nao suportado.\n");
								
							else if(cdoRet==CDO_CondRetIdJaCriado)
								printf("Já existe outro professor com esse valor de identificacao.\n Não pode haver dois professores com o mesmo valor de identificacao\n");
							break;
						}
						printf("Rg alterado com sucesso!\n");
						break;
					case 4:
						printf("digite a nova matricula\n");
						scanf("%d", &cdoInt);
						cdoRet = CDO_alteraMatricula(cdoInt);
						if(cdoRet!=CDO_CondRetOk){
							printf("Erro.\n");
							if(cdoRet==CDO_CondRetFormatoInvalido)
								printf("Formato de dados nao suportado.\n");
								
							else if(cdoRet==CDO_CondRetIdJaCriado)
								printf("Já existe outro professor com esse valor de identificacao.\n Não pode haver dois professores com o mesmo valor de identificacao\n");
							break;
						}
						printf("Matricula alterada com sucesso!\n");
						break;
					case 5:
						printf("digite o novo email\n");
						scanf(" %s", cdoString);
						cdoRet = CDO_alteraEmail(cdoString);
						if(cdoRet!=CDO_CondRetOk){
							printf("Erro.\n");
							if(cdoRet==CDO_CondRetFormatoInvalido)
								printf("Formato de dados nao suportado.\n");
								
							else if(cdoRet==CDO_CondRetIdJaCriado)
								printf("Já existe outro professor com esse valor de identificacao.\n Não pode haver dois professores com o mesmo valor de identificacao\n");
							break;
						}
						printf("Email alterado com sucesso!\n");
						break;
					case 6:
						printf("digite o novo telefone\n");
						scanf("%d", &cdoInt);
						cdoRet = CDO_alteraTelefone(cdoInt);
						if(cdoRet!=CDO_CondRetOk){
							printf("Erro.\n");
							if(cdoRet==CDO_CondRetFormatoInvalido)
								printf("Formato de dados nao suportado.\n");
								
							else if(cdoRet==CDO_CondRetIdJaCriado)
								printf("Já existe outro professor com esse valor de identificacao.\n Não pode haver dois professores com o mesmo valor de identificacao\n");
							break;
						}
						printf("Telefone alterado com sucesso!\n");
						break;
					case 7:
						printf("digite a data de nascimento no formato dd/mm/aa\n");
						scanf("%d/%d/%d", &cdoDia, &cdoMes, &cdoAno);
						cdoRet = CDO_alteraDataNascimento(cdoDia, cdoMes, cdoAno);
						if(cdoRet!=CDO_CondRetOk){
							printf("Erro.\n");
							if(cdoRet==CDO_CondRetFormatoInvalido)
								printf("Formato de dados nao suportado.\n");
								
							else if(cdoRet==CDO_CondRetIdJaCriado)
								printf("Já existe outro professor com esse valor de identificacao.\n Não pode haver dois professores com o mesmo valor de identificacao\n");
							break;
						}
						printf("Data alterada com sucesso!\n");
						break;
					case 8:
						printf("Modificando Endereco,\n");
						printf("digite o novo Pais:\n");
						scanf(" %s", cdoPais);
						printf("digite o novo UF:\n");
						scanf(" %s", cdoUf);
						printf("digite a nova Cidade:\n");
						scanf(" %s", cdoCidade);
						printf("digite o novo Bairro:\n");
						scanf(" %s", cdoBairro);
						printf("digite a nova Rua:\n");
						scanf(" %s", cdoRua);
						printf("digite o novo Numero:\n");
						scanf(" %d", &cdoNumero);
						printf("digite o novo Complemento:\n");
						scanf(" %s", cdoComplemento);
						cdoRet = CDO_alteraEndereco(cdoPais, cdoUf, cdoCidade, cdoBairro, cdoRua, cdoNumero, cdoComplemento);
						if(cdoRet!=CDO_CondRetOk){
							printf("Erro.\n");
							if(cdoRet==CDO_CondRetFormatoInvalido)
								printf("Formato de dados nao suportado.\n");
								
							else if(cdoRet==CDO_CondRetIdJaCriado)
								printf("Já existe outro professor com esse valor de identificacao.\n Não pode haver dois professores com o mesmo valor de identificacao\n");
							break;
						}
						printf("Endereco alterado com sucesso!\n");
						break;
					default:
						if(opcao != 9)
						{
							system("cls");
							printf("\n\nOPCAO INVALIDA!!!!!\n\n");
						}
						break;
					
				}
				break;
			default:
				if(opcao != 6)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}

}

/***********************************************************************
*
*  $FC Função: MEN_menuPAdministrativo
*
*  $ED Descrição da função
*		Mostra o menu Administrativo.
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_menuPAdministrativo()
{
	int opcao = 0, rg, numero;
	char nome[81], cpfS[10], email[50], pais[50], rua[50], cidade[50], bairro[50], compl[20], uf[50];
	unsigned int mat, telefone, dia, mes, ano;
	Data nasc; 
	Endereco end;
	CPF cpf;

	if(MEN_loginAdministrativo() == 1) // Se volta 1, ok.
	{
	while(opcao != 11)
	{
		printf("\nMenu Administrativo\n");
		printf("\nDigite 1: ver corpo discente");//ok
		printf("\nDigite 2: ver corpo docente");//ok
		//printf("\nDigite 3: ver disciplina");
		//printf("\nDigite 4: ver criterio de aprovacao");
		printf("\nDigite 3: adicionar aluno");//ok
		printf("\nDigite 4: deletar aluno");
		printf("\nDigite 5: adicionar professor");//ok
		printf("\nDigite 6: deletar professor");//ok
		//printf("\nDigite 9: deletar sala");
		//printf("\nDigite 10: adicionar sala");
		//printf("\nDigite 11: deletar turma");
		//printf("\nDigite 12: adicionar turma");
		//printf("\nDigite 13: modificar grade");
		printf("\nDigite 7: modificar dados pessoais de um aluno");//ok
		printf("\nDigite 8: modificar dados pessoais de um professor");
		printf("\nDigite 9: limpa corpo discente");
		printf("\nDigite 10: limpa corpo docente");
		printf("\nDigite 11: sair\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				//mostra alunos
				system("cls");
				CDI_imprime();
				break;
			case 2:
				//mostra professores
				system("cls");
				CDO_mostraTodos();
				break;
			case 3:
				//adiciona aluno
				system("cls");
				printf("\nDigite o nome do aluno: \n");
				scanf(" %s", nome);
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				printf("\nDigite a telefone: \n");
				scanf("%d", &telefone);
				printf("\nDigite a data de nacimento: \n");
					printf("\ndia"); 
					printf("\nmes"); 
					printf("\nano\n");
				scanf("%d", &nasc.dia);
				scanf("%d", &nasc.mes);
				scanf("%d", &nasc.ano);
				while(!(nasc.dia > 0 && nasc.dia < 31 || nasc.mes > 0 && nasc.mes < 13 || nasc.ano > 1900 && nasc.ano < 2010))
				{
					printf("\nDigite a data de nacimento: \n");
					printf("\ndia"); 
					printf("\nmes"); 
					printf("\nano\n");
					scanf("%d", &nasc.dia);
					scanf("%d", &nasc.mes);
					scanf("%d", &nasc.ano);
				}
				printf("\nDigite o cpf: \n");
				scanf("%d", &cpf.dig1);
				scanf("%d", &cpf.dig2);
				scanf("%d", &cpf.dig3);
				scanf("%d", &cpf.cod);
				while(!(cpf.dig1 > 0 && cpf.dig1 < 1000 || cpf.dig2 > 0 && cpf.dig2 < 1000 || cpf.dig3 > 0 && cpf.dig3 < 1000 || cpf.cod > 0 && cpf.cod < 100))
				{
					printf("\nDigite o cpf: \n");
					scanf("%d", &cpf.dig1);
					scanf("%d", &cpf.dig2);
					scanf("%d", &cpf.dig3);
					scanf("%d", &cpf.cod);
				}
				printf("\nDigite o estado\n");
				scanf(" %s", end.estado);
				printf("\nDigite a cidade\n");
				scanf(" %s", end.cidade);
				printf("\nDigite o bairro\n");
				scanf(" %s", end.bairro);
				printf("\nDigite a rua\n");
				scanf(" %s", end.rua);
				printf("\nDigite o comp\n");
				scanf(" %s", end.comp);
				CDI_insere(nome, mat, &cpf, telefone, &nasc, &end);

				break;
			case 4:
				//remove aluno
				system("cls");
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				CDI_remove(mat);
				break;
			case 5:
				//Adiciona professor
				system("cls");
				printf("\nDigite o nome do professor: \n");
				scanf(" %s", nome);
				printf("\nDigite o rg: \n");
				scanf("%d", &rg);
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				printf("\nDigite a telefone: \n");
				scanf("%d", &telefone);
				printf("\nDigite a data de nacimento: \n");
				printf("Dia: \n");
				scanf("%d", &dia);
				printf("Mes: \n");
				scanf("%d", &mes);
				printf("Ano: \n");
				scanf("%d", &ano);
				while(!(dia > 0 && dia < 31 || mes > 0 && mes < 13 || ano > 1900 && ano < 2010))
				{
					printf("\nDigite a data de nacimento: \n");
					printf("\ndia"); 
					printf("\nmes"); 
					printf("\nano\n");
					scanf("%d", &dia);
					scanf("%d", &mes);
					scanf("%d", &ano);
				}
				printf("\nDigite o pais: \n");
				scanf(" %s", pais);
				printf("\nDigite o cpf: \n");
				scanf(" %s", cpfS);
				printf("\nDigite o email: \n");
				scanf(" %s", email);
				printf("\nDigite o estado\n");
				scanf(" %s", uf);
				printf("\nDigite a cidade\n");
				scanf(" %s", cidade);
				printf("\nDigite o bairro\n");
				scanf(" %s", bairro);
				printf("\nDigite a rua\n");
				scanf(" %s", rua);
				printf("\nDigite a numero\n");
				scanf("%d", &numero);
				printf("\nDigite o comp\n");
				scanf(" %s", compl);
				if(CDO_cadastra(nome, rg, cpfS, mat, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, compl)==CDO_CondRetFormatoInvalido){ 
					printf("nao foi possivel cadastrar, formato invalido\n");
					printf("%s, %d, %s, %d, %s, %d, %d, %d, %d, %s, %s, %s, %s, %s, %d, %s\n", nome, rg, cpfS, mat, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, compl);
				}
				CDO_cadastra(nome, rg, cpfS, mat, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, compl);
				break;
			case 6:
				//retira porfessor
				system("cls");
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				CDO_buscaPorMatricula(mat);
				CDO_mostraAtual();
				CDO_retira();
				break;
			case 7:
				//Altera aluno
				system("cls");
				printf("\nDigite o nome do aluno: \n");
				scanf(" %s", nome);
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				printf("\nDigite a telefone: \n");
				scanf("%d", &telefone);
				printf("\nDigite a data de nacimento: \n");
				scanf("%d", &nasc.dia);
				scanf("%d", &nasc.mes);
				scanf("%d", &nasc.ano);
				while(!(nasc.dia > 0 && nasc.dia < 31 || nasc.mes > 0 && nasc.mes < 13 || nasc.ano > 1900 && nasc.ano < 2010))
				{
					printf("\nDigite a data de nacimento: \n");
					printf("\ndia"); 
					printf("\nmes"); 
					printf("\nano\n");
					scanf("%d", &nasc.dia);
					scanf("%d", &nasc.mes);
					scanf("%d", &nasc.ano);
				}
				printf("\nDigite o cpf: \n");
				scanf("%d", &cpf.dig1);
				scanf("%d", &cpf.dig2);
				scanf("%d", &cpf.dig3);
				scanf("%d", &cpf.cod);
				while(!(cpf.dig1 > 0 && cpf.dig1 < 1000 || cpf.dig2 > 0 && cpf.dig2 < 1000 || cpf.dig3 > 0 && cpf.dig3 < 1000 || cpf.cod > 0 && cpf.cod < 100))
				{
					printf("\nDigite o cpf: \n");
					scanf("%d", &cpf.dig1);
					scanf("%d", &cpf.dig2);
					scanf("%d", &cpf.dig3);
					scanf("%d", &cpf.cod);
				}
				printf("\nDigite o estado\n");
				scanf(" %s", end.estado);
				printf("\nDigite a cidade\n");
				scanf(" %s", end.cidade);
				printf("\nDigite o bairro\n");
				scanf(" %s", end.bairro);
				printf("\nDigite a rua\n");
				scanf(" %s", end.rua);
				printf("\nDigite o comp\n");
				scanf(" %s", end.comp);
				CDI_altera(mat, nome, mat, &cpf, telefone, &nasc, &end);
				break;
			case 8:
				//Altera professor
				system("cls");
				
				printf("\nDigite a matricula\n");
				scanf("%d", &mat);
				//busca
				CDO_buscaPorMatricula(mat);
				CDO_mostraAtual();

				//depopis
				printf("\nDigite o nome do professor: \n");
				scanf(" %s", nome);
				printf("\nDigite o rg: \n");
				scanf("%d", &rg);
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				printf("\nDigite a telefone: \n");
				scanf("%d", &telefone);
				printf("\nDigite a data de nacimento: \n");
				scanf("%d", &dia);
				scanf("%d", &mes);
				scanf("%d", &ano);
				while(!(dia > 0 && dia < 31 || mes > 0 && mes < 13 || ano > 1900 && ano < 2010))
				{
					printf("\nDigite a data de nacimento: \n");
					printf("\ndia"); 
					printf("\nmes"); 
					printf("\nano\n");
					scanf("%d", &dia);
					scanf("%d", &mes);
					scanf("%d", &ano);
				}
				printf("\nDigite o cpf: \n");
				scanf(" %s", cpfS);
				printf("\nDigite o email: \n");
				scanf(" %s", email);
				printf("\nDigite o estado\n");
				scanf(" %s", uf);
				printf("\nDigite a cidade\n");
				scanf(" %s", cidade);
				printf("\nDigite o bairro\n");
				scanf(" %s", bairro);
				printf("\nDigite a rua\n");
				scanf(" %s", rua);
				printf("\nDigite a numero\n");
				scanf("%d", &numero);
				printf("\nDigite o comp\n");
				scanf(" %s", compl);
				CDO_alteraNome(nome);
				CDO_alteraRg(rg);
				CDO_alteraCpf(cpfS);
				CDO_alteraMatricula(mat);
				CDO_alteraEmail(email);
				CDO_alteraTelefone(telefone);
				CDO_alteraDataNascimento(dia, mes, ano);
				CDO_alteraEndereco(pais, uf, cidade, bairro, rua, numero, compl);
				break;
			case 9:
				CDI_limpa();
				break;
			case 10:
				CDO_libera();
				break;
			default:
				if(opcao != 11)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}
	}else
	{
		printf("\nErro no login\n");
	}
	system("cls");
}

/***********************************************************************
*
*  $FC Função: MEN_loginAdministrativo
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

int MEN_loginAdministrativo()
{
	char user[81];
	char senha[81];
	printf("\nLogin Administrador\n");

	printf("\nDigite a user: ");
	scanf(" %s", user);

	printf("\nDigite a senha: ");
	scanf(" %s", senha);

	if(strcmp("admin", user) == 0 && strcmp("admin", senha) == 0 )
	{
		system("cls");
		return 1;
	}

	system("cls");
	return 0;
}

