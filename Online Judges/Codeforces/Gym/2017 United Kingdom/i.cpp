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
	int n,i,j;
	int h[20];
	int hasilMod[20];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&h[i]);}
	int tinggi;
	scanf("%d",&tinggi);
	for(i=0;i<n;i++){
		hasilMod[i] = tinggi % h[i];
	}
	int minim = inf;
	int ans;
	for(i=0;i<n;i++){
		if(minim > hasilMod[i]) {
			minim = hasilMod[i];
			ans = h[i];
		}
	}
	printf("%d\n",ans);
	return 0;
};