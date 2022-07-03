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
    string removeDuplicateLetters(string s) {
    	set<char> sc;
    	for(char c: s) {
    		sc.insert(c);
    	}
    	int numUniqueChar = sc.size();

    	string ans;

        while(s.size()) {
        	adj.assign(256, vi());
        	int n = s.size();
        	memset(isExist, false, sizeof vis);
        	for(int i=0;i<n;i++){
        		numUniqueUntilEnd[i] = 0;
        		isExist[s[i]] = true;
        	}

        	memset(vis, false, sizeof vis);

        	numUniqueUntilEnd[n-1] = 1;
        	adj[s[n-1]].pb(n-1);
        	vis[s[n-1]] = true;
        	for(int i=n-2;i>=0;i--){
        		char c = s[i];
        		adj[c].pb(i);
        		numUniqueUntilEnd[i] = numUniqueUntilEnd[i+1];
        		if(vis[c]) {
        			continue;
        		}
        		vis[c] = true;
        		numUniqueUntilEnd[i]++;
        	}
        	for(int i='a';i<='z';i++){
        		sort(adj[i].begin(), adj[i].end());
        	}

        	int numCharLeft = numUniqueChar - ans.size();
        	string newS;
        	for(char c='a';c<='z';c++){
        		if(!isExist[c]){continue;}
        		if(adj[c].size() == 0) {
        			assert(false);
        		}
        		int idx = adj[c][0];

        		if(numUniqueUntilEnd[idx] < numCharLeft) {
        			continue;
        		}
        		ans += c;
        		//remove all c from s and also that's smaller than idx;
        		string newS;
        		for(int i=0;i<n;i++){
        			if(i < idx){continue;}
        			if(s[i] == c){
        				continue;
        			}
        			newS += s[i];
        		}

        		s = newS;
        		break;
        	}
        }

        return ans;
    }
private:
	int numUniqueUntilEnd[10010];
	bool vis[256];
	vector<vi> adj;
	bool done[256];
	bool isExist[256];
};

int main(){
	string s;
	while(cin>>s){
		Solution sol;
		cout<<sol.removeDuplicateLetters(s)<<endl;
	}
	
	return 0;
};