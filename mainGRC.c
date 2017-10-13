#include <stdio.h>
#include <stdlib.h>
#include "gradeCurricular.h"

int main(void){
	char nome[80];
	GRC_tpCondRet ret;
	ret = GRC_cria();
	ret = GRC_cadastra( "Modular" , "INF1301", 4, "Programacao Modular, Ardt Von Stadt", "NaoVouEscrever muito pois o LimiteE curto");
	ret = GRC_cadastra( "Prog2" , "INF1007", 4, "C para idiotas", "Listas, ordenacao e TAD");
	printf("adicionar preReq\n");
	printf("preReq %d\n", GRC_inserePreRequisito("INF1007"));
	printf("preReq %d\n", GRC_inserePreRequisito("INF1007"));
	printf("preReq %d\n", GRC_inserePreRequisito("INF1007"));
	ret = GRC_mostraTodas();
	printf("retF %d\n", ret);
	printf("retNome %d\n", GRC_consultaNome(nome));
	printf("%s\n", nome);
	GRC_limpa();
	GRC_libera();
	printf("FIM\n");
	return 0;
}
