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
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string s;
		cin>>s;
		int cnt[26];
		int n = s.length();
		memset(cnt, 0, sizeof cnt);
		for(i=0;i<n;i++){
			cnt[s[i] - 'a']++;
		}
		int cntOdd= 0, cnt1 = 0;
		for(i=0;i<26;i++){
			if(cnt[i] & 1) {
				cntOdd++;
				if(cnt[i] == 1){
					cnt1++;
				}
			}
		}
		if(n == 1){
			printf("DPS\n");
		}else if(n == 2){
			if(cnt1 == 0){printf("!DPS\n");}
			else{printf("DPS\n");}
		}else if(n == 3) {
			if(cnt1 == 0){printf("!DPS\n");}
			else{printf("DPS\n");}
		}else {
			if(cntOdd <= 3 && cntOdd != 0){printf("DPS\n");}
			else{printf("!DPS\n");}		
		}
		
	}
	return 0;
};