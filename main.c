#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct PESSOA {
  char nome[50];
  int idade;
  char sexo;
  char cidade[50];
  char estado[50];
};
typedef struct PESSOA Pessoa;

struct PESSOAS {
  Pessoa pessoas[14292];
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

//função para carregar os dados do arquivo pais.txt para a struct pais
Pais carregar_pais (Pais pais) {
  FILE *pont_pais; //ponteiro para o arquivo pais
  char str_text[100];
  int i, j, num;

  pont_pais = fopen ("pais.txt", "r"); //abrir arquivo pais.txt em modo de leitura

  if (pont_pais != NULL) { //se o arquivo existir
    fgets (str_text, 100, pont_pais); //ler a primeira linha, ou seja, quantos estados foram cadastrados
    numero_total = atoi(str_text);
    for (i = 0; i < numero_total; i++) { //ler os estados cadastrados
      fgets(str_text, 50, pont_pais);
      strncpy(pais.estado[i].nome, str_text,  strlen(str_text) -1 );
      fgets(str_text, 50, pont_pais); //ler quantas cidades cadastradas nesse estado
      numero[i] = atoi(str_text);
      for (j = 0; j < numero[i]; j++) { //ler as cidades cadastradas
        fgets(str_text, 50, pont_pais);
        strncpy(pais.estado[i].cidades[j].nome, str_text, strlen(str_text) -1 );
      }
    }
  }

  fclose (pont_pais); //fechar o arquivo pais
  return pais;
}

void atualizar_arquivo (Pais pais, Pessoas pessoas) {
  printf ("a");
  FILE *pont_pais; //ponteiro para arquivo pais
  FILE *pont_pessoas; //ponteiro para arquivo pessoas


  pont_pais = fopen ("pais.txt", "w"); //abrir aquivo pais.txt para escrita
  pont_pessoas = fopen ("pessoas.txt", "w"); //abrir aquivo pessoas.txt para escrita

  //pegar todas as informações guardadas na struct pais e armazenas no arquivo pais.txt
  int i, j;
  fprintf (pont_pais, "%d\n", numero_total); //printar o número total de estados cadastrados no arquivo
  for (i = 0; i < numero_total; i++) { 
    fprintf (pont_pais, "%s\n", pais.estado[i].nome); //printar o nome do estado no arquivo
    fprintf (pont_pais, "%d\n", numero[i]); //printar a quantidade de cidades desse estado no arquivo
    for (j = 0; j < numero[i]; j++) {
      fprintf (pont_pais, "%s\n", pais.estado[i].cidades[j].nome); //printar as cidades no arquivo
    } 
  } 

  //pegar todas as informações guardadas na struct pessoas e armazenar no arquivo pessoas.txt
  fprintf (pont_pessoas, "%d\n", numero_pessoas); //número total de pessoas cadastradas
  for (i = 0; i < numero_pessoas; i++) {
    
  }

  fclose (pont_pais); //fechar arquivo pais
  fclose (pont_pessoas); //fechar arquivo pessoas
}

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

	//transformar tudo em minusculo
	for (i = 0; i < strlen(estado.nome); i++) {
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

	//transformar tudo em minusculo
	for (i = 0; i < strlen(estado.nome); i++) {
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

	//transformar tudo em minusculo
	for (i = 0; i < strlen(cidade.nome); i++) {
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

//função para cadastrar pessoa
Pessoas cadastrar_pessoa (Pais pais, Pessoas pessoas) {
  printf ("\n----------------\n");
  printf ("CADASTRAR PESSOA\n");
  printf ("----------------\n\n");

  Pessoa pessoa; //variável Pessoa candidata a cadastrar


  //pedir informações de Pessoa
  int i;
  char letra;
  printf ("Nome da pessoa: ");
  scanf ("%s", pessoa.nome);

  //transformar tudo em minusculas
  for (i = 0; i < strlen(pessoa.nome); i++) {
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
  } while (pessoa.sexo != 'F' && pessoa.sexo != 'M' && pessoa.sexo != 'f' && pessoa.sexo != 'm');

  //pedir localização da pessoa
  int lugar;

	Estado estado; //variável estado da pessoa candidata para cadastrar

	//pedir o nome do estado
	printf ("Nome do Estado: ");
	scanf ("%s", estado.nome);

	//transformar tudo em minusculo
	for (i = 0; i < strlen(estado.nome); i++) {
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

	//transformar tudo em minusculo
	for (i = 0; i < strlen(cidade.nome); i++) {
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

//função para mostrar todas as pessoas de um certo Estado
void listarPessoas_porEstado (Pais pais, Pessoas pessoas) {
  printf ("\n\n-------------------------\n");
  printf ("Listar Pessoas por Estado\n");
  printf ("-------------------------\n\n");

  //pedir informações do estado
  char estado[50];
  printf ("Nome do Estado: ");
  scanf ("%s", estado);

  //transformar tudo em minusculo
  int i;
	for (i = 0; i < strlen(estado); i++) {
			estado[i] = tolower(estado[i]);
	}

  //verificação se o estado é cadastrado
  int okay = 1; //okay igual a 1 significa que não é cadastrado
  int lugar; //irá armazenar a posição do estado pesquisado no vetor

	for (i = 0; i < numero_total; i++) {
		if (strcmp (estado, pais.estado[i].nome) == 0){
			okay = 0;
			lugar = i;
		}
	}

	//retornar ao menu
	if (okay == 1) {
		printf ("Estado ainda não está cadastrado.\n");
		return;
	}

  for (i = 0; i < numero_pessoas; i++) {
    if (strcmp(estado, pessoas.pessoas[i].estado) == 0)
      printf ("%s\n", pessoas.pessoas[i].nome);
  }

  return;
}

//função para mostrar todas as pessoas de uma certa Cidade
void listarPessoas_porCidade (Pais pais, Pessoas pessoas) {
  printf ("\n\n-------------------------\n");
  printf ("Listar Pessoas por Cidade\n");
  printf ("-------------------------\n\n");

  //pedir informações do estado
  char estado[50];
  printf ("Nome do Estado: ");
  scanf ("%s", estado);

  //transformar tudo em minusculo
  int i;
	for (i = 0; i < strlen(estado); i++) {
			estado[i] = tolower(estado[i]);
	}

  //verificação se o estado é cadastrado
  int okay = 1; //okay igual a 1 significa que não é cadastrado
  int lugar; //irá armazenar a posição do estado pesquisado no vetor

	for (i = 0; i < numero_total; i++) {
		if (strcmp (estado, pais.estado[i].nome) == 0){
			okay = 0;
			lugar = i;
		}
	}

	//retornar ao menu
	if (okay == 1) {
		printf ("Estado ainda não está cadastrado.\n");
		return;
	}

  //pedir informações da cidade
  char cidade[50];
  printf ("Nome da Cidade: ");
  scanf ("%s", cidade);

  //transformaro tudo em minusculo
	for (i = 0; i < strlen(cidade); i++) {
			cidade[i] = tolower(cidade[i]);
	}

  //verificação se a cidade é cadastrada
  int posicao; //irá armazenar a posição da cidade pesquisada no vetor

	for (i = 0; i < numero[lugar]; i++) {
		if (strcmp (cidade, pais.estado[lugar].cidades[i].nome) == 0){
			okay = 0;
      posicao = i;
		}
	}

	//retornar ao menu
	if (okay == 1) {
		printf ("Cidade ainda não está cadastrada.\n");
		return;
	}

  for (i = 0; i < numero_pessoas; i++) {
    if (strcmp(cidade, pessoas.pessoas[i].cidade) == 0) {
      if (strcmp (estado, pessoas.pessoas[i].estado) == 0)
        printf ("%s\n", pessoas.pessoas[i].nome);
    }
  }

  return;
}

//função para pesquisar pessoas por parte do nome
void consultar_pessoa (Pessoas pessoas) {
  printf ("\n\n----------------\n");
  printf ("Consultar Pessoa\n");
  printf ("----------------\n\n");

  //pedir parte do nome
  char parte[50];
  printf ("Parte do nome: ");
  scanf ("%s", parte);

  //trasnformar tudo em minusculo
  int i;
  for (i = 0; i < strlen (parte); i++)
    parte[i] = tolower(parte[i]);

  //analisar os nomes
  int j, k = 0, okay = 1;

  for (i = 0; i < numero_pessoas; i++) { //pecorrer o vetor pessoas.pessoas
    for (j = 0; j < strlen (pessoas.pessoas[i].nome); j++) { // pecorrer o vetor pessoas.pessoa[i].nome
      if (pessoas.pessoas[i].nome[j] == parte[k]) { 
        k++; 
      }
      else
        k = 0;
      if (k == (strlen (parte) - 1))
        okay = 0;
    }
    
    if (okay == 0) {
      printf ("\nNome: %s - ", pessoas.pessoas[i].nome);
      printf ("Idade: %d - ", pessoas.pessoas[i].idade);
      printf ("Sexo: %c - ", pessoas.pessoas[i].sexo);
      printf ("Cidade: %s - ", pessoas.pessoas[i].cidade);
      printf ("Estado: %s\n", pessoas.pessoas[i].estado);
    }

    okay = 1;
    k = 0;
  }

  return;
}

//função para excluir pessoa
Pessoas excluir_pessoa (Pessoas pessoas) {
	printf ("\n\n----------------\n");
	printf ("Excluir Pessoa\n");
	printf ("----------------\n\n");

	//pedir nome
	char nome[50];
	printf ("Nome: ");
	scanf ("%s", nome);

	//trasnformar tudo em minusculo
	int i;
	for (i = 0; i < strlen (nome); i++)
		nome[i] = tolower(nome[i]);

	//analisar os nomes
	int okay = 1; //okay igual a um significa que não foi cadastrado nenhum nome assim
	int contador = 1; //numero de pessoas com esse nome

	for (i = 0; i < numero_pessoas; i++) {
		if (strcmp (nome, pessoas.pessoas[i].nome) == 0){
			okay = 0;
			printf ("\n%d) ", contador);
			contador++;
			printf ("Nome: %s - ", pessoas.pessoas[i].nome);
			printf ("Idade: %d - ", pessoas.pessoas[i].idade);
			printf ("Sexo: %c - ", pessoas.pessoas[i].sexo);
			printf ("Cidade: %s - ", pessoas.pessoas[i].cidade);
			printf ("Estado: %s\n", pessoas.pessoas[i].estado);
		}
	}

	int escolha;
	char nada[4] = "nada";
	contador = 1;
	if (okay == 0) {
		printf ("\nQual deseja excluir?");
		scanf ("%d", &escolha);
		for (i = 0; i < numero_pessoas; i++) {
			if (strcmp (nome, pessoas.pessoas[i].nome) == 0){
				if (contador == escolha) {
					printf ("ok");
					strncpy(pessoas.pessoas[i].nome, nada, sizeof(nada));
				  pessoas.pessoas[i].idade = 0;
				  pessoas.pessoas[i].sexo = 'N';
				  strncpy(pessoas.pessoas[i].estado, nada, sizeof(nada));
				  strncpy(pessoas.pessoas[i].cidade, nada, sizeof(nada));
          numero_pessoas--;
				}
				contador++;
			}
		}
	}
  return pessoas;
}

void relatorio (Pessoas pessoas) {
	printf ("\n\n---------------------\n");
	printf ("RELATÓRIO DEMOGRÁFICO\n");
	printf ("---------------------\n\n");

	printf ("Percentual de pessoas em cada faixa etária\n");
	float primeiro = 0, segundo = 0, terceiro = 0, quarto = 0, quinto = 0;
	int i;

	//contar quantas pessoas tem em cada idade
	for (i = 0; i < numero_pessoas; i++) {
		if (pessoas.pessoas[i].idade < 16)
			primeiro++;
		else if (pessoas.pessoas[i].idade >= 16 && pessoas.pessoas[i].idade < 30)
			segundo++;
		else if (pessoas.pessoas[i].idade >= 30 && pessoas.pessoas[i].idade < 50)
			terceiro++;
		else if (pessoas.pessoas[i].idade >= 50 && pessoas.pessoas[i].idade < 61)
			quarto++;
		else
			quinto++;
	}

	//fazer o calculo de porcentagem
	primeiro = primeiro/numero_pessoas * 100;
	segundo = segundo/numero_pessoas * 100;
	terceiro = terceiro/numero_pessoas * 100;
	quarto = quarto/numero_pessoas * 100;
	quinto = quinto/numero_pessoas * 100;

	printf ("Pessoas de 0 a 15 anos: %.2f% \n", primeiro);
	printf ("Pessoas de 16 a 29 anos: %.2f% \n", segundo);
	printf ("Pessoas de 30 a 49 anos: %.2f% \n", terceiro);
	printf ("Pessoas de 50 a 60 anos: %.2f% \n", quarto);
	printf ("Pessoas de 60 anos ou mais: %.2f% \n", quinto);

	//contar quantas pessoas tem em cada sexo
	float feminino = 0, masculino = 0;
	for (i = 0; i < numero_pessoas; i++) {
		if (pessoas.pessoas[i].sexo == 'F' || pessoas.pessoas[i].sexo == 'f')
			feminino++;
		else 
			masculino++;
	}

	//fazer o calculo de porcentagem
	feminino = feminino/numero_pessoas * 100;
	masculino = masculino/numero_pessoas * 100;

	printf ("\nPessoas do sexo feminino: %.2f% \n", feminino);
	printf ("Pessoas do sexo masculino: %.2f% \n", masculino);
}

void encerrar (Pais pais, Pessoas pessoas) {
  printf ("b");
	continuar = 0;
  atualizar_arquivo(pais, pessoas);
}

int main () {
	int opcao;

	//criação de um novo país
  Pais pais;

  //criando pessoas 
  Pessoas pessoas;

  pais = carregar_pais(pais);

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
			listarPessoas_porEstado(pais, pessoas);
		else if (opcao == 5)
			listarPessoas_porCidade(pais, pessoas);
		else if (opcao == 6)
			consultar_pessoa(pessoas);
		else if (opcao == 7)
			pessoas = excluir_pessoa (pessoas); //não completa
		else if (opcao == 8)
			relatorio(pessoas);
		else if (opcao == 9)
			encerrar(pais, pessoas);
		else
			printf ("Opção Inválida\n");
	}

	return 0;
}