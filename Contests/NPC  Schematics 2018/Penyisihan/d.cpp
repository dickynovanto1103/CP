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
	ll bil, last;
	while(scanf("%lld",&bil) !=EOF){
		s.insert(bil);
		last = bil;
	}
	it = s.find(last);
	s.erase(it);
	for(it=s.begin();it!=s.end();it++){
		ll num = *it;
		s.erase(it);
		// printf("num: %lld\n",num);
		ll harapan = last - num;
		if(s.find(harapan) != s.end()){printf("ADA\n"); return 0;}
		s.insert(num);
	}
	printf("TIDAK ADA\n");
	return 0;
};