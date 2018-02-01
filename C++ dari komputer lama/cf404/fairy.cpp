#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int64_t n,m,mid,l,r;
	scanf("%I64d %I64d",&n,&m);
	if(n<=m){cout<<n<<endl;}
	else{
		n-=m;
		l = 0; r = 2e9;
		while(l<r){
			mid = (l+r)/2;
			int64_t val = (mid*(mid+1))/2;	
			if(n-val<=0){r = mid;}
			else{l = mid+1;}
		}
		//cout<<"l : "<<l<<endl;
		cout<<l+m<<endl;
	}

	return 0;
}