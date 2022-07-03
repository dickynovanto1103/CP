#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int &b = a;
	b = 123;
	printf("%d %d\n", a, b);

	return 0;
}