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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		priority_queue<int, vi, greater<int> > pq;
		for(i=0;i<n;i++){
			int bil;
			scanf("%d",&bil);
			pq.push(bil);
		}
		bool valid = false;
		while(pq.size() > 1) {
			int depan = pq.top(); pq.pop();
			int belakang = pq.top(); pq.pop();
			// printf("depan: %d belakang: %d\n",depan, belakang);
			if(depan == 2048){valid = true; break;}
			else{
				if(depan > 2048){break;}
				else{
					if(depan == belakang) {
						pq.push(depan + belakang);
					}else{
						pq.push(belakang);
					}
				}
			}
		}
		if(pq.top() == 2048){valid = true;}
		if(valid){printf("YES\n");}
		else{printf("NO\n");}
	}
	return 0;
};