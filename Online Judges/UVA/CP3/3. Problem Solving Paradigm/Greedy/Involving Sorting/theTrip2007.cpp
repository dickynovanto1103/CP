#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,arr[10010];
	list<int> a;
	list<int>::iterator it;
	while(scanf("%d",&n),n){
		int bil;
		for(i=0;i<n;i++){scanf("%d",&arr[i]);}
		sort(arr,arr+n);
		for(i=0;i<n;i++){a.pb(arr[i]);}
		for(it = a.begin();it!=a.end();it++){
			printf("%d\n",*it);
		}
		int idx = lower_bound(a.begin(),a.end(),1) - a.begin();
		printf("idx: %d\n",idx);
		a.clear();
	}
	return 0;
}