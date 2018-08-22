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

const int maxn = 102;

int main(){
	int n,q,x;
	bool ada[maxn];
	memset(ada, false, sizeof ada);
	scanf("%d %d %d",&n,&q,&x);
	ada[x] = true;
	while(q--){
		int a,b;
		scanf("%d %d",&a,&b);
		swap(ada[a], ada[b]);
	}
	for(int i=1;i<=n;i++){
		if(ada[i]){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
};