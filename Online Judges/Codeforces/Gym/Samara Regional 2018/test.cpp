#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	char kata[100];
	strcpy(kata,"");
	kata[0] = 'a';
	kata[1] = 'b';
	kata[1] = '\0';
	kata[1] = 'a';
	printf("kata = %s : %d\n",kata,(int)strlen(kata));
	return 0;
}