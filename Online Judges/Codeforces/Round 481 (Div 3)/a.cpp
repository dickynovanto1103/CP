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
	int a[100];
	int idx[1010];
	memset(idx,-1,sizeof idx);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		idx[a[i]] = i;
	}
	vi ans;
	for(i=0;i<n;i++){
		int bil = a[i];
		if(idx[bil]==i){ans.pb(bil);}
	}
	printf("%d\n",(int)ans.size());
	for(i=0;i<ans.size();i++){
		if(i){printf(" ");}
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
};