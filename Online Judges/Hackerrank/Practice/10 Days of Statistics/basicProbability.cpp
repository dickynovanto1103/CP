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
	int i,j;
	int cnt = 0;
	for(i=1;i<=6;i++){
		for(j=1;j<=6;j++){
			if((i+j)<=9){cnt++;}
		}
	}
	printf("%d\n",cnt);
	return 0;
};