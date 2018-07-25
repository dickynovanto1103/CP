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
	set<char> s;
	for(int i=0;i<kata.length();i++){
		char kar = kata[i];
		s.insert(kar);

	}
	if(s.size()%2==1){printf("IGNORE HIM!\n");}
	else{printf("CHAT WITH HER!\n");}
	return 0;
};