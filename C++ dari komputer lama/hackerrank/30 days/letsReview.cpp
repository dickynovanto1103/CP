#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i;
	string kata;
	vector <char> kata1, kata2;
	scanf("%d",&n);
	while(n--){
		cin>>kata;
		for(i=0;i<kata.length();i++){
			if(i%2==0){kata1.push_back(kata[i]);}
			else{kata2.push_back(kata[i]);}
		}
		
		for(i=0;i<kata1.size();i++){printf("%c",kata1[i]);}
		printf(" ");
		for(i=0;i<kata2.size();i++){printf("%c",kata2[i]);}
		printf("\n");
		kata1.clear(); kata2.clear();
	}
	return 0;
}