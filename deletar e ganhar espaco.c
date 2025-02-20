#include <stdio.h> // biblioteca de comunicacao com o usuario
#include <stdlib.h> // biblioteca de alocacao de espaco de memoria
#include <locale.h> // biblioteca de alocacao de texto por regiao
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() // funcao responsavel para cadastrar os usuarios no sistema
{
	// inicio criacao de variaveis / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criacao de variaveis / string

	
	printf("Digite o CPF a ser registrado: "); // coletando informacao do usuario
	scanf("%s" , cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  
	fprintf(file, ",");  // cria o arquivo e utiliza a virgula para separar o cpf, do primeiro nome
	fclose(file);
	
	printf("Digite o nome a ser registrado: "); // coletando a informacao do primeiro nome
	scanf("%s" , nome);  //%s refere-se novamente a string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); // salva o primeiro nome no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); // cria o arquivo e utiliza a virgula agora para separar o primeiro nome do sobrenome
	fclose(file);
	
	printf("Digite o sobrenome a ser registrado: "); // coletando as informacoes do sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salva o sobrenome no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); // cria o arquivo e utiliza a virgula para separar o sobrenome do cargo a ser registrado
	fclose(file);
	
	printf("Digite o cargo a ser registrado: "); // coletando as informacoes do cargo a ser registrado
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); // salva o cargo a ser registrado no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "."); // cria o arquivo e finaliza o programa
	fclose(file);
	
	system("pause");
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // essa condicao significa que se os dados nao forem encontrados ela imprime que nao foi possivel abrir o arquivo
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)  // enquanto funcao obter o conteudo ou so dados cadastrados ou seja diferente de nulo ele imprime que existe as informacoes do usuario
	{
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); // imprime para que seja digitadoo dado a ser coletado para deletar
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)  // essa condicao significa que se for nula o sistema imprime que nenhum dado ou usuario foi encontrado no sistema
	{
		printf("Usuario nao se encontra no sistema!.\n");
		system("pause");
	}
}

int main() {
    int opcao;

    setlocale(LC_ALL, "Portuguese"); // definindo a linguagem

    do {
        system("cls"); // responsavel por "limpar" a tela 

        printf("### Cartório da EBAC ###\n\n");  // inicio do menu
        printf("Escolha a opcao desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n\n");
        printf("Qual opcao voce deseja: "); // fim fo menu

        scanf("%d", &opcao); // armazenando a escolha do usuario

        switch (opcao) {   // inicio da selecao do menu
            case 1:
            registro(); // chamada de funcoes
            break;
                
            case 2:
            consulta();
            break;
            
            case 3:
            deletar();
            break;
            
			default:
            printf("Opcao invalida! Poderia tentar outra opcao para continuar?\n");
            system("pause");
            break;
            // fim da selecao
        }
    } while (opcao != 4);

    return 0;
}
