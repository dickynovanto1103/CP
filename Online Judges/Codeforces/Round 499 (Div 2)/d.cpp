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

const int maxn = 35;

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	bool isJujur[maxn];
	memset(isJujur, false, sizeof isJujur);
	for(int i=0;i<n;i++){
		cout<<1<<flush<<endl;
		int bil;
		cin>>bil;
		
		if(bil == 0){
			return 0;
		}else{
			if(bil > 0){
				isJujur[i] = true;
			}else{
				isJujur[i] = false;
			}
		}
	}
	int bil;
	int kiri = 2, kanan = m, mid;
	int idx = 0;
	int sisaQuery = 60-n;
	// printf("sisaQuery: %d\n",sisaQuery);
	while(sisaQuery>0){
		mid = (kiri+kanan)/2;
		cout<<mid<<flush<<endl;
		cin>>bil;
		if(bil==0){
			return 0;
		}
		if(isJujur[idx]){
			if(bil>0){
				kiri = mid+1;
			}else if(bil < 0){
				kanan = mid-1;
			}else{
				return 0;
			}
		}else{
			if(bil>0){
				kanan = mid-1;
			}else if(bil < 0){
				kiri = mid+1;
			}else{
				return 0;
			}
		}
		idx++;
		idx%=n;
		sisaQuery--;
	}
	cout<<"lewat"<<flush<<endl;
	return 0;
};