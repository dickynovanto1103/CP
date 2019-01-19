#include <bits/stdc++.h>

using namespace std;

int main(){
	int cnt=1,i,j,k,l,m;
	map<string,int> mapper;
	map<string,int>::iterator it;

	//1 huruf
	
	for(i=97;i<=122;i++){
		string kata = "";
		char kar = i; kata+=kar;
		mapper[kata]=cnt++;
		//printf("kata: ");cout<<kata<<endl;
	}
	//2 huruf
	for(i=97;i<=122;i++){
		for(j=i+1;j<=122;j++){
			string kata = "";
			char kar = i; kata+=kar;
			kar = j; kata+=kar;
			mapper[kata]=cnt++;
			//printf("kata: ");cout<<kata<<endl;
		}
	}
	for(i=97;i<=122;i++){
		for(j=i+1;j<=122;j++){
			for(k=j+1;k<=122;k++){
				string kata = "";
				char kar = i; kata+=kar;
				kar = j; kata+=kar;
				kar = k; kata+=kar;
				mapper[kata]=cnt++;	
			}
		}
	}
	for(i=97;i<=122;i++){
		for(j=i+1;j<=122;j++){
			for(k=j+1;k<=122;k++){
				for(l=k+1;l<=122;l++){
					string kata = "";
					char kar = i; kata+=kar;
					kar = j; kata+=kar;
					kar = k; kata+=kar;
					kar = l; kata+=kar;
					mapper[kata]=cnt++;	
				}
			}
		}
	}
	for(i=97;i<=122;i++){
		for(j=i+1;j<=122;j++){
			for(k=j+1;k<=122;k++){
				for(l=k+1;l<=122;l++){
					for(m=l+1;m<=122;m++){
						string kata = "";
						char kar = i; kata+=kar;
						kar = j; kata+=kar;
						kar = k; kata+=kar;
						kar = l; kata+=kar;
						kar = m; kata+=kar;
						mapper[kata]=cnt++;		
					}
					
				}
			}
		}
	}
	string kata;
	while(cin>>kata){
		if(mapper.find(kata)==mapper.end()){printf("0\n");}
		else{printf("%d\n",mapper[kata]);}
		
	}
	
	return 0;
}