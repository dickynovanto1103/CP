#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,i,j;
	string kata;
	map<string,int> mapper;
	map<string,int>::iterator it;
	int a[10010];
	int tc;
	scanf("%d",&tc);
	cin>>ws;
	int test = 1;
	while(tc--){
		if(test>1){printf("\n");}
		int cnt = 0;
		int total = 0;
		vector<string> listOfKata;
		//inisialisasi
		for(i=0;i<10001;i++){a[i] = 0;}
		while(getline(cin,kata)){
			if(kata==""){break;}
			it = mapper.find(kata);
			total++;
			if(it==mapper.end()){mapper[kata] = cnt; a[cnt]++; cnt++; listOfKata.push_back(kata);}
			else{int idx = mapper[kata]; a[idx]++;}
		}
		sort(listOfKata.begin(), listOfKata.end());
		int ukuran = listOfKata.size();
		double persen;
		for(i=0;i<ukuran;i++){
			cout<<listOfKata[i]<<" ";
			int idx = mapper[listOfKata[i]];
			double cnt = a[idx]*1.0;
			persen = (cnt/(double)total) * 100;
			printf("%.4lf\n",persen);
		}
		test++;

		mapper.clear();
	}
	return 0;
}