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
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int ans;
	if(b>=a && b<=c){ans = c-a+1;}
	else{
		ans = abs(b-a) + abs(b-c) + 1;
	}
	printf("%d\n",ans);
	return 0;
};