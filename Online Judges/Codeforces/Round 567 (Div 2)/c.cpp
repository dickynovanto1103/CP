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

const int maxn = 1e3 + 3;
const ll mod = 1e9 + 7;

string s[maxn];
ll hash1[maxn][maxn];
int maksNilai[maxn][maxn];

ll getHash(int row1, int row2, int col) {
	ll hash3 = hash1[row2][col];
	ll hash2 = row1 == 0 ? 0 : hash1[row1-1][col];
	ll hash = hash3 - hash2;
	if(hash < 0){hash += mod;}
	return hash;
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		cin>>s[i];
	}

	ll p = 31;

	for(i=0;i<m;i++){
		ll pow = p;
		ll val = 0;
		for(j=0;j<n;j++){
			hash1[j][i] = (val + ((ll)(s[j][i] - 'a' + 1) * pow)%mod)%mod;
			val = hash1[j][i];
			pow *= p;
			pow %= mod;
		}
	}

	for(i=0;i<m;i++){
		char cur = 'A';
		ll nilai = 1;
		int lastIdx = 0;
		for(j=0;j<n;j++){
			if(s[j][i] != cur){
				// printf("nilai: %d lastIdx: %d sampe row: %d\n",nilai, lastIdx, j);
				for(int k=lastIdx;k<j;k++){
					maksNilai[k][i] = nilai--;
				}
				lastIdx = j;
				cur = s[j][i];
				nilai = 1;
			}else{
				nilai++;
			}
			
		}
		for(int k=lastIdx;k<n;k++){
			maksNilai[k][i] = nilai--;
		}
	}
	ll ans = 0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int maksVal = maksNilai[i][j];
			int nextRow = i + maksVal;
			if(nextRow < n && maksNilai[nextRow][j] == maksVal) {
				nextRow += maksVal;
				if(nextRow < n && maksNilai[nextRow][j] >= maksVal) {
					//cari next column yang sama mana aja
					nextRow += maksVal;
					nextRow--;
					// printf("nextRow: %d\n",nextRow);
					ll hashFirst = getHash(i,nextRow,j);
					// ll hashSecond = getHash2(i, nextRow, j);
					ll cnt = 0;
					int k;
					for(k=j;k<m;k++){
						if(hashFirst == getHash(i, nextRow, k)) {
							cnt++;
						}else{
							break;
						}
					}
					// printf("i: %d j: %d cnt: %lld\n",i,j,cnt);
					ans += (cnt*(cnt+1))/2LL;
					// printf("ans jd: %lld\n",ans);
					j = k-1;
				}else{
					continue;
				}
			}else{
				continue;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
};