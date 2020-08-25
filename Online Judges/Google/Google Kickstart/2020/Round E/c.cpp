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
typedef pair<ii, int> iii;
typedef vector<ii> vii;

ll lastTimePlay[100001];

struct Cmp {
	bool operator()(const iii& a, const iii& b) {
		if(a.first.first == b.first.first) {
			return a.first.second < b.first.second;
		}
		return a.first.first > b.first.first;
	}
};

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	int a[100001], b[100001];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		priority_queue<iii> pq;
		ll sum = 0;
		for(i=0;i<n;i++){
			scanf("%d %d",&a[i],&b[i]);
			sum += a[i];
		}
		ll ans = sum;
		ll cursum = sum;
		int cnt = 0;
		int ansCnt = 0;
		for(i=0;i<n;i++){
			cursum += a[i];
			pq.push(iii(ii(a[i] + b[i], a[i]), i));	
			while(!pq.empty()) {
				iii front = pq.top();
				int cur = front.first.first, idx = front.second;
				if(cur > sum) {
					sum -= a[idx];
					cursum -= 2*a[idx];
					cnt++;
					pq.pop();
					if(ans < cursum) {
						ans = cursum;
						ansCnt = cnt;
					}
				}else{
					if(ans < cursum) {
						ans = cursum;
						ansCnt = cnt;
					}
					break;
				}
			}
		}

		if(pq.empty()) {
			printf("%d %lld\n",ansCnt, ans);
		}else{
			printf("%d INDEFINITELY\n", cnt);
		}
	}
	
	return 0;
};