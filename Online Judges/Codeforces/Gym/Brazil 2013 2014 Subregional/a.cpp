#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a!=b && a!=c & b==c) {
		printf("A\n");
	}else if(b!=a && b!=c && a==c) {
		printf("B\n");
	}else if(c!=a && c!=b && a==b) {
		printf("C\n");
	}else{
		printf("*\n");
	}
	return 0;
};