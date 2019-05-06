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
	int a[200010];
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	int cur = -1;
	string ans = "";
	int kiri = 0, kanan = n-1;
	while(kiri<=kanan){
		int minim = min(a[kiri], a[kanan]);
		if(a[kiri] <= cur && a[kanan] <= cur){break;}
		if(a[kiri] <= cur || a[kanan] <= cur){
			if(a[kiri] <= cur){
				cur = a[kanan];
				ans += 'R'; kanan--;
				
			}else{
				cur = a[kiri];
				ans += 'L'; kiri++;
				
			}
			continue;
		}
		
		if(a[kiri] == minim && a[kanan] == minim) {
			// printf("halo\n");
			//proses kiri aja
			int curKiri = kiri, curKanan = kanan;
			string curAns = ans;
			// cout<<"ans ek:"<<ans<<endl;
			int current = cur;
			for(i=kiri;i<=kanan;i++) {
				if(cur < a[i]){
					cur = a[i];
					curAns += 'L';
				}else{break;}
			}
			string curAnsBaru = ans;
			// cout<<"ans:"<<ans<<endl;
			// cout<<curKiri<<" "<<curKanan<<endl;
			cur = current;
			for(i=kanan;i>=kiri;i--){
				if(cur < a[i]){
					cur = a[i];
					curAnsBaru += 'R';
				}else{break;}
			}
			// cout<<"curAnsBaru SEKARNG:"<<curAnsBaru<<endl;
			if(curAnsBaru.length() > curAns.length()) {
				ans = curAnsBaru;
			}else{
				ans = curAns;
			}
			cout<<ans.length()<<endl<<ans<<endl;
			return 0;

		}else {
			if(a[kiri] == minim) {
				ans += 'L';
				cur = a[kiri];
				kiri++;
			}else {
				ans += 'R';
				cur = a[kanan];
				kanan--;
			}

		}
	}
	printf("%d\n",(int)ans.length());
	cout<<ans<<endl;
	return 0;
};