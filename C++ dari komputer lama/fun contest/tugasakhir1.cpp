#include <bits/stdc++.h>

using namespace std;

string kata,temp;

int main(){
	long long ans=1,i,sum=1,panjangkata,cursum;
	cin>>kata;
	panjangkata=kata.length();
	//printf("panjang kata: %d\n",panjangkata);
	temp=kata;
	for(i=0;i<panjangkata;i++){
		//cek banyak ta
		if(i+3 < panjangkata){
			
			if(kata[i]=='D' && kata[i+1]=='O' && kata[i+2]=='T' && kata[i+3]=='A'){sum*=4; sum=sum%1000000007;kata[i]='x';kata[i+1]='x';kata[i+2]='x';kata[i+3]='x';}
		}
		if(i+2 < panjangkata){
			
			if(kata[i]=='G' && kata[i+1]=='T' && kata[i+2]=='A'){sum*=3; sum=sum%1000000007;kata[i]='x';kata[i+1]='x';kata[i+2]='x';}
		}
		if(i+1 < panjangkata){
			
			if(kata[i]=='T' && kata[i+1]=='A'){sum*=2; sum=sum%1000000007;kata[i]='x';kata[i+1]='x';}
		}
		
	}	
	printf("%lld\n",sum);
	return 0;
}