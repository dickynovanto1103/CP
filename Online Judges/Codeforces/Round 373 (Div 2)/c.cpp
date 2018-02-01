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

const int maxn = 2e5 + 5;

int main(){
	int n,t;
	int i,j;
	scanf("%d %d",&n,&t);
	string kata;
	cin>>kata;
	int a[maxn];
	a[0] = 0;
	for(i=0;i<n;i++){
		a[i+1] = kata[i]-'0';
	}
	for(i=1;i<=n;i++){
		if(a[i]==('.'-'0')){break;}
	}
	int idxTitik = i;
	int idx = i;
	//printf("idx: %d\n",i);
	bool found = false;
	for(i = idx+1;i<=n;i++){
		//printf("a[%d]: %d\n",i,a[i]);
		if(a[i]>=5){
			found = true;
			break;
		}
	}
	if(!found){cout<<kata<<endl; return 0;}
	idx = i;

	a[i] = 0;
	int carry = 1;
	for(i=idx-1;i>idxTitik;i--){
		a[i]+=carry;
		carry = a[i]/10;
		a[i]%=10;
		if(a[i]>0 && a[i]<5){
			break;
		}else{
			t--;
			if(t==0){break;}
			carry = 1;
			a[i] = 0;
			
		}
		
		
	}
	idx = i;
	// if(carry==1){
	// 	for(i=idx-1;i>idxTitik;i--){
	// 		printf("i: %d\n",i);
	// 		a[i]+=carry;
	// 		carry = a[i]/10;
	// 		a[i]%=10;
	// 		if(a[i]>0 && a[i]<5){
	// 			break;
	// 		}else{
	// 			carry = 1;
	// 			a[i] = 0;
	// 		}
	// 	}
	// }

	bool titikRemoved = false;
	if(carry==1 && idx==(idxTitik+1) && a[idx]==0){
		titikRemoved = true;
		printf("masuk sini\n");
		for(i=idxTitik-1;i>=1;i--){
			a[i]+=carry;
			carry = a[i]/10;
			a[i]%=10;
			printf("a[%d] jd: %d\n",i,a[i]);
			if(carry==1){
				carry = 1;
				a[i] = 0;
			}else{
				break;
			}
			
		}
		if(carry==1){a[0]=1;}
	}
	int start = 0;
	if(a[0]==0){start = 1;}
	if(titikRemoved){
		printf("masuk sinikah\n");
		printf("idxTitik: %d\n",idxTitik);
		
		for(i=start;i<idxTitik;i++){
			
			printf("%c",a[i]+'0');
		}
		printf("\n");	
		return 0;
	}
	
	for(i=start;i<=idx;i++){
		printf("%c",a[i]+'0');
	}
	printf("\n");
	return 0;
};