#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll memo[6][300001];
int n,listIdx[300001],cnt;
const int mod = 1e9 + 7;
string kata;

int jumlahBom(string kata, int idx){
	int v1 = idx-1, v2 = idx+1;
	int cntBom = 0, cntTanya = 0;
	if(v1>=0){
		if(temp[v1]=='*'){cntBom++;}
		else if(temp[v1]=='?'){cntTanya++;}
	}
	if(v2<n){
		if(temp[v2]=='*'){cntBom++;}
		else if(temp[v2]=='?'){cntTanya++;}
	}
	return cntBom;
}

ll solve(int id, int idx, string temp){
	if(idx==cnt){return 1;}
	if(memo[id][idx]!=-1){return memo[id][idx];}
	int indeks = listIdx[idx];
	string kataBaru = temp;
	int v1 = indeks-1, v2 = indeks+1;
	int cntBom = 0, cntTanya = 0;
	if(v1>=0){
		if(temp[v1]=='*'){cntBom++;}
		else if(temp[v1]=='?'){cntTanya++;}
	}
	if(v2<n){
		if(temp[v2]=='*'){cntBom++;}
		else if(temp[v2]=='?'){cntTanya++;}
	}

	if(id==0){//*1
		if(v1<0){return 0;}//indeks=0
		if(cntBom==2){return 0;}
		if(cntBom==1 && v2<n && kataBaru[v2]=='*'){return 0;}
		if(cntBom==1 && kataBaru[v1]=='*'){kataBaru[indeks]='1';}
	}else if(id==1){//0
		if(cntBom>0){return 0;}
		kataBaru[indeks]='0';
	}else if(id==2){//2
		if(cntBom+cntTanya<2){return 0;}
		if(kataBaru[v2]=='?' && kataBaru[v1]=='*'){kataBaru[v2]='*'; kataBaru[indeks]='2';}
		
		if(cntBom==2){kataBaru[indeks]='2';}
		
	}else if(id==3){//bom
		bool found = false;
		char kar = kataBaru[indeks];
		kataBaru[indeks] = '*';
		int bil = kataBaru[v2]-48;
		if(bil>=0 && bil<=9){//cek kanan dan kiri dari potensial bom..harus berjumlah sama klo angka
			if(jumlahBom(kataBaru,v2)>bil){return 0;}
			else{
				bil = kataBaru[v1]-48;
				if(bil>=0 && bil<=9){
					if(jumlahBom(kataBaru,v1)>bil){return 0;}
					else{kataBaru[indeks]='2';}
				}else{
					kataBaru[indeks]='*';
				}
				
			}
		}else{
			kataBaru[indeks]='*';
		}
		
	}else{//1*
		if(v2>=n){return 0;}
		if(kataBaru[v2]=='?'){
			if(kataBaru[v1]=='*'){return 0;}
			else{kataBaru[]}
		}
		if(jumlahBom(kataBaru,indeks)>1)
	}
	
	ll ans = 0;
	

	for(i=0;i<5;i++){
		ans+=solve(i,idx+1,kataBaru);
		ans%=mod;
	}
	memo[id][idx] = ans;
}

int main() {
	int i;
	cin>>kata>>endl;
	n = kata.length();
	cnt = 0;
	for(i=0;i<n;i++){if(kata[i]=='?'){listIdx[cnt]=i; cnt++;}}
	memset(memo,-1,sizeof memo);
	string temp = kata;
	ll ans = 0;
	for(i=0;i<5;i++){
		ans+=solve(i,0,temp);	
		ans%=mod;
	}
	
	return 0;
}