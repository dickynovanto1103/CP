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
	int tc,i,j,k,l,m,n;	
	int permutasi[6][3]={{0,1,2},{0,2,1},
						{1,0,2},{1,2,0},
						{2,0,1},{2,1,0}};
	/*for(i=0;i<6;i++){
		for(j=0;j<3;j++){
			if(j){printf(" ");}
			printf("%d",permutasi[i][j]);
		}
		printf("\n");
	}*/
	scanf("%d",&tc);
	while(tc--){
		string kata1,kata2;
		int a[5][4];
		cin>>kata1;
		for(i=0;i<5;i++){
			for(j=0;j<4;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int sum,sum2, ans1 = 0, ans2 = 0;
		for(i=0;i<5;i++){
			
			for(j=i+1;j<5;j++){
				sum=0;
				sum+=a[i][3]; sum+=a[j][3];
				vi listIdx;
				for(k=0;k<5;k++){
					if(k!=i && k!=j){
						listIdx.pb(k);
					}
				}
				/*printf("listidx:\n");
				for(k=0;k<3;k++){
					if(k){printf(" ");}
					printf("%d",listIdx[k]);
				}*/
				ii pas[5];
				for(k=0;k<6;k++){
					for(l=0;l<3;l++){
						pas[l].second = permutasi[k][l];
					}
					for(m=0;m<3;m++){
						pas[m].first = listIdx[m];
					}
					int temp = sum;
					for(m=0;m<3;m++){
						int idxBaris = pas[m].first;
						int idxKolom = pas[m].second;
						temp+=a[idxBaris][idxKolom];
					}
					ans1 = max(ans1,temp);
				}
				
				listIdx.clear();
			}
		}
		//printf("ans1: %d\n",ans1);
		cin>>kata2;
		for(i=0;i<5;i++){
			for(j=0;j<4;j++){
				scanf("%d",&a[i][j]);
			}
		}
		/*for(i=0;i<5;i++){
			for(j=0;j<4;j++){
				if(j){printf(" ");}
				printf("%d",a[i][j]);
			}
			printf("\n");
		}*/
		ans2 = 0;
		for(i=0;i<5;i++){
			
			for(j=i+1;j<5;j++){
				sum2=0;
				sum2+=a[i][3]; sum2+=a[j][3];
				vi listIdx;
				for(k=0;k<5;k++){
					if(k!=i && k!=j){
						listIdx.pb(k);
					}
				}
				/*printf("listidx:\n");
				for(k=0;k<3;k++){
					if(k){printf(" ");}
					printf("%d",listIdx[k]);
				}*/
				ii pas[5];
				//printf("sum2: %d\n",sum2);
				for(k=0;k<6;k++){
					for(l=0;l<3;l++){
						pas[l].second = permutasi[k][l];
					}
					for(m=0;m<3;m++){
						pas[m].first = listIdx[m];
					}
					int temp = sum2;
					for(m=0;m<3;m++){
						int idxBaris = pas[m].first;
						int idxKolom = pas[m].second;
						//printf("idxbaris: %d idxkolom: %d\n",idxBaris,idxKolom);
						temp+=a[idxBaris][idxKolom];
						//printf("temp jd: %d\n",temp);
					}
					ans2 = max(ans2,temp);
					//printf("ans2 jd: %d\n",ans2);
				}
				
				listIdx.clear();
			}
		}
		//printf("ans1: %d ans2: %d\n",ans1,ans2);
		if(ans1==ans2){printf("50-50\n");}
		else{
			if(ans1>ans2){cout<<kata1<<endl;}
			else{cout<<kata2<<endl;}
		}
	}
	return 0;
}