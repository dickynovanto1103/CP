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

const int maxn = 100010;

string kata[maxn];
int harga[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		cin>>kata[i]>>harga[i];
	}
	int minim = inf;
	string ans = "-1";
	for(i=0;i<n;i++){
		bool isValid = true;
		int hargaSekarang = harga[i];
		int cnt4 = 0, cnt7 = 0;
		while(harga[i]>0){
			int bil = harga[i]%10;
			harga[i]/=10;
			if(bil!=4 && bil!=7){isValid = false; break;}
			else{
				if(bil==4){cnt4++;}
				else{cnt7++;}
			}
		}
		if(isValid){
			if(cnt4==cnt7){
				if(minim > hargaSekarang){minim = hargaSekarang; ans = kata[i];}
			}
		}

	}
	cout<<ans<<endl;
	return 0;
};