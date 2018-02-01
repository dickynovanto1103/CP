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

int main() {
	int n,i,a[1010];
	while(scanf("%d",&n),n){
		i = 0;
		while(scanf("%d",&a[i]),a[i]){
			for(i=1;i<n;i++){scanf("%d",&a[i]);}
			/*printf("array:\n");
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",a[i]);
			}
			printf("\n");*/

			//proses
			stack<int> s1,s2;
			for(i=n;i>=1;i--){s1.push(i);}
			//ngikutin permintaan permutasi
			bool found = true;
			for(i=0;i<n;i++){
				int bil = a[i];
				//ambil dari s1
				while(!s1.empty() && s1.top()<=bil){s2.push(s1.top()); s1.pop();}
				if(s2.top()==bil){s2.pop();}
				else{found = false; break;}
			}
			if(!found){printf("No\n");}
			else{printf("Yes\n");}
			i=0;

		}
		printf("\n");
	}
	return 0;
}