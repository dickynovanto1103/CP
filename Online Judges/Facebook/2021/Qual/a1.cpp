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

bool isVowel(char c) {
	return c == 'A' || c == 'I' || c == 'U'|| c == 'E' || c == 'O';
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		string s;
		cin>>s;

		int n = s.size();
		int minim = inf;
		for(int i=0;i<26;i++){
			char dest = i + 'A';
			int cnt = 0;

			for(int j=0;j<n;j++){
				if(s[j] == dest) {
					continue;
				}
				if(isVowel(dest) == isVowel(s[j])) {
					cnt+=2;
				}else {
					cnt++;
				}
			}
			minim = min(minim, cnt);
		}

		printf("%d\n", minim);
	}
	
	return 0;
};