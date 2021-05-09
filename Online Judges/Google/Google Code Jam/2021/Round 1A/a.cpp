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

string append0(string s, int cntDigit) {
	for(int i=0;i<cntDigit;i++){
		s += "0";
	}
	return s;
}

int len(string s) {
	return s.size();
}

ll convertStringToInteger(string s) {
	ll ans = 0;
	for(int i=0;i<len(s);i++){
		ans *= 10;
		ans += s[i] - '0';
	}
	return ans;
}

string convertIntToStringWith0Prefix(ll n, int initialPanjangString) {
	string s;
	while(n) {
		int mod = n % 10;
		n /= 10;
		s += mod + '0';
	}
	reverse(s.begin(), s.end());
	string ans;
	int num0ToAppend = max(initialPanjangString - len(s), 0);
	ans.append(num0ToAppend, '0');
	ans.append(s);
	return ans;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	string s[102];
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			cin>>s[i];
		}

		int ans = 0;
		for(i=0;i<n-1;i++){
			j = i+1;
			int lenJ = s[j].size(), lenI = s[i].size();
			if(s[i] < s[j]) {
				int tambahDigit = max(lenI - lenJ, 0);
				ans += tambahDigit;
				s[j] = append0(s[j], tambahDigit);
			} else if(s[i] == s[j]) {
				ans++;
				s[j] = append0(s[j], 1);
			} else { //s[i] > s[j]
				if(len(s[i]) < len(s[j])) { // 8, 70
					continue;
				}else if(len(s[i]) == len(s[j])) { // 8 7 -> 8 70
					//tambah 1 digit 0 di belakang
					ans++;
					s[j] = append0(s[j], 1);
				}else{ //len(i) > len(j)
					int minPanjang = min(len(s[i]), len(s[j]));
					string s1 = s[i].substr(0, minPanjang);
					string s2 = s[j].substr(0, minPanjang);
					ll bil1 = convertStringToInteger(s1), bil2 = convertStringToInteger(s2);

					int selisihPanjang = len(s[i]) - len(s[j]);
					if(bil1 > bil2) {
						ans += selisihPanjang + 1;
						s[j] = append0(s[j], selisihPanjang + 1);

						continue;
					} else if(bil1 == bil2){ 
						string substr = s[i].substr(len(s[j]), selisihPanjang);

						ll bil = convertStringToInteger(substr);
						bil++;
						string stringJadi = convertIntToStringWith0Prefix(bil, len(substr));
						if(bil == 1){
							ans += len(stringJadi);
							s[j].append(stringJadi);
							continue;
						}
						
						if(len(stringJadi) == len(substr)) {
							ans += len(stringJadi);
							s[j].append(stringJadi);
							continue;
						}else{
							ans += len(stringJadi);
							s[j].append(len(stringJadi), '0');
							continue;
						}
					}else{
						assert(false);
					}
					
					
				}
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
};