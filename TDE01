Lista de exercícios structs com base em produtos (id, nome,
valor)



Contar Produtos Abaixo de um Valor: Crie um programa que
conte quantos produtos têm um valor abaixo de um determinado valor fornecido
pelo usuário.
Buscar Produto pelo ID: Implemente um programa que permita
ao usuário buscar um produto pelo ID. Se o produto for encontrado, exiba suas
informações; caso contrário, informe que não foi encontrado.
Atualizar Valor do Produto: Desenvolva um programa que permita
ao usuário atualizar o valor de um produto com base no seu ID.
Calcular Média de Preços: Implemente um programa que calcule
e retorne a média dos preços dos produtos.
Exibir Produtos Acima da Média: Crie um programa que exiba
todos os produtos cujo preço é superior à média calculada.


Contar Produtos Abaixo de um Valor: Crie um programa que
conte quantos produtos têm um valor abaixo de um determinado valor fornecido
pelo usuário.

#include <stdio.h>

#define MAX_PRODUTOS 10
#define NOME_MAX 20

typedef struct {
    int id;
    char nome[NOME_MAX];
    float valor;
} Produto;

int main() {
	
	int valorLimite;
	int contador = 0;
	
    Produto produtos[MAX_PRODUTOS];
   
    // Leitura dos dados dos produtos
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Digite o ID do produto %d: ", i + 1);
        scanf("%d", &produtos[i].id);
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Digite o valor do produto %d: ", i + 1);
        scanf("%f", &produtos[i].valor);
    }

    // Exibição dos dados dos produtos
    printf("\nDados dos Produtos:\n");
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Produto %d:\n", i + 1);
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Valor: %.2f\n", produtos[i].valor);
        printf("-----------------------\n");
    }
    
    printf("\nDefina um valor máximo:\n");
    scanf("%d",&valorLimite);
    
   	for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (produtos[i].valor < valorLimite) {
            contador++;
        }
    }
    
    printf("Quantidade de produtos com valor abaixo de %d: %d\n", valorLimite, contador);

    return 0;
}


Buscar Produto pelo ID: Implemente um programa que permita
ao usuário buscar um produto pelo ID. Se o produto for encontrado, exiba suas
informações; caso contrário, informe que não foi encontrado.

#include <stdio.h>

#define MAX_PRODUTOS 10
#define NOME_MAX 20

typedef struct {
    int id;
    char nome[NOME_MAX];
    float valor;
} Produto;

int main() {
	
	int idBusca;
	int encontrado = 0;	
	
    Produto produtos[MAX_PRODUTOS];
   
    // Leitura dos dados dos produtos
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Digite o ID do produto %d: ", i + 1);
        scanf("%d", &produtos[i].id);
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Digite o valor do produto %d: ", i + 1);
        scanf("%f", &produtos[i].valor);
    }

    // Exibição dos dados dos produtos
    printf("\nDados dos Produtos:\n");
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Produto %d:\n", i + 1);
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Valor: %.2f\n", produtos[i].valor);
        printf("-----------------------\n");
    }
    
    printf("Digite o ID do produto a ser buscado: ");
    scanf("%d", &idBusca);
    
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (produtos[i].id == idBusca) {
            printf("Produto encontrado:\n");
            printf("ID: %d\n", produtos[i].id);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Valor: %.2f\n", produtos[i].valor);
            encontrado = 1; 
            break; 
        }
    }
    
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", idBusca);
    }
    
    

    return 0;
}

Atualizar Valor do Produto: Desenvolva um programa que permita
ao usuário atualizar o valor de um produto com base no seu ID.

#include <stdio.h>

#define MAX_PRODUTOS 10
#define NOME_MAX 20

typedef struct {
    int id;
    char nome[NOME_MAX];
    float valor;
} Produto;

int main() {
	
	Produto produtos[MAX_PRODUTOS];
    int idBusca; 
    int encontrado = 0; 
    float novoValor;	
	
   
    // Leitura dos dados dos produtos
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Digite o ID do produto %d: ", i + 1);
        scanf("%d", &produtos[i].id);
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Digite o valor do produto %d: ", i + 1);
        scanf("%f", &produtos[i].valor);
    }

    
    printf("\nDados dos Produtos:\n");
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Produto %d:\n", i + 1);
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Valor: %.2f\n", produtos[i].valor);
        printf("-----------------------\n");
    }
    
    printf("Digite o ID do produto a ser atualizado: ");
    scanf("%d", &idBusca);


    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (produtos[i].id == idBusca) {
            printf("Produto encontrado:\n");
            printf("ID: %d\n", produtos[i].id);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Valor atual: %.2f\n", produtos[i].valor);

            
            printf("Digite o novo valor: ");
            scanf("%f", &novoValor);
            produtos[i].valor = novoValor; 
            printf("Valor atualizado com sucesso!\n");
            encontrado = 1; 
            break; 
        }
    }

    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", idBusca);
    }
    
    

    return 0;
}

Calcular Média de Preços: Implemente um programa que calcule
e retorne a média dos preços dos produtos.

#include <stdio.h>

#define MAX_PRODUTOS 10
#define NOME_MAX 20

typedef struct {
    int id;
    char nome[NOME_MAX];
    float valor;
} Produto;

int main() {
	
	Produto produtos[MAX_PRODUTOS];
    float soma = 0.0; 
    float media; 
    int i;	
	
   
    // Leitura dos dados dos produtos
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Digite o ID do produto %d: ", i + 1);
        scanf("%d", &produtos[i].id);
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Digite o valor do produto %d: ", i + 1);
        scanf("%f", &produtos[i].valor);
    }

    
    
    media = soma / MAX_PRODUTOS;

    
    printf("\nA média dos preços dos produtos é: %.2f\n", media);
    

    return 0;
}

Exibir Produtos Acima da Média: Crie um programa que exiba
todos os produtos cujo preço é superior à média calculada.

#include <stdio.h>

#define MAX_PRODUTOS 10
#define NOME_MAX 20

typedef struct {
    int id;
    char nome[NOME_MAX];
    float valor;
} Produto;

int main() {
	
	 Produto produtos[MAX_PRODUTOS];
    float soma = 0.0; 
    float media; 
    int i;
   	
	
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Digite o ID do produto %d: ", i + 1);
        scanf("%d", &produtos[i].id);
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);
        printf("Digite o valor do produto %d: ", i + 1);
        scanf("%f", &produtos[i].valor);
    }

    
   
    media = soma / MAX_PRODUTOS;

    
    printf("\nA média dos preços dos produtos é: %.2f\n", media);
    
    printf("\nProdutos com preço superior à média:\n");
    for (i = 0; i < MAX_PRODUTOS; i++) {
        if (produtos[i].valor > media) {
            printf("ID: %d, Nome: %s, Valor: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
        }
    }

    

    return 0;
}

