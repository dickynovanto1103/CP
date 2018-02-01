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
	int tc,i,j;
	int a,b,k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d %d",&a,&b,&k);
		if(a==b){
			for(i=0;i<a;i++){
				printf("PL");
			}
			printf("\n");
		}else if(a>b){
			int batas = (a+b)/(b+1);
			if(batas>2){printf("mustahil\n"); continue;}
			while(b>0){
				int banyakPrint = (a+b)/(b+1);
				for(i=0;i<banyakPrint;i++){printf("L");}
				a-=banyakPrint;
				printf("P");
				b--;
			}
			while(a>0){
				printf("L");
				a--;
			}
			printf("\n");

		}else{
			int batas = (a+b)/(a+1);
			if(batas>k){printf("mustahil\n"); continue;}
			while(a>0){
				int banyakPrint = (a+b)/(a+1);
				for(i=0;i<banyakPrint;i++){printf("P");}
				b-=banyakPrint;
				printf("L");
				a--;
			}
			while(b>0){
				printf("P");
				b--;
			}
			printf("\n");
		}
	}
	
	return 0;
};