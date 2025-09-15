#include<iostream>
#include<iomanip>
using namespace std;

int main(void)
{
	int a;
	int table;

	cout << "Entrez une valeur entre 1 et 9" << endl;
	cin >> a;

	while (a < 1 || a > 9) {
		cout << "Valeur invalide, veuillez entrer une nouvelle valeur" << endl;
		cin >> a;
		cout << endl;
	}

	for (int i = 1; i <= 10; i++) {
		table = i * a;
		cout <<table << setw(3);
	}
	cout << endl;
}