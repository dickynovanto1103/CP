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
typedef vector<char> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string kata;
	int i,j;
	while(cin>>kata, kata!="0"){
		multiset<char> kecil, besar;
		multiset<char>::iterator it;
		int pjg = kata.length();
		int cnt[256];
		memset(cnt, 0, sizeof cnt);
		for(i=0;i<pjg;i++){
			char kar = kata[i];
			if(kar >= 'A' && kar <= 'Z'){
				besar.insert(kar);
			}else{
				kecil.insert(kar);
			}
			cnt[kar]++;
		}
		string ans = "";
		if(kecil.size() == 0){
			printf("no WFF possible\n");
			continue;
		}else if(kecil.size() == 1){
			if(besar.count('N') == 0){printf("no WFF possible\n"); continue;}
			else{
				int banyakN = besar.count('N');
				for(i=0;i<banyakN;i++){
					ans += 'N';
				}
				ans += *kecil.begin();
			}
		}else{
			int banyakN = besar.count('N');
			for(i=0;i<banyakN;i++){
				ans += 'N';
			}
			besar.erase('N');
			int banyakKecil = kecil.size();
			int banyakBesar = besar.size();
			vi listKecil, listBesar;
			for(it = kecil.begin(); it!=kecil.end();it++){
				listKecil.pb(*it);
			}
			for(it = besar.begin(); it!=besar.end();it++){
				listBesar.pb(*it);
			}
			if(banyakBesar+1 <= banyakKecil){
				while(!listBesar.empty()){
					ans += listBesar.back();
					ans += listKecil.back();
					listBesar.pop_back(); listKecil.pop_back();
				}
				ans += listKecil.back();
			}else{
				while(!listBesar.empty()){
					ans += listBesar.back();
					ans += listKecil.back();
					listBesar.pop_back(); listKecil.pop_back();
					if(listKecil.size() == 1){break;}
				}
				ans += listKecil.back();
			}
		}
		cout<<ans<<endl;

	}
	return 0;
};