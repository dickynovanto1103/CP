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
	int n,i,j,m;
	scanf("%d %d",&n,&m);
	int a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	int sisa = m;
	int ans[maxn];
	for(i=0;i<n;i++){
		int sisaNama = a[i];
		int cnt = 0;
		if(sisa > sisaNama){
			sisa -= sisaNama;
		}else{
			sisaNama-=sisa;
			sisa = m;
			cnt++;
			cnt+=(sisaNama / m);
			sisa -= (sisaNama%m);
		}
		ans[i] = cnt;

	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};