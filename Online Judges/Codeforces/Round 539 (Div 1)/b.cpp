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

bool isPalin(const string& s) {
	int i,j;
	int n = s.length();
	for(i=0;i<n/2;i++){
		if(s[i] != s[n-i-1]){return false;}
	}
	return true;
}

int main(){
	string s;
	int n,i,j;
	cin>>s;
	n = s.length();
	if(n <= 3){printf("Impossible\n"); return 0;}
	set<char> st;
	int cnt[26];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		st.insert(s[i]);
		cnt[s[i] - 'a']++;
	}

	set<char>::iterator it;
	if(st.size() == 2){
		int cnt1 = 0;
		for(it=st.begin();it!=st.end();it++){
			char el = *it;
			if(cnt[el - 'a'] == 1){cnt1++;}
		}
		if(cnt1 == 1){printf("Impossible\n"); return 0;}
		goto here;
	}else if(st.size() == 1){printf("Impossible\n");}
	else{
		here:;
		int ans = 4;
		for(i=1;i<=n/2;i++){
			string s1 = s.substr(0, i);
			int idxAkhir = n-i;
			string s2 = s.substr(idxAkhir, i);
			if(s1 == s2){continue;}
			else{
				if(s1.size() + s2.size() == n){
					ans = min(ans, 1);
				}else{
					ans = min(ans, 2);	
				}
			}
		}

		for(i=1;i<n;i++){
			int pjg = n-i;
			string s1 = s.substr(0, i);
			string s2 = s.substr(i, pjg);
			string hasil1 = s1 + s2;
			string hasil2 = s2 + s1;
			if(isPalin(hasil1) && hasil1 != s){ans = min(ans,1);}
			if(isPalin(hasil2) && hasil2 != s){ans = min(ans,1);}
		}
		
		printf("%d\n",ans);
	}

	return 0;
};