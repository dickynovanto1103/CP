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
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string s;
		int cnt[26];
		memset(cnt, 0, sizeof cnt);
		for(i=0;i<n;i++) {
			cin>>s;
			for(j=0;j<s.length();j++){
				char c = s[j];
				cnt[c - 'a']++;
			}
		}
		bool bisa = true;
		for(i=0;i<26;i++){
			if(cnt[i] % n != 0){
				bisa = false;
				break;
			}
		}
		if(bisa){printf("YES\n");}
		else{printf("NO\n");}
	}
	
	return 0;
};