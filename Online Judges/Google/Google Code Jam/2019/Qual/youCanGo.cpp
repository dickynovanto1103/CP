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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		string kata;
		cin>>kata;
		string ans = "";
		if(kata[0] == 'S'){ans += 'E';}
		else{
			ans += 'S';
		}
		char terakhir = kata.back();

		if(terakhir == 'E'){
			//cari cara supaya bs kanan terus sampe pol terus ke bawah pol..cari space dimana bs ke kanan terus
			if(ans[0] == 'E'){
				for(i=0;i<(n-2);i++){ans += 'E';}
				for(i=0;i<(n-1);i++){ans += 'S';}
			}else{
				bool adaKeKanan[50010];
				memset(adaKeKanan, false, sizeof adaKeKanan);
				int row = 1;
				for(i=0;i<kata.size();i++) {
					if(kata[i] == 'E'){
						adaKeKanan[row] = true;
					}else{
						row++;
					}
				}

				for(i=2;i<=n;i++){//cari di row yang ada ke kanan false
					if(!adaKeKanan[i]){
						break;
					}else{
						ans += 'S';
					}
				}
				for(i=0;i<(n-1);i++){
					ans += 'E';
				}
				while(ans.size() < kata.size()){ans += 'S';}
			}
		}else{
			//cari cara supaya bs ke bawah terus dan nanti ke kanan..berarti cari space dimana ga ada yg ke bawah
			if(ans[0] == 'S'){
				for(i=0;i<(n-2);i++){ans += 'S';}
				for(i=0;i<(n-1);i++){ans += 'E';}
			}else {
				bool adaKeBawah[50010];
				memset(adaKeBawah, false, sizeof adaKeBawah);
				int col = 1;
				for(i=0;i<kata.size();i++) {
					if(kata[i] == 'E'){
						col++;
					}else{
						adaKeBawah[col] = true;
					}
				}

				for(i=2;i<=n;i++){//cari di row yang ada ke kanan false
					if(!adaKeBawah[i]){
						break;
					}else{
						ans += 'E';
					}
				}
				for(i=0;i<(n-1);i++){
					ans += 'S';
				}
				while(ans.size() < kata.size()){ans += 'E';}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
};