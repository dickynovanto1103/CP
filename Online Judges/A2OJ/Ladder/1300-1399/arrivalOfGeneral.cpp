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
	int a[110];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//catat indeks maksimum terdekat dengan kiri, dan minimum terdekat dengan kanan;
	int minim = inf, maks = -inf, idxMin, idxMaks;
	for(i=0;i<n;i++){
		if(a[i]>maks){
			maks = a[i];
			idxMaks = i;
		}
	}
	int ans = 0;
	for(i=idxMaks;i>=1;i--){
		swap(a[i],a[i-1]);
		ans++;
	}
	for(i=0;i<n;i++){
		if(a[i]<=minim){
			minim = a[i];
			idxMin = i;
		}
	}
	for(i=idxMin;i<(n-1);i++){
		swap(a[i],a[i+1]);
		ans++;
	}
	printf("%d\n",ans);
	return 0;
};