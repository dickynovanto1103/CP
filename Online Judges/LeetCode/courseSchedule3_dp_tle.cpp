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

struct Pas {
	int dur;
	int end;
};

int dp[10001][10001];

bool cmp(Pas a, Pas b) {
	return a.end < b.end;
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        n = courses.size();
        for(int i=0;i<=n;i++){
    	for(int j=0;j<=10000;j++){
        		dp[i][j] = -1;
        	}
        }
        for(int i=0;i<n;i++){
        	Pas pas;
        	pas.dur = courses[i][0];
        	pas.end = courses[i][1];

        	arr[i] = pas;
        }

        sort(arr, arr + n, cmp);

        return solve(0, 0);
    }

    int solve(int idx, int lastPlace) {
    	if(idx == n){return 0;}
    	int& ans = dp[idx][lastPlace];
    	if(ans != -1) return ans;
    	if(lastPlace + arr[idx].dur > arr[idx].end) {return solve(idx+1, lastPlace);}

    	return ans = max(solve(idx + 1, lastPlace), 1 + solve(idx + 1, lastPlace + arr[idx].dur));
    }

private:
	Pas arr[10001];
	int n;
};

int main(){
	int n;
	while(cin>>n) {
		vector<vi> courses;
		for(int i=0;i<n;i++){
			int dur, end;
			scanf("%d %d",&dur,&end);
			vi v = {dur, end};
			courses.pb(v);
		}

		Solution sol;
		cout<<sol.scheduleCourse(courses)<<endl;
	}
	
	return 0;
};