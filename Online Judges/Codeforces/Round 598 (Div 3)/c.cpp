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
	int n,m,d,i,j;
	scanf("%d %d %d",&n,&m,&d);
	int a[1010];
	int tot = 0;
	int ans[1010];
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
		tot += a[i];
	}
	int sisa = n - tot;
	int idx = 0;
	for(i=0;i<m;i++){
		int ambil = min(d-1, sisa);
		sisa -= ambil;
		for(j=0;j<ambil;j++){
			ans[idx++] = 0;
		}
		for(j=0;j<a[i];j++){
			ans[idx++] = i+1;
		}
	}
	if(sisa >= d){printf("NO\n");}
	else{
		printf("YES\n");
		for(i=0;i<sisa;i++){
			ans[idx++] = 0;
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
};