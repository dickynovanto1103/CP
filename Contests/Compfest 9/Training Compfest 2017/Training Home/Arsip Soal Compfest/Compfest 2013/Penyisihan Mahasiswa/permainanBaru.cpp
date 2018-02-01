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

int coba[110];
void geserKiri(int n){
	int i;
	int a = coba[0];
	for(i=0;i<n-1;i++){coba[i] = coba[i+1];}
	coba[n-1] = a;
}

void geserKanan(int n){
	int i;
	int a = coba[n-1];
	for(i=n-1;i>=1;i--){coba[i] = coba[i-1];}
	coba[0] = a;
}

bool isLexicograficallySmaller(int a[], int b[], int n){
	for(int i=0;i<n;i++){
		if(a[i] > b[i]){return false;}
		else if(a[i]<b[i]){return true;}
	}
	return false;//klo sama semua elemennya..ga lebih kecil secara lexicografi
}

int main() {
	int tc,n,k,arr[110], a[110][110],i,j;
	scanf("%d",&tc);
	int testcase = 1;
	int ans[110];
	while(tc--){
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++){scanf("%d",&arr[i]); ans[i] = inf;}
		
		if(k%2==0){
			//geser kiri
			for(int banyakGeser=0;banyakGeser<=k;banyakGeser+=2){
				
				for(i=0;i<n;i++){coba[i] = arr[i];}
				/*printf("coba awal: ");
				for(i=0;i<n;i++){
					if(i){printf(" ");}
					printf("%d",coba[i]);
				}
				printf("\n");*/
				for(j=0;j<banyakGeser;j++){
					geserKiri(n);
				}
				/*printf("setelah digeser sebanyak %d kali\n",banyakGeser);
				for(i=0;i<n;i++){
					if(i){printf(" ");}
					printf("%d",coba[i]);
				}
				printf("\n");*/
				
				if(isLexicograficallySmaller(coba,ans,n)){
					for(i=0;i<n;i++){ans[i] = coba[i];}
				}
			}
			//geser kanan
			for(int banyakGeser=0;banyakGeser<=k;banyakGeser+=2){
				for(i=0;i<n;i++){coba[i] = arr[i];}
				//printf("coba awal: "); cout<<coba<<endl;
				for(j=0;j<banyakGeser;j++){
					geserKanan(n);
				}
				//printf("setelah digeser sebanyak %d coba jd: ",banyakGeser); cout<<coba<<endl;
				if(isLexicograficallySmaller(coba,ans,n)){
					for(i=0;i<n;i++){ans[i] = coba[i];}
				}
			}
		}else{
			//geser kiri
			for(int banyakGeser=1;banyakGeser<=k;banyakGeser+=2){
				for(i=0;i<n;i++){coba[i] = arr[i];}
				//printf("coba awal: "); cout<<coba<<endl;
				for(j=0;j<banyakGeser;j++){
					geserKiri(n);
				}
				//printf("setelah digeser sebanyak %d coba jd: ",banyakGeser); cout<<coba<<endl;
				if(isLexicograficallySmaller(coba,ans,n)){
					for(i=0;i<n;i++){ans[i] = coba[i];}
				}
			}
			//geser kanan
			for(int banyakGeser=1;banyakGeser<=k;banyakGeser+=2){
				for(i=0;i<n;i++){coba[i] = arr[i];}
				//printf("coba awal: "); cout<<coba<<endl;
				for(j=0;j<banyakGeser;j++){
					geserKanan(n);
				}
				//printf("setelah digeser sebanyak %d coba jd: ",banyakGeser); cout<<coba<<endl;
				if(isLexicograficallySmaller(coba,ans,n)){
					for(i=0;i<n;i++){ans[i] = coba[i];}
				}
			}
		}
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",ans[i]);
		}
		printf("\n");
		
		
	}
	return 0;
}