#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,q;
	string kata;
	map<string,int> mapper;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>kata;
		mapper[kata] = i;
	}
	while(q--){
		cin>>kata;
		if(mapper.find(kata)==mapper.end()){printf("-1\n");}
		else{printf("%d\n",mapper[kata]);}
	}
	return 0;
}