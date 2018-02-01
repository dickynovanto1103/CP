#include <bits/stdc++.h>

using namespace std;

int main(){
	int tc,n,org,i,j,cnt,maxcntdibantu,cntdibantu;
	bool isdibantu;
	map <string,int> mapper,mapperdibantu;
	map <string,int>::iterator it;
	string status,nama;
	scanf("%d",&tc);
	while(tc--){
		isdibantu=false;
		cnt=maxcntdibantu=cntdibantu=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			cin>>status;
			if(status=="dibantu"){isdibantu=true;}
			scanf("%d",&org);
			for(j=0;j<org;j++){
				cin>>nama;
				if(status=="dibantu"){
					maxcntdibantu=max(maxcntdibantu,org);
					it=mapperdibantu.find(nama);
					if(it==mapperdibantu.end()){mapperdibantu[nama]=++cntdibantu;}
				}
				it=mapper.find(nama);
				if(it==mapper.end()){mapper[nama]=++cnt;}
			}
		}
		if(cnt==maxcntdibantu){cnt++;}
		printf("%d\n",cnt);
		mapper.clear(); mapperdibantu.clear();
	}
	return 0;
}