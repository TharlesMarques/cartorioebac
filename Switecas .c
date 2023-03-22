#include <stdio.h>  //biblioteca de comunicação do usuário
#include <stdlib.h>   //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int Registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variavel/string
	printf("Digite o CPF a ser cadastrado: ");//coletando informaçoes do usuario
	scanf("%s", cpf); //%s refere-se a string
	
 	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strig
 	
 	FILE *file; // cria o arquivo
 	file = fopen(arquivo, "w"); //criar o arquivo "w" escreve
 	fprintf(file,cpf); // salvo o valor da variavel
 	fclose(file); // fecha o arquivo
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("Digite o nome a ser cadastrado: ");
 	scanf("%s",nome);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,nome);
 	fclose(file);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("Digite o sobrenome a ser cadstrado:");
 	scanf("%s",sobrenome);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,sobrenome);
 	fclose(file);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("Digite o cargo a ser cadastrado:");
 	scanf("%s",cargo);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,cargo);
 	fclose(file);
 	
 	system("pause");
 	

}
int Consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo: ");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
 
}
int Deletar()
{
	char cpf[40];
	
	printf("Digitar o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se enconta no sistema!. \n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //definindo as variáveis
    int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
        printf("### cartório da EBAC ###\n\n"); //inicio do menu
     	printf("Escolha a opção desejada do menu:\n\n");
     	printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - Sair do sistema\n");
    	printf("Opção: ");//fim do menu
	
    	scanf("%d", &opcao);//armazenddo a escolha do usuário
	
    	system("cls");//responasavel por limpar a tela
    	
    	
    	switch(opcao)//inicio da seleção do menu
    	{
    case 1:
    	Registro();//chamada de funções
		break;
		
	case 2:
		Consultar();
		break;
		
	case 3:
		Deletar();
  		break;
  		
  	case 4:
  		printf("Obrigado por utilizar o sistema!");
  		return 0;
  		break;
	
		default:
		printf("Essa opcao não está disponível!");
		system("pause");
	}//fim da seleção
}
}
		


