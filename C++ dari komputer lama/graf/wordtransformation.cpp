#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;

vector <vi> AdjList;
int main(){
	int tc,i,j,cnt;
	map <string, int> mapper;
	map <string,int>::iterator it;
	string kata[210],temp;
	i=0;
	scanf("%d",&tc);
	while(tc--){
		cin>>kata[i];
		while(kata[i]!="*"){
			mapper[kata[i]]=cnt++;
			cout<<"kata di kamus: "<<kata[i]<<endl;
			i++;
			cin>>kata[i];
		}
		getline(cin>>ws,temp);
		while(temp!=""){printf("kata yang dibaca: "); cout<<temp<<endl; getline(cin,temp);}
		getline(cin,temp);
	}
	
	return 0;
}