#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respns�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
		
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s referefe-se a string
	
	strcpy(arquivo,cpf); //respons�vel por copiar o valor das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o aqrquivo e o "a" atualiza o arquivo
	fprintf(file,nome); // salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salva o valor da vari�vel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //salava o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o arquivo

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando inforna��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL) //cria uma condi��o caso n�o haja usu�rio cadastrado 
	{
		printf("N�o poss�vel abrir o arquivo, n�o localizado!.\n"); //se o "if" for verdade informa que n�o h� usu�rio cadastrado 
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
		
	system("pause");
	

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio foi deltado com sucesso e n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
}


int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;			
		} //fim da sele��o
	
	}	
}
