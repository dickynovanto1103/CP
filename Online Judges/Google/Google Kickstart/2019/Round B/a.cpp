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

int pref[100010][27];

void process(string kata) {
	int i,j;
	for(i=0;i<kata.length();i++){
		pref[i][kata[i] - 'A']++;
	}
	for(i=1;i<kata.length();i++){
		for(j=0;j<26;j++){
			pref[i][j] += pref[i-1][j];
		}
	}
}

bool isCan(int a,int b) {
	int genap = 0, ganjil = 0;
	for(int i=0;i<26;i++){
		int cnt = pref[b][i] - (a == 0 ? 0: pref[a-1][i]);
		if(cnt & 1){ganjil++;}
		else{genap++;}

	}
	// printf("a: %d b: %d ganjil: %d genap: %d\n",a,b,ganjil, genap);
	return ganjil <= 1;
}

int main(){
	int tc,i,j,n,q;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		memset(pref, 0, sizeof pref);
		scanf("%d %d",&n,&q);
		string kata;

		cin>>kata;
		process(kata);
		int ans = 0;
		for(i=0;i<q;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			a--; b--;
			if(isCan(a,b)){
				ans++;
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
};