#include <bits/stdc++.h>

using namespace std;
int main(){
	int gcdA = 0, gcdB = 0;
	int n;
	scanf("%d", &n);
	while(n--){
		int x, y;
		scanf("%d%d", &x, &y);
		if(gcdA == 0){
			gcdA = x;
			gcdB = y;
		}
		else{
			gcdA = max(__gcd(gcdA, x), __gcd(gcdA, y));
			gcdB = max(__gcd(gcdB, x), __gcd(gcdB, y));	
		}
		fprintf(stderr, "MASIH %d: %d %d\n", n, gcdA, gcdB);
	}
	int maxgcd = max(gcdA, gcdB);
	if(maxgcd == 1) puts("-1");
	else printf("%d\n", maxgcd);
	return 0;
}