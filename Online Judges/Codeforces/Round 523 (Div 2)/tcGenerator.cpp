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
	int n = 30000, x = 123929892, y = x;
	printf("%d %d %d\n",n,x,y);
	srand(time(NULL));
	for(int i=0;i<n;i++){
		int a,b;
		do{
			a = rand(); a%=inf;
			b = rand(); b%=inf;	
		}while(a>b);
		
		printf("%d %d\n", a,b);
	}
	return 0;
};