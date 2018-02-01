#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int a[1<<15 + 5];
int main() {
	int n,k,m,i;
	scanf("%d %d %d",&n,&k,&m);
	int counter = 1, oldM = m;
	/*for(i=(1<<n);i < (1<<n) + (1<<n);i++){
		printf("i: %d n: %d\n",i,n);
		a[i] = counter++; printf("a[%d]: %d\n",i,counter-1);
	}*/
	bool foundAns = false;
	do{
			
		int banyak = 1<<n;
		int start = 1<<n;
		bool found = true;
		while(start>1){
			//printf("banyak :%d start: %d\n",banyak,start);
			for(i=start;i<start+banyak;i+=2){
				//printf("test: i: %d\n",i);
				a[i/2] = max(a[i],a[i+1]);
				//printf("a[%d]: %d\n",i/2,a[i/2]);
			}
			banyak/=2;
			start/=2;	
		}
		//cari nilai k
		/*for(i=1;i<=2*(1<<n)-1;i++){
			printf("a[%d]: %d\n",i,a[i]);
		}*/
		for(i=(1<<n);i < (1<<n) + (1<<n);i++){
			if(a[i]==k){break;}
		}

		int idx = i;
		//printf("idx: %d\n",idx);
		while(idx>=1){
			if(a[idx/2]==k){idx/=2; m--;}
			else{break;}
		}
		if(m==0){foundAns = true;}
		else{m = oldM;}
		if(foundAns){
			int cnt = 0;
			for(i=(1<<n);i < (1<<n) + (1<<n);i++){
				if(cnt){printf(" ");}
				printf("%d",a[i]);
				cnt=1;
			}
			printf("\n");
			break;
		}
		m = oldM;
	}while(next_permutation(a+(1<<n),a+(1<<n) + (1<<n)));
	if(!foundAns){printf("-1\n");}
	return 0;
}