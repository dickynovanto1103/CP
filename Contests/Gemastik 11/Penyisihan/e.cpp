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
	int n,m,i,j,t,d,l;
	scanf("%d %d %d %d",&n,&m,&t,&d)
	scanf("%d",&l);
	int panjang = t + d;
	int banyakRow = n / panjang;
	int sisaRow = n%panjang;
	int banyakCol = m/panjang;
	int sisaCol = m%panjang;


	int banyakOrnamen;
	if(t%2){
		banyakOrnamen = ((t*t) / 2) + 1;
	}else{
		banyakOrnamen = ((t*t) / 2);
	}
	ll ans = 0;
	ans += (banyakOrnamen*banyakRow*banyakCol);
	
	return 0;
};