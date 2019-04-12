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

int n,i,j,k,t;
int m, h, w;
int a[1000][1000];
char s[15];

int main(){
	scanf("%d", &t);
	while(t--){
		int a=0, b=0, c=0;
		scanf("%s", s);
		for(int i=0;i<10;++i)
			a += s[i]-'0';
		scanf("%s", s);
		for(int i=0;i<10;++i)
			b += s[i]-'0';
		scanf("%s", s);
		for(int i=0;i<10;++i)
			c += s[i]-'0';
		int ma = 0;
		for(int i=0;i<=min(a, b);++i){
			int d = a + b - 2*i;
			if(d > 10) continue;
			for(int j=0;j<=min(d, c);++j){
				int e = c + d -2*j;
				if(e > 10) continue;
				ma = max(ma, e);
			}
		}
		for(int i=0;i<ma;++i)
			printf("1");
		for(int i=ma;i<10;++i)
			printf("0");
		puts("");
	}
	// scanf("%d %d %d %d", &n, &m, &h, &w);
	// for(int i=0;i<n;++i){
	// 	for(int j=0;j<m;++j){
	// 		scanf("%d", a+i);
	// 	}
	// }
	// int ans = n*m;
	// for(int i=0;i<=n-h;++i){
	// 	set<int> b, c;
	// 	for(int j=0;j<w;++j){
	// 		for(int l=0;l<h;++l){
	// 			if(b.size() == c.size())
	// 				b.insert(a[l+i][j]);
	// 			else if(b.size() > c.size())
	// 				c.insert(a[l+i][j]);
	// 			else
	// 				b.insert(a[l+i][j]);
	// 		}
	// 	}
	// }
	return 0;
};