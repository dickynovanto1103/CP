#include <bits/stdc++.h>
#include <unistd.h>

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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct compare2{
	bool operator() (const ii &a, const ii &b) const{
		return a.first < b.first;
	}
};

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string st;
		cin>>st;
		// printf("n: %d\n",n);
		// cout<<"st:"<<st<<endl;
		char cur = 'a';
		int prev = 0;
		// set<ii, compare> s;
		// set<ii, compare>::iterator it;
		set<ii, compare2> s1;
		set<ii, compare2>::iterator it1;
		set<ii, compare2> s2;
		set<ii, compare2> s3, satu;
		vii list;
		for(i=0;i<n;i++){
			if(cur != st[i]) {
				if(cur == 'a'){

				}else{
					s1.insert(ii(prev, i-1));
					int selisih = i-1-prev+1;
					// s.insert(ii(prev, i-1));
					if(selisih == 2) {
						s2.insert(ii(prev, i-1));
					}else if(selisih > 2){
						s3.insert(ii(prev, i-1));
					} else if(selisih == 1){
						satu.insert(ii(prev, i-1));
					}
				}
				prev = i;
			}
			
			cur = st[i];
		}
		// s.insert(ii(prev, n-1));
		s1.insert(ii(prev, n-1));
		int selisih = n-1-prev+1;
		if(selisih == 2) {
			s2.insert(ii(prev, n-1));
		}else if(selisih > 2){
			s3.insert(ii(prev, n-1));
		} else if(selisih == 1){
			satu.insert(ii(prev, n-1));
		}

		// printf("test2\n");
		// for(it1=s1.begin(); it1!=s1.end();it1++){
		// 	ii pas = *it1;
		// 	printf("%d %d\n",pas.first, pas.second);
		// }
		int ans = 0;
		while(s1.size() > 0){
			ii pertama = *s1.begin();
			// printf("pertama: %d %d\n",pertama.first, pertama.second);
			if(pertama.second != pertama.first){
				s1.erase(ii(pertama.first, pertama.second));
				int selisih = pertama.second - pertama.first + 1;
				// printf("selisih: %d\n",selisih);
				if(selisih > 2){
					s3.erase(pertama);
				}else if(selisih == 2){
					s2.erase(pertama);
				}
			}else{
				// printf("hello\n");
				//ambil dari yang paling besar
				s1.erase(pertama);
				satu.erase(pertama); //this is the bug of not deleting the element of only having length 1
				//find next bil pasangan yang terdekat dengan pertama dan selisihnya > 2..klo ga ada...pilih yang selisihnya 2 terdekat
				if(s3.size()){
					// printf("halo\n");
					ii pas = *s3.begin();
					s1.erase(pas);
					s3.erase(pas);
					s1.insert(ii(pas.first+1, pas.second));
					int selisihNow = pas.second - (pas.first+1)+1;
					if(selisihNow == 2){
						s2.insert(ii(pas.first+1, pas.second));
					}else if (selisihNow > 2){
						s3.insert(ii(pas.first+1, pas.second));
					}else{
						assert(false);
					}
				}else if(s2.size()) {
					// printf("halo1\n");
					ii pas = *s2.begin();
					s1.erase(pas);
					s2.erase(pas);
					s1.insert(ii(pas.first+1, pas.second));
					satu.insert(ii(pas.first+1, pas.second));
				}else if(satu.size()){
					// printf("erased pertama: %d %d\n",pertama.first, pertama.second);
					if(satu.size()){
						ii pas = *satu.begin();
						// printf("pas: %d %d\n",pas.first, pas.second);
						satu.erase(pas);
						// printf("halo\n");
						s1.erase(pas);
						// printf("halo1\n");	
					}
					
				}
				
				
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
};