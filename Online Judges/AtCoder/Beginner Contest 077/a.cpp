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
	string kata1,kata2;
	int i,j;
	cin>>kata1>>kata2;
	i=0;
	for(i=0;i<3;i++){
		j=2-i;
		if(kata1[i]!=kata2[j]){break;}
	}
	if(i==3){printf("YES\n");}
	else{printf("NO\n");}
	return 0;
};