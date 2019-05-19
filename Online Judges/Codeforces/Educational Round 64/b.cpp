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

bool isValid(string kata) {
	int i;
	int pjg = kata.length();
	for(i=0;i<pjg-1;i++){
		if(abs(kata[i] - kata[i+1]) == 1){return false;}
	}
	return true;
}
int cnt[26];

vii listPas;
string ans;
void pickGenap() {
	int ukuran = listPas.size(),i,j;
	for(i=0;i<ukuran;i++){
		ii pas = listPas[i];
		for(j=pas.first + 1;j<=pas.second;j+=2){
			int banyak = cnt[j];
			for(int k=0;k<banyak;k++){
				ans+=(j+'a');
			}
		}
	}
}

void pickGanjil() {
	int ukuran = listPas.size(),i,j;
	for(i=0;i<ukuran;i++){
		ii pas = listPas[i];
		for(j=pas.first;j<=pas.second;j+=2){
			int banyak = cnt[j];
			for(int k=0;k<banyak;k++){
				ans+=(j+'a');
			}
		}
	}
}

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		string kata;
		cin>>kata;
		
		memset(cnt, 0, sizeof cnt);
		int pjg = kata.length();
		for(i=0;i<pjg;i++){
			cnt[kata[i] - 'a']++;
		}
		int front = -1, end = -1;
		
		
		for(i=0;i<26;i++){
			if(cnt[i]){
				end = i;
			}else{
				if(end - front <= 0){continue;}
				listPas.pb(ii(front + 1, end));
				// printf("dipush: %d %d\n",front+1, end);
				front = i;
				end = i;
			}
		}

		if(cnt[25]){
			listPas.pb(ii(front + 1, 25));
		}

		ans = "";
		pickGanjil();
		pickGenap();
		if(isValid(ans)){
			cout<<ans<<endl;
		}else{
			ans = "";
			pickGenap();
			pickGanjil();
			if(isValid(ans)){
				cout<<ans<<endl;
			}else{
				printf("No answer\n");
			}
		}
		listPas.clear();

	}
	return 0;
};