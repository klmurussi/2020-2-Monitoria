#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct CIDADE {
	char nome[50];
};
typedef struct CIDADE Cidade;

struct ESTADO {
	char nome[50];
	Cidade cidade[200];
};
typedef struct ESTADO Estado;

struct PAIS {
	Estado estado[50];
};
typedef struct PAIS Pais;

//variáveis globais
int continuar = 1; // enquanto continuar for igual a 1, o programa não vai parar
int numero_total = 0; // número de estados cadastrados

//função para cadastrar um NOVO estado
Pais cadastrar_estado (Pais pais) {
	int i;

	printf ("\n\n----------------\n");
	printf ("CADASTRAR ESTADO\n");
	printf ("----------------\n\n");

	Estado estado; //variável estado candidato para cadastrar

	//pedir o nome do novo estado
	printf ("Nome do Estado para cadastrar: ");
	scanf ("%s", estado.nome);

	//transformar o primeiro caracter em maiusculo e os demais em minusculo
	for (i = 0; i < strlen(estado.nome); i++) {
		if (i == 0)
			estado.nome[i] = toupper(estado.nome[i]);
		else
			estado.nome[i] = tolower(estado.nome[i]);
	}

	//analisar se esse estado já não é cadastrado
	int okay = 1; //okay igual a 1 significa que não é cadastrado

	for (i = 0; i < numero_total; i++) {
		if (strcmp (estado.nome, pais.estado[i].nome) == 0){
			okay = 0;
			printf ("Estado já cadastrado.\n");
		}
	}

	//adicionar o estado candidato ao país e acrescentar mais um no número total de estados cadastrados
	if (okay == 1) {
		strncpy(pais.estado[numero_total].nome, estado.nome, sizeof(estado.nome));
		numero_total++;
	}

	return pais;
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

	//criação de um novo país
	Pais pais;

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
			pais = cadastrar_estado(pais);
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