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
	int a[3],i;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		set<int> s;
		for(i=0;i<3;i++){scanf("%d",&a[i]); s.insert(a[i]);}
		sort(a,a+3);
		

		bool isSegitiga = false, isLurus = false;
		if((a[0] + a[1]) > a[2]){
			isSegitiga = true;
			if(s.size() == 1){
				printf("segitiga sama sisi\n");
			}else if(s.size() == 2){
				printf("segitiga sama kaki\n");
			}else{
				int jumlah = a[0]*a[0] + a[1]*a[1];
				if(jumlah == (a[2]*a[2])){
					printf("segitiga siku-siku\n");
				}else{
					printf("segitiga sembarang\n");
				}
			}
		}else if((a[0] + a[1]) == a[2]){
			printf("garis lurus\n");
		}else{
			printf("bukan segitiga\n");
		}
	}
	
	
	return 0;
};