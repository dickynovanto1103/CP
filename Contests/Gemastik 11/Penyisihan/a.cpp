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

const int maxn = 1e5 + 5;

int main(){
	int n,i,j;
	ll a[maxn];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%lld",&a[i]);}
	sort(a+1,a+n);
	ll sekarang = a[0];
	for(i=1;i<n;i++){
		if(sekarang >= a[i]){
			sekarang -= a[i];
		}else{
			printf("kalah\n");
			return 0;
		}
	}
	printf("menang\n");
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%lld",a[i]);
	}
	printf("\n");
	return 0;
};