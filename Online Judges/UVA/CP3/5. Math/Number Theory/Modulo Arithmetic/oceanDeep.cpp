#include <bits/stdc++.h>

using namespace std;
#define maxn 131071
int main(){
	int n,i,sum;
	string kata;
	string katatotal="";
	while(cin>>kata){
		
		katatotal+=kata;
		//cout<<"kata total: "<<katatotal<<endl;
		if(katatotal[katatotal.length()-1]=='#'){
			n = katatotal.length()-1; // ignoring the #
			sum = 0;
			//printf("n: %d\n",n);
			for(i=0;i<n;i++){
				int bil = katatotal[i]-48;
				//printf("bil: %d\n",bil);
				sum = (((sum%maxn * 2)%maxn) + (bil))%maxn;
				//printf("sum: %d\n",sum);
			}	
			if(sum==0){printf("YES\n");}
			else{printf("NO\n");}
			katatotal="";
		}
		
	}	
	
	
	return 0;
}