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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isOk(string s) {
	for(int i=0;i<s.size() - 1;i++){
		if(s[i] > s[i+1]) return false;
	}

	return true;
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		string s;
		cin>>s;
		if(isOk(s)) {
			cout<<s<<endl;
			continue;
		}

		string ans;

		for(i=0;i<s.size() - 1;i++){
			if(s[i] > s[i+1]) {
				//isi 9 di idx yang mulai ngaco
				for(j=i+1;j<s.size();j++) {
					s[j] = '9';
				}

				//mulai back, coba kurangin satu
				for(j=i;j>=1;j--){
					int num = s[j] - '0';
					num = (num - 1 + 10) % 10;
					s[j] = num + '0';
					if(s[j-1] > s[j]) {
						s[j] = '9';
					}
				}
				break;
			}
		}
	}
	
	return 0;
};