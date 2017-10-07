#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "corpodiscente.h"
#include "corpoDocente.h"


typedef CDO_tpCondRet (*AlteraInt)(int);

int main(void){
	char nomeFunc[][20] ={"a Matricula", "o RG", "o Telefone"};
	AlteraInt vFunc[] ={CDO_alteraMatricula, CDO_alteraRg, CDO_alteraTelefone};
	int paramInt, opcao, i;
	CDO_tpCondRet ret;
	CDO_cria();
	CDO_cadastra( "Bruce Marcellino Souza Pereira de Andrade" , 111222333, "12345678901", 1112223, "bmMail@mail", 111222333, 11, 12, 2196, "BrasilComS", "Ra", "RioDeJaneiro", "umBairro", "AvQalquer", 666, "defrontePuc");
	do{
		for(i=0;i<3;i++)
			printf("Digite %d para alterar %s.\n", i, nomeFunc[i]);
		scanf("%d", &opcao);
		printf("Digite o novo valor para %s.", nomeFunc[opcao]);
		scanf("%d", &paramInt);
		ret = vFunc[opcao](paramInt);
		if(ret==CDO_CondRetOk)
			printf("Alteracao realizada com sucesso!\n");
		else if(ret==CDO_CondRetFormatoInvalido)
			printf("ERRO. Formato de dados invalido\n");
		else if(ret==CDO_CondRetIdJaCriado)
			printf("ERRO. Ja existe um professor com este valor de identificacao.\n");
		CDO_mostraAtual();
		
	}while(opcao!=0);

	return 0;
}

/*
int main(void)
{	
	CPF cpf;
	Data data;
	Endereco end;
	unsigned int mat;
	Aluno *aluno;
	cpf.cod = 00; cpf.dig1 = 123; cpf.dig2 = 456; cpf.dig3 = 789;
	data.ano = 1990; data.dia = 14; data.mes = 07;
	strcpy(end.bairro,"Copacabana");
	strcpy(end.cidade, "Rio de Janeiro");
	strcpy(end.estado, "RJ");
	strcpy(end.rua, "Av. Nossa Sra. de Copacabana");
	strcpy(end.comp, "1900, Apto 708");
	printf("cria:%d\n",ALU_CriaAluno(&aluno,"Outro", 1412312, &cpf, 990011223, &data, &end));
	CDI_cria();
	CDO_cria();
	CDO_cadastra( "Bruce Marcellino Souza Pereira de Andrade" , 111222333, "12345678901", 1112223, "bmMail@mail", 111222333, 11, 12, 2196, "BrasilComS", "Ra", "RioDeJaneiro", "umBairro", "AvQalquer", 666, "defrontePuc");
	CDO_mostraAtual();

	CDI_insere("Jose",1412312,&cpf, 990011223,&data,&end);
	CDI_insere("Outro", 1412312, &cpf, 990011223, &data, &end);
	CDI_imprime();
	//printf("%d\n", MAXTESTE);
	printf("getMAt:%d\n", ALU_GetMat(aluno,&mat));
	printf("mat:%d\n",mat);
	return 0;
}
*/
