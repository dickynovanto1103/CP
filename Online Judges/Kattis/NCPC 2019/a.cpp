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
	string ka;
	cin>>ka;
	int n,i,j;
	scanf("%d",&n);
	string s[100001];
	int cntBegin[26], cntEnd[26];
	memset(cntBegin, 0, sizeof cntBegin); memset(cntEnd, 0, sizeof cntEnd);
	for(i=0;i<n;i++){
		cin>>s[i];
		int pjg = s[i].size();
		char end = s[i][pjg-1];
		cntBegin[s[i][0]-'a']++; cntEnd[end-'a']++;
	}
	string ans = "?";
	int pjgAsli = ka.size();
	for(i=0;i<n;i++){
		if(s[i][0] == ka[pjgAsli-1]){
			if(ans == "?"){
				ans = s[i];	
			}
			
			int pjg = s[i].size();
			char end = s[i][pjg-1];
			cntBegin[s[i][0] - 'a']--; cntEnd[end-'a']--;
			
			if(cntBegin[end-'a'] == 0){
				ans = s[i] + "!";
				// ans += '!';
				cout<<ans<<endl;
				return 0;
			}else{
				cntBegin[s[i][0] - 'a']++; cntEnd[end-'a']++;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
};