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
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string s;
		cin>>s;
		ii pas[100];
		int n = s.size();
		for(i=0;i<n;i++){
			int angka = s[i] - '0';
			pas[i].fi = angka;
			pas[i].se = angka;
		}
		for(i=0;i<n-1;i++){
			int minim = min(pas[i].se, pas[i+1].fi);
			pas[i].se -= minim;
			pas[i+1].fi -= minim;
		}
		for(i=0;i<n;i++){
			for(j=0;j<pas[i].fi;j++){
				printf("(");
			}
			printf("%c",s[i]);
			for(j=0;j<pas[i].se;j++){
				printf(")");
			}
		}
		printf("\n");
	}
	return 0;
};