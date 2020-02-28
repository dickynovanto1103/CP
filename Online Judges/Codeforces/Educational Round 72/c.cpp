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
	int n,i,j;
	scanf("%d",&n);
	string s;
	int pref[200010];

	for(int tt=0;tt<n;tt++){
		ll ans = 0;
		cin>>s;
		int pjg = s.length();
		
		for(j=0;j<pjg;j++){
			pref[j] = 0;
		}
		vi listIdx;
		for(j=0;j<pjg;j++){
			if(s[j] == '1'){
				ans++;
				pref[j] = 1;
				listIdx.pb(j);
			}
			if(j){pref[j] += pref[j-1];}
		}
		for(i=0;i<listIdx.size();i++){
			int bil = 1;
			int idx = listIdx[i];
			for(j=idx+1;j<pjg;j++){
				bil*=2;
				bil += s[j]-'0';
				if(bil > pjg){break;}
				int banyakDigit = j - idx + 1;
				int sisa = bil - banyakDigit;
				// printf("bil: %d banyakDigit: %d sisa: %d\n",bil, banyakDigit, sisa);
				if(sisa == 0){
					ans++;
				}else{
					int awal = idx-sisa;
					if(awal < 0){

					}else{
						int nilaiPref = pref[idx-1] - (awal == 0 ? 0 : pref[awal-1]);
						if(nilaiPref == 0){ans++;}
					}
				}
			}
		}
		printf("%lld\n",ans);

	}
	return 0;
};