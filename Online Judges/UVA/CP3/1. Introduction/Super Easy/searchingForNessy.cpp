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
	int tc,i,j;
	int n,m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		int baris, kolom;
		n-=2; m-=2;
		baris = n/3;
		if(n%3!=0){baris++;}
		kolom = m/3;
		if(m%3!=0){kolom++;}	
		printf("%d\n",baris*kolom);
	}
	

	return 0;
};