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

int div1[10000001];

int main(){
	int n;
	scanf("%d",&n);
	int i,j;

	for(i=1;i<=n;i++){
		for(j=i;j<=n;j+=i){
			div1[j]++;
		}
	}
	uint64 ans = 0;
	for(i=1;i<=n;i++){
		ans += (uint64)i*(uint64)div1[i];
	}
	cout<<ans<<endl;
	return 0;
};