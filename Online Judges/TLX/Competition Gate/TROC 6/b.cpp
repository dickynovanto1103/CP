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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string s,t;
	int i,j;
	cin>>s>>t;
	set<char> st;
	int cnt[26];
	memset(cnt, 0, sizeof cnt);

	for(i=0;i<t.length();i++){
		st.insert(t[i]);
		
	}
	for(i=0;i<s.length();i++){
		cnt[s[i] - 'a']++;
	}
	if(st.size() > 1) {
		printf("0\n");
	}else{
		int kar = t[0] - 'a';
		int tot = 0;
		int asli = 0;
		for(i=0;i<26;i++){
			if(i != kar){
				tot += cnt[i];
			}else{
				asli += cnt[i];
			}
		}
		ll banyak = (ll)((ll)t.length() - 1) * (ll)tot;
		ll sisa = asli - banyak;
		sisa = max(sisa, 0LL);
		// printf("asli: %d sisa: %lld banyak: %lld\n",asli,sisa, banyak);
		// printf("cnt[%d]: %d\n",kar,cnt[kar]);
		int occ = sisa - t.length() + 1;
		// printf("occ: %d\n",occ);
		
		printf("%d\n",max(occ,0));
	}

	return 0;
};