#include <iostream>
using namespace std;
class A {
public:
	A() { x = 0; cout << "1"; }
	A(int px) { x = px; cout << "2"; }
	A(const A& pa) { x = pa.x; cout << "3"; }
protected:
	int x;
};
class B {
public:
	B(const A& pa = A()) : a(pa) { cout << "4"; }
	B(const A& pa, int py) { a = pa; y = py; cout << "5"; }
protected:
	A a;
	int y;
};
class C : public B {
public:
	C(int pz = 1) { z = pz; cout << "6"; }
	C(A pa) : B(pa) { z = 0; cout << "7"; }
	C(const B& pb) : B(pb), a(1) { z = 0; cout << "8"; }
protected:
	A a;
	int z;
};
int main() {
	cout << "-- A --\n";
	A a0; cout << endl; // on initialise la variable a par défaut, on a donc x = 0, ce qui renvoie 1
	A a1(3); cout << endl; // on initialise maintenant la variable avec px = 3, quand x=px, on renvoie 2
	A a2(a1); cout << endl; // on initialise maintenant a2 avec le constructeur de copie A(const A&) ce qui affiche 3
	A a3 = a2; cout << endl; //Appel implicite du constructeur de copie (comme A a3(a2)) → affiche 3
	a3 = a1; cout << endl; //Rien n'est affiché car on n'appelle pas de constructeurs
	cout << "-- B --\n";
	B b0(a0, 3); cout << endl; // On appelle le constructeur B(const A& pa, int py), d'abord on construit a par défaut, puis on affecte a = a0, enfin on a y = 3, si y = 3 alors cout 5. Le résultat concatène les deux et renvoie donc 1 et 5 soit 15
	B b1(a1); cout << endl; // Initialisation de a(pa) → appelle le constructeur de copie de A (3) ce qui renvoie 3, puis cout<<"4". On obtient donc 34
	B b2; cout << endl; // On appelle le constructeur 	B(const A& pa = A()) : a(pa) { cout << "4"; }, On fait d'abord appelle à A() qui vaut 1, puis a(pa) constructeur de copie de A qui affiche 3. Enfin cout << 4, ce qui renvoie 134
	cout << "-- C --\n";
	C c0; cout << endl;  // On initialise d'abord la class B par défaut, ce qui renvoie au constructeur B(const A& pa = A()), qui initialise A() = 1, ensuite on a le constructeur copie a(pa), ce qui renvoie 3, puis cout <<"4". enfin on a le A a; dans le protected qui initalise un a par défaut, donc =1, et enfin cout<<6.
	C c1(a1); cout << endl; // On initialise c1 avec le constructeur (A pa) : B(pa), ce qui renvoie d'abord const A& pa donc 3, puis class B ce qui est une copie de a(pa) ce qui renvoie 3, puis 4. Enfin on a A a dans le protected qui renvoie 1, et enfin cout << 7. Au final on a 33417
	C c2(b2); cout << endl; // On initalise c2b2 ce qui fait appelle au constructeur C(const B& pb) : B(pb) constructeur de copie par défaut de B, ce qui renvoie "3", puis a(1) soit appelle a A(int px) donc ce qui renvoie 2. Et enfin cout 8
}