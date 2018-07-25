#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> binary;
	int number;

	scanf("%d",&number);

	while(number > 0)
	{
		if(number%2 == 0)
		{
			binary.push_back(0);
		}
		else
		{
			binary.push_back(1);
		}
		number /= 2;
	}

	for(int i = binary.size() - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}
	printf("\n");

	return 0;
}