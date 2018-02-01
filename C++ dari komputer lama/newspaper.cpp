#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[400];

int main(){
	int tc,i,j,n,m,pjg,bil;
	ll ans;
	double final;
	char karakter;
	map <char,int> mapper;
	map <char,int>::iterator it;
	string kata;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<400;i++){a[i]=0;}//inisialisasi
		for(i=0;i<n;i++){scanf(" %c %d",&karakter,&bil); a[karakter]=bil; mapper[karakter]=i;}
		scanf("%d",&m);
		ans=0;
		for(i=0;i<m;i++){
			//printf("i: %d\n",i);
			if(i==0){getline(cin>>ws,kata);}
			else{getline(cin,kata);}
			
			//cout<<"kata: "<<kata<<endl;
			pjg = kata.length();
			for(j=0;j<pjg;j++){
				it=mapper.find(kata[j]);
				if(it!=mapper.end()){ans+=a[kata[j]];}
				
			}
		}
		final=(double)ans / 100.0;
		printf("%.2lf$\n",final);
	}
	return 0;
}