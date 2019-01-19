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
	string kata;
	int test=1;
	while(cin>>kata && kata!="*"){

		printf("Case %d: ",test++);
		if(kata=="Hajj"){cout<<"Hajj-e-Akbar"<<endl;}
		else{cout<<"Hajj-e-Asghar"<<endl;}
	}
	return 0;
}