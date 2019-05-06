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

vi satu, dua, both, notBoth;
vi ans;
string c,a;

bool isValid(int banyak1, int n) {
	ans.clear();
	int banyak2 = banyak1;
	bool vis[5002];
	memset(vis, false, sizeof vis);
	int tot = both.size() + satu.size();
	int i;
	if(tot == banyak1) {
		for(i=0;i<both.size();i++){
			ans.pb(both[i]);
			vis[both[i]] = true;
		}
		for(i=0;i<satu.size();i++){
			ans.pb(satu[i]);
			vis[satu[i]] = true;
		}

		for(i=0;i<dua.size();i++){
			if(ans.size() == (n/2)){break;}
			ans.pb(dua[i]);
			vis[dua[i]] = true;
		}

		for(i=0;i<notBoth.size();i++){
			if(ans.size() == (n/2)){break;}
			ans.pb(notBoth[i]);
			vis[notBoth[i]] = true;
		}
		
		for(i=1;i<=n;i++){
			if(!vis[i]) {
				if(a[i-1] == '1'){banyak2--;}
			}
		}
		if(banyak2 == 0 && ans.size() == n/2){return true;}
		else{return false;}
	}else if(tot < banyak1) {
		return false;
	}else{
		int tot2 = both.size() + dua.size();
		if(tot2 == banyak2) { //banyak 2 sesuai tp banyak 1 ga sesuai
			for(i=0;i<both.size();i++){
				vis[both[i]] = true;
			}
			for(i=0;i<dua.size();i++){
				vis[dua[i]] = true;
			}
			for(i=0;i<satu.size();i++){
				if(ans.size() == banyak1){break;}
				ans.pb(satu[i]);
			}
			
			for(i=0;i<notBoth.size();i++){
				if(ans.size() == n/2){break;}
				ans.pb(notBoth[i]);
			}

			if(ans.size() == n/2){return true;}
			else{return false;}
		}else if(tot2 < banyak2){
			return false;
		}else{
			int sisaBoth = both.size(), sisaSatu = satu.size(), sisaDua = dua.size();
			bool final = false;
			// printf("gan: \n");
			for(i=0;i<both.size();i++){
				if(ans.size() == banyak1){break;}
				// printf("both[%d]: %d\n",i,both[i]);
				ans.pb(both[i]);
				vis[both[i]] = true;
				sisaBoth--;

				if(sisaBoth + sisaDua == banyak2){
					final = true;
					break;
				}
			}
			for(i=0;i<satu.size();i++){
				if(ans.size() == banyak1){break;}
				// printf("dipush %d\n",satu[i]);
				ans.pb(satu[i]);
				vis[satu[i]] = true;
				sisaSatu--;
			}
			for(i=0;i<dua.size();i++){
				if(final){break;}
				if(ans.size() == (n/2)){break;}
				// printf("dipush %d\n",satu[i]);
				ans.pb(dua[i]);
				vis[dua[i]] = true;
				sisaDua--;
				if(sisaBoth + sisaDua == banyak2) {
					final = true;
					break;
				}
			}
			for(i=0;i<notBoth.size();i++){
				if(ans.size() == (n/2)){break;}
				// printf("dipush %d\n",notBoth[i]);
				ans.pb(notBoth[i]);
				vis[notBoth[i]] = true;
			}

			banyak2 = 0;
			for(i=1;i<=n;i++){
				if(!vis[i]) {
					if(a[i-1] == '1'){banyak2++;}
				}
			}
			if(banyak2 == banyak1 && ans.size() == n/2){return true;}
			else{return false;}
		}
	}
	
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	cin>>c>>a;
	
	for(i=0;i<n;i++){
		if(c[i] == a[i]){
			if(c[i] == '0'){notBoth.pb(i+1);}
			else{both.pb(i+1);}
		}else{
			if(c[i] == '1'){satu.pb(i+1);}
			else{dua.pb(i+1);}
		}
	}
	int req = n/2;
	for(i=0;i<=req;i++){ //jumlah 1 sebanyak i
		if(isValid(i, n)){
			// printf("ans.size: %d\n",(int)ans.size());
			for(j=0;j<ans.size();j++){
				if(j){printf(" ");}
				printf("%d",ans[j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
};