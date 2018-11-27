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

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

bool isSemuaPositif(int n){
	for(int i=0;i<n;i++){
		if(b[i] < 0){return false;}
	}
	return true;
}

int main(){
	int tc,n,i,j;
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%d",&a[i]);}
		for(i=0;i<n;i++){scanf("%d",&b[i]);}
		for(i=0;i<n;i++){
			
			b[i] -= a[i];
			a[i] -= a[i];
			// printf("b[%d] jadi: %d\n",i,b[i]);
		}
		if(!isSemuaPositif(n)){printf("NIE\n"); continue;}
		for(i=0;i<(n-2);i++){
			if(b[i] > 0){
				int selisih1 = b[i], selisih2 = b[i+1], selisih3 = b[i+2];
				int loop = selisih1;
				
				b[i] -= loop;
				b[i+1] -= loop*2;
				b[i+2] -= loop*3;
			}
		}
		bool isValid = true;
		for(i=0;i<n;i++){
			if(b[i] != 0){
				isValid = false;
				break;
			}
		}
		if(isValid){printf("TAK\n");}
		else{printf("NIE\n");}
	}
	return 0;
};