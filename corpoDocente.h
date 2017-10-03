/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.h
*  Letras identificadoras:      CDO
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
*     Versão	Autor		Data		Observações
*       0.01   BM   02/10/2017	Funcoes modelo adicionadas 
*       0.00   BM   01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*	  TODO
*
***************************************************************************/
typedef enum{
	CDO_CondRetOk
} CDO_tpCondRet;


typedef struct corpoDocente CorpoDocente;

CDO_tpCondRet CDO_cria();
CDO_tpCondRet CDO_cadastra(char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);
CDO_tpCondRet CDO_mostraAtual();
CDO_tpCondRet CDO_mostraTodos();
CDO_tpCondRet CDO_retira();
CDO_tpCondRet CDO_limpa();
CDO_tpCondRet CDO_libera();
CDO_tpCondRet CDO_alteraNome(char *nome);
CDO_tpCondRet CDO_consultaNome(char *nome);
CDO_tpCondRet CDO_buscaNome(char *chave);
