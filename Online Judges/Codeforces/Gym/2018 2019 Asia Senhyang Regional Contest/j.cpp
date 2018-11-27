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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

bool isExistKurung(string kata) {
	int pjg = kata.length();
	int i,j;
	int nilai = 0;
	for(i=0;i<pjg;i++){
		if(kata[i] == '['){return true;}
		
	}
	return false;
}

int dalamKurung(string kata) {
	if(isExistKurung(kata)){
		int i,j;
		int pjg = kata.length();
		int sum = 0;
		bool sudah = false;
		for(i=0;i<pjg;i++){
			if(kata[i] == '['){
				sudah = true;
			}else if(kata[i] == ']'){
				sudah = false;
			}else{
				if(sudah){
					sum *= 10;
					sum += kata[i] - '0';
				}
			}
		}
		return sum;
	}else{
		return 1;
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		int n;
		scanf("%d",&n);
		string tipe, dum;
		ll tot = 0;
		for(i=0;i<n;i++){
			cin>>tipe>>dum;
			ll pengali;
			if(tipe == "bool"){
				pengali = 1;
			}else if(tipe == "int"){
				pengali = 4;
			}else if(tipe == "long"){
				if(dum == "long"){
					pengali = 8;
				}else if(dum == "double") {
					pengali = 16;
				}
				cin>>dum;

			}else if(tipe == "double"){
				pengali = 8;
			}else if(tipe == "__int128"){
				pengali = 16;
			}else if(tipe == "float") {
				pengali = 4;
			}else if(tipe == "char") {
				pengali = 1;
			}
			ll bil = dalamKurung(dum);
			tot += (bil*pengali);
			// printf("bil: %lld pengali: %lld\n",bil,pengali);
		}
		// printf("tot: %lld\n",tot);
		ll ans = (tot + (1023LL)) / 1024LL;
		printf("%lld\n", ans);
	}
	return 0;
};