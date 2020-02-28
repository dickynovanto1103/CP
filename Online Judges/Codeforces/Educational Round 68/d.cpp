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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;



int main(){
	int tc,i,j;
	scanf("%d",&tc);

	while(tc--){
		int n,k;
		scanf("%d %d",&n,&k);
		if(k == 3) {
			if(n >= 3) {
				if(n%4 == 0){printf("Bob\n");}
				else{printf("Alice\n");}
			}else{
				if(n%3 == 0){printf("Bob\n");}
				else{printf("Alice\n");}	
			}
		}else{
			if(n < k){
				if(n%3 == 0){printf("Bob\n");}
				else{printf("Alice\n");}
			}else{
				if(k%3 == 0){
					if(n%(k+1) == k){printf("Alice\n");}
					else{
						int bil = n%(k+1);
						if(bil%3 == 0){printf("Bob\n");}
						else{printf("Alice\n");}
					}
				}else{
					if(n%3 == 0){printf("Bob\n");}
					else{printf("Alice\n");}	
				}
			}	
		}
		
	}
	return 0;
};