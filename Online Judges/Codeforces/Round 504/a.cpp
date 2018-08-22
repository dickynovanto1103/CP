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
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m,i,j;
	string a,b;
	scanf("%d %d",&n,&m);
	cin>>a>>b;
	if(a == b){printf("YES\n"); return 0;}
	string kata1 = "", kata2 = "";
	bool sudahBintang = false;
	for(i=0;i<n;i++){
		if(a[i] == '*'){sudahBintang = true; continue;}
		if(sudahBintang){
			kata2 += a[i];
		}else{
			kata1 += a[i];
		}
	}
	if(!sudahBintang){
		if(a == b){printf("YES\n");}
		else{printf("NO\n");}
		return 0;
	}
	string ambil1 = b.substr(0,kata1.length());
	if(ambil1 != kata1){
		printf("NO\n");
		return 0;
	}
	// cout<<ambil1<<endl;
	// cout<<"kata1: "<<kata1<<" kata2" <<kata2<<" ambil1: "<<ambil1<<endl;
	//ambil sisanya
	int panjang1 = kata1.length();
	int sisa = n-panjang1 - 1;
	// printf("sisa: %d\n",sisa);
	string sementara = "";
	string temp = b;
	while(sisa--){
		if(b.empty()){break;}
		sementara += b.back();
		b.pop_back();
	}
	reverse(sementara.begin(), sementara.end());
	// cout<<"sementara: "<<sementara<<endl;
	// printf("b: "); cout<<b<<endl;
	if(sementara != kata2){
		printf("NO\n");
	}else{
		if(b.length() >= kata1.length()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		// if(b == kata1){
		// 	printf("YES\n");
		// }else{
		// 	printf("NO\n");
		// }
		// printf("YES\n");
	}
	b = temp;
	
	// string temp = b;
	// string ambil2 = "";
	// while(ambil2.length() < kata2.length()){
	// 	char kar = a.back();
	// 	ambil2 += kar;
	// 	a.pop_back();
	// }
	// reverse(ambil2.begin(), ambil2.end());
	// // printf("ambil1: "); cout<<ambil1<<" ambil2: "<<ambil2<<endl;
	// if(kata1 == ambil1 && kata2 == ambil2){
	// 	printf("YES\n");
	// }else{
	// 	printf("NO\n");
	// }
	return 0;
};