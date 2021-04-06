#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct PESSOA {
  char nome[50];
  int idade;
  char sexo;
  char cidade[50];
  char estado[50];
};
typedef struct PESSOA Pessoa;

struct PESSOAS {
  Pessoa pessoas[20000];
};
typedef struct PESSOAS Pessoas;

struct CIDADE {
	char nome[50];
};
typedef struct CIDADE Cidade;

struct ESTADO {
	char nome[50];
	Cidade cidades[200];
};
typedef struct ESTADO Estado;

struct PAIS {
	Estado estado[50];
};
typedef struct PAIS Pais;

//variáveis globais
int continuar = 1; // enquanto continuar for igual a 1, o programa não vai parar
int numero_total = 0; // número de estados cadastrados
int numero_pessoas = 0; //número de pessoas cadastradas
//número de cidades cadastradas em cada estado
//primeiramente zerar todas elas
int numero [50] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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

//função para cadastrar uma NOVA cidade em um estado JÁ CADASTRADO
Pais cadastrar_cidade (Pais pais) {
	int i, lugar;

	printf ("\n\n----------------\n");
	printf ("CADASTRAR CIDADE\n");
	printf ("----------------\n\n");

	Estado estado; //variável estado da cidade candidata para cadastrar

	//pedir o nome do estado
	printf ("Nome do Estado em que está localizado a Cidade: ");
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
			lugar = i;
		}
	}

	//retornar ao menu
	if (okay == 1) {
		printf ("Estado ainda não está cadastrado.\n");
		return pais;
	}

	//agora cadastrar cidade NOVA
	Cidade cidade;
	printf ("Nome do Cidade para cadastrar: ");
	scanf ("%s", cidade.nome);

	//transformar o primeiro caracter em maiusculo e os demais em minusculo
	for (i = 0; i < strlen(cidade.nome); i++) {
		if (i == 0)
			cidade.nome[i] = toupper(cidade.nome[i]);
		else
			cidade.nome[i] = tolower(cidade.nome[i]);
	}

	//analisar se essa cidade já não é cadastrada
	okay = 1; //okay igual a 1 significa que não é cadastrada

	for (i = 0; i < numero[lugar]; i++) {
		if (strcmp (cidade.nome, pais.estado[lugar].cidades[i].nome) == 0){
			okay = 0;
			printf ("Cidade já cadastrado.\n");
		}
	}

	//adicionar a cidade candidata ao estado e acrescentar mais um no número total de cidades cadastradas
	if (okay == 1) {
		strncpy(pais.estado[lugar].cidades[numero[lugar]].nome, cidade.nome, sizeof(cidade.nome));
		numero[lugar]++;
	}

	return pais;
}

Pessoas cadastrar_pessoa (Pais pais, Pessoas pessoas) {
  printf ("\n----------------\n");
  printf ("CADASTRAR PESSOA\n");
  printf ("----------------\n\n");

  Pessoa pessoa; //variável Pessoa candidata a cadastrar


  //pedir informações de Pessoa
  printf ("Nome da pessoa: ");
  scanf ("%s", pessoa.nome);

  int i;

  //transformar a primeira letra em maiuscula e as outras em minusculas
  for (i = 0; i < strlen(pessoa.nome); i++) {
		if (i == 0)
			pessoa.nome[i] = toupper(pessoa.nome[i]);
		else
			pessoa.nome[i] = tolower(pessoa.nome[i]);
	}

  do {
    printf ("Idade da pessoa: ");
    scanf ("%d", &pessoa.idade);
  } while (pessoa.idade < 0);

  do {
    printf ("Sexo (F/M): ");
    scanf ("%c", &pessoa.sexo); //apenas para limpar o buffer
    scanf ("%c", &pessoa.sexo);
  } while (pessoa.sexo != 'F' && pessoa.sexo != 'M');

  //pedir localização da pessoa
  int lugar;

	Estado estado; //variável estado da pessoa candidata para cadastrar

	//pedir o nome do estado
	printf ("Nome do Estado: ");
	scanf ("%s", estado.nome);

	//transformar o primeiro caracter em maiusculo e os demais em minusculo
	for (i = 0; i < strlen(estado.nome); i++) {
		if (i == 0)
			estado.nome[i] = toupper(estado.nome[i]);
		else
			estado.nome[i] = tolower(estado.nome[i]);
	}

	//analisar se esse estado já é cadastrado
	int okay = 1; //okay igual a 1 significa que não é cadastrado

	for (i = 0; i < numero_total; i++) {
		if (strcmp (estado.nome, pais.estado[i].nome) == 0){
			okay = 0;
			lugar = i;
		}
	}

	//retornar ao menu
	if (okay == 1) {
		printf ("Estado ainda não está cadastrado.\n");
		return pessoas;
	}

	Cidade cidade; //variável Cidade da pessoa candidata a cadastrar
	printf ("Nome do Cidade: ");
	scanf ("%s", cidade.nome);

	//transformar o primeiro caracter em maiusculo e os demais em minusculo
	for (i = 0; i < strlen(cidade.nome); i++) {
		if (i == 0)
			cidade.nome[i] = toupper(cidade.nome[i]);
		else
			cidade.nome[i] = tolower(cidade.nome[i]);
	}

	//analisar se essa cidade já é cadastrada
	okay = 1; //okay igual a 1 significa que não é cadastrada
  int cidad;

	for (i = 0; i < numero[lugar]; i++) {
		if (strcmp (cidade.nome, pais.estado[lugar].cidades[i].nome) == 0){
			okay = 0;
      cidad = i;
		}
	}

	//adicionar a pessoa candidata ao país e acrescentar mais um no número total de numero de moradores da cidade
	if (okay == 1) {
    printf ("Cidade ainda não está cadastrado.\n");
		return pessoas;
	}

  strncpy(pessoas.pessoas[numero_pessoas].nome, pessoa.nome, sizeof(pessoa.nome));
  pessoas.pessoas[numero_pessoas].idade = pessoa.idade;
  pessoas.pessoas[numero_pessoas].sexo = pessoa.sexo;
  strncpy(pessoas.pessoas[numero_pessoas].estado, estado.nome, sizeof(estado.nome));
  strncpy(pessoas.pessoas[numero_pessoas].cidade, cidade.nome, sizeof(cidade.nome));
  numero_pessoas++;
  return pessoas;
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

  //criando pessoas
  Pessoas pessoas;

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
			pais = cadastrar_cidade(pais);
		else if (opcao == 3)
		  pessoas = cadastrar_pessoa(pais, pessoas);
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