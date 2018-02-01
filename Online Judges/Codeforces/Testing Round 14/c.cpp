#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi totalJumlah;


struct pasangan{
	char kar;
	int nilai;
};

bool cmp(pasangan a, pasangan b){return a.nilai>b.nilai;}

int main(){
	int n,i,j;
	scanf("%d",&n);
	string listkata[1100];
	bool bolehNol[256];
	
	memset(bolehNol,true,sizeof bolehNol);
	map<char,int> mapper;
	map<int,char> mapper2;	
	int cnt = 0;
	for(i=0;i<n;i++){
		cin>>listkata[i];
		bolehNol[listkata[i][0]] = false;
		for(j=0;j<listkata[i].length();j++){
			char kar = listkata[i][j];
			int pangkat = listkata[i].length()-j-1;
			if(mapper.find(kar)==mapper.end()){
				mapper[kar] = cnt;
				mapper2[cnt] = kar;
				totalJumlah.pb((ll)pow(10,pangkat));
				// printf("mapper[%c]: %d dan totalJumlah.size()-1: %d\n",kar,cnt,(int)totalJumlah.size()-1);
				// printf("untuk karakter: %c baru ditambah: %lld\n",kar,(ll)pow(10,pangkat));
				cnt++;
			}else{
				int idx = mapper[kar];
				totalJumlah[idx]+=(ll)pow(10,pangkat);	
				//printf("untuk karakter: %c ditambah: %lld jadi: %lld\n",kar,(ll)pow(10,pangkat), totalJumlah[idx]);
			}
		}
	}
	vector<pasangan> listPasangan;
	for(i=0;i<cnt;i++){
		char kar = mapper2[i];
		pasangan a;
		a.kar = kar;
		a.nilai = totalJumlah[i];
		listPasangan.pb(a);
	}
	sort(listPasangan.begin(), listPasangan.end(), cmp);
	int nilaiAsli[256];
	//melakukan mex
	set<int> s;
	for(i=0;i<(int)listPasangan.size();i++){
		char kar = listPasangan[i].kar;
		
		// printf("idx: %d\n",idx);
		// printf("kar: %c dengan totalJumlah: %lld\n",kar,totalJumlah[idx]);
		//mex
		for(j=0;;j++){
			if(!s.count(j)){
				if(j==0){
					if(bolehNol[kar]){
						s.insert(j);
						nilaiAsli[kar] = j;
						//printf("nilaiAsli[%c]: %d\n",kar,nilaiAsli[kar]);
						break;
					}	
				}else{
					s.insert(j);
					nilaiAsli[kar] = j;
					//printf("nilaiAsli[%c]: %d\n",kar,nilaiAsli[kar]);
					break;
				}
				
			}
		}
	}

	ll sum = 0;
	for(i=0;i<n;i++){
		ll angka = 0;
		for(j=0;j<listkata[i].length();j++){
			char kar = listkata[i][j];
			angka*=10; angka+=nilaiAsli[kar];
		}
		sum+=angka;
	}
	printf("%lld\n",sum);
	return 0;
};