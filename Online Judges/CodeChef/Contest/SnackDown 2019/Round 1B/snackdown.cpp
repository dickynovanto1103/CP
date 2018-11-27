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
	set<int> s;
	s.insert(2010); s.insert(2015); s.insert(2016);s.insert(2017);s.insert(2019);
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int bil;
		scanf("%d",&bil);
		if(s.count(bil)){printf("HOSTED\n");}
		else{printf("NOT HOSTED\n");}
	}
	return 0;
};