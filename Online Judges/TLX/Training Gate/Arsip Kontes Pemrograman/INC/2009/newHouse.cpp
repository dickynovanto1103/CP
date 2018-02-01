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

string kata[40];
int mid;

bool can(int i, int j){
	int k,l;
	// printf("\n\ni: %d j: %d mid: %d\n",i,j,mid);
	for(k=i;k<(i+mid);k++){
		for(l=j;l<(j+mid);l++){
			// printf("k: %d l: %d\n",k,l);
			if(kata[k][l]=='#'){return false;}
		}
	}
	return true;
}

int main(){
	int tc,n,i,j;
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){cin>>kata[i];}
		int kiri = 0, kanan = n;
		int ans;
		while(kiri<=kanan){
			mid = (kiri+kanan)/2;

			bool found = false;
			for(i=0;i<=(n-mid);i++){
				for(j=0;j<=(n-mid);j++){
					//cek apakah . semua di mid*mid
					if(can(i,j)){
						ans = mid;
						kiri = mid+1;
						found = true;
						break;
					}
				}
				if(found){break;}
			}
			if(!found){kanan = mid-1;}
		}
		printf("%d\n",ans);
	}
	return 0;
};