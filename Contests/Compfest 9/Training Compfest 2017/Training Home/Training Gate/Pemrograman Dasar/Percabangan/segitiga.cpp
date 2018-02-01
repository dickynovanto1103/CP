#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool canFormTriangle(int a, int b, int c){
	return((a+b>c) && (a+c>b) && (b+c)>a);
}

int main() {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(canFormTriangle(a,b,c)){printf("segitiga\n");}
	else{printf("bukan segitiga\n");}
	return 0;
}