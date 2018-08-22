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

string kata1,kata2;

bool isSama(int awal1, int akhir1, int awal2, int akhir2){
	int panjang = akhir1 - awal1 + 1;
	int i;
	if(panjang == 1){
		if(kata1[awal1] == kata2[awal2]){return true;}
		else{return false;}
	}
	if(panjang%2==1){
		int idx2 = awal2;
		for(i=awal1;i<=akhir1;i++){
			if(kata1[i] != kata2[idx2]){
				return false;
			}
			idx2++;
		}
		return true;
	}else{
		int idx2 = awal2;
		bool isValid = true;
		for(i=awal1;i<=akhir1;i++){
			if(kata1[i] != kata2[idx2]){
				isValid = false;
				break;
			}
			idx2++;
		}
		if(!isValid){//bagi 2
			int idxTengah1 = (awal1 + akhir1)/2;
			int idxTengah2 = (awal2 + akhir2)/2;
			if((isSama(awal1,idxTengah1, awal2, idxTengah2) && isSama(idxTengah1 + 1, akhir1, idxTengah2 + 1, akhir2)) || (isSama(awal1, idxTengah1, idxTengah2 + 1, akhir2) && isSama(idxTengah1 + 1, akhir1, awal2, idxTengah2))){
				return true;
			}else{
				return false;
			}
		}else{
			return true;
		}
	}
}

int main(){
	cin>>kata1>>kata2;
	int n,i,j;
	n = kata1.length();
	if(isSama(0,n-1, 0,n-1)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}

	return 0;
};