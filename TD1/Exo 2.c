#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findRoots(double a, double b, double c) {
    double Delta, x1, x2;

    Delta = b * b - 4.0 * a * c;

    if (a == 0) {
        if (b != 0) {
            printf("Equation du premier degre : x = %.2f\n", -c / b);
        }
        else {
            printf("Pas une equation valide.\n");
        }
        return;
    }

    if (Delta > 0) {
        x1 = (-b - sqrt(Delta)) / (2.0 * a);
        x2 = (-b + sqrt(Delta)) / (2.0 * a);
        printf("Deux solutions reelles distinctes : x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    else if (Delta == 0) {
        x1 = (-b) / (2.0 * a);
        printf("Une solution double : x1 = %.2f\n", x1);
    }
    else {
        double Reel = -b / (2.0 * a);
        double Imaginaire = sqrt(Delta) / (2.0 * a);
        printf("Deux solutions complexes :\n");
        printf("x1 = %.2f - %.2fi\n", Reel, Imaginaire);
        printf("x2 = %.2f + %.2fi\n", Reel, Imaginaire);
    }
}

int main() {
    double a, b, c;

    printf("Entrez la valeur de a : ");
    scanf("%lf", &a);
    printf("Entrez la valeur de b : ");
    scanf("%lf", &b);
    printf("Entrez la valeur de c : ");
    scanf("%lf", &c);

    printf("Les racines du polynome %.2fx^2 + %.2fx + %.2f sont :\n", a, b, c);
    findRoots(a, b, c);

    return 0;
}