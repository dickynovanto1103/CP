#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	string a,b;
	int tc,q;
	scanf("%d",&tc);
	while(tc--){
		cin>>a;
		scanf("%d",&q);
		while(q--){
			cin>>b;
			int foundAt = a.find(b);
			if(foundAt==string::npos){printf("n\n");}
			else{printf("y\n");}
		}
	}
	return 0;
}