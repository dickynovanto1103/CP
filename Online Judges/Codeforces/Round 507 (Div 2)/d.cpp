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
	ll n,k;
	scanf("%lld %lld",&n,&k);
	ll kiri = 1, kanan = n, mid;
	bool cekKiri = true;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		if(cekKiri){
			cout<<kiri<<" "<<mid<<flush<<endl;	
			string ans;
			cin>>ans;
			if(ans == "Bad"){return 0;}
			else{
				if(ans == "Yes"){
					kanan = mid-1;
					if(kiri == mid){return 0;}
					cekKiri = false;
				}else{
					cekKiri = false;
				}
			}
		}else{
			cout<<mid+1<<" "<<kanan<<flush<<endl;
			string ans;
			cin>>ans;
			if(ans == "Bad"){return 0;}
			else{
				if(ans == "Yes"){
					kiri = mid+1;
					if((mid+1) == kanan){return 0;}
					// cekKiri = true;
				}else{
					cekKiri = true;
				}
			}
		}
	}
	return 0;
};