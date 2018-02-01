#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	string input,output;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>input;
		if(input=="semangat"){output="\\(^_^)/";}
		else if(input=="sebel"){output=">.<\"";}
		else if(input=="bingung"){output="(")/?";}

		cout<<"Case #"<<i+1<<": "<<output<<endl;
	}
	return 0;
}