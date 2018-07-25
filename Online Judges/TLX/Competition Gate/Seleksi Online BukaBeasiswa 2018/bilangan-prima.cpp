#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int n;
	bool isPrime = true;

	scanf("%d",&n);

	for(int i = 2; i*i <= n; i++)
	{
		if(n%i == 0)
		{
			isPrime = false;
		}
	}

	if(isPrime)
	{
		printf("Prima\n");
	}else
	{
		printf("Bukan Prima\n");
	}

	return 0;
}