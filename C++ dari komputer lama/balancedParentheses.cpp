#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int main(){
	int n,i,j;
	stack<char> kotak;
	

	string kata;
	bool found;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		stack<char> bulat;
		if(i==0){getline(cin>>ws,kata);}
		else{getline(cin,kata);}
		found = true;
		if(kata.length()==0){printf("YES\n");}
		else{

			for(j=0;j<kata.length() && found;j++){
				if(kata[j]=='(' || kata[j]=='[' || kata[j]=='{'){
					bulat.push(kata[j]);
				}else{
					if(kata[j]==')'){
						if(bulat.empty()){found=false;}
						else{
							if(bulat.top()=='('){bulat.pop();}
							else{found=false;}
						}
					}else if(kata[j]==']'){
						if(bulat.empty()){found=false;}
						else{
							if(bulat.top()=='['){bulat.pop();}
							else{found=false;}
						}
					}else if(kata[j]=='}'){
						if(bulat.empty()){found=false;}
						else{
							if(bulat.top()=='{'){bulat.pop();}
							else{found=false;}
						}
					}
				}

			}
			if(found){
				if(bulat.empty()){printf("YES\n");}
				else{
					printf("NO\n");
					//kosongkan kedua stack
					//while(!bulat.empty()){bulat.pop();}
				}
			}else{printf("NO\n");}
			
		}
		//printf("i: %d\n",i);
	}
	return 0;
}