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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	int a[maxn];
	scanf("%d",&n);
	int jumlah1 = 0, jumlah2 = 0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1){jumlah1++;}
		else{jumlah2++;}
	}
	int grup;
	if(jumlah2>jumlah1){
		grup = jumlah1;
	}else if(jumlah2<jumlah1){
		jumlah1-=jumlah2;
		grup = jumlah2;
		grup+=(jumlah1/3);
	}else{grup = jumlah1;}
	printf("%d\n",grup);
	return 0;
};