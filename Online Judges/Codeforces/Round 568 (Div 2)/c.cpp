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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int t[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	int sum = 0;
	int cnt = 0;
	priority_queue<int> pq;
	multiset<int> s;
	for(i=0;i<n;i++){
		
		sum += t[i];
		if(!pq.empty()){
			int atas = pq.top(); pq.pop();
			sum -= atas; cnt++;
			s.insert(atas);
		}
		while(sum > m && !pq.empty()){
			int atas = pq.top(); pq.pop();
			sum -= atas; cnt++;
			s.insert(atas);
			// printf("sum: %d atas: %d cnt: %d\n",sum, atas,cnt);
		}
		while(sum <= m && !s.empty()) {
			int depan = *s.begin();
			if((sum + depan) <= m){
				sum += depan;
				pq.push(depan);
				cnt--;
				s.erase(s.begin());
			}else{
				break;
			}
		}
		pq.push(t[i]);
		printf("%d ",cnt);
	}
	printf("\n");
	return 0;
};