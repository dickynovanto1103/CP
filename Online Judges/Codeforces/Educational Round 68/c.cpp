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
		string s[3];
		for(i=0;i<3;i++){cin>>s[i];}
		int cnt[3][26];
		memset(cnt, 0, sizeof cnt);
		for(i=0;i<3;i++){
			int pjg = s[i].length();
			for(j=0;j<pjg;j++){
				cnt[i][s[i][j] - 'a']++;
			}
		}
		if(s[0].length() > s[1].length()){printf("NO\n"); continue;}
		bool valid = true;
		int pjgA = s[0].length();
		int idxA = 0, idxB = 0;
		for(i=idxA;i<s[0].length();i++){
			char c = s[1][idxB];
			if(c != s[0][i]){
				//cari s[1][i] di s[2]
				if(cnt[2][c - 'a'] > 0){
					cnt[2][c - 'a']--;
					i--;
					pjgA++;
				}else{
					valid = false;
					break;
				}
			}
			idxB++;
			idxA++;
			if(pjgA > s[1].length()){valid = false; break;}
		}
		for(i=idxB;i<s[1].length();i++){
			char c = s[1][i];
			if(cnt[2][c-'a'] > 0){
				cnt[2][c-'a']--;
			}else{
				valid = false;
				break;
			}
		}
		if(valid){printf("YES\n");}
		else{printf("NO\n");}

		// for(i=0;i<26;i++){
		// 	if(cnt[0][i] > cnt[1][i]){valid = false; break;}
		// 	int minim = cnt[0][i];
		// 	cnt[1][i] -= minim;
		// 	cnt[0][i] -= minim;
		// }
		// if(!valid){printf("NO\n"); continue;}
		// for(i=0;i<26;i++){
		// 	if(cnt[2][i] >= cnt[1][i]){
		// 	}else{
		// 		printf("kena\n");
		// 		valid = false; break;
		// 	}
		// }
		// if(!valid){printf("NO\n");}
		// else{printf("YES\n");}
	}
	return 0;
};