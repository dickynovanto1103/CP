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

const int maxn = 3e5 + 5;

vi listValidKiri, listValidKanan, listNetral;
int hasil;

bool isValid(string kata){
	stack<char> s;
	int i,j;
	int pjg = kata.length();
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar=='('){
			s.push(kar);
		}else{
			if(s.empty()){
				return false;
			}else{
				if(s.top() == '('){
					s.pop();	
				}
			}
		}
	}
	if(s.empty()){return true;}
	else{return false;}
}

bool isValidKanan(string kata) {
	//harus negatif dan stack harus kosong
	stack<char> s;
	int i,j;
	int pjg = kata.length();
	int total = 0;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar=='('){total++;}
		else{total--;}
		if(kar=='('){
			s.push(kar);
		}else{
			if(s.empty()){continue;}
			if(s.top() == '('){
				s.pop();
			}
		}
	}

	if(total <0 && s.empty()){
		hasil = total;
		return true;
	}
	else{return false;}
}

bool isValidKiri(string kata) {
	//total harus positif dan ada sisa di stack
	stack<char> s;
	int i,j;
	int pjg = kata.length();
	int total = 0;
	for(i=0;i<pjg;i++){
		char kar = kata[i];
		if(kar=='('){
			total++;
		}else{
			total--;
		}
		if(kar=='('){
			s.push(kar);
		}else{
			if(s.empty()){
				return false;
			}else{
				if(s.top() == '('){
					s.pop();	
				}
			}
		}
	}
	if(total>0 && !s.empty()){
		hasil = total;
		return true;
	}else{
		return false;
	}
}

string kata[maxn];

int main(){
	int n,i,j;
	
	// printf("halo\n");
	scanf("%d",&n);
	// printf("n; %d\n",n);
	for(i=0;i<n;i++){
		cin>>kata[i];
		// printf("test\n");
		if(isValid(kata[i])){

			listNetral.pb(i);
		}else{
			// printf("test2\n");
			if(isValidKiri(kata[i])){
				listValidKiri.pb(hasil);
			}else{
				// printf("test3\n");
				if(isValidKanan(kata[i])){
					listValidKanan.pb(hasil);
				}
			}
		}
	}

	ll ans = 0;
	ll ukuranNetral = listNetral.size();
	ans+=(ukuranNetral*ukuranNetral);
	// printf("ans jd: %lld\n",ans);
	sort(listValidKiri.begin(), listValidKiri.end());
	sort(listValidKanan.begin(), listValidKanan.end());

	for(i=0;i<listValidKiri.size();i++){

		int bil = listValidKiri[i];
		// printf("bil: %d\n",bil);
		int cari = -bil;
		//hitung cari di listValid kanan
		ll banyak = 0;
		if(binary_search(listValidKanan.begin(), listValidKanan.end(), cari)){
			int idx1 = lower_bound(listValidKanan.begin(), listValidKanan.end(), cari) - listValidKanan.begin();
			int idx2 = upper_bound(listValidKanan.begin(), listValidKanan.end(), cari) - listValidKanan.begin() - 1;	
			// printf("idx1: %d idx2: %d\n",idx1,idx2);
			banyak=(idx2 - idx1 + 1);
		}
		ans+=banyak;
		// printf("1 ans jd: %lld\n",ans);
	}
	// for(i=0;i<listValidKanan.size();i++){
	// 	int bil = listValidKanan[i];
	// 	printf("bil: %d\n",bil);
	// 	// int cari = -bil;
	// 	// //hitung cari di listValid kiri
	// 	// ll banyak;
	// 	// if(binary_search(listValidKiri.begin(), listValidKiri.end(), cari)){
	// 	// 	int idx1 = lower_bound(listValidKiri.begin(), listValidKiri.end(), cari) - listValidKiri.begin();
	// 	// 	int idx2 = upper_bound(listValidKiri.begin(), listValidKiri.end(), cari) - listValidKiri.begin() - 1;	
	// 	// 	banyak=(idx2 - idx1 + 1);
	// 	// }
	// 	// ans+=banyak;
	// 	// printf("2 ans jd: %lld\n",ans);
	// }
	printf("%lld\n",ans);

	return 0;
};