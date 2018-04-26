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

const int maxn = 110;
string kata[maxn][maxn];
string ans[2*maxn];
string seharusnya1[210];
string seharusnya2[210];

int change1(int n){
	int i,j;
	
	int ans1 = 0, ans2 = 0;
	for(i=0;i<2*n;i++){
		for(j=0;j<2*n;j++){
			// printf("%c",ans[i][j]);
			if(ans[i][j]!=seharusnya1[i][j]){ans1++;}
			if(ans[i][j]!=seharusnya2[i][j]){ans2++;}
		}
		// printf("\n");
	}
	// printf("\n");
	return min(ans1,ans2);
}

int main(){
	int n, i, j;
	scanf("%d",&n);
	for(int tt=0;tt<4;tt++){
		for(i=0;i<n;i++){
			cin>>kata[tt][i];
		}
	}
	int angka = 1;
	for(i=0;i<=205;i++){
		seharusnya2[i]="";
		seharusnya1[i]="";
		if(i>0){
			if(seharusnya1[i-1][0]=='0'){
				angka = 1;
			}else{
				angka = 0;
			}
		}
		for(j=0;j<=205;j++){
			char kar = angka+'0';
			char kar2 = (1-angka) + '0';
			seharusnya1[i]+=(kar);
			seharusnya2[i]+=(kar2);
			angka = 1-angka;
		}
	}

	// for(i=0;i<=200;i++){
	// 	seharusnya2[i] = "";
	// 	for(j=0;j<=200;j++){
	// 		if(seharusnya1[i][j]=='0'){
	// 			seharusnya2[i]+='1';
	// 		}else{
	// 			seharusnya2[i]+='0';
	// 		}
	// 	}
	// }
	
	// printf("seharusnya1\n");
	// for(i=0;i<=200;i++){cout<<seharusnya1[i]<<endl;}
	// printf("seharusnya2\n");
	// for(i=0;i<=200;i++){cout<<seharusnya2[i]<<endl;}

	int minim = inf;
	int a[] = {0,1,2,3};
	do{

		for(i=0;i<=205;i++){ans[i] = "";}
		// for(i=0;i<4;i++){printf("%d ",a[i]);}
		// printf("\n");
		for(i=0;i<4;i++){
			int idx = a[i];
			// printf("%s\n", );
			if(i<=1){
				for(j=0;j<n;j++){
					ans[j]+=kata[idx][j];
				}
			}else{
				for(j=0;j<n;j++){
					ans[j+n]+=kata[idx][j];
				}
			}
		}

		int jawab = change1(n);
		minim = min(minim,jawab);
		// for(i=0;i<2*n;i++){
		// 	cout<<ans[i]<<endl;
		// }
		// printf("\n");
		
	}while(next_permutation(a,a+4));
	
	printf("%d\n",minim);
	return 0;
};