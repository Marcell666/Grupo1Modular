/***************************************************************************
*  $MCI Módulo de implementação: Módulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.C
*  Letras identificadoras:      GRC
*
*  Nome da base de software:    Fonte do módulo Corpo Docente
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruce Marcellino, BM  
*			Felipe Alfena, FA
*			Nicolas Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.  
*
*  $HA Histórico de evolução:
*     Versão  Autor 	Data     	Observações
*       0.52   BM/RP	04/10/2017	Revisão
*       0.51   BM   	04/10/2017	Revisão
*       0.50   RP   	03/10/2017	Documentação
	0.40   FA	03/10/2017	Funções busca adicionadas
*       0.30   MR   	03/10/2017	Funções de consulta/altera adicionadas 
*       0.20   BM   	02/10/2017	Funcoes modelo adicionadas 
*       0.10   BM	01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para manipular os professores na lista de corpo docente.
*     Este módulo utiliza funcões de interface do modulo professor.
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"
#include "listas.h"

/***********************************************************************
*
*  $TC Tipo de dados: corpoDocente
*
*
*  $ED Descrição do tipo
*     Estrutura principal que armazena os dados de um corpo docente ao qual este módulo se dedica.
*
***********************************************************************/

typedef struct parDisciplina{
	Disciplina *disciplina;
	List *preRequisitos;
} ParDisciplinas;

typedef struct gradeCurricular{
	List *parDisciplinas;
} GradeCurricular;


/*****  Dados encapsulados no módulo  *****/
	
static GradeCurricular *grc;
	/* instância de corpo docente armazenada por este módulo */

/***** Protótipos das funções encapsuladas no módulo *****/
// TODO retirar isto
GRC_tpCondRet buscaIdentificacao(int rgChave, char *cpfChave, int matriculaChave, char *emailChave);


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: GRC Criar Lista de Corpo Docente
*  ****/

GRC_tpCondRet GRC_cria(){
	grc = (GradeCurricular*) malloc(sizeof(CorpoDocente));
	createList(&grc->parDisciplinas);
	return GRC_CondRetOk;
}/* Fim função: GRC Criar Lista de Corpo Docente */

/***************************************************************************
*
*  Função: GRC Cadastrar Professor
*  ****/

GRC_tpCondRet GRC_cadastra(char* nome, char* codigo, int creditos, char* bibliografia, char* ementa){
	ParDisciplina *parD
	DIS_ptDisciplina disc = NULL;
	DIS_tpCondRet ret;
	if(buscaCodigo(codigo) != GRC_CondRetOk)
		return GRC_CondRetIdJaCriado;
	ret = DIS_gera_param(disc, nome, codigo, creditos, bibliografia, ementa);
	if(ret == PRF_CondRetNaoHaMemoria) return GRC_CondRetNaoHaMemoria;
	if(ret == PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	parD = (ParDisciplina*) malloc(sizeof(ParDisciplina));
	parD->disciplina = disc;
	createList(&parD->preRequisitos);
	push_back(grc->parDisciplinas, (void**) parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Cadastrar Professor */

/***********************************************************************
*
*  $FC Função: GRC Busca Identificacao
*
*  $FV Valor retornado
*     Retorna GRC_CondRetIdJaCriado caso um professor com o mesmo valor de uma das chaves seja encontrado.
*     Retorna PRF_CondRetOk caso contrário.
*
***********************************************************************/
GRC_tpCondRet buscaIdentificacao(int rgChave, char *cpfChave, int matriculaChave, char *emailChave){
	PRF_ptProfessor prof = NULL;
	char cpf[PRF_TAM_STRING];
	char email[PRF_TAM_STRING];
	int matricula;
	int rg;
	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetOk;

		PRF_consultaCpf(prof, cpf);
		PRF_consultaRg(prof, &rg);
		PRF_consultaEmail(prof, email);
		PRF_consultaMatricula(prof, &matricula);
		if(strcmp(cpfChave, cpf)==0 || strcmp(emailChave, email)==0 || rgChave == rg || matriculaChave == matricula) return GRC_CondRetIdJaCriado;
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);

	/* Não encontrou */
	return GRC_CondRetOk;
}/* Fim função: GRC Busca Atual */

/***************************************************************************
*
*  Função: GRC Mostra Atual
*  ****/

GRC_tpCondRet GRC_mostraAtual(){
	ParDisciplina parD = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_exibe(parD->disciplina);
	return GRC_CondRetOk;
}/* Fim função: GRC Mostra Atual */

 /***************************************************************************
 *
 *  Função: GRC Mosta Todos Professores
 *  ****/

GRC_tpCondRet GRC_mostraTodos(){
	ParDisciplina parD = NULL;
	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazio;
		DIS_exibe(parD->disciplina);
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);
	return GRC_CondRetOk;
}/* Fim função: GRC Mosta Todos Professores */

 /***************************************************************************
 *
 *  Função: GRC Limpa Lista
 *  ****/

GRC_tpCondRet GRC_limpa(){
	ParDisciplina *parD = NULL;
	while(pop_back(grc->parDisciplinas, (void**) &parD)==LIS_CondRetOK){
		DIS_deleta_Disciplina(&parD->disciplina);
		del(&parD->preRequisitos);
		free(parD);	
	};
	return GRC_CondRetOk;
}/* Fim função: GRC Limpa Lista */

 /***************************************************************************
 *
 *  Função: GRC Retira da Lista
 *  ****/

GRC_tpCondRet GRC_retira(){
	if(pop_cursor(grc->parDisciplinas, &parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_deleta_Disciplina(&parD->disciplina);
	del(&parD->preRequisitos);
	free(parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Retira da Lista */

 /***************************************************************************
 *
 *  Função: GRC Libera
 *  ****/

GRC_tpCondRet GRC_libera(){
	GRC_limpa();
	del(grc->parDisciplinas);
	return GRC_CondRetOk;
}/* Fim função: GRC Libera */

 /***************************************************************************
 *
 *  Função: GRC Busca Por RG
 *  ****/

GRC_tpCondRet GRC_buscaPorRg(int chave){
	PRF_ptProfessor prof = NULL;
	int rg;

	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;

		PRF_consultaRg(prof, &rg);
		if(chave == rg) 
			return GRC_CondRetOk;
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);

	return GRC_CondRetProfessorNaoEncontrado;
}/* Fim função: GRC Busca Por RG */

 /***************************************************************************
 *
 *  Função: GRC Busca Por CPF
 *  ****/
GRC_tpCondRet GRC_buscaPorCpf(char *chave){
	PRF_ptProfessor prof = NULL;
	char cpf[PRF_TAM_STRING];

	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;

		PRF_consultaCpf(prof, cpf);
		if(strcmp(chave, cpf)==0)
			return GRC_CondRetOk;
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);

	return GRC_CondRetProfessorNaoEncontrado;
}/* Fim função: GRC Busca Por CPF */

 /***************************************************************************
 *
 *  Função: GRC Busca Por Matricula
 *  ****/

GRC_tpCondRet GRC_buscaPorMatricula(int chave){
	PRF_ptProfessor prof = NULL;
	int matricula;

	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;

		PRF_consultaMatricula(prof, &matricula);
		if(chave == matricula) 
			return GRC_CondRetOk;
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);

	return GRC_CondRetProfessorNaoEncontrado;
}/* Fim função: GRC Busca Por Matricula */

 /***************************************************************************
 *
 *  Função: GRC Busca Por Email
 *  ****/

GRC_tpCondRet GRC_buscaPorEmail(char *chave){
	PRF_ptProfessor prof = NULL;
	char email[PRF_TAM_STRING];

	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;

		PRF_consultaEmail(prof, email);
		if(strcmp(chave, email)==0)
			return GRC_CondRetOk;
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);

	return GRC_CondRetProfessorNaoEncontrado;
}/* Fim função: GRC Busca Por Email */

 /***************************************************************************
 *
 *  Função: GRC Consulta Nome
 *  ****/
GRC_tpCondRet GRC_consultaNome(char *nome){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaNome(prof, nome);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Nome*/

 /***************************************************************************
 *
 *  Função: GRC Consulta RG
 *  ****/
GRC_tpCondRet GRC_consultaRg(int *rg){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaRg(prof,rg);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta RG */

 /***************************************************************************
 *
 *  Função: GRC Consulta CPF
 *  ****/
GRC_tpCondRet GRC_consultaCpf(char *cpf){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaCpf(prof, cpf);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta CPF*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Matricula
 *  ****/
GRC_tpCondRet GRC_consultaMatricula(int *matricula){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof,matricula);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Matricula*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Email
 *  ****/
GRC_tpCondRet GRC_consultaEmail(char *email){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaEmail(prof, email);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Email*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Telefone
 *  ****/
GRC_tpCondRet GRC_consultaTelefone(int *tel){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaTelefone(prof, tel);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Telefone*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Data de Nascimento
 *  ****/
GRC_tpCondRet GRC_consultaDataNascimento(int *dia, int *mes, int *ano){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaDiaNascimento(prof, dia);
	PRF_consultaMesNascimento(prof, mes);
	PRF_consultaAnoNascimento(prof, ano);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Data de Nascimento*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Endereço
 *  ****/
GRC_tpCondRet GRC_consultaEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int *numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaPais(prof,pais);
	PRF_consultaUf(prof,uf);
	PRF_consultaCidade(prof,cidade);
	PRF_consultaBairro(prof,bairro);
	PRF_consultaRua(prof,rua);
	PRF_consultaNumero(prof,numero);
	PRF_consultaComplemento(prof,complemento);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Endereço*/

 /***************************************************************************
 *
 *  Função: GRC Altera Nome
 *  ****/
GRC_tpCondRet GRC_alteraNome(char *nome){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	if(PRF_alteraNome(prof, nome)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	return GRC_CondRetOk;
}/* Fim função: GRC Altera Nome*/

 /***************************************************************************
 *
 *  Função: GRC Altera RG
 *  ****/
GRC_tpCondRet GRC_alteraRg(int rg){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(GRC_buscaPorRg(rg) == GRC_CondRetOk) return GRC_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	GRC_buscaPorMatricula(id);
	if(PRF_alteraRg(prof,rg)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	return GRC_CondRetOk;
}/* Fim função: GRC Altera RG*/

 /***************************************************************************
 *
 *  Função: GRC Altera CPF
 *  ****/
GRC_tpCondRet GRC_alteraCpf(char *cpf){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(GRC_buscaPorCpf(cpf) == GRC_CondRetOk) return GRC_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	GRC_buscaPorMatricula(id);
	if(PRF_alteraCpf(prof, cpf)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	return GRC_CondRetOk;
}/* Fim função: GRC Altera CPF*/

 /***************************************************************************
 *
 *  Função: GRC Altera Matricula
 *  ****/
GRC_tpCondRet GRC_alteraMatricula(int matricula){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(GRC_buscaPorMatricula(matricula) == GRC_CondRetOk) return GRC_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	GRC_buscaPorMatricula(id);
	if(PRF_alteraMatricula(prof, matricula)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	return GRC_CondRetOk;
}/* Fim função: GRC Altera Matricula*/

 /***************************************************************************
 *
 *  Função: GRC Altera Email
 *  ****/
GRC_tpCondRet GRC_alteraEmail(char* email){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(GRC_buscaPorEmail(email) == GRC_CondRetOk) return GRC_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	GRC_buscaPorMatricula(id);
	if(PRF_alteraEmail(prof, email)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	return GRC_CondRetOk;
}/* Fim função: GRC Altera Email*/

 /***************************************************************************
 *
 *  Função: GRC Altera Telefone
 *  ****/
GRC_tpCondRet GRC_alteraTelefone(int tel){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	if(PRF_alteraTelefone(prof, tel)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	return GRC_CondRetOk;
}/* Fim função: GRC Altera Telefone*/

 /***************************************************************************
 *
 *  Função: GRC Altera Data de Nascimento
 *  ****/
GRC_tpCondRet GRC_alteraDataNascimento(int dia, int mes, int ano){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	if(PRF_alteraDataNascimento(prof, dia, mes, ano)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	return GRC_CondRetOk;
}/* Fim função: GRC Altera Data de Nascimento*/

 /***************************************************************************
 *
 *  Função: GRC Altera Endereco
 *  ****/
GRC_tpCondRet GRC_alteraEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &prof) == LIS_CondRetListaVazia)
			return GRC_CondRetCorpoDocenteVazio;
	if(PRF_alteraPais(prof,pais)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	if(PRF_alteraUf(prof,uf)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	if(PRF_alteraCidade(prof,cidade)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	if(PRF_alteraBairro(prof,bairro)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	if(PRF_alteraRua(prof,rua)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	if(PRF_alteraNumero(prof,numero)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	if(PRF_alteraComplemento(prof,complemento)==PRF_CondRetFormatoInvalido) return GRC_CondRetFormatoInvalido;
	return GRC_CondRetOk;
}/* Fim função: GRC Altera Endereco*/
