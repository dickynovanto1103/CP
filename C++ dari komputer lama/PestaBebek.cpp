#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N,i,k;
	string nama[1010],temp;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>nama[i];
		temp=nama[i];
		sort(nama,nama+i+1);
		for(k=1;k<=i;k++){
			if(nama[k]==temp){
				cout<<k<<endl;
			}
		}
	}
	
	return 0;
}