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
	multiset<int> s;
	multiset<int>::iterator it;
	for(int i=0;i<10;i++){
		s.insert(i); s.insert(i);
	}

	it = s.find(1);
	s.erase(it);
	for(it=s.begin();it!=s.end();it++){
		printf("%d ",*it);
	}
	printf("\n");


	return 0;
};