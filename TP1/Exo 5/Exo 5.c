#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool comparer(const char mot[], const char motcache[]) {
        return (strcmp(mot, motcache) == 0);
}

int main()
{
    int tentatives = 10;
	char mot[100];
	char motcache[100];

	printf("Veuillez entrer votre mot : \n");
	scanf("%s", mot);

    int taille = strlen(mot);
    printf("Taille du mot = %d\n", taille);

    for (int i = 0; i < taille; i++) {
        motcache[i] = '*';   
    }
    motcache[taille] = '\0'; 

    printf("Mot cache : %s\n", motcache);

    bool trouve = false;
    char lettre;

    while (!trouve) {
        printf("Entrez une lettre :\n");
        scanf(" %c", &lettre);

        bool bonneLettre = false;
        for (int i = 0; i < taille; i++) {
            if (lettre == mot[i]) {
                motcache[i] = lettre;
                printf("%s\n", motcache);
                bonneLettre = true;
            }
        }
        if (!bonneLettre) {
            tentatives--;
            printf("Il vous reste %d tentatives\n", tentatives);
        }
        if (tentatives == 0) {
            printf("Vous avez perdu");
            return 0;
       }
       trouve = comparer(mot, motcache);
    }

    printf("Felicitation, vous avez trouve le mot");

    return 0;
}