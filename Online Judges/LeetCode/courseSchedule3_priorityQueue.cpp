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

bool cmp(Pas a, Pas b) {
	return a.end < b.end;
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        n = courses.size();

        for(int i=0;i<n;i++){
        	Pas pas;
        	pas.dur = courses[i][0];
        	pas.end = courses[i][1];

        	arr[i] = pas;
        }

        sort(arr, arr + n, cmp);

        int cnt = 0, time = 0, pickedCourse = 0;
        priority_queue<int, vi> pq;
        for(int i=0;i<n;i++){
        	if(time + arr[i].dur <= arr[i].end) {
        		cnt++;
        		time += arr[i].dur;
        		
        		pq.push(arr[i].dur);
        		continue;
        	}

        	//find one that has bigger duration than the current one
        	if(pq.size() == 0 || pq.top() <= arr[i].dur) {
        		continue;
        	}

        	int largestCourse = pq.top(); pq.pop();
        	time -= largestCourse;
        	time += arr[i].dur;

        	pq.push(arr[i].dur);
        }

        return cnt;
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