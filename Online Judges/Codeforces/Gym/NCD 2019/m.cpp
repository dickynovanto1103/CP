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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a,b,c,d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a == 0){
			if(c)
				puts("Congrats");
			else
				puts("Lazy");
		}
		else if(c == 0){
			puts("HaHa");
		}
		else if(b == 0 && d == 0)
			puts("Lazy");
		else if(b == d && a == c)
			puts("Lazy");
		else{
			double x = b/10.0 * log10(a);
			double y = d/10.0 * log10(c);
			if(fabs(x - y) < eps)
				puts("Lazy");
			else if(x < y)
				puts("Congrats");
			else
				puts("HaHa");
		}
	}
	return 0;
};