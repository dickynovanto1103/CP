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

bool vis[500010];

struct compare{
	bool operator() (const ii &a, const ii &b) const{
		if(a.first == b.first){return a.second > b.second;}
		return a.first < b.first;
	}
};

int main(){
	int que,i,j;
	while(scanf("%d",&que)!=EOF){
		memset(vis, false, sizeof vis);
		int com;
		int money;
		priority_queue<ii, vii, compare> pq;
		queue<int> q;
		vi ans;
		int customerNum = 1;
		for(i=1;i<=que;i++){
			scanf("%d",&com);
			if(com == 1){
				scanf("%d", &money);
				pq.push(ii(money, customerNum));
				q.push(customerNum);
				// printf("pushed: %d %d\n", money, customerNum);
				customerNum++;
			}else if(com == 2){
				int customer = q.front(); q.pop();
				while(vis[customer]){
					customer = q.front(); q.pop();
				}
				vis[customer] = true;
				ans.pb(customer);
			}else if(com == 3) {
				ii pas = pq.top(); pq.pop();
				int customer = pas.second; 
				int money = pas.first;
				// printf("money: %d customer: %d\n", money, customer);
				while(vis[customer]){
					pas = pq.top(); pq.pop();
					customer = pas.second;
				}
				vis[customer] = true;
				ans.pb(customer);
			}
		}

		for(i=0;i<ans.size();i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
	}

	
	return 0;
};