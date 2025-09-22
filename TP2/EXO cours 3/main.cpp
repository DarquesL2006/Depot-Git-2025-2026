#include <iostream>
#include <string>
using namespace std;

class Quadrupede {
protected:
    string nom; 
public:
    Quadrupede(string n = "") : nom(n) {}

    // Getter
    string getNom() const { return nom; }

    // Setter
    void setNom(string n) { nom = n; }

    // M�thode speak (si virtual, le polymorphisme fonctionnera)
    virtual void speak() const {
        cout << nom << " est un quadrup�de." << endl;
    }
};

class Chat : public Quadrupede {
public:
    Chat(string n = "") : Quadrupede(n) {}

    void speak() const override {
        cout << nom << " dit : Miaou !" << endl;
    }
};

// Classe d�riv�e : Chien
class Chien : public Quadrupede {
public:
    Chien(string n = "") : Quadrupede(n) {}

    void speak() const override {
        cout << nom << " dit : Ouaf !" << endl;
    }
};

int main() {
    Chat* c1 = new Chat("Minou");
    Chat* c2 = new Chat("F�lix");
    Chien* d1 = new Chien("Rex");
    Chien* d2 = new Chien("Milou");

    const int n = 4;
    Quadrupede* quadrupede[n] = { c1, c2, d1, d2 };

    // Boucle d'appel
    for (int i = 0; i < n; i++) {
        quadrupede[i]->speak();  // polymorphisme si virtual
    }

    // Nettoyage m�moire
    for (int i = 0; i < n; i++) {
        delete quadrupede[i];
    }

    return 0;
}
