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
typedef pair<int,string> is;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<is> vis;

vis v;

ii find(int angka) {
	int kiri = 0, kanan = 10000, mid, ansAwal;

	while(kiri <= kanan){
		mid = (kiri+kanan)/2;
		if(v[mid].first >= angka){
			ansAwal = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}
	}
	kiri = 0, kanan = 10000;
	int ansAkhir;

	while(kiri <= kanan){
		mid = (kiri+kanan)/2;
		if(v[mid].first <= angka){
			ansAkhir = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	return ii(ansAwal, ansAkhir);
}

int main(){
	int tc,u,i,j;
	scanf("%d",&tc);

	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&u);
		v.clear();
		for(i=0;i<10000;i++){
			int bil;
			string s;
			cin>>bil>>s;
			v.pb(is(bil, s));
		}
		sort(v.begin(), v.end());
		set<string> s;
		string ans[11];
		for(i=1;i<=10;i++){

			ii idx = find(i);
			// printf("i: %d idx: %d %d\n",i, idx.first, idx.second);
			int awal = idx.first, akhir = idx.second;
			for(j=awal;j<=akhir;j++){
				
				if(s.find(v[j].second) == s.end()){
					s.insert(v[j].second);
					ans[i] = v[j].second;
					// printf("ans[%d]: ",i); cout<<ans[i]<<endl;
					break;
				}
			}
		}
		string sepuluh = ans[10];
		string jawab;
		jawab.pb(sepuluh[1]);
		for(i=1;i<=9;i++){jawab += ans[i];}
		cout<<jawab<<endl;
	}
	
	return 0;
};