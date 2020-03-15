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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,a,b,c,d;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int y = abs(b-d);
		int x = abs(a-c);
		int gcd = __gcd(x,y);
		if(gcd == 0){printf("0\n"); continue;}
		x /= gcd; y /= gcd;
		int selisihX = abs(c - a);
		int selisihY = abs(d - b);
		int satu = inf;
		if(x != 0){
			satu = selisihX / x;
		}

		int dua = inf;
		if(y != 0) {
			dua = selisihY / y;
		}
		if(satu == dua && satu == inf){printf("0\n"); continue;}
		satu--; dua--;
		printf("%d\n",min(satu, dua));
	}
	return 0;
};