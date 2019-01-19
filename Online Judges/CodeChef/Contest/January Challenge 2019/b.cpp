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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 2e5 + 5;

int main(){
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		int n,bil1,bil2,i,j;
		scanf("%d %d %d",&n,&bil1,&bil2);
		int a[maxn];
		bool isErased[maxn];
		memset(isErased, false, sizeof isErased);
		bool adaYangDihapus = false;
		bool pernahHapus =false;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] % bil1 == 0 && a[i]%bil2 == 0){
				isErased[i] = true;
				pernahHapus = true;
			}
			if(a[i] % bil1 == 0 || a[i] % bil2 == 0){
				adaYangDihapus = true;
			}
		}
		if(!adaYangDihapus){
			printf("ALICE\n");
			continue;
		}

		int cnt1 = 0, cnt2 = 0;

		for(i=0;i<n;i++){
			if(!isErased[i]){
				if(a[i] % bil1 == 0){
					cnt1++;
				}
				if(a[i] % bil2 == 0){
					cnt2++;
				}
			}
		}
		if(pernahHapus){
			if(cnt1<cnt2){printf("ALICE\n");}
			else{printf("BOB\n");}	
		}else{
			if(cnt1<=cnt2){printf("ALICE\n");}
			else{printf("BOB\n");}
		}
		
	}
	return 0;
};