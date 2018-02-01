#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int a,b,c,x;
	scanf("%d %d %d %d",&a,&b,&c,&x);
	int idx = x;
	int cnt = 0;
	do{
		idx = (a*idx + b)%c;
		cnt++;
	}while(idx!=x);
	printf("%d\n",cnt);
	return 0;
}