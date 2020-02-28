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
	string s;
	cin>>s;
	int cnt[256];
	memset(cnt, 0, sizeof cnt);
	for(int i=0;i<s.length();i++){
		cnt[s[i]]++;
	}
	int counter = 0;
	for(int i='A';i<='Z';i++){
		if(cnt[i] == 2) {
			counter++;
		}else if(cnt[i] == 0) {

		}else{
			printf("No\n");
			return 0;
		}
	}

	if(counter == 2){
		printf("Yes\n");
	}

	return 0;
};