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
	int pjg = 0;
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
			pjg++;
		}else{
			// printf("kiri: %d kanan: %d\n",kiri, kanan);
			if(a[kiri] == minim){ans += 'L';cur = a[kiri]; kiri++; }
			else{ans += 'R';cur = a[kanan]; kanan--; }
			pjg++;	
		}
		
	}
	printf("%d\n",pjg);
	cout<<ans<<endl;
	return 0;
};