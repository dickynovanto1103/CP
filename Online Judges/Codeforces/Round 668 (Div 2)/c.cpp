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
	int tc,i,j,n,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&k);
		string a;
		cin>>a;

		bool bisa = true;
		for(i=0;i<n;i++){
			int next = i+k;
			if((next < n)){
				if(a[next] != a[i]) {
					if((a[next] == '1' || a[next] == '0') && (a[i] == '1' || a[i] == '0')) {
						bisa = false;
						break;
					}else{
						if(a[next] == '?' && a[i] == '?') {

						}else if(a[next] == '?' && a[i] != '?'){
							a[next] = a[i];
						}else if(a[next] != '?' && a[i] == '?'){
							a[i] = a[next];
						}else{
							assert(false);
						}
					}
				}
			}
		}
		if(!bisa){printf("NO\n"); continue;}
		int cnt1 = 0, cnt0 = 0, cntT = 0;
		for(i=0;i<k;i++){
			if(a[i] == '1'){cnt1++;}
			else if(a[i] == '0'){cnt0++;}
			else{cntT++;}
		}
		int kiri = 0, kanan = k-1;
		while(kanan < n){
			//cek validity
			int selisih = abs(cnt1 - cnt0);
			if(selisih % 2 != cntT % 2){
				bisa = false;
				break;
			}
			if(selisih > cntT) {
				bisa = false;
				break;
			}
			if(a[kiri] == '1'){
				cnt1--;
			}else if(a[kiri] == '0'){
				cnt0--;
			}else{
				cntT--;
			}
			kiri++;

			kanan++;
			if(kanan < n){
				if(a[kanan] == '1'){
					cnt1++;
				}else if(a[kanan] == '0'){
					cnt0++;
				}else{
					cntT++;
				}
			}
		}

		if(bisa){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	
	return 0;
};