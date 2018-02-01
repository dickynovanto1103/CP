#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,n,i,pjg,cnt,test=1;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		cin>>n>>kata;
		
		pjg=kata.length();
		//cek yang sebelahnya 2;
		cnt=0;
		for(i=0;i<pjg;i++){
			if(kata[i]=='.'){
				if(i+2<pjg){cnt++;kata[i]='$';kata[i+1]='$';kata[i+2]='$';}
				else if(i+1<pjg){cnt++;kata[i]='$';kata[i+1]='$';}
				else if(i<pjg){cnt++;kata[i]='$';}
			}
		}

		printf("Case %d: %d\n",test++,cnt);
	}
	return 0;
}