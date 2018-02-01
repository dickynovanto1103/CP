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

int main() {
	int n,i,j;
	ll a,fib[100];
	fib[0] = 0; fib[1] = 1;
	for(i=2;i<80;i++){
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i]>INT_MAX){break;}
	}
	int idx = i;
	/*for(i=0;i<idx;i++){
		printf("i: %d : %lld\n",i,fib[i]);
	}*/
	scanf("%d",&n);

	
	while(n--){
		scanf("%lld",&a);
		ll temp = a;
		string kata="";
		for(i=0;i<=idx;i++){kata+="0";}
		for(i=idx;i>=2;i--){
			//printf("a: %lld i: %d fib: %lld\n",a,i,fib[i]); 
			if(fib[i]<=a){
				a-=fib[i]; kata+="1";
				//printf("fib[%d]: %lld a jd: %lld\n",i,fib[i],a);
				//if(a==0){break;}
			}
			else{kata+="0";}
			//printf("kata jd: "); cout<<kata<<endl;
		}
		for(i=0;i<kata.length();i++){
			if(kata[i]=='1'){break;}
		}
		int indeks = i;
		string kataAns="";
		for(i=indeks;i<kata.length();i++){
			char kar = kata[i];
			kataAns+=kar;
		}
		printf("%lld = ",temp); cout<<kataAns; printf(" (fib)\n");
	}
	return 0;
}