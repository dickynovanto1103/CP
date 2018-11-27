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

struct pasangan{
	int a,b;
};

bool cmp(pasangan a, pasangan b){
	return a.a < b.a;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	pasangan pas[101];
	for(i=0;i<n;i++){scanf("%d",&pas[i].a);}
	for(i=0;i<n;i++){scanf("%d",&pas[i].b);}
	sort(pas, pas+n, cmp);
	
	for(i=0;i<n;i++){
		if(pas[i].a > m){break;}
		else{
			m += pas[i].b;
		}
	}
	printf("%d\n",m);
	return 0;
};