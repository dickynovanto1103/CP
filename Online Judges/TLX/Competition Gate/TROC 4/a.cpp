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
	for(int i=2;i<=100;i++){
		if(i%a == 0 || i%b == 0 || i%c == 0){continue;}
		else{printf("%d\n",i); return 0;}
	}

	return 0;
};