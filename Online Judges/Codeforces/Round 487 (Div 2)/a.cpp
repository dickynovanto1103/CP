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
	cin>>kata;
	int n,i,j;
	n = kata.length();
	int dx[] = {};
	set<char> s[110];
	for(i=0;i<n;i++){
		char kar = kata[i];
		if(kar=='.'){continue;}
		s[i].insert(kar);
		if((i-1)>=0){
			s[i-1].insert(kar);
		}
		if((i+1)<n){
			s[i+1].insert(kar);
		}
	}
	int valid = false;
	for(i=0;i<110;i++){
		if(s[i].size()==3){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
};