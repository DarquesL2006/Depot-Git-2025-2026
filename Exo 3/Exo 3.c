#include <stdio.h>
#include <ctype.h>

char minuscule(char c) {
    return tolower(c);
}

int main() {
    char lettre = 'G';
    printf("Minuscule de %c : %c\n", lettre, minuscule(lettre));
    return 0;
}
