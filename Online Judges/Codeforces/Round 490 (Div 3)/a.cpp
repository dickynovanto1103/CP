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

const int maxn = 101;

int main(){
	int n,k,i,j;
	int a[maxn];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	i = 0; j = n-1;
	int cnt = 0;
	while(true){
		if(i>j){break;}
		bool dikurangi = false;
		if(a[j]<=k){j--; cnt++; dikurangi = true;}
		if(i>j){break;}
		if(a[i]<=k){i++; cnt++; dikurangi = true;}
		if(i>j){break;}
		if(!dikurangi){break;}
	}
	printf("%d\n",cnt);
	return 0;
};