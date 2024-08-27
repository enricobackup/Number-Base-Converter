#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binario_para_decimal(int binario);
void binario_para_hexadecimal(int binario);
void decimal_para_binario(int decimal);
void decimal_para_hexadecimal(int decimal);
void hexa_para_binario(int hexadecimal);
int hexa_para_decimal(int hexadecimal);

int main() { 
	int primeira_escolha, valor_recebido, segunda_escolha;

	printf("Bem-vindo(a)! Por favor, escolha o valor a ser convertido \n"
		"1- Binario\n"
		"2- Decimal\n"
		"3- Hexadecimal\n"
		"4- Sair\n"   
		"# ");
	scanf("%d", &primeira_escolha);

	if (primeira_escolha == 1) { 
		printf("Insira seu numero binario \n");
		scanf("%d", &valor_recebido);
		printf("Deseja converte-lo para qual tipo? \n"
			"1- Decimal \n"
			"2- Hexadecimal \n"
			"# ");
		scanf("%d", &segunda_escolha);

		if (segunda_escolha == 1) {
			int resultado = binario_para_decimal(valor_recebido);
			printf("Numero decimal: %d\n", resultado);
		} else if (segunda_escolha == 2) {
			binario_para_hexadecimal(valor_recebido);
		}
	} else if (primeira_escolha == 2) {
		printf("Insira seu numero decimal \n");
		scanf("%d", &valor_recebido);
		printf("Deseja converte-lo para qual tipo? \n"
			"1- Binario \n"
			"2- Hexadecimal \n"
			"# ");
		scanf("%d", &segunda_escolha);

		if (segunda_escolha == 1) {
			decimal_para_binario(valor_recebido);
		} else if (segunda_escolha == 2) {
			decimal_para_hexadecimal(valor_recebido);
		}
	} else if (primeira_escolha == 3) {
		printf("Insira seu numero hexadecimal (use 0x para indicar que e hexadecimal) \n");
		scanf("%x", &valor_recebido);
		printf("Deseja converte-lo para qual tipo? \n"
			"1- Binario \n"
			"2- Decimal \n"
			"# ");
		scanf("%d", &segunda_escolha);

		if (segunda_escolha == 1) {
			hexa_para_binario(valor_recebido);
		} else if (segunda_escolha == 2) {
			int resultado = hexa_para_decimal(valor_recebido);
			printf("Numero decimal: %d\n", resultado);
		}
	} else if (primeira_escolha == 4) {
		printf("Saindo...\n");
		exit(0);
	} else {
		printf("Por favor, escolha um valor valido\n");
	}

	return 0;
}

int binario_para_decimal(int binario) {
	int decimal = 0, base = 1, rem;
	while (binario > 0) {
		rem = binario % 10;
		decimal = decimal + rem * base;
		binario = binario / 10;
		base = base * 2;
	}
	return decimal;
}

void binario_para_hexadecimal(int binario) {
	int decimal = binario_para_decimal(binario);
	printf("Numero hexadecimal: %X\n", decimal);
}

void decimal_para_binario(int decimal) {
	int binario[32];
	int i = 0;
	while (decimal > 0) {
		binario[i] = decimal % 2;
		decimal = decimal / 2;
		i++;
	}
	printf("Numero binario: ");
	for (int j = i - 1; j >= 0; j--) {
		printf("%d", binario[j]);
	}
	printf("\n");
}

void decimal_para_hexadecimal(int decimal) {
	printf("Numero hexadecimal: %X\n", decimal);
}

void hexa_para_binario(int hexadecimal) {
	int decimal = hexa_para_decimal(hexadecimal);
	decimal_para_binario(decimal);
}

int hexa_para_decimal(int hexadecimal) {
	return hexadecimal;
}
