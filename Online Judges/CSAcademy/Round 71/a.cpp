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
	bool isA = false;
	for(int i=0;i<kata.length();i++){
		char kar = kata[i];
		if(kar=='A'){
			if(!isA){printf("%c",kar); isA = true;}
		}else{
			isA = false;
			printf("%c",kar);
		}
	}
	printf("\n");
	return 0;
};