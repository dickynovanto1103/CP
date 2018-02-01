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

//int a[inf + 1];

int main() {
	int tc,n,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int bil,bilawal;
		//scanf("%d",&bilawal);
		/*int idx = 1, ansIdx;
		bool found = false;
		for(i=1;i<n;i++){
			scanf("%d",&bil);
			if(bil==0 && !found){ansIdx = i-1; found = true;}
		}
		printf("OUTPUT %d\n",ansIdx);*/
		string respon;
		int i=0;
		//printf("n: %d\n",n);
		while(i<n){
			printf("READ %d\n",i);
			cin>>respon;
			if(respon=="false"){printf("OUTPUT %d\n",i-1); break;}
			i++;
			fflush(stdout);
		}
		/*for(i=0;i<n-1;i++){
			printf("i: %d\n",i);
			
			//fflush(stdout);
		}*/
	}
	return 0;
}