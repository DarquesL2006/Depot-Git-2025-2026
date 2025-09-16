#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main(void) {
    ifstream fichier("donnees.txt");
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier !" << endl;
        return 1;
    }

    int nbligne = 0;
    int nblettres = 0;
    int nbmots = 0;
    string text;

    vector<int> occ(26, 0);


    while (getline(fichier, text)) {
        cout << ": " << text << endl;
        nbligne++;

        for (char c : text) {
            unsigned char uc = static_cast<unsigned char>(c);
            if (isalpha(uc)) {
                char lc = static_cast<char>(tolower(uc));
                occ[lc - 'a']++;
            }
        }

        for (char c : text) {
            if (isalpha(c)) {
                nblettres++;
            }
        }

        istringstream iss(text);
        string mot;
        while (iss >> mot) {
            nbmots++;
        }
    }

        cout << "Le nombre de lignes est : " << nbligne << endl;
        cout << "Le nombre de mots est : " << nbmots << endl;
        cout << "Le nombre de lettres est : " << nblettres << endl;

        cout << "\nOccurrences des lettres :" << endl;
        for (int i = 0; i < 26; i++) {
            if (occ[i] > 0) {
                cout << static_cast<char>('a' + i) << " : " << occ[i] << endl;
            }
        }
        fichier.close();
        return 0;

}
