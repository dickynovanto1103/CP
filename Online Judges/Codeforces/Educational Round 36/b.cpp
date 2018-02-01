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

int main(){
	int n,pos,l,r;
	int i,j;
	scanf("%d %d %d %d",&n,&pos,&l,&r);
	//if(l==1 && r==n){printf("0\n"); return 0;}
	int cntHapus = 0;
	bool kiri = false, kanan = false;
	if(l>1){cntHapus++; kiri = true;}
	if(r<n){cntHapus++; kanan = true;}
	int jarakMin = min(pos-l,r-pos);
	if(cntHapus==0){printf("0\n"); return 0;}
	else{
		int ans = 0;
		if(cntHapus==1){
			if(kiri){
				if(pos<l){
					ans = l-pos+1;
				}else{
					ans = pos-l + 1;	
				}
				

			}
			else if(kanan){
				if(pos>r){
					ans = pos-r+1;
				}else{
					ans = r-pos+1;
				}
				//ans = r-pos+1;
			}
		}else{
			int ans1, ans2;
			if(pos>r){
				ans = pos-r+(r-l)+2;
			}else if(pos<l){
				//printf("masuk sini\n");
				ans = l-pos+(r-l)+2;
			}else{
				ans1=pos-l+1+(r-l)+1;
				ans2 = r-pos+1+(r-l)+1;
				ans=min(ans1,ans2);	
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
};