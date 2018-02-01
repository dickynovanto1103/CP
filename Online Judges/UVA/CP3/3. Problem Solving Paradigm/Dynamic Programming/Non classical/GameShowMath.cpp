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

int n,a[110],target;
bool foundSolution;

string intToString(int a){
	string kata = "";
	//convert dulu ke array of int
	int i;
	vi arr;
	while(a>0){
		int bil = a%10;
		a/=10;
		arr.pb(bil);
	}
	for(i=arr.size()-1;i>=0;i--){
		kata+=arr[i]+48;
	}
	return kata;
}

int hitung(int bil1, int bil2, int op){
	if(op==0){return bil1+bil2;}
	else if(op==1){return bil1-bil2;}
	else if(op==2){return bil1*bil2;}
	else if(op==3){return bil1/bil2;}
}

void solve(int id, int bil, string kata){
	int i;
	if(foundSolution){return;}
	if(id==n-1){
		if(bil==target){cout<<kata<<"="<<target<<endl; foundSolution= true;}
	}
	else{
		for(i=0;i<4;i++){
			//cout<<"kata sekarang: "<<kata<<endl; printf("id: %d\n",id);
			int hasil = hitung(bil,a[id+1],i);
			//if(hasil==target){printf("ketemu solusi\n");}
			//printf("considering a[%d] = %d dengan operasi: %d hasil: %d\n",id+1,a[id+1],i,hasil);
			if(i==3){//pembagian
				int temp = bil;//coba nanti resubmit ga usah make temp
				double tmp = (double) temp;
				int temp2 = a[id+1];//coba nanti resubmit ga usah make temp
				double tmp2 = (double) temp2;
				int ans = (int)ceil(tmp/tmp2);
				if(ans==hasil){
					string tempKata = kata;
					tempKata+="/";
					string hasilKonversi = intToString(a[id+1]);
					tempKata+=hasilKonversi;
					//cout<<"kata menjadi: "<<tempKata<<endl;
					solve(id+1,hasil,tempKata);
				}
			}else{
				if(hasil>=-32000 && hasil<=32000){
					string tempKata = kata;
					if(i==0){tempKata+="+";}
					else if(i==1){tempKata+="-";}
					else if(i==2){tempKata+="*";}
					string hasilKonversi = intToString(a[id+1]);
					tempKata+=hasilKonversi;
					//cout<<"kata menjadi: "<<tempKata<<endl;
					solve(id+1,hasil,tempKata);
				}
			}
		}
	}
}

int main() {
	int tc,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string kata;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]); 
		}
		scanf("%d",&target);
		//solve
		kata = intToString(a[0]);
		int bil = a[0];
		foundSolution = false;
		solve(0,bil,kata);
		if(!foundSolution){printf("NO EXPRESSION\n");}
	}
	return 0;
}