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
	int y,b,r;
	scanf("%d %d %d",&y,&b,&r);
	if(b <= y){
		y = b-1;
	}else{
		b = y+1;
	}
	if(r > b){
		r = b+1;
	}else{
		b = r-1;
		y = b-1;
	}
	printf("%d\n",r+b+y);

	return 0;
};