#include <bits/stdc++.h>

using namespace std;

struct nama{
	string kata;
	int jumlah;
};

bool acompare(nama lhs, nama rhs){return lhs.jumlah > rhs.jumlah;}
bool bcompare(nama lhs, nama rhs){return lhs.kata < rhs.kata;}

int main(){
	int tc,n,i,j,test=1,pjg,cnt;
	nama data[110];
	map<char,int> mapper;
	map<char,int>::iterator it;
	scanf("%d",&tc);
	while(tc--){
		printf("Case #%d: ",test++);
		scanf("%d",&n); cnt = 0;
		for(i=0;i<n;i++){data[i].jumlah=0;}//inisialisasi
		for(i=0;i<n;i++){
			if(i==0){getline(cin>>ws,data[i].kata);}
			else{getline(cin,data[i].kata);}
			pjg=data[i].kata.length();
			for(j=0;j<pjg;j++){
				char karakter = data[i].kata[j];
				if(karakter!=' '){
					it=mapper.find(karakter);
					if(it==mapper.end()){data[i].jumlah++; mapper[karakter]=cnt++;}
				}
			}
			mapper.clear();

		}
		//sort jumlah karakter decreasing order dulu
		sort(data,data+n,acompare);
		//klo ties occurs sort berdasarkan alfabet
		int temp = data[0].jumlah, idx = 0; 
		for(i=1;i<n;i++){
			if(data[i].jumlah!=temp){sort(data+idx,data+i,bcompare); idx = i; temp = data[i].jumlah;}
		}
		sort(data+idx,data+n,bcompare);
		/*printf("data akhir:\n");
		for(i=0;i<n;i++){cout<<data[i].jumlah<<" "<<data[i].kata<<endl;}*/
		cout<<data[0].kata<<endl;
		
		mapper.clear();
	}
	return 0;
}