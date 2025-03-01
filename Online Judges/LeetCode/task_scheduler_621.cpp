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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int cnt[26] = {0};
        for(int i=0;i<tasks.size();i++){
        	int task = tasks[i] - 'A';
        	cnt[task]++;
        }

        priority_queue<ii, vii> pq;
        for(int i=0;i<26;i++){
        	if(cnt[i] > 0) {
        		pq.push(ii(cnt[i], i));
        	}
        }

        int ans = 0;
        while(!pq.empty()) {
        	vii remainingTasksNow;
        	for(int i=0;i<=n;i++){
        		// printf("pq size: %d i: %d\n", pq.size(), i);
        		ans++;
        		if(pq.empty()) {
        			if(remainingTasksNow.size() > 0) {
        				continue;
        			}else{
        				ans--; //because there is no remaining task, so need to finish the work, hence the decrementing the time answer
        				break;
        			}
        		}
        		ii top = pq.top(); pq.pop();
        		int cntTask = top.first, taskNum = top.second;
        		cntTask--;
        		if(cntTask > 0) {
        			remainingTasksNow.push_back(ii(cntTask, taskNum));
        		}
        	}

        	for(int i=0;i<remainingTasksNow.size();i++){
        		pq.push(remainingTasksNow[i]);
        	}
        }

        return ans;
    }
};

void solve(){

}

int main(){
	// int tc = 1;
	// scanf("%d",&tc);
	// while(tc--){
	// 	solve();
	// }

	int n, intervalSize;
	while(cin>>n>>intervalSize) {
		vector<char> tasks(n, '\0');
		for(int i=0;i<n;i++){
			cin>>tasks[i];
		}

		Solution s;
		int ans = s.leastInterval(tasks, intervalSize);
		printf("%d\n", ans);
	}

	return 0;
};