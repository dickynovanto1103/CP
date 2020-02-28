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

const int maxn = 2e5 + 5;

int main(){
	int n,i,j;
	scanf("%d",&n);
	if(n == 2){printf("1\n"); return 0;}
	ii a[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i].first); a[i].second = i+1;
	}
	sort(a,a+n);
	int selisih[maxn];
	for(i=0;i<n-1;i++){
		selisih[i] = a[i+1].first - a[i].first;
	}
	//cek hapus 1 depan sama belakang
	bool sama = true;
	int cur = selisih[1];
	for(i=1;i<n-1;i++){
		if(cur != selisih[i]){sama = false; break;}
	}
	if(sama){printf("%d\n",a[0].second); return 0;}
	cur = selisih[0];
	sama = true;
	for(i=0;i<n-2;i++){
		if(cur != selisih[i]){sama = false; break;}
	}
	if(sama){printf("%d\n",a[n-1].second); return 0;}
	//coba tambah 2 pertama dan cek setelahnya
	int tambah = selisih[0] + selisih[1];
	sama = true;
	for(i=2;i<n-1;i++){
		if(tambah != selisih[i]){sama = false; break;}
	}
	if(sama){printf("%d\n",a[1].second); return 0;}
	//coba 2 terakhir dan cek sisanya
	tambah = selisih[n-2] + selisih[n-3];
	sama = true;
	for(i=0;i<n-3;i++){
		if(selisih[i] != tambah){sama = false; break;}
	}
	if(sama){printf("%d\n",a[n-2].second); return 0;}
	//berarti di tengah"

	vi listCur;
	listCur.pb(selisih[0]);
	// cur = selisih[0];
	int ans = 0;
	int cnt = 0;
	bool printed = false;
	if(listCur.size() > 2){printf("-1\n"); return 0;}
	for(int tt=0;tt<listCur.size();tt++){
		cur = listCur[tt];
		// printf("cur: %d\n",cur);
		bool valid = true;
		for(i=0;i<n-1;i++){
			if(cur != selisih[i]){
				if(((i + 1) < (n-1)) && ((selisih[i] + selisih[i+1]) == cur)){
					cnt++;
					ans = a[i+1].second;
					i++;
				}else{
					valid = false; break;
				}
			}
		}	
		if(cnt > 1){valid = false;}
		if(valid){
			printf("%d\n",ans);	
			return 0;
		}
	}
	printf("-1\n");
	
	
	
	return 0;
};