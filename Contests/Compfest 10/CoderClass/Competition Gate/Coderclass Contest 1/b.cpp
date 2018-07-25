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
	unsigned long long a,b;
	scanf("%llu %llu",&a,&b);
	unsigned long long sor = 0;
	for(int i=a;i<=b;i++){
		sor ^= i;
		printf("i: %d sor: %llu\n",i,sor);
	}
	return 0;
};