#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef unsigned long long uint64;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


int main() {
	uint64 a,b,i;
	int tc;
	scanf("%d",&tc);
	while(tc--){
		//printf("a: %lld b: %lld\n",a,b);
		scanf("%llu %llu",&a,&b);
		//printf("a: %llu b: %llu\n",a,b);
		if(a==0 && a==b){printf("0\n");}
		else{
			uint64 ans = a;
			//string kata = toBinary(ans);
			uint64 target;
			if(a%2==1){target = a-1;}
			else{target = 0;}
			uint64 awal;
			for(i=a+1;i<=b;i++){
				//string binaryBil = toBinary(i);
				/*printf("ans: %lld binary: ",ans); cout<<kata<<endl;
				printf("i: %lld binary: ",i); cout<<binaryBil<<endl;*/
				ans^=i;
				if(ans==target){awal = i; break;}
				//kata = toBinary(ans);
				//printf("setelah di xor dengan %lld, ans jd: %lld dan binary: ",i,ans); cout<<kata<<endl;
			}
			//printf("awal: %llu\n",awal);
			if(i==b+1){//ga usah loop
				cout<<ans<<endl;
			}else{
				
				uint64 loop = (b-awal)/(uint64)4;
				uint64 idxBaru = awal + (loop*4);
				/*printf("masuk sini lah\n");
				printf("b: %llu target: %llu\n",b,target);
				printf("idx baru: %llu loop: %llu\n",idxBaru,loop);*/
				ans = target;
				if(idxBaru==b){
					cout<<ans<<endl;
				}
				else{
					for(i=idxBaru+1;i<=b;i++){
						//printf("i: %llu\n",i);
						ans^=i;
						if(i==b){break;}
					}
					//printf("test:\n");
					cout<<ans<<endl;
					
				}
				
			}
		}
	}
	
	
	

	
	
	return 0;
}