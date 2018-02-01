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
	int tc,n;
	int banyak,tot,a[110];
	scanf("%d",&tc);
	while(tc--){
		//printf("tc: %d\n",tc);
		scanf("%d",&n);
		/*ciri"misere nim biar second player win:
			1. untuk sebagian ni>1 dan n1^n2^...nk = 0
			2. untuk semua ni<=1 dan n1^n2^n3^...^nk = 1
		*/
		bool isAllOne = true;
		tot = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]); tot^=a[i];
			if(a[i]!=1){isAllOne = false;}
		}
		if(isAllOne){
			if(n%2==1){printf("Second\n");}
			else{printf("First\n");}
		}else{
			if(tot==0){printf("Second\n");}
			else{printf("First\n");}
		}

	}
	return 0;
};