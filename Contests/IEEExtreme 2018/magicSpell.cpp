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
	int n,i,j;
	scanf("%d\n",&n);
	ll sum = 0;
	for(i=0;i<n;i++){
		string kata;
		getline(cin,kata);
		cout<<kata<<endl;

		for(j=0;j<kata.length();j++){
			sum += (kata[j] * (j+1));
			
		}
	}
	printf("%lld\n",sum);
	return 0;
};