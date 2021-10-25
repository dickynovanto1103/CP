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

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	int pos[27];
	while(tc--){
		string s;
		cin>>s;
		int n = s.length();
		memset(pos, -1, sizeof pos);

		for(int i=0;i<n;i++){
			pos[s[i] - 'a'] = i;
		}
		int kiri = -1, kanan = -1;
		bool valid = true;
		for(i=0;i<n;i++){
			if(pos[i] == -1) {
				valid = false;
				break;
			}
			if(kiri == -1 && kanan == -1) {
				kiri = pos[i];
				kanan = pos[i];
				continue;
			}
			
			if(pos[i] == kiri - 1) {
				kiri--;
				continue;
			} else if(pos[i] == kanan + 1) {
				kanan++;
				continue;
			}
			valid = false;
			break;
		}
		if(valid) {
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
};