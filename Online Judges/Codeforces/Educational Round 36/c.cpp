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

vi parse(ll n){
	int i,j;
	vi a;
	while(n>0){
		int bil = n%10;
		a.pb(bil);
		n/=10;
	}
	reverse(a.begin(),a.end());
	return a;
}

vi a,b;
int counter[10];
bool isValidBigger;
string jawab;
vector<string> listAns;
void solve(int idx, string &kata){
	int i;
	if(idx==b.size()){
		return;
	}
	int bilMaks = b[idx];
	bool found = false;
	string ans = kata;
	if(isValidBigger){
		for(i=9;i>=0;i--){
			if(counter[i]>0){
				found = true;
				counter[i]--;
				char kar = i+'0';
				string baru = kata+kar;
				if(baru=="0"){continue;}
				//cout<<"baru: "<<baru<<endl;
				solve(idx+1, baru);
				if(baru.length()==b.size()){
					listAns.pb(baru); 
				}
				counter[i]++;
			}
		}
	}else{
		for(i=bilMaks;i>=0;i--){
			if(i!=bilMaks){isValidBigger = true;}
			if(counter[i]>0){
				found = true;
				counter[i]--;
				char kar = i+'0';
				string baru = ans+kar;
				if(baru=="0"){continue;}
				//cout<<"baru: "<<baru<<endl;
				solve(idx+1, baru);
				if(baru.length()==b.size()){
					listAns.pb(baru); 
				}
				counter[i]++;
			}
		}
	}
	if(!found){return;}
	
}

int main(){
	ll bil1,bil2;
	int i,j;
	isValidBigger = false;
	
	memset(counter,0,sizeof counter);
	scanf("%lld %lld",&bil1,&bil2);
	a = parse(bil1);
	b = parse(bil2);

	for(i=0;i<a.size();i++){
		counter[a[i]]++;
	}
	// for(i=0;i<b.size();i++){
	// 	if(i){printf(" ");}
	// 	printf("%d",b[i]);
	// }
	// printf("\n");

	if(b.size()>a.size()){
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());

		for(i=0;i<a.size();i++){
			//if(i){printf(" ");}
			printf("%d",a[i]);

		}
		printf("\n");
	}else{
		string kata = "";
		string katab = "";
		for(i=0;i<b.size();i++){
			int angka = b[i];
			katab+=(angka+'0');
		}

		solve(0,kata);
		int ukuran = listAns.size();
		string maks = "0";
		for(i=0;i<ukuran;i++){
			if(katab>=listAns[i]){
				maks = max(maks,listAns[i]);
			}
		}
		cout<<maks<<endl;
		// bool isVisited[20];
		// memset(isVisited,false,sizeof isVisited);
		// vi ans;
		// bool validToBigger = false;
		// for(i=0;i<b.size();i++){
		// 	int bil = b[i];
		// 	//cari di a bil yang <=di b
		// 	int maks = -1;
		// 	int idx=-1;
		// 	for(j=0;j<a.size();j++){
		// 		int bil1 = a[j];
		// 		if(validToBigger){
		// 			if(!isVisited[j]){
		// 				if(maks < bil1){
		// 					idx = j;
		// 					maks = bil1;
		// 				}
		// 			}
		// 		}else{
		// 			if(bil1<=bil && !isVisited[j]){

		// 				if(maks<bil1){
		// 					idx = j;
		// 					maks = bil1;
		// 				}
		// 			}	
		// 		}
				

		// 	}
		// 	if(maks==-1){
		// 		// printf("masuk sini\n");
		// 		for(i=0;i<a.size();i++){
		// 			//if(i){printf(" ");}
		// 			printf("%d",a[i]);

		// 		}
		// 		printf("\n");
		// 		return 0;
		// 	}
		// 	if(maks<bil){validToBigger = true;}
		// 	ans.pb(maks);
		// 	isVisited[idx] = true;
		// }
		// // bool beres = true;
		// // for(i=0;i<a.size();i++){
		// // 	if(!isVisited[i]){beres = false; break;}
		// // }
		// // if(!beres){
		// // 	for(i=0;i<a.size();i++){
		// // 		//if(i){printf(" ");}
		// // 		printf("%d",a[i]);

		// // 	}
		// // 	printf("\n");
		// // 	return 0;
		// // }
		// for(i=0;i<ans.size();i++){
		// 	//if(i){printf(" ");}
		// 	printf("%d",ans[i]);
		// }
		// printf("\n");
	}
	return 0;
};