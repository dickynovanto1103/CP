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

int a[100001];

int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		set<ii> ans;
		set<ii>::iterator it;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		bool valid = true;
		int idx = 1;
		queue<ii> q[4];
		for(i=1;i<=n;i++){
			if(a[i] == 3){
				//cari ada ga yang 3
				if(q[3].size()) {
					ii pas = q[3].front(); q[3].pop();
					int row = pas.first, col = pas.second;
					ans.insert(ii(row, i)); ans.insert(ii(idx, i));
					q[3].push(ii(idx,i));
					idx++;
				}else{
					q[3].push(ii(idx, i));
					ans.insert(ii(idx, i));
					idx++;
				}
			}else if(a[i] == 2) {
				q[2].push(ii(idx, i));
				ans.insert(ii(idx, i));
				if(q[3].size()){
					ii pas = q[3].front(); q[3].pop();
					int row = pas.first, col = pas.second;
					ans.insert(ii(row, i)); ans.insert(ii(idx, i));
				}
				idx++;
			}else if(a[i] == 1){
				if(q[2].size()){//prioritas ke 2 karena 2 cuman bs dipasangin dengan 1
					ii pas = q[2].front(); q[2].pop();
					int row = pas.first, col = pas.second;
					ans.insert(ii(row, i));
				} else if(q[3].size()){
					ii pas = q[3].front(); q[3].pop();
					int row = pas.first, col = pas.second;
					ans.insert(ii(row, i)); ans.insert(ii(idx, i));
				} else {
					ans.insert(ii(idx, i));
				}
				idx++;
			}
		}

		for(i=0;i<=3;i++){
			if(q[i].size()){
				valid = false;
				break;
			}
		}
		if(!valid){
			printf("-1\n");
		}else{
			int sz = ans.size();
			printf("%d\n",sz);
			for(it = ans.begin(); it!=ans.end();it++){
				ii pas = *it;
				printf("%d %d\n",pas.first, pas.second);
			}
		}
	}
	
	
	
	return 0;
};