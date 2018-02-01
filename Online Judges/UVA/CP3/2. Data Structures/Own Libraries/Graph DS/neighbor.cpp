#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> AdjList;
int main(){
	int tc,n,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		AdjList.assign(n+1,vi());
		string kata;
		cin>>ws;
		int minim = 1000000;
		for(i=1;i<=n;i++){
			getline(cin,kata);
			//cout<<"kata: "<<kata<<endl;
			int ukuran = kata.length();
			int bil = 0;
			int cnt = 0;
			for(j=0;j<ukuran;j++){
				if(kata[j]==' '){
					//printf("bil: %d\n",bil);
					cnt++;
					AdjList[i].push_back(bil); bil = 0;
				}
				else{
					char kar = kata[j];
					int angka = kar-48;
					bil*=10; bil+=angka;
				}
			}
			cnt++;
			//printf("bil terakhir: %d\n",bil);
			AdjList[i].push_back(bil);
			minim = min(minim,cnt);
		}
		/*for(i=1;i<=n;i++){
			printf("node %d:",i);
			for(j=0;j<AdjList[i].size();j++){
				printf(" %d",AdjList[i][j]);
			}
			printf("\n");
		}*/
		vi listans;
		for(i=1;i<=n;i++){
			if(AdjList[i].size()==minim){
				listans.push_back(i);
			}
		}
		int ukuran = listans.size();
		for(i=0;i<ukuran;i++){
			if(i>0){printf(" ");}
			printf("%d",listans[i]);
		}
		printf("\n");
		AdjList.clear();
	}
	return 0;
}