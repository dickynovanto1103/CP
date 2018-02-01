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
	int tc,a,b,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&k);
		int total = a+b;
		int pembagi = a+1;
		int penambahan=0;
		if(b%2==1){penambahan=1;}
		int batas;
		if(a==0){
			if(b>k){printf("mustahil\n");}
			else{
				int i;
				for(i=0;i<b;i++){printf("P");}
				printf("\n");
			}
		}else{
			batas = b/2;
			if(b%2==1){batas++;}
			if(batas>k){printf("mustahil\n");}
			else{
				
				int i;
				for(i=0;i<batas;i++){printf("P");}
				printf("L");
				int sisa = b-batas;
				for(i=0;i<sisa;i++){printf("P");}
				printf("\n");
			}	
		}
		
	}
	return 0;
};