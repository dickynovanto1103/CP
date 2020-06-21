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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		if(n == 1){printf("FastestFinger\n");}
		else if(n == 2){printf("Ashishgup\n");}
		else{
			//cari ada ga divisor ganjil
			if(n % 2 == 1){printf("Ashishgup\n"); continue;}

			vi oddDivisors;
			for(i=1;i*i<=n;i++){
				// printf("i: %d n: %d\n",i,n);
				if(n % i == 0){
					int div1 = i;
					int div2 = n/i;
					// printf("%d %d\n",div1, div2);
					if(div1 == 1 || div2 == 1){continue;}
					if(div1 % 2 == 1 || div2 % 2 == 1){
						// adaGanjil = true;
						// break;
						if(div1 == div2){
							oddDivisors.pb(div1);
						}else{
							if(div1 % 2 == 1){oddDivisors.pb(div1);}
							else{oddDivisors.pb(div2);}
						}
					}
				}
			}
			if(oddDivisors.size()){
				if(oddDivisors.size() == 1){
					int pembagi = oddDivisors[0];
					n /= pembagi;
					if(n == 2){printf("FastestFinger\n");}
					else{printf("Ashishgup\n");}
				}else{
					printf("Ashishgup\n");
				}
			}
			else{printf("FastestFinger\n");}
			// printf("Ashishgup\n");
		}
	}
	
	return 0;
};