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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[100001];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	sort(a,a+n);
	int banyak = (n-1)/2;
	vi kecil, besar;
	for(i=0;i<banyak;i++){
		kecil.pb(a[i]);
	}
	for(i=banyak;i<n;i++){
		besar.pb(a[i]);
	}

	printf("%d\n",banyak);
	int ans[100001];
	for(i=0;i<n;i++){
		if(i % 2 == 1){
			if(kecil.size()){
				ans[i] = kecil.back(); kecil.pop_back();
			}else{
				ans[i] = besar.back(); besar.pop_back();
			}
		}else{
			ans[i] = besar.back(); besar.pop_back();
		}
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");


	
	return 0;
};