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
	int i;
	getline(cin,kata);
	ll sum = 1;
	for(i=0;i<kata.length();i++){
		if(kata[i]=='e'){

			if(kata[i+1]=='u'){sum*=3; sum%=1000000007;}
			else{sum*=2; sum%=1000000007;}
		}
	}
	printf("%lld\n",sum);
	return 0;
}