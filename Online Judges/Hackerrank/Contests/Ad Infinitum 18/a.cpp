#include <bits/stdc++.h>

using namespace std;

int main(){
	int b,a,h;
	double tinggi;
	scanf("%d %d",&b,&a);
	tinggi = a*2.0/(double)b;
	h = ceil(tinggi);
	printf("%d\n",h );
	return 0;
}