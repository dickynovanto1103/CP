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

const int maxn = 100010;
int a[maxn],b[maxn];

int main(){
	int n,e1,e2;
	int i,j;
	scanf("%d %d %d",&n,&e1,&e2);
	int tujuan[2];
	tujuan[0] = 1; tujuan[1] = n;
	for(i=0;i<n;i++){scanf("%d %d",&a[i],&b[i]);}
	int ans = 0;
	//set 4 kombinasi
	int range1[2], range2[2];
	bool ismenurun1, ismenurun2;	
	ismenurun1 = false; ismenurun2 = false;
	for(i=0;i<2;i++){
			
		range1[0] = e1; range1[1] = tujuan[i];
		
		for(j=0;j<2;j++){
			int cnt = 0;
			range2[0] = e2; range2[1] = tujuan[j];
			
			if(range1[0]>range1[1]){ismenurun1 = true;}
			else{ismenurun1 = false;}
			if(range2[0]>range2[1]){ismenurun2 = true;}
			else{ismenurun2 = false;}
			// printf("%d %d\n",ismenurun1, ismenurun2);
			// printf("range1: %d %d range2: %d %d\n",range1[0],range1[1],range2[0],range2[1]);
			for(int k=0;k<n;k++){
				bool ismenurundata;
				if(a[k]>b[k]){ismenurundata = true;}
				else{ismenurundata = false;}
				//printf("data menurun: %d\n",ismenurundata);
				bool sudah = false;
				if(ismenurundata && ismenurun1){
					if((range1[0]>=a[k] && range1[1]<=b[k])){
						cnt++; sudah = true;
						//printf("terhitung1\n");
					}
				}
				if(sudah){continue;}
				if(ismenurundata && ismenurun2){
					if(range2[0]>=a[k] && range2[1]<=b[k]){
						cnt++; sudah = true;
						//printf("terhitung2\n");
					}
				}

				if(sudah){continue;}
				if(!ismenurundata && !ismenurun1){
					//printf("masuk sini\n");
					if(range1[0]<=a[k] && range1[1]>=b[k]){
						cnt++; sudah = true;
						//printf("terhitung3\n");
					}
				}
				if(sudah){continue;}
				if(!ismenurundata && !ismenurun2){
					if(range2[0]<=a[k] && range2[1]>=b[k]){
						cnt++; sudah = true;
						//printf("terhitung4\n");
					}
				}

				// if(ismenurun1 && ismenurun2){
				// 	if((range1[0]>=a[k] && range1[1]<=b[k] && ismenurundata) || (range2[0]>=a[k] && range2[1]<=b[k] && ismenurundata)){cnt++;}
				// }else if(!ismenurun1 && ismenurun2){					
				// 	if((range1[0]<=a[k] && range1[1]>=b[k] && !ismenurundata) || (range2[0]>=a[k] && range2[1]<=b[k] && ismenurundata)){cnt++;}
				// }else if(ismenurun1 && !ismenurun2){
				// 	if((range2[0]<=a[k] && range2[1]>=b[k] && ismenurundata) || (range1[0]>=a[k] && range1[1]<=b[k] && !ismenurundata)){cnt++;}
				// }else{
				// 	if((range2[0]<=a[k] && range2[1]>=b[k] && !ismenurundata) || (range1[0]<=a[k] && range1[1]>=b[k] && !ismenurundata)){cnt++;}
				// }
				
				
			}
			//printf("cnt: %d\n",cnt);
			ans = max(ans,cnt);
		}
	}
	printf("%d\n",ans);
	return 0;
};