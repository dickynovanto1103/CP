#include <bits/stdc++.h>

using namespace std;

int main(){
	stack<char> s;
	int i;
	bool found=true;
	string kata,semua = "";
	while(getline(cin,kata)){
		semua+=kata;
	}
	
	//cout<<semua<<endl;
	for(i=0;i<semua.length();i++){
		char kar = semua[i];
		if(kar=='('){s.push(kar);}
		else if(kar==')'){
			//printf("masuk kurung tutup\n");
			if(s.empty()){printf("Error\n"); found = false; break;}
			char karakter = s.top(); 
			if(karakter != '('){printf("Error\n"); found = false;break;}
			else{s.pop();}
		}else if(kar=='['){s.push(kar);}
		else if(kar==']'){
			//printf("masuk kurung siku tutup\n");
			if(s.empty()){printf("Error\n"); found = false;found = false;break;}
			char karakter = s.top(); 
			if(karakter != '['){printf("Error\n");found = false; break;}
			else{s.pop();}
		}else if(kar=='{'){s.push(kar);}
		else if(kar=='}'){
			//printf("masuk kurung kurawal tutup\n");
			if(s.empty()){printf("Error\n");found = false; break;}
			char karakter = s.top(); 
			if(karakter != '{'){printf("Error\n"); found = false;break;}
			else{s.pop();}
		}
		//printf("%c\n",kar);
	}
	if(found){
		if(s.empty()){printf("Compiled\n");}
		else{printf("Error\n");}	
	}
	
	return 0;
}