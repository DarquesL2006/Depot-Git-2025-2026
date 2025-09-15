#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factoriel(int n) {
	if (n == 0) {
		return 1;
	}
	else
		return n * factoriel(n - 1);
}

int main() {
	int n = 9;
	int resultat = 1;

	if (n >= 20) {
		printf("Factoriel non disponible\n\n");
	}

	for (int i = 1; i <= n; i++) {
		resultat *= i;
	}
	printf("Le resultat de %d factoriel par calcul avec la boucle 'for' est : %d\n", n, resultat);

	resultat = 1;
	int i = 1;

	while (i <= n) {
		resultat *= i;
		i++;
	}
	printf("Le resultat de %d factoriel par calcul avec la boucle 'while' est : %d\n", n, resultat);

	printf("Le resultat de %d factoriel par calcul par recursion est : %d\n", n, factoriel(n));


	return 0;
}