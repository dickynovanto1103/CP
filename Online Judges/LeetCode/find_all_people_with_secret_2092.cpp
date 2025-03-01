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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    	vector<bool> isKnowSecret(n, false);
    	isKnowSecret[0] = isKnowSecret[firstPerson] = true;
    	
    	vi timeStamps = getTimeStampsFromMeetings(meetings);
    	unordered_map<int, vii> listOfEdgesByTimeMap = getListOfEdgesByTimeMap(meetings);
    	unordered_map<int, vi> adj;
    	for(int time: timeStamps) {
    		adj.clear();
    		vii edges = listOfEdgesByTimeMap[time];
    		queue<int> q;
    		unordered_map<int, bool> isProcessed;
    		for(ii edge: edges) {
    			adj[edge.first].pb(edge.second);
    			adj[edge.second].pb(edge.first);
    			if(isKnowSecret[edge.first] && !isProcessed[edge.first]) {
    				q.push(edge.first);
    				isProcessed[edge.first] = true;
    			}

    			if(isKnowSecret[edge.second] && !isProcessed[edge.second]) {
    				q.push(edge.second);
    				isProcessed[edge.second] = true;
    			}
    		}

    		while(!q.empty()) {
    			int front = q.front(); q.pop();
    			for(int i=0;i<adj[front].size();i++){
    				int v = adj[front][i];
    				if(isKnowSecret[v]) {
    					continue;
    				}

    				isKnowSecret[v] = true;
    				q.push(v);
    			}
    		}
    	}

  		vi ans;
  		for(int i=0;i<n;i++){
  			if(isKnowSecret[i]){
  				ans.pb(i);
  			}
  		}
  		return ans;
    }

    unordered_map<int, vii> getListOfEdgesByTimeMap(vector<vector<int>>& meetings) {
    	unordered_map<int, vii> listOfEdgesByTimeMap;
    	for(int i=0;i<meetings.size();i++){
    		int from = meetings[i][0], to = meetings[i][1], time = meetings[i][2];
    		listOfEdgesByTimeMap[time].pb(ii(from, to));
    	}

    	return listOfEdgesByTimeMap;
    }

    vector<int> getTimeStampsFromMeetings(vector<vector<int>>& meetings) {
    	vi ans;
    	set<int> timeStamps;
    	set<int>::iterator it;
  		for(int i=0;i<meetings.size();i++){
  			int time = meetings[i][2];
  			timeStamps.insert(time);
  		}

  		for(it=timeStamps.begin();it!=timeStamps.end();it++){
  			ans.pb(*it);
  		}

  		return ans;
    }
};

void solve(){

}

int main(){
	int tc = 1;
	scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};