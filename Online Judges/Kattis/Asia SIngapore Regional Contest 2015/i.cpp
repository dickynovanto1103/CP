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

ll cnt = 0;

void coba(int a, int b, int c, int last){
	if(a==0 && b==0 && c==0){
		cnt++;
		return;
	}
	if(last != 1 && a > 0)
		coba(a-1, b, c, 1);
	if(last != 2 && b > 0)
		coba(a, b-1, c, 2);
	if(last != 3 && c > 0)
		coba(a, b, c-1, 3);
}

int main(){
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	coba(a,b,c, 0);
	printf("%lld\n", cnt);
	return 0;
};