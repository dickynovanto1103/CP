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
	map<int,int> mapper;
	mapper[1] = 2;
	mapper[2] = 2;
	mapper[-1] = 2;
	mapper[-2] = 3;
	map<int,int>::iterator it;
	for(it=mapper.begin();it!=mapper.end();it++)  {
		printf("%d %d\n",it->first, it->second);
	}
	return 0;
};