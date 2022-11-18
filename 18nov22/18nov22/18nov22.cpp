#include <iostream>

#define HANOI_CIRCLE 3


void Hanoi(int n, char D, char A, char I)
{
	if (n == 0) return;
	Hanoi(n - 1, D, I, A);
	std::cout << "deplacement de " << D << " vers " << A << std::endl;
	Hanoi(n - 1, I, A, D);

}


int main()
{

	Hanoi(HANOI_CIRCLE, 'A', 'B', 'C');

}
