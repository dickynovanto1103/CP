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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	stack<ii> s;
	ll ans = 0;
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		s.push(ii(bil, 1));
		int cnt = 0;
		// printf("i: %d bil: %d\n",i, bil);
		while(!s.empty()){
			ii front = s.top(); 
			if(front.first > bil){
				ans += cnt;
				// printf("cnt disini: %d ans jd: %lld push: %d\n",cnt, ans, bil);
				s.push(ii(bil, cnt));
				break;
			}
			cnt += front.second;
			s.pop();
		}
		if(s.empty()){
			ans += cnt;
			// printf("cnt here: %d ans jd: %lld\n",cnt, ans);
			s.push(ii(bil, cnt));
		}
	}
	printf("%lld\n",ans);
	return 0;
};