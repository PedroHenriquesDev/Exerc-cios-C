//Ex 01
#include <stdio.h>
#include <string.h>

int main() {
    
    char str[100];
    
    
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    
    
    printf("Conteúdo da string: %s", str);
    
   
    printf("Comprimento da string: %lu\n", strlen(str) - 1); // Subtrai 1 para desconsiderar o '\n' inserido pelo fgets
    
    return 0;
}

//EX 02

#include <stdio.h>
#include <string.h>

int main() {
    
    char str1[100], str2[100];
    
   
    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    
    
    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);

   
    
    if (strcmp(str1, str2) == 0) {
        printf("As strings são iguais.\n");
    } else {
        printf("As strings são diferentes.\n");
    }

    return 0;
}

//EX03

#include <stdio.h>

int main() {
    
    char str[100];
    
    
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);  // Lê a string do usuário
    
    
    printf("Caractere por caractere:\n");
    for (int i = 0; str[i] != '\0'; i++) {  // Continua até encontrar o terminador de string '\0'
        printf("%c\n", str[i]);
    }

    return 0;
}

//EX04

#include <stdio.h>

int main() {
   
    char str[100];
    int count = 0; 
    
   
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);  // Lê a string do usuário
    
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'A') {  // Verifica se o caractere é 'a' ou 'A'
            count++;
        }
    }
    
    
    printf("O caractere 'a' aparece %d vez(es) na string.\n", count);

    return 0;
}

//EX05

#include <stdio.h>
#include <string.h>  

int main() {
    
    char str1[100], str2[100];
    
    
    printf("Digite uma string: ");
    fgets(str1, sizeof(str1), stdin);  // Lê a string do usuário
    
    
    str1[strcspn(str1, "\n")] = '\0';
    
    
    strcpy(str2, str1);
    
   
    printf("String original: %s\n", str1);
    printf("String copiada: %s\n", str2);

    return 0;
}

//EX 06

#include <stdio.h>
#include <string.h>  // Para usar a função strcat()

int main() {
    
    char str1[100], str2[100], result[200];  // O vetor result deve ser grande o suficiente para armazenar a concatenação
    
    
    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);  // Lê a primeira string
    str1[strcspn(str1, "\n")] = '\0';  // Remove o '\n' caso o usuário pressione Enter
    
   
    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);  // Lê a segunda string
    str2[strcspn(str2, "\n")] = '\0';  // Remove o '\n' caso o usuário pressione Enter
    
   
    strcpy(result, str1);
    
    
    strcat(result, str2);
    
   
    printf("Resultado da concatenação: %s\n", result);

    return 0;
}

//EX07

#include <stdio.h>
#include <ctype.h>  

int main() {
    
    char str[100];
    
    
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);  // Lê a string do usuário
    
    
    str[strcspn(str, "\n")] = '\0';
    
   
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);  // Converte o caractere para maiúsculo
    }
    
    
    printf("String em maiúsculas: %s\n", str);

    return 0;
}

//EX08

#include <stdio.h>
#include <ctype.h>  

int main() {
    
    char str[100];
    int count = 0;  // Variável para contar o número de vogais
    
   
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);  // Lê a string do usuário
    
    
    str[strcspn(str, "\n")] = '\0';
    
   
    for (int i = 0; str[i] != '\0'; i++) {
        // Converte o caractere para minúsculo e verifica se é uma vogal
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;  // Incrementa o contador de vogais
        }
    }
    
    
    printf("Número de vogais: %d\n", count);

    return 0;
}

//EX09

#include <stdio.h>

int main() {
   
    char str[100];
    int count = 0;  // Variável para contar o número de espaços em branco
    
    
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);  // Lê a string do usuário
    
    
    str[strcspn(str, "\n")] = '\0';
    
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {  // Verifica se o caractere é um espaço em branco
            count++;  // Incrementa o contador de espaços
        }
    }
    
  
    printf("Número de espaços em branco: %d\n", count);

    return 0;
}

//EX10

#include <stdio.h>
#include <ctype.h>  

int main() {
    
    char str[100];
    
   
    int num_letters = 0, num_digits = 0, num_specials = 0;
    
    
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);  // Lê a string do usuário
    
    
    str[strcspn(str, "\n")] = '\0';
    
 
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            num_letters++;  // Incrementa o contador de letras
        }
        else if (isdigit(str[i])) {
            num_digits++;  // Incrementa o contador de dígitos
        }
        else {
            num_specials++;  // Incrementa o contador de caracteres especiais
        }
    }
    
    
    printf("Número de letras: %d\n", num_letters);
    printf("Número de dígitos: %d\n", num_digits);
    printf("Número de caracteres especiais: %d\n", num_specials);

    return 0;
}
