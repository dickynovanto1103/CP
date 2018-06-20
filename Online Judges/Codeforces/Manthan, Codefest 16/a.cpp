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

int gcdExtended(int a, int b, int &x, int &y) {
	if(a==0) {
		x = 0;
		y = 1;
		return b;
	}
	int x1,y1;
	int hasilGCD = gcdExtended(b%a, a, x1,y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return hasilGCD;
}

bool findSolution(int a, int b, int c, int &x, int &y, int &gcd) {
	gcd = gcdExtended(a, b, x, y);
	if(c%gcd){
		return false;
	}else{
		// printf("x: %d y: %d\n",x,y);
		x*=(c/gcd);
		y*=(c/gcd);
		if(x<0 || y<0){
			if(x<0){
				while(x<0){
					x+=(b/gcd);
					y-=(a/gcd);
					// printf("jadi x: %d y: %d\n",x,y );
				}
				if(y<0){return false;}
				
			}else if(y<0){
				while(y<0){
					x-=(b/gcd);
					y+=(a/gcd);
				}
				if(x<0){return false;}
			}
		}
		return true;
	}
}

int main(){
	int n,m,c;
	scanf("%d %d %d",&n,&m,&c);
	int x,y,gcd;
	if(findSolution(n,m,c,x,y,gcd)) {
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
};