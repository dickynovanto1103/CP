#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	map<string,string> mapper;
	map<string,string>::iterator it;
	string kata, nomor;
	scanf("%d",&n);
	while(n--){
		cin>>kata>>nomor;
		mapper[kata] = nomor;
	}
	while(cin>>kata){
		it = mapper.find(kata);
		if(it==mapper.end()){printf("Not found\n");}
		else{cout<<kata<<"="<<mapper[kata]<<endl;}
	}
	return 0;
}