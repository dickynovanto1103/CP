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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<int> a;

void parse(const string& kata){
	int pjg = kata.length();
	int num = 0;
	for(int i=0;i<pjg;i++){
		if(kata[i] == ' '){
			a.pb(num);
			num = 0;
		}else{
			num *= 10;
			num += (kata[i] - '0');
		}
	}
	a.pb(num);
}

int cnt[2000];

int main(){
	string s;
	int i,j;
	while(getline(cin, s)){
		a.clear();
		parse(s);
		int pjg = a.size();
		memset(cnt, 0, sizeof cnt);
		bool valid = true;
		int maks = 0;
		for(i=0;i<pjg;i++){
			for(j=i-1;j>=0;j--){
				int selisih = abs(a[i] - a[j]);
				cnt[selisih]++;
				maks = max(maks, selisih);
				if(cnt[selisih] == 2){printf("not a ruler\n"); valid = false; break;}
			}
			if(!valid){break;}
		}

		if(valid){
			vi ans;
			for(i=1;i<=maks;i++){
				if(cnt[i] == 0){ans.pb(i);}
			}
			if(ans.size() > 0){
				printf("missing");
				for(i=0;i<ans.size();i++){printf(" %d",ans[i]);}
				printf("\n");
			}else{
				printf("perfect\n");
			}

		}
	}
	return 0;
};