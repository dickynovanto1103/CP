#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define maxn 20

bool isDoublets(string a, string b){
	int cnt = 0;
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i]){cnt++;}
	}
	return cnt==1;
}
vector<string> listKata;
int parent[25200];

void PrintPath(int idx){
	//printf("parent[%d] : %d\n",idx,parent[idx]);
	if(parent[idx]!=idx){PrintPath(parent[idx]);}
	cout<<listKata[idx]<<endl;
}

int main() {
	string kata;
	vector<string> listWord[maxn];
	int cnt = 0,i,j;
	int minim = inf,maks = -inf;
	while(getline(cin,kata) && kata.length()){
		int pjg = kata.length();
		if(listWord[pjg].empty()){listWord[pjg].pb("");}
		listWord[pjg].pb(kata);
		minim = min(minim,pjg); maks = max(maks,pjg);
		cnt++;
	}
	//printf("ada cnt: %d\n",cnt);
	/*for(i=minim;i<=maks;i++){
		printf("string dengan panjang: %d\n",i);
		vector<string> list = listWord[i];
		for(j=0;j<list.size();j++){
			if(j){printf(" ");}
			cout<<list[j];
		}
		printf("\n");
	}*/
	//printf("list\n");
	string a,z;
	int test = 1;
	while(cin>>a>>z){
		if(test==2){printf("\n");}
		//cout<<a<<" "<<z<<endl;
		int pjg = a.length();
		int pjg1 = z.length();
		memset(parent,0,sizeof parent);
		if(pjg1==pjg){
			listKata = listWord[pjg];
			int idxA = find(listKata.begin(),listKata.end(),a) - listKata.begin();
			int idxZ = find(listKata.begin(),listKata.end(),z) - listKata.begin();
			if(idxA==listKata.size() || idxZ==listKata.size()){printf("No solution.\n");}//ga ketemu salah satu atau dua"nya
			else{//ketemu dua"nya..cari
				parent[idxA] = idxA;
				queue<int> q; q.push(idxA);
				int ukuran = listKata.size();
				while(!q.empty() && q.front()!=idxZ){
					int front = q.front(); q.pop();
					//printf("front: %d\n",front);
					for(i=0;i<ukuran;i++){
						if(!parent[i] && isDoublets(listKata[i],listKata[front])){
							//printf("parent[%d] sekarang: %d\n",i,parent[i]);
							parent[i] = front;
							//printf("parent[%d] = %d versi kata: parent dari ",i,front); cout<<listKata[i]<<" adalah "<<listKata[front]<<endl;
							q.push(i);
						}
					}
				}
				//printf("sudah keluar\n");
				if(!parent[idxZ]){printf("No solution.\n");}
				else{PrintPath(idxZ);}
			}
		}else{
			printf("No solution.\n");
		}
		listKata.clear();
		test = 2;	
	}
	return 0;
}