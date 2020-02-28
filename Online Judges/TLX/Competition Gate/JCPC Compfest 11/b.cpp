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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string s;
vi listNol;
const int maxn = 1e6 + 1;
bool vis[maxn];
int start = -1;
int n;
int tempStart;

bool can(int mid) {
	memset(vis, false, sizeof vis);
	int i,j;
	int ukuran = listNol.size();
	debug printf("mid: %d\n",mid);
	start = tempStart;
	for(i=0;i<ukuran;i++){
		int idx = listNol[i];
		if(start > idx) {
			if(start == idx+1) {
				int last = idx;

				debug printf("lebih iterasi dari %d ke %d\n",idx+1, idx+mid);
				for(j=idx+1;j<=min(idx+mid, n-1);j++){
					last = j;
					if(s[j] == '0'){
						break;
					}
					vis[j] = true;
				}
				debug printf("last: %d\n",last);
				bool changed = false;
				for(j=last+1;j<n;j++){
					if(s[j] == '1'){changed = true; start = j; break;}
				}
				if(!changed){
					goto here;
				}
			}
		}else{
			debug printf("start: %d idx: %d mid: %d\n",start, idx, mid);
			if(idx - start > mid){

				debug printf("ga valid\n");
				return false;
			}else{
				int last = start;
				debug printf("kurang iterasi dari %d ke %d\n",start, start + mid);
				for(j=start;j<=min(start+mid, n-1);j++){
					last = j;
					if(s[j] == '0' && j > idx){break;}
					vis[j] = true;
				}
				debug printf("last: %d\n",last);
				bool changed = false;
				for(j=last+1;j<n;j++){
					if(s[j] == '1'){changed = true;start = j; break;}
				}
				if(!changed){
					goto here;
				}
			}
		}
		
	}
	here:;
	for(i=0;i<n;i++){
		if(s[i] == '1' && !vis[i]){return false;}
	}
	return true;
}

int main(){
	int i,j;
	
	scanf("%d",&n);
	cin>>s;
	
	for(i=0;i<n;i++){
		if(s[i] == '0'){
			listNol.pb(i);
		}else if(s[i] == '1' && start == -1){
			start = i;
			tempStart = start;
		}
	}

	int kiri = 1, kanan = n, mid, ans;
	while(kiri <= kanan) {
		mid = (kiri + kanan)/2;
		if(can(mid)) {
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid + 1;
		}
	}
	printf("%d\n",ans);
	return 0;
};