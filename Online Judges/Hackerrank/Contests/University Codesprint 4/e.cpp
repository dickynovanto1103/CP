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
int a[maxn];
map<int,int> mapper;

int main(){
	int n,q,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		int cnt = 0;
		for(j=l;j<=r;j++){
			if(mapper[a[j]]==0){cnt++; mapper[a[j]]++;}
			else if(mapper[a[j]]==1){cnt--; mapper[a[j]]++;}

		}
		printf("%d\n",cnt);
		mapper.clear();
	}
	return 0;
};