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
typedef tuple<int,int,int> tiii;
typedef vector<ii> vii;

struct CustomComparator {
	bool operator()(const int &a, const int &b) {
		return a < b;
	}
};

int main(){
	priority_queue<int, vi, CustomComparator> pq;
	pq.push(1);
	pq.push(23);
	pq.push(4);
	while(!pq.empty()) {
		printf("%d\n", pq.top()); pq.pop();
	}
	
	return 0;
};