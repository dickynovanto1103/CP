#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int banyakDigit(int n){
	int cnt = 0;
	while(n>0){n/=10; cnt++;}
	return cnt;
}

int gcd(int a, int b){return b==0? a: gcd(b,a%b);}

int main() {
	map<int,int> mapper;
	int step, mod,i;
	while(scanf("%d %d",&step,&mod)!=EOF){
		/*int bil = 0, cnt = 0;
		mapper[bil] = cnt++;
		for(i=1;i<mod;i++){
			bil = (bil+step)%mod;
			//printf("bil: %d\n",bil);
			if(mapper.find(bil)==mapper.end()){mapper[bil] = cnt++;}
			else{break;}
		}*/
		string kata;
		if(gcd(step,mod)==1){kata = "Good Choice";}
		else{kata = "Bad Choice";}
		//if(i==mod){kata = "Good Choice";}
		//else{kata = "Bad Choice";}
		int n = banyakDigit(step);
		for(i=0;i<10-n;i++){printf(" ");}
		printf("%d",step);

		n = banyakDigit(mod);
		for(i=0;i<10-n;i++){printf(" ");}
		printf("%d",mod);
		for(i=0;i<4;i++){printf(" ");}
		cout<<kata<<endl;
		printf("\n");
		mapper.clear();
		
	}
	return 0;
}