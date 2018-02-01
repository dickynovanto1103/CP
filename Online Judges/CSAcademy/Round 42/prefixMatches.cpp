#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	int n,i,j,a[100010],b[100010];
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d",&a[i]);
	}
	string kata="";
	for(i=0;i<n;i++){kata+="0";}
	kata[0] = 'A';
	int idx = 'A';
	for(i=1;i<n;i++){
		//if(kata[i]!='0'){continue;}
		if(a[i]==0){
			if(kata[i]=='0'){
				idx++; 
				char kar = idx;
				kata[i]=kar;	
			}
			
		}else{
			int j = 0,indeks = i;
			//printf("a[i]\n");
			while(true){
				for(j=0;j<i;j++){
					kata[indeks++]=kata[j];
					//printf("indeks: %d j: %d\n",indeks,j);
					if(indeks==i+a[i]){break;}
				}
				/*printf("i+a[i]: %d\n",i+a[i]);
				printf("indeks: %d\n",indeks);*/
				if(indeks==i+a[i]){break;}
			}
		}
	}
	j=-1; i =0;
	b[0] = -1;
	int m = kata.length();
	while(i<m){
		while(j>=0 && kata[i]!=kata[j]){j = b[j];}
		i++; j++;
		b[i] = j;
	}

	for(i=2;i<=n;i++){
		if(i>2){printf(" ");}
		printf("%d",b[i]);
	}
	printf("\n");
	//cout<<kata<<endl;
	return 0;
}