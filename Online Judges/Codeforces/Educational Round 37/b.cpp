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

struct pasangan{
	int l,r,idx;
};

bool cmp(pasangan a, pasangan b){
	if(a.l == b.l){return a.idx < b.idx;}
	return a.l < b.l;
}

int main(){
	int tc,i,j,n,l,r;
	scanf("%d",&tc);
	pasangan pas[1010];
	int ans[1010];
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d",&l,&r);
			pasangan temp;
			temp.l = l; temp.r = r; temp.idx = i;
			pas[i] = temp;
		}
		//sort(pas,pas+n,cmp);
		int detik = pas[0].l;
		ans[0]=detik;
		detik++;
		for(i=1;i<n;i++){
			if(detik>pas[i].r){ans[i] = 0;}
			else{
				int detikDatang = pas[i].l;
				int maks = max(detikDatang,detik);
				ans[i] = maks; detik = maks+1;
			}
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
};