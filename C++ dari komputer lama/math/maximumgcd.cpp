#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(){
	int tc,n,i, a[110],j,ans,bil,idx;
	string str;
	scanf("%d",&tc);
	while(tc--){
		ans=-1; i=0; idx=0;
		getline(cin >> ws,str);
		//cout<<"string yang dibaca adalah: "<<str << endl;
		bil = 0;
		while(idx<str.length()){
			bil=bil*10 + str[idx]-'0';
			idx++;
			if(str[idx]==' ' || idx==str.length()){a[i++]=bil;idx++; bil=0;}
		}
		int cnt=i;
		//for(i=0;i<cnt;i++){printf("a indeks ke %d adalah %d\n",i,a[i]);}

		//for(i=0;i<cnt;i++){printf("%d\n",a[i]);}
		for(i=0;i<cnt-1;i++){
			for(j=i+1;j<cnt;j++){
				//printf("test cek\n");
				ans=max(ans,gcd(a[i],a[j]));
				//printf("test cek %d dan %d\n",i,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}