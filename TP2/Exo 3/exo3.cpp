#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

int main(void) {
    ifstream fichier("donnees.txt");
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier !" << endl;
        return 1;
    }
    string ligne;
    while (getline(fichier, ligne)) { 
        cout << "Vu : " << ligne << endl;
    }

    fichier.close();
    return 0;
}