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
	int n,i,j,a[550];
	ll k;
	scanf("%d %lld",&n,&k);
	int maks = n;
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	if(k>(ll)n){printf("%d\n",maks);}
	else{
		queue<int> q;
		for(i=0;i<n;i++){
			q.push(a[i]);
		}
		int ans;

		
		int cnt = 0;
		while(true){
			int front = q.front(); q.pop();
			ll tt;
			
			bool udah = false;
			while(cnt<k){
				if(q.empty()){break;}
				int bil = q.front();
				if(front<bil){
					//printf("yang menang: %d front dipush ke belakang\n",bil);
					q.push(front);
					cnt = 1;
					// printf("listbil:");
					// while(!q.empty()){
					// 	printf(" %d",q.front());
					// 	cadangan.push(q.front()); q.pop();
					// }
					// printf("\n");
					// while(!cadangan.empty()){
					// 	//printf(" %d",q.front());
					// 	q.push(cadangan.front()); cadangan.pop();
					// }
					break;
				}else{
					//printf("yang dipush ke belakang: %d\n",bil);
					q.push(bil); q.pop();
					// printf("listbil:");
					// while(!q.empty()){
					// 	printf(" %d",q.front());
					// 	cadangan.push(q.front()); q.pop();
					// }
					// printf("\n");
					// while(!cadangan.empty()){
					// 	//printf(" %d",q.front());
					// 	q.push(cadangan.front()); cadangan.pop();
					// }
					cnt++;
				}
				if(cnt==k){
					ans = front;
					udah = true; break;
				}
			}
			if(udah){break;}
			
			
		}
		printf("%d\n",ans);
	}
	return 0;
};