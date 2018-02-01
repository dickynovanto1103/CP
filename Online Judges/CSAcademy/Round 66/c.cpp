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
ll cnt[maxn], hitung[maxn];

int main(){
	int n,i,j,t;
	int a[100010];
	scanf("%d %d",&n,&t);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(i=1;i<=t;i++){
		if(cnt[i]!=0){
			for(j=i;j<=t;j+=i){
				hitung[j]+=cnt[i];
			}
		}
	}
	ll maks = 0;
	for(i=1;i<=t;i++){
		maks = max(maks,hitung[i]);
	}
	ll banyak = 0;
	for(i=1;i<=t;i++){
		if(hitung[i]==maks){banyak++;}
	}
	printf("%lld %lld\n",maks,banyak);
	return 0;
};