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

const int maxn = 1e2 + 2;

int main(){
	int n,i,j,b;
	scanf("%d %d",&n,&b);
	int a[maxn];
	bool isValid[maxn];
	memset(isValid, false, sizeof isValid);
	int cntGenap = 0, cntGanjil = 0;
	vi listPrice;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<(n-1);i++){
		// scanf("%d",&a[i]);
		// printf("a[%d]: %d\n",i,a[i]);
		if(a[i]%2==0){
			cntGenap++;
		}else{
			cntGanjil++;
		}
		if(cntGenap == cntGanjil){
			listPrice.pb(abs(a[i] - a[i+1]));
		}
	}
	sort(listPrice.begin(), listPrice.end());
	int cnt = 0;
	for(i=0;i<listPrice.size();i++){
		// printf("listPrice: %d\n",listPrice[i]);
		b-=listPrice[i];
		if(b>=0){cnt++;}
	}
	printf("%d\n",cnt);

	return 0;
};