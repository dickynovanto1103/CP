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
	string kata;
	int i,j;
	cin>>kata;
	int cnt = 0;
	for(i=0;i<kata.length();i++){
		char kar = kata[i];
		if(kar=='a' || kar=='i' || kar=='u' || kar=='e' || kar=='o' || kar=='1' || kar=='3' || kar=='5' || kar=='7' || kar=='9'){
			cnt++;
		}
	}
	printf("%d\n",cnt );
	return 0;
};