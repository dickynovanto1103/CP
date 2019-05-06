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
 
string kata;

int n;

int main(){
	int k,i,j;
	
	scanf("%d %d",&n,&k);
	cin>>kata;
	
	int cnt = 0, cnt1 = 0;
	set<ii> s, s1;
	int maks = 0;
	vii listPas;
	for(i=0;i<n;i++){
		if(kata[i] == '0'){
			if(cnt1){
				maks = max(maks, cnt1);
				s1.insert(ii(i-cnt1,i-1));
				// printf("dipush 1 %d %d\n",i-cnt1, i-1);
				cnt1 = 0;
			}
			cnt++;
		}else if(kata[i] == '1') {
			cnt1++;
			if(cnt){
				s.insert(ii(i-cnt,i-1));
				listPas.pb(ii(i-cnt, i-1));
				// printf("dipush 0 %d %d\n",i-cnt, i-1);
				cnt = 0;
			}
		}
	}
	if(kata[i-1] == '0'){
		s.insert(ii(i-cnt, i-1));
		listPas.pb(ii(i-cnt, i-1));
		// printf("dipush 0 %d %d\n",i-cnt, i-1);
	}else{
		maks = max(maks, cnt1);
		s1.insert(ii(i-cnt1,i-1));
		// printf("dipush 1 %d %d\n",i-cnt1, i-1);
	}
	
	if(listPas.size() <= k){
		printf("%d\n",n);
	}else{
		int left = 0, right = k-1;
		int ans = maks;
		set<ii>::iterator it, it2;
		while(right < listPas.size()) {
			int palingKiri = listPas[left].first;
			int palingKanan = listPas[right].second;
			it = s1.lower_bound(ii(palingKiri, 0));
			ii kiri = ii(1,0);
			if(it != s1.begin()){
				it--;
				kiri = *it;	
			}

			it = s1.lower_bound(ii(palingKanan+1, 0));
			ii kanan = ii(1,0);
			if(it != s1.end()){
				kanan = *it;
			}

			if(kiri != ii(1,0)){
				palingKiri = kiri.first;
			}
			if(kanan != ii(1,0)){
				palingKanan = kanan.second;
			}
			ans = max(ans, palingKanan - palingKiri + 1);

			right++;
			left++;
		}
		printf("%d\n",ans);
		return 0;
	}
	
	
	return 0;
};