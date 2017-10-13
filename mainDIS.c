// RODAR ESSE ARQUIVO, INCREMENTANDO ELE, CADA VEZ QUE TIVER UMA NOVA FUNÇAO!!!
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"

int main(void){
  Disciplina *dis=NULL;
  char *msg = NULL;
  int creditos;
  DIS_tpCondRet ret;
  
  ret = DIS_gera_param(&dis, "blabla","1234", 4, "bleble", "blibli");

  ret = DIS_exibe(dis);

  ret = DIS_get_nome(dis,&msg);
  printf("NOME%d: %s\n", ret, msg);
  free(msg);
  
  ret = DIS_get_ementa(dis,&msg);
  printf("EMENTA%d: %s\n", ret, msg);
  free(msg);
  
//  printf("CREDITOS: %d\n",cred);

  ret = DIS_get_codigo(dis, &msg);
  printf("CODIGO%d: %s\n", ret, msg);
  free(msg);

  ret = DIS_get_bibliografia(dis,&msg);
  printf("BIBLIOGRAFIA %d: %s\n", ret, msg);
  free(msg);
  ret = DIS_deleta_Disciplina(&dis);
  ret = DIS_exibe(dis);

  return 0;
}
