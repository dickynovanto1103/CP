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
	string s,t;
	cin>>s>>t;
	int n = s.size(), m = t.size();
	int kiri = 0, kanan = m-1;
	int ans = inf;
	while(kanan < n){
		int idx = 0;
		int tot = 0;
		// printf("kiri: %d kanan: %d idx: %d\n",kiri, kanan, idx);
		for(int i=kiri;i<=kanan;i++){
			// printf("s[%d]: %c t[%d]: %c\n",i,s[i],idx,t[idx]);
			if(s[i] != t[idx]){
				tot++;
			}
			idx++;
		}
		ans = min(ans, tot);
		kiri++; kanan++;
	}
	printf("%d\n",ans);
	
	return 0;
};