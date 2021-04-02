#include <stdio.h>

//variáveis globais
int continuar = 1; // enquanto continuar for igual a 1, o programa não vai parar

void cadastrar_estado () {

}

void cadastrar_cidade () {

}

void cadastrar_pessoa () {

}

void listarPessoas_porEstado () {

}

void listarPessoas_porCidade () {

}

void consultar_pessoa () {

}

void excluir_pessoa () {

}

void relatorio () {

}

void encerrar () {
	continuar = 0;
}

int main () {
	int opcao;

	while (continuar == 1) {
		//mostrar menu de opções
		printf ("\n---------------------------------\n");
		printf ("REGISTRO DEMOGRÁFICO DE VACINAÇÃO\n");
		printf ("---------------------------------\n\n");
		printf ("Menu de opções:\n\n");
		printf ("1) Cadastrar Estado\n");
		printf ("2) Cadastrar Cidade\n");
		printf ("3) Cadastrar Pessoa\n");
		printf ("4) Listar pessoas por Estado\n");
		printf ("5) Listar pessoas por Cidade\n");
		printf ("6) Consultar Pessoa por Nome\n");
		printf ("7) Excluir Pessoa\n");
		printf ("8) Gerar relatório de vacinação\n");
		printf ("9) Encerrar o programa\n");
		scanf ("%d", &opcao);

		//ir para os procedimentos corretos
		if (opcao == 1)
			cadastrar_estado();
		else if (opcao == 2)
			cadastrar_cidade();
		else if (opcao == 3)
			cadastrar_pessoa();
		else if (opcao == 4)
			listarPessoas_porEstado();
		else if (opcao == 5)
			listarPessoas_porCidade();
		else if (opcao == 6)
			consultar_pessoa();
		else if (opcao == 7)
			excluir_pessoa();
		else if (opcao == 8)
			relatorio();
		else if (opcao == 9)
			encerrar();
		else
			printf ("Opção Inválida\n");
	}

	return 0;
}