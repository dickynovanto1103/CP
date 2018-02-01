#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int mat[25][25],i,j,a,b,n,m;
	scanf("%d %d",&n,&m);
	memset(mat,0,sizeof mat);
	
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b); a--; b--; mat[a][b] = mat[b][a] = 1;
	}
	int kiri = 0, kanan = n, mid;
	int arr[25],ans;
	while(kiri<=kanan){
		mid = (kiri+kanan)/2;
		memset(arr,0,sizeof arr);
		for(i=0;i<mid;i++){arr[i] = 1;}//occupied
		reverse(arr,arr+n);
		bool foundBenar;
		//printf("mid: %d\n",mid);
		/*for(i=0;i<mid;i++){
			if(i){printf(" ");}
			printf("%d",arr[i]);
		}
		printf("\n");*/
		do{
			/*printf("array:\n");
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",arr[i]);
			}
			printf("\n");*/
			vi listNode;
			for(i=0;i<n;i++){if(arr[i]){listNode.pb(i);}}

			int ukuran = listNode.size();
			/*printf("listnode: \n");
			for(i=0;i<ukuran;i++){
				if(i){printf(" ");}
				printf("%d",listNode[i]);
			}
			printf("\n");*/
			foundBenar = true;
			for(i=0;i<ukuran;i++){
				a = listNode[i];
				for(j=i+1;j<ukuran;j++){
					b = listNode[j];
					if(mat[a][b]==0){foundBenar = false; break;}
				}
				if(!foundBenar){break;}
			}
			if(foundBenar){break;}
		}while(next_permutation(arr,arr+n));
		if(foundBenar){ans = mid; kiri = mid+1; }//naikkan batasnya
		else{kanan = mid-1;}
	}
	printf("%d\n",ans);	
	
	
	return 0;
}