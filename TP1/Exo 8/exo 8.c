#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction utilitaire pour afficher la matrice
void afficher(int** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Fonction de tri d'une colonne par sélection
void trierColonne(int** mat, int n, int col) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mat[i][col] > mat[j][col]) {
                int tmp = mat[i][col];
                mat[i][col] = mat[j][col];
                mat[j][col] = tmp;
            }
        }
    }
}

int main() {
    int n, m;
    printf("Entrez le nombre de lignes (n) : ");
    scanf("%d", &n);
    printf("Entrez le nombre de colonnes (m) : ");
    scanf("%d", &m);

    // Allocation dynamique d'une matrice n x m
    int** mat = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(m * sizeof(int));
    }

    srand(time(NULL));

    // Remplir avec des valeurs aléatoires
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    printf("\nMatrice initiale :\n");
    afficher(mat, n, m);

    // Trier chaque colonne
    for (int j = 0; j < m; j++) {
        trierColonne(mat, n, j);
    }

    printf("\nMatrice triee colonne par colonne :\n");
    afficher(mat, n, m);

    // Libération mémoire
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return EXIT_SUCCESS;
}
