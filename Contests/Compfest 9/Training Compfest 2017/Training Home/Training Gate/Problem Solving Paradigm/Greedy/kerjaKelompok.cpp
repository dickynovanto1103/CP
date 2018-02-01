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
	int n,i,a[100001];
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	sort(a,a+n);
	reverse(a,a+n);
	bool isSamaSemua = true;
	int bil = a[0];
	for(i=1;i<n;i++){
		if(bil!=a[i]){isSamaSemua = false; break;}
	}
	if(n==1){printf("%d\n",a[0]);}
	else{
		int cnt = 0;
		if(!isSamaSemua){
			for(i=0;i<n-1;i++){
				if(a[i]==0){continue;}
				if(a[i]!=1){
					if(a[i+1]==a[i]){
						a[i+1]=1;
						a[i]=1;
						int idx = i+1;
						while(idx<n && a[idx]==1){idx++;}//cari sampai ketemu bilangan yang lebih besar dari 1..biar pairing optimal
						if(idx==n){idx=i+1;}
						a[idx]-=a[i];
						a[i] = 0;
					}else{
						int minim = min(a[i+1],a[i]);
						bil = a[i] - minim;
						a[i+1]=bil;
						a[i] = 0;
					}
				}else{
					int idx = i+1;
					while(idx<n && a[idx]==1){idx++;}//cari sampai ketemu bilangan yang lebih besar dari 1..biar pairing optimal
					if(idx==n){idx=i+1;}
					a[idx]-=a[i];
					a[i] = 0;
				}
				//if(a[i]%2==1){cnt++;}
				/*printf("temp:\n");
				for(int j=0;j<n;j++){
					if(j){printf(" ");}
					printf("%d",a[j]);
				}
				printf("\n");*/
			}

			printf("%d\n",a[n-1]);	
		}else{
			if(n%2==0){printf("0\n");}
			else{
				if(a[0]%2==1){printf("1\n");}
				else{printf("0\n");}
			}
		}
		
		/*if(!isSamaSemua){
				
		}else{
			
		}*/	
	}
	
	
	return 0;
}