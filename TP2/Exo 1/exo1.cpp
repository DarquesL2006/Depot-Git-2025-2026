#include <iostream>
/*avec la nouvelle version de l'ide iostream.h ne fonctionne pas, il faut mettre iostream*/
//#define multiplier(x,y) ((x) * (y))
constexpr int multiplier(int x, int y) {
	return x * y;
}
/*constexpr permet d'assurer que les variables sont connues � la compilation*/
int main(void)
{
	int a;
	int b;
	/*On rajoute std:: pour d�finir les entr�es et sorties comme standard*/
	std::cout << "Entrez une valeur :" << std::endl;
	/*On change le sens de l'opp�rande "<<" sur l'entr�e, pour qu'il r�cup�re la valeur entr�, et l'ins�re dans la variable a*/
	std::cin >> a;
	std::cout << "Entrez une autre valeur :" << std::endl;
	std::cin >> b;
	std::cout << multiplier(a + 1, b + 1) << std::endl;
}