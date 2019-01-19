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

const int maxn = 1e6 + 6;

int a[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ii pas = ii(0, a[0]);
	for(i=1;i<n;i++){
		int harapan = a[i];
		int satu = harapan - pas.first;
		int dua = harapan - pas.second;
		if(satu < 0 && dua < 0){printf("0\n"); return 0;}
		if(satu > dua){
			swap(satu, dua);
		}
		satu = max(satu, 0); dua = max(dua, 0);
		pas = ii(satu, dua);
	}
	printf("%d\n",pas.second - pas.first + 1);
	//cek 
	return 0;
};