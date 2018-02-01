#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,a[1010],i;
	int sum;
	scanf("%d",&n);
	set<int> s;
	set<int>::iterator it;
	for(i=0;i<n;i++){scanf("%d",&a[i]); s.insert(a[i]);}
	int ans = inf;
	for(it=s.begin();it!=s.end();++it){
		int bil = *it;
		sum = 0;
		for(i=0;i<n;i++){
			if(a[i]!=bil){sum+=a[i];}
		}
		ans = min(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}