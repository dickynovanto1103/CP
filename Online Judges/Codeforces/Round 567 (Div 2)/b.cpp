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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

string sum(string a, string b) {
	if(a.length() < b.length()){swap(a,b);}
	string ans = "";
	bool isCarry = false;
	int idx = a.length() - 1;
	for(int i=b.length()-1;i>=0;i--){
		int bil1 = b[i] - '0', bil2 = a[idx] - '0';
		int bilBaru = bil1 + bil2;
		// printf("%d %d\n",bil1, bil2);
		// printf("i: %d bilBaru: %d\n",i, bilBaru);
		if(isCarry){bilBaru++; isCarry = false;}

		if(bilBaru >= 10){isCarry = true;}
		ans += ((bilBaru%10) + '0');
		idx--;
	}
	int start = a.length() - b.length() - 1;
	for(int i=idx;i>=0;i--){
		int bil = a[i] - '0';
		if(isCarry){bil++; isCarry =false;}
		if(bil >= 10){isCarry = true;}
		// printf("bil: %d\n",bil);
		ans += ((bil%10) + '0');
	}
	if(isCarry){ans += '1';}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	string s;
	cin>>s;
	vi listValid;
	int minim1 = inf;
	for(i=1;i<n;i++){
		if(s[i] != '0'){
			int pjg1 = i;
			int pjg2 = n-i;
			int maks = max(pjg1, pjg2);
			// printf("maks: %d pjg1: %d pjg2: %d i: %d\n",maks, pjg1, pjg2,i);
			if(minim1 > maks) {
				minim1 = maks;
				listValid.clear();
				listValid.pb(i);
			}else if(minim1 == maks) {
				listValid.pb(i);
				// printf("dipush: %d\n", );
			}
		}
	}
	string minim = "";
	for(i=0;i<listValid.size();i++){
		int idxAmbil = listValid[i];
		// printf("idxAmbil: %d\n",idxAmbil);
		string bil1, bil2;
		for(j=0;j<idxAmbil;j++){
			bil1 += s[j];
		}
		for(j=idxAmbil;j<n;j++){
			bil2 += s[j];
		}
		string jumlah1 = sum(bil1, bil2);
		if(minim == ""){minim = jumlah1;}
		else{
			string jumlah2 = minim;
			if(jumlah1.length() > jumlah2.length()) {
				minim = jumlah2;
				// cout<<jumlah2<<endl;
			}else if(jumlah1.length() < jumlah2.length()){
				minim = jumlah1;
			}else{
				if(jumlah2 > jumlah1){
					minim = jumlah1;
				}else{
					minim = jumlah2;
				}
			}
		}
	}
	cout<<minim<<endl;
	// int idxAmbil = listValid.size()/2;
	// idxAmbil = listValid[idxAmbil];
	// // printf("%d\n",idxAmbil);
	// string bil1, bil2;
	// for(i=0;i<idxAmbil;i++){
	// 	bil1 += s[i];
	// }
	// for(i=idxAmbil;i<n;i++){
	// 	bil2 += s[i];
	// }
	// string jumlah1 = sum(bil1, bil2);
	// string jumlah2 = "";
	// if(listValid.size() > 1) {
	// 	idxAmbil = (listValid.size() + 1) / 2;
	// 	if(listValid.size() % 2 == 0){
	// 		idxAmbil++;
	// 	}
	// 	idxAmbil = listValid[idxAmbil];
	// 	// printf("%d\n",idxAmbil);
	// 	bil1 = "", bil2 = "";
	// 	for(i=0;i<idxAmbil;i++){
	// 		bil1 += s[i];
	// 	}
	// 	for(i=idxAmbil;i<n;i++){
	// 		bil2 += s[i];
	// 	}
	// 	// cout<<bil1<<" "<<bil2<<endl;
	// 	jumlah2 = sum(bil1, bil2);
	// }
	// string minim;
	// // cout<<jumlah1<<" ---- "<<jumlah2<<endl;
	// if(jumlah1 == "" || jumlah2 == ""){
	// 	if(jumlah2 == ""){
	// 		cout<<jumlah1<<endl;
	// 	}else{
	// 		cout<<jumlah2<<endl;
	// 	}
	// 	return 0;
	// }
	// if(jumlah1.length() > jumlah2.length()) {
	// 	minim = jumlah2;
	// 	// cout<<jumlah2<<endl;
	// }else if(jumlah1.length() < jumlah2.length()){
	// 	minim = jumlah1;
	// 	// cout<<jumlah1<<endl;
	// }else{
	// 	if(jumlah2 > jumlah1){
	// 		minim = jumlah1;
	// 		// cout<<jumlah1<<endl;
	// 	}else{
	// 		minim = jumlah2;
	// 		// cout<<jumlah2<<endl;
	// 	}
	// }

	// idxAmbil = listValid.size() / 2;
	// idxAmbil--;
	// if(idxAmbil >= 0) {
	// 	idxAmbil = listValid[idxAmbil];
	// 	bil1 = "", bil2 = "";
	// 	for(i=0;i<idxAmbil;i++){
	// 		bil1 += s[i];
	// 	}
	// 	for(i=idxAmbil;i<n;i++){
	// 		bil2 += s[i];
	// 	}
	// 	// cout<<bil1<<" "<<bil2<<endl;
	// 	jumlah1 = sum(bil1, bil2);
	// 	jumlah2 = minim;
	// 	if(jumlah1 == "" || jumlah2 == ""){
	// 		if(jumlah2 == ""){
	// 			cout<<jumlah1<<endl;
	// 		}else{
	// 			cout<<jumlah2<<endl;
	// 		}
	// 		return 0;
	// 	}
	// 	if(jumlah1.length() > jumlah2.length()) {
	// 		minim = jumlah2;
	// 		// cout<<jumlah2<<endl;
	// 	}else if(jumlah1.length() < jumlah2.length()){
	// 		minim = jumlah1;
	// 		// cout<<jumlah1<<endl;
	// 	}else{
	// 		if(jumlah2 > jumlah1){
	// 			minim = jumlah1;
	// 			// cout<<jumlah1<<endl;
	// 		}else{
	// 			minim = jumlah2;
	// 			// cout<<jumlah2<<endl;
	// 		}
	// 	}
	// 	cout<<minim<<endl;

	// }else{
	// 	cout<<minim<<endl;
	// }

	
	return 0;
};