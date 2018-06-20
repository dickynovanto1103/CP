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

const int maxn = 2e5 + 5;


int main(){
	int tc,i,j;
	scanf("%d",&tc);
	
	for(int tt=1;tt<=tc;tt++) {
		int n;
		scanf("%d",&n);
		printf("Case #%d: ",tt);
		int a[maxn], diff[maxn];
		memset(a,0,sizeof a);
		memset(diff,0,sizeof diff);
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		for(i=1;i<=(n+1);i++){
			diff[i] = a[i] - a[i-1];
		}
		priority_queue<ii> pq;
		bool isAnswered = false;
		for(i=1;i<=(n+1);i++){
			if(diff[i]<0){
				int banyakQueryMelibatkanR = -diff[i];
				while(banyakQueryMelibatkanR) {
					
					ii front = pq.top(); pq.pop();
					int idx = -front.first, banyakQueryMelibatkanL = front.second;
					if((i - idx) < 3){
						printf("No\n");
						isAnswered = true; break;
					}
					int minim = min(banyakQueryMelibatkanL, banyakQueryMelibatkanR);
					banyakQueryMelibatkanR -= minim;
					banyakQueryMelibatkanL -= minim;
					if(banyakQueryMelibatkanL){
						pq.push(ii(front.first, banyakQueryMelibatkanL));
					}
				}
				if(isAnswered){break;}
			}else if(diff[i] > 0){
				pq.push(ii(-i,diff[i]));
			}
		}

		if(!isAnswered){
			if(pq.empty()) {
				printf("Yes\n");	
			}else{
				printf("No\n");
			}
		}
		
	}


	return 0;
};