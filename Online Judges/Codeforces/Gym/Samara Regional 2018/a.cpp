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
	int s,g;
	scanf("%d %d",&s,&g);
	int start = g;
	int a = g;
	int b = s-g;
	if(b <= 0){printf("-1\n"); return 0;}
	if(__gcd(a,b)==start && __gcd(a,b)==start){
		printf("%d %d\n",a,b);
	}else{
		printf("-1\n");
	}
	return 0;
};