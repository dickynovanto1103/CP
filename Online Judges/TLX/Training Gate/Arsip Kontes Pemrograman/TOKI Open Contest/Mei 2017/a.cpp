#include <bits/stdc++.h>

using namespace std;

int main(){
	string kata;
	int n;
	cin>>kata;
	scanf("%d",&n);
	for(int i=kata.length()-1;i>=0;i--){
		if(kata[i]=='_'){
			int bil = n%26;
			n/=26;
			if(bil!=0){n++;}
			int tambahan;
			if(bil==0){bil+=122;}//biar jadi z
			else{bil+=96;}
			char kar = bil;
			kata[i] = kar;
		}
	}
	cout<<kata<<endl;
	return 0;
}