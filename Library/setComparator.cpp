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

struct compare{
	bool operator() (const int &a, const int &b) const{
		return a < b;
	}
};

int main() {
	set<int,compare> s;
	s.insert(1);
	s.insert(34);
	s.insert(4);
	set<int,compare>::iterator it;
	for(it=s.begin(); it!=s.end();it++){
		printf("%d\n", *it);
	}
}

