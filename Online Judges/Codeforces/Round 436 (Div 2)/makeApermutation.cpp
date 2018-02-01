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

const int maxn = 2e5 + 10;
int a[maxn], counter[maxn];
bool isUnique[maxn];

int main(){
	int n,i,j;
	scanf("%d",&n);
	memset(isUnique,true,sizeof isUnique);
	set<int> s;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		counter[a[i]]++;
		if(counter[a[i]]>1){isUnique[a[i]] = false; s.insert(a[i]);}
	}
	//catat yang masih counternya 0...masukin ke vector bilangan blm ada
	vi listBilBelumAda;
	for(i=1;i<=n;i++){
		if(counter[i]==0){listBilBelumAda.pb(i);}
	}
	//balik vektornya biar nanti tinggal popback O(1)
	reverse(listBilBelumAda.begin(),listBilBelumAda.end());
	if(listBilBelumAda.empty()){
		printf("0\n");
		for(i=0;i<n;i++){
			if(i){printf(" ");}
			printf("%d",a[i]);
		}
		printf("\n");
		return 0;
	}
	// printf("listBilBelumAda: \n");
	// for(i=listBilBelumAda.size()-1;i>=0;i--){
	// 	if(i==0){printf("%d",listBilBelumAda[i]);}
	// 	else{printf("%d ",listBilBelumAda[i]);}
	// }
	// printf("\n");
	printf("%d\n",listBilBelumAda.size());
	int counterBil[maxn];
	memset(counterBil,0,sizeof counterBil);
	//printf("%d\n",counter[5]);
	for(i=0;i<n;i++){
		int bil = a[i];
		if(listBilBelumAda.size()==0){break;}
		int bilCalonGanti = listBilBelumAda.back();
		if(counter[bil]==1){continue;}
		// printf("a[%d]: %d\n",i,a[i]);
		if(!isUnique[bil]){
			if(bilCalonGanti<bil){//lgsg ganti
				a[i] = bilCalonGanti; listBilBelumAda.pop_back();
				counter[bil]--;
				// printf("counter[%d] jd: %d\n",bil,counter[bil]);
			}else{
				//cek jumlah counternya
				if(counterBil[bil]==1){
					a[i] = bilCalonGanti; listBilBelumAda.pop_back();
					counter[bil]--;
					// printf("counter[%d] jd: %d\n",bil,counter[bil]);
				}else{
					counterBil[bil]++;
				}
			}

		}
		
	}
	for(i=0;i<n;i++){
		if(i){printf(" ");}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
};