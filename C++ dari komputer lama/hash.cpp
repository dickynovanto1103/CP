#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int total,n,i,bil;
	string kata;
	scanf("%d",&n);
	while(n--){
		cin>>kata;
		total=0;
		cout<<kata<<endl;
		for(i=0;i<kata.length();i++){
			bil=kata[i]-'a'+1;
			//printf("karakter: %c bil: %d\n",kata[i],bil);
			total+=bil;
		}
		printf("total: %d\n",total);
		total%=5;
		printf("total sekarang: %d\n",total+1);
	}
	return 0;
}