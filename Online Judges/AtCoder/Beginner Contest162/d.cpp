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
typedef pair<int,int> ii;
typedef vector<ii> vii;



char charBeda(char c, char d) {
	string s = "RGB";	
	for(int i=0;i<3;i++){
		if(s[i] != c && s[i] != d){
			return s[i];
		}
	}
	return '-';
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	string s;
	cin>>s;
	int pref[26][4001];
	string te = "RGB";

	for(i=0;i<n;i++){
		pref[s[i] - 'A'][i]++;
		if(i){
			for(j=0;j<3;j++){
				pref[te[j] - 'A'][i] += pref[te[j] - 'A'][i-1];
			}
		}
	}
	ll ans = 0;

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(s[i] != s[j]){
				char beda = charBeda(s[i], s[j]);
				//find beda di tempat lain
				int selisih = j - i;
				int forbidden = j + selisih;
				if(forbidden >= n){
					int banyak = pref[beda - 'A'][n-1] - pref[beda - 'A'][j];
					ans += banyak;
				}else{
					int banyak1 = pref[beda - 'A'][n-1] - pref[beda - 'A'][forbidden];
					int banyak2 = pref[beda - 'A'][forbidden-1] - pref[beda - 'A'][j];
					ans += banyak1;
					ans += banyak2;
				}
			}
			
		}
	}
	printf("%lld\n",ans);
	return 0;
};