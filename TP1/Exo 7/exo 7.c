#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    const int n = 10;
    int tab[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {

        tab[i] = rand() % 100;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    return EXIT_SUCCESS;
}