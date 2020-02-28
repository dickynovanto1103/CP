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
	int n,i,j;
	scanf("%d",&n);
	string s;
	cin>>s;
	int cnt[26];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		cnt[s[i] - 'a']++;
	}
	int o = 'o' - 'a', z = 'z' - 'a', e = 'e'-'a', r = 'r' - 'a', nn = 'n' - 'a';
	vi a;
	while(cnt[o] && cnt[nn] && cnt[e]){
		a.pb(1);
		cnt[o]--;cnt[nn]--;cnt[e]--;
	}
	while(cnt[o] && cnt[z] && cnt[e] && cnt[r]){
		a.pb(0);
		cnt[o]--;cnt[z]--;cnt[e]--; cnt[r]--;
	}
	for(int x: a){
		printf("%d ",x);
	}
	printf("\n");
	return 0;
};