#include <stdio.h>
int main()
{
	/*int x = 14, y = 13;
	if (x > y)
	{
		if (x < 20)
		{
			x -= 10;
		}
		else
		{
			x += 10;
		}
	}
	printf("%d\n", x);
	return 0;*/

	//Le programme renvoie 4

	int x = 4, y = 3;
	x = x + y;
	y = x - y;
	printf("%d\n", y);
	return 0;	//Le programme renvoie également 4
}