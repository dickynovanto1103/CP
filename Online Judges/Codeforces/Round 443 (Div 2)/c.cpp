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
	int n,i,j;
	vi bits;
	scanf("%d",&n);
	bits.assign(11,2);
	for(i=0;i<n;i++){
		char kar;
		int bil;
		scanf("\n%c %d",&kar,&bil);
		//printf("kar: %c bil: %d\n",kar,bil);
		for(j=0;j<10;j++){
			if((bil & (1<<j))){
				//printf("masuk tidak nol\n");
				if(kar=='|'){
					bits[j] = 1;
				}else if(kar=='^'){
					bits[j]^=1;
				}
			}else{
				//printf("masuk nol\n");
				if(kar=='&'){
					bits[j] = 0;
				}
			}
		}
	}

	int untukOr = 0,untukAnd = 0,untukXor = 0;
	// printf("bits:\n");
	// for(i=0;i<10;i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",bits[i]);
	// }
	// printf("\n");
	for(i=0;i<10;i++){
		if(bits[i]==1){untukOr |= (1<<i);}
		else if(bits[i]==0){untukAnd |= (1<<i);}
		else if(bits[i]==3){untukXor |= (1<<i);}
	}
	printf("3\n");
	//printf("untukAnd: %d\n",untukAnd);
	printf("& %d\n",(1023 ^ untukAnd));
	printf("| %d\n",untukOr);
	printf("^ %d\n",untukXor);
	return 0;
};