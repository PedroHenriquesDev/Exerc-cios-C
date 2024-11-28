//1- Crie um programa que gerencie informações sobre alunos de uma escola. As informações devem ser
//armazenadas em um arquivo e cada registro deve conter:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Aluno
typedef struct {
    int matricula;
    char nome[50];
    char curso[30];
    int idade;
} Aluno;

// Protótipos das funções
void incluirAluno();
void alterarAluno();
void excluirAluno();
void consultarAluno();
void listarAlunos();
void menu();

int main() {
    menu();
    return 0;
}

void incluirAluno() {
    FILE *file = fopen("alunos.dat", "ab");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Aluno aluno;
    printf("Digite o número de matrícula: ");
    scanf("%d", &aluno.matricula);
    getchar(); // Consumir o '\n' pendente
    printf("Digite o nome: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; // Remover o '\n'
    printf("Digite o curso: ");
    fgets(aluno.curso, sizeof(aluno.curso), stdin);
    aluno.curso[strcspn(aluno.curso, "\n")] = '\0'; // Remover o '\n'
    printf("Digite a idade: ");
    scanf("%d", &aluno.idade);

    fwrite(&aluno, sizeof(Aluno), 1, file);
    fclose(file);

    printf("Aluno incluído com sucesso!\n");
}

void alterarAluno() {
    FILE *file = fopen("alunos.dat", "r+b");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int matricula;
    printf("Digite o número de matrícula do aluno a ser alterado: ");
    scanf("%d", &matricula);

    Aluno aluno;
    int encontrado = 0;
    while (fread(&aluno, sizeof(Aluno), 1, file)) {
        if (aluno.matricula == matricula) {
            encontrado = 1;
            printf("Digite o novo nome: ");
            getchar(); // Consumir o '\n' pendente
            fgets(aluno.nome, sizeof(aluno.nome), stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; // Remover o '\n'
            printf("Digite o novo curso: ");
            fgets(aluno.curso, sizeof(aluno.curso), stdin);
            aluno.curso[strcspn(aluno.curso, "\n")] = '\0'; // Remover o '\n'
            printf("Digite a nova idade: ");
            scanf("%d", &aluno.idade);

            fseek(file, -sizeof(Aluno), SEEK_CUR);
            fwrite(&aluno, sizeof(Aluno), 1, file);
            printf("Aluno alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com matrícula %d não encontrado.\n", matricula);
    }

    fclose(file);
}

void excluirAluno() {
    FILE *file = fopen("alunos.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(file);
        return;
    }

    int matricula;
    printf("Digite o número de matrícula do aluno a ser excluído: ");
    scanf("%d", &matricula);

    Aluno aluno;
    int encontrado = 0;
    while (fread(&aluno, sizeof(Aluno), 1, file)) {
        if (aluno.matricula == matricula) {
            encontrado = 1;
        } else {
            fwrite(&aluno, sizeof(Aluno), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("alunos.dat");
    rename("temp.dat", "alunos.dat");

    if (encontrado) {
        printf("Aluno excluído com sucesso!\n");
    } else {
        printf("Aluno com matrícula %d não encontrado.\n", matricula);
    }
}

void consultarAluno() {
    FILE *file = fopen("alunos.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int matricula;
    printf("Digite o número de matrícula do aluno a ser consultado: ");
    scanf("%d", &matricula);

    Aluno aluno;
    int encontrado = 0;
    while (fread(&aluno, sizeof(Aluno), 1, file)) {
        if (aluno.matricula == matricula) {
            encontrado = 1;
            printf("\nMatrícula: %d\n", aluno.matricula);
            printf("Nome: %s\n", aluno.nome);
            printf("Curso: %s\n", aluno.curso);
            printf("Idade: %d\n", aluno.idade);
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com matrícula %d não encontrado.\n", matricula);
    }

    fclose(file);
}

void listarAlunos() {
    FILE *file = fopen("alunos.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Aluno aluno;
    printf("\nLista de Alunos:\n");
    printf("-------------------------------\n");
    while (fread(&aluno, sizeof(Aluno), 1, file)) {
        printf("Matrícula: %d\n", aluno.matricula);
        printf("Nome: %s\n", aluno.nome);
        printf("Curso: %s\n", aluno.curso);
        printf("Idade: %d\n", aluno.idade);
        printf("-------------------------------\n");
    }

    fclose(file);
}

void menu() {
    int opcao;

    do {
        printf("\nSistema de Gerenciamento de Alunos\n");
        printf("1. Incluir um novo aluno\n");
        printf("2. Alterar informações de um aluno\n");
        printf("3. Excluir um aluno pelo número de matrícula\n");
        printf("4. Consultar informações de um aluno\n");
        printf("5. Listar todos os alunos cadastrados\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: incluirAluno(); break;
            case 2: alterarAluno(); break;
            case 3: excluirAluno(); break;
            case 4: consultarAluno(); break;
            case 5: listarAlunos(); break;
            case 6: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 6);
}

//2. Cadastro de Funcionários
//Implemente um programa que gerencie os dados de funcionários de uma empresa. O programa deve
//usar um arquivo para persistir os dados e cada registro deve conter:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Funcionario
typedef struct {
    int id;
    char nome[50];
    char cargo[30];
    int salario;
} Funcionario;

// Protótipos das funções
void cadastrarFuncionario();
void alterarFuncionario();
void excluirFuncionario();
void consultarFuncionario();
void listarFuncionarios();
void menu();

int main() {
    menu();
    return 0;
}

void cadastrarFuncionario() {
    FILE *file = fopen("funcionarios.dat", "ab");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Funcionario funcionario;
    printf("Digite o ID do funcionário: ");
    scanf("%d", &funcionario.id);
    getchar(); // Consumir o '\n' pendente
    printf("Digite o nome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0'; // Remover o '\n'
    printf("Digite o cargo do funcionário: ");
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
    funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0'; // Remover o '\n'
    printf("Digite o salário do funcionário (em reais): ");
    scanf("%d", &funcionario.salario);

    fwrite(&funcionario, sizeof(Funcionario), 1, file);
    fclose(file);

    printf("Funcionário cadastrado com sucesso!\n");
}

void alterarFuncionario() {
    FILE *file = fopen("funcionarios.dat", "r+b");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int id;
    printf("Digite o ID do funcionário a ser alterado: ");
    scanf("%d", &id);

    Funcionario funcionario;
    int encontrado = 0;
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        if (funcionario.id == id) {
            encontrado = 1;
            printf("Digite o novo cargo: ");
            getchar(); // Consumir o '\n' pendente
            fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
            funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0'; // Remover o '\n'
            printf("Digite o novo salário (em reais): ");
            scanf("%d", &funcionario.salario);

            fseek(file, -sizeof(Funcionario), SEEK_CUR);
            fwrite(&funcionario, sizeof(Funcionario), 1, file);
            printf("Dados do funcionário alterados com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário com ID %d não encontrado.\n", id);
    }

    fclose(file);
}

void excluirFuncionario() {
    FILE *file = fopen("funcionarios.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(file);
        return;
    }

    int id;
    printf("Digite o ID do funcionário a ser excluído: ");
    scanf("%d", &id);

    Funcionario funcionario;
    int encontrado = 0;
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        if (funcionario.id == id) {
            encontrado = 1;
        } else {
            fwrite(&funcionario, sizeof(Funcionario), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("funcionarios.dat");
    rename("temp.dat", "funcionarios.dat");

    if (encontrado) {
        printf("Funcionário excluído com sucesso!\n");
    } else {
        printf("Funcionário com ID %d não encontrado.\n", id);
    }
}

void consultarFuncionario() {
    FILE *file = fopen("funcionarios.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int id;
    printf("Digite o ID do funcionário a ser consultado: ");
    scanf("%d", &id);

    Funcionario funcionario;
    int encontrado = 0;
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        if (funcionario.id == id) {
            encontrado = 1;
            printf("\nID: %d\n", funcionario.id);
            printf("Nome: %s\n", funcionario.nome);
            printf("Cargo: %s\n", funcionario.cargo);
            printf("Salário: R$%d\n", funcionario.salario);
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionário com ID %d não encontrado.\n", id);
    }

    fclose(file);
}

void listarFuncionarios() {
    FILE *file = fopen("funcionarios.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Funcionario funcionario;
    printf("\nLista de Funcionários:\n");
    printf("---------------------------------\n");
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        printf("ID: %d\n", funcionario.id);
        printf("Nome: %s\n", funcionario.nome);
        printf("Cargo: %s\n", funcionario.cargo);
        printf("Salário: R$%d\n", funcionario.salario);
        printf("---------------------------------\n");
    }

    fclose(file);
}

void menu() {
    int opcao;

    do {
        printf("\nSistema de Gerenciamento de Funcionários\n");
        printf("1. Cadastrar um novo funcionário\n");
        printf("2. Alterar dados de um funcionário\n");
        printf("3. Excluir um funcionário pelo ID\n");
        printf("4. Consultar informações de um funcionário pelo ID\n");
        printf("5. Listar todos os funcionários cadastrados\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarFuncionario(); break;
            case 2: alterarFuncionario(); break;
            case 3: excluirFuncionario(); break;
            case 4: consultarFuncionario(); break;
            case 5: listarFuncionarios(); break;
            case 6: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 6);
}

//3. Gerenciamento de Livros
//Desenvolva um programa para gerenciar um catálogo de livros em uma biblioteca. As informações
//devem ser salvas em um arquivo e cada registro deve conter:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Livro
typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
    int ano;
} Livro;

// Protótipos das funções
void adicionarLivro();
void alterarLivro();
void excluirLivro();
void consultarLivro();
void listarLivros();
void menu();

int main() {
    menu();
    return 0;
}

void adicionarLivro() {
    FILE *file = fopen("livros.dat", "ab");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Livro livro;
    printf("Digite o código do livro: ");
    scanf("%d", &livro.codigo);
    getchar(); // Consumir o '\n' pendente
    printf("Digite o título do livro: ");
    fgets(livro.titulo, sizeof(livro.titulo), stdin);
    livro.titulo[strcspn(livro.titulo, "\n")] = '\0'; // Remover o '\n'
    printf("Digite o autor do livro: ");
    fgets(livro.autor, sizeof(livro.autor), stdin);
    livro.autor[strcspn(livro.autor, "\n")] = '\0'; // Remover o '\n'
    printf("Digite o ano de publicação: ");
    scanf("%d", &livro.ano);

    fwrite(&livro, sizeof(Livro), 1, file);
    fclose(file);

    printf("Livro adicionado com sucesso!\n");
}

void alterarLivro() {
    FILE *file = fopen("livros.dat", "r+b");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int codigo;
    printf("Digite o código do livro a ser alterado: ");
    scanf("%d", &codigo);

    Livro livro;
    int encontrado = 0;
    while (fread(&livro, sizeof(Livro), 1, file)) {
        if (livro.codigo == codigo) {
            encontrado = 1;
            printf("Digite o novo título do livro: ");
            getchar(); // Consumir o '\n' pendente
            fgets(livro.titulo, sizeof(livro.titulo), stdin);
            livro.titulo[strcspn(livro.titulo, "\n")] = '\0'; // Remover o '\n'
            printf("Digite o novo autor do livro: ");
            fgets(livro.autor, sizeof(livro.autor), stdin);
            livro.autor[strcspn(livro.autor, "\n")] = '\0'; // Remover o '\n'
            printf("Digite o novo ano de publicação: ");
            scanf("%d", &livro.ano);

            fseek(file, -sizeof(Livro), SEEK_CUR);
            fwrite(&livro, sizeof(Livro), 1, file);
            printf("Dados do livro alterados com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Livro com código %d não encontrado.\n", codigo);
    }

    fclose(file);
}

void excluirLivro() {
    FILE *file = fopen("livros.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(file);
        return;
    }

    int codigo;
    printf("Digite o código do livro a ser excluído: ");
    scanf("%d", &codigo);

    Livro livro;
    int encontrado = 0;
    while (fread(&livro, sizeof(Livro), 1, file)) {
        if (livro.codigo == codigo) {
            encontrado = 1;
        } else {
            fwrite(&livro, sizeof(Livro), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("livros.dat");
    rename("temp.dat", "livros.dat");

    if (encontrado) {
        printf("Livro excluído com sucesso!\n");
    } else {
        printf("Livro com código %d não encontrado.\n", codigo);
    }
}

void consultarLivro() {
    FILE *file = fopen("livros.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int codigo;
    printf("Digite o código do livro a ser consultado: ");
    scanf("%d", &codigo);

    Livro livro;
    int encontrado = 0;
    while (fread(&livro, sizeof(Livro), 1, file)) {
        if (livro.codigo == codigo) {
            encontrado = 1;
            printf("\nCódigo: %d\n", livro.codigo);
            printf("Título: %s\n", livro.titulo);
            printf("Autor: %s\n", livro.autor);
            printf("Ano de publicação: %d\n", livro.ano);
            break;
        }
    }

    if (!encontrado) {
        printf("Livro com código %d não encontrado.\n", codigo);
    }

    fclose(file);
}

void listarLivros() {
    FILE *file = fopen("livros.dat", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Livro livro;
    printf("\nCatálogo de Livros:\n");
    printf("-------------------------------\n");
    while (fread(&livro, sizeof(Livro), 1, file)) {
        printf("Código: %d\n", livro.codigo);
        printf("Título: %s\n", livro.titulo);
        printf("Autor: %s\n", livro.autor);
        printf("Ano de publicação: %d\n", livro.ano);
        printf("-------------------------------\n");
    }

    fclose(file);
}

void menu() {
    int opcao;

    do {
        printf("\nSistema de Gerenciamento de Livros\n");
        printf("1. Adicionar um novo livro\n");
        printf("2. Alterar dados de um livro\n");
        printf("3. Excluir um livro pelo código\n");
        printf("4. Consultar informações de um livro pelo código\n");
        printf("5. Listar todos os livros cadastrados\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarLivro(); break;
            case 2: alterarLivro(); break;
            case 3: excluirLivro(); break;
            case 4: consultarLivro(); break;
            case 5: listarLivros(); break;
            case 6: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 6);
}


//4. Registro de Veículos
//Crie um programa que registre informações sobre veículos em uma concessionária. O programa deve
//usar um arquivo para armazenar os dados, e cada registro deve conter:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char modelo[50];
    char placa[10];
    int ano;
} Veiculo;

void adicionarVeiculo() {
    FILE *file = fopen("veiculos.dat", "ab");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Veiculo v;
    printf("ID do veículo: ");
    scanf("%d", &v.id);
    printf("Modelo do veículo: ");
    scanf(" %[^\n]", v.modelo);
    printf("Placa do veículo: ");
    scanf(" %[^\n]", v.placa);
    printf("Ano do veículo: ");
    scanf("%d", &v.ano);

    fwrite(&v, sizeof(Veiculo), 1, file);
    fclose(file);
    printf("Veículo adicionado com sucesso!\n");
}

void alterarVeiculo() {
    FILE *file = fopen("veiculos.dat", "rb+");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int id;
    printf("Informe o ID do veículo que deseja alterar: ");
    scanf("%d", &id);

    Veiculo v;
    while (fread(&v, sizeof(Veiculo), 1, file)) {
        if (v.id == id) {
            fseek(file, -sizeof(Veiculo), SEEK_CUR);

            printf("Novo modelo do veículo: ");
            scanf(" %[^\n]", v.modelo);
            printf("Nova placa do veículo: ");
            scanf(" %[^\n]", v.placa);
            printf("Novo ano do veículo: ");
            scanf("%d", &v.ano);

            fwrite(&v, sizeof(Veiculo), 1, file);
            fclose(file);
            printf("Veículo atualizado com sucesso!\n");
            return;
        }
    }

    fclose(file);
    printf("Veículo com ID %d não encontrado.\n", id);
}

void excluirVeiculo() {
    FILE *file = fopen("veiculos.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!file || !temp) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int id;
    printf("Informe o ID do veículo que deseja excluir: ");
    scanf("%d", &id);

    Veiculo v;
    int encontrado = 0;
    while (fread(&v, sizeof(Veiculo), 1, file)) {
        if (v.id != id) {
            fwrite(&v, sizeof(Veiculo), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("veiculos.dat");
    rename("temp.dat", "veiculos.dat");

    if (encontrado) {
        printf("Veículo excluído com sucesso!\n");
    } else {
        printf("Veículo com ID %d não encontrado.\n", id);
    }
}

void consultarVeiculo() {
    FILE *file = fopen("veiculos.dat", "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char placa[10];
    printf("Informe a placa do veículo: ");
    scanf(" %[^\n]", placa);

    Veiculo v;
    while (fread(&v, sizeof(Veiculo), 1, file)) {
        if (strcmp(v.placa, placa) == 0) {
            printf("ID: %d\nModelo: %s\nPlaca: %s\nAno: %d\n", v.id, v.modelo, v.placa, v.ano);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Veículo com a placa %s não encontrado.\n", placa);
}

void listarVeiculos() {
    FILE *file = fopen("veiculos.dat", "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Veiculo v;
    printf("Lista de veículos cadastrados:\n");
    while (fread(&v, sizeof(Veiculo), 1, file)) {
        printf("ID: %d\nModelo: %s\nPlaca: %s\nAno: %d\n\n", v.id, v.modelo, v.placa, v.ano);
    }

    fclose(file);
}

int main() {
    int opcao;
    do {
        printf("\nRegistro de Veículos\n");
        printf("1.


//5. Controle de Filmes
//Desenvolva um programa para gerenciar um acervo de filmes de uma locadora. Os dados devem ser
//armazenados em um arquivo e cada registro deve conter:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char titulo[50];
    char genero[20];
    int ano;
} Filme;

void adicionarFilme() {
    FILE *file = fopen("filmes.dat", "ab");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Filme f;
    printf("ID do filme: ");
    scanf("%d", &f.id);
    printf("Título do filme: ");
    scanf(" %[^\n]", f.titulo);
    printf("Gênero do filme: ");
    scanf(" %[^\n]", f.genero);
    printf("Ano de lançamento: ");
    scanf("%d", &f.ano);

    fwrite(&f, sizeof(Filme), 1, file);
    fclose(file);
    printf("Filme adicionado com sucesso!\n");
}

void alterarFilme() {
    FILE *file = fopen("filmes.dat", "rb+");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int id;
    printf("Informe o ID do filme que deseja alterar: ");
    scanf("%d", &id);

    Filme f;
    while (fread(&f, sizeof(Filme), 1, file)) {
        if (f.id == id) {
            fseek(file, -sizeof(Filme), SEEK_CUR);

            printf("Novo título do filme: ");
            scanf(" %[^\n]", f.titulo);
            printf("Novo gênero do filme: ");
            scanf(" %[^\n]", f.genero);
            printf("Novo ano de lançamento: ");
            scanf("%d", &f.ano);

            fwrite(&f, sizeof(Filme), 1, file);
            fclose(file);
            printf("Filme atualizado com sucesso!\n");
            return;
        }
    }

    fclose(file);
    printf("Filme com ID %d não encontrado.\n", id);
}

void excluirFilme() {
    FILE *file = fopen("filmes.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!file || !temp) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int id;
    printf("Informe o ID do filme que deseja excluir: ");
    scanf("%d", &id);

    Filme f;
    int encontrado = 0;
    while (fread(&f, sizeof(Filme), 1, file)) {
        if (f.id != id) {
            fwrite(&f, sizeof(Filme), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("filmes.dat");
    rename("temp.dat", "filmes.dat");

    if (encontrado) {
        printf("Filme excluído com sucesso!\n");
    } else {
        printf("Filme com ID %d não encontrado.\n", id);
    }
}

void consultarFilme() {
    FILE *file = fopen("filmes.dat", "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int id;
    printf("Informe o ID do filme: ");
    scanf("%d", &id);

    Filme f;
    while (fread(&f, sizeof(Filme), 1, file)) {
        if (f.id == id) {
            printf("ID: %d\nTítulo: %s\nGênero: %s\nAno: %d\n", f.id, f.titulo, f.genero, f.ano);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Filme com ID %d não encontrado.\n", id);
}

void listarFilmes() {
    FILE *file = fopen("filmes.dat", "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Filme f;
    printf("Lista de filmes cadastrados:\n");
    while (fread(&f, sizeof(Filme), 1, file)) {
        printf("ID: %d\nTítulo: %s\nGênero: %s\nAno: %d\n\n", f.id, f.titulo, f.genero, f.ano);
    }

    fclose(file);
}

int main() {
    int opcao;
    do {
        printf("\nControle de Filmes\n");
        printf("1. Adicionar filme\n");
        printf("2. Alterar filme\n");
        printf("3. Excluir filme\n");
        printf("4. Consultar filme pelo ID\n");
        printf("5. Listar todos os filmes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarFilme();
                break;
            case 2:
                alterarFilme();
                break;
            case 3:
                excluirFilme();
                break;
            case 4:
                consultarFilme();
                break;
            case 5:
                listarFilmes();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

//6. Cadastro de Cidades
//Crie um programa que gerencie o cadastro de cidades de um país. O programa deve armazenar os
//dados em um arquivo de texto, e cada registro deve conter as seguintes informações:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    char estado[30];
    int populacao;
} Cidade;

void incluirCidade() {
    FILE *file = fopen("cidades.txt", "a");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Cidade c;
    printf("Código da cidade: ");
    scanf("%d", &c.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c.nome);
    printf("Estado: ");
    scanf(" %[^\n]", c.estado);
    printf("População: ");
    scanf("%d", &c.populacao);

    fprintf(file, "%d,%s,%s,%d\n", c.codigo, c.nome, c.estado, c.populacao);
    fclose(file);
    printf("Cidade adicionada com sucesso!\n");
}

void alterarCidade() {
    FILE *file = fopen("cidades.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int codigo;
    printf("Informe o código da cidade que deseja alterar: ");
    scanf("%d", &codigo);

    Cidade c;
    int encontrado = 0;
    char linha[150];
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d,%49[^,],%29[^,],%d", &c.codigo, c.nome, c.estado, &c.populacao);
        if (c.codigo == codigo) {
            encontrado = 1;
            printf("Novo nome da cidade: ");
            scanf(" %[^\n]", c.nome);
            printf("Novo estado: ");
            scanf(" %[^\n]", c.estado);
            printf("Nova população: ");
            scanf("%d", &c.populacao);
        }
        fprintf(temp, "%d,%s,%s,%d\n", c.codigo, c.nome, c.estado, c.populacao);
    }

    fclose(file);
    fclose(temp);

    remove("cidades.txt");
    rename("temp.txt", "cidades.txt");

    if (encontrado) {
        printf("Cidade atualizada com sucesso!\n");
    } else {
        printf("Cidade com código %d não encontrada.\n", codigo);
    }
}

void excluirCidade() {
    FILE *file = fopen("cidades.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int codigo;
    printf("Informe o código da cidade que deseja excluir: ");
    scanf("%d", &codigo);

    Cidade c;
    int encontrado = 0;
    char linha[150];
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d,%49[^,],%29[^,],%d", &c.codigo, c.nome, c.estado, &c.populacao);
        if (c.codigo != codigo) {
            fprintf(temp, "%d,%s,%s,%d\n", c.codigo, c.nome, c.estado, c.populacao);
        } else {
            encontrado = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("cidades.txt");
    rename("temp.txt", "cidades.txt");

    if (encontrado) {
        printf("Cidade excluída com sucesso!\n");
    } else {
        printf("Cidade com código %d não encontrada.\n", codigo);
    }
}

void consultarCidade() {
    FILE *file = fopen("cidades.txt", "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int codigo;
    printf("Informe o código da cidade: ");
    scanf("%d", &codigo);

    Cidade c;
    char linha[150];
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d,%49[^,],%29[^,],%d", &c.codigo, c.nome, c.estado, &c.populacao);
        if (c.codigo == codigo) {
            printf("Código: %d\nNome: %s\nEstado: %s\nPopulação: %d\n", c.codigo, c.nome, c.estado, c.populacao);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Cidade com código %d não encontrada.\n", codigo);
}

void listarCidades() {
    FILE *file = fopen("cidades.txt", "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Cidade c;
    char linha[150];
    printf("Lista de cidades cadastradas:\n");
    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "%d,%49[^,],%29[^,],%d", &c.codigo, c.nome, c.estado, &c.populacao);
        printf("Código: %d\nNome: %s\nEstado: %s\nPopulação: %d\n\n", c.codigo, c.nome, c.estado, c.populacao);
    }

    fclose(file);
}

int main() {
    int opcao;
    do {
        printf("\nCadastro de Cidades\n");
        printf("1. Incluir cidade\n");
        printf("2. Alterar dados da cidade\n");
        printf("3. Excluir cidade\n");
        printf("4. Consultar cidade\n");
        printf("5. Listar todas as cidades\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirCidade();
                break;
            case 2:
                alterarCidade();
                break;
            case 3:
                excluirCidade();
                break;
            case 4:
                consultarCidade();
                break;
            case 5:
                listarCidades();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}



