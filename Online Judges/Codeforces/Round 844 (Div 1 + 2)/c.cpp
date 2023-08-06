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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,char> ic;
typedef vector<ii> vii;
typedef vector<ic> vic;

vector<vi> adj, tempAdj;

bool cmp(ii a, ii b) {
	return a.first > b.first;
}

string tempAns;

int main(){
	int tc;
	scanf("%d",&tc);
	int idxTc = 1;
	while(tc--){
		int n;
		scanf("%d",&n);
		string s;
		cin>>s;
		int freq[26];
		memset(freq, 0, sizeof(freq));

		adj.assign(26, vi());
		for(int i=0;i<n;i++) {
			char c = s[i];
			adj[c-'a'].pb(i);
		}

		for(char c: s){
			freq[c-'a']++;
		}

		vii sorted;
		for(int i=0;i<26;i++){
			sorted.pb(ii(freq[i], i));
		}

		sort(sorted.begin(), sorted.end(), cmp);
		// printf("CASE %d\n", idxTc++);
		// for(int i=0;i<26;i++){
		// 	if(sorted[i].first == 0){break;}
		// 	printf("%d %c\n", sorted[i].first, sorted[i].second + 'a');
		// }

		int minChange = inf;
		string ans;

		for(int i=1;i<=26;i++){
			int karBeda = i;
			if(n % karBeda != 0) {
				continue;
			}

			int tempFreq[26];
			for(int j=0;j<26;j++){
				tempFreq[j] = freq[j];
			}

			int freqKar = n / karBeda;

			// printf("i: %d freqKar: %d\n", i, freqKar);

			bool isTujuan[26];
			memset(isTujuan, false, sizeof isTujuan);
			for(int j=0;j<karBeda;j++){
				// printf("halo j: %d sorted: %c\n", j, sorted[j].second + 'a');
				isTujuan[sorted[j].second] = true;
				// printf("tujuan = karakter: %c\n", sorted[j].second + 'a');
			}

			vii perluTambah, penambahKhusus, penambah;
			for(int j=0;j<26;j++){
				if(isTujuan[j]) {
					if(tempFreq[j] < freqKar) {
						perluTambah.pb(ii(tempFreq[j], j));
						// printf("ditambah di perlu tambah: %d %c\n", tempFreq[j], j + 'a');
					}else if(tempFreq[j] > freqKar){
						penambahKhusus.pb(ii(tempFreq[j], j));
						// printf("ditambah di penambah khusus: %d %c\n", tempFreq[j], j + 'a');
					}
				}else{
					if(tempFreq[j] == 0) continue;
					penambah.pb(ii(tempFreq[j], j));
					// printf("ditambah di penambah: %d %c\n", tempFreq[j], j + 'a');
				}
				
			}

			tempAdj = adj;

			int change = 0;
			string tempAns = s;

			int idxDitambah = 0;
			int idxPenambah = 0;
			while(idxDitambah < perluTambah.size() && idxPenambah < penambahKhusus.size()) {
				penambahKhusus[idxPenambah].first--;
				perluTambah[idxDitambah].first++;
				
				int idxGanti = tempAdj[penambahKhusus[idxPenambah].second].back();
				tempAdj[penambahKhusus[idxPenambah].second].pop_back();
				tempAns[idxGanti] = perluTambah[idxDitambah].second + 'a';

				// cout<<"[PENAMBAH KHUSUS] diganti di idx: "<<idxGanti<<" sekarang tempans jd: "<<tempAns<<endl;
				change++;

				if(penambahKhusus[idxPenambah].first == freqKar) {
					idxPenambah++;
				}

				if(perluTambah[idxDitambah].first == freqKar){
					idxDitambah++;
				}
			}

			idxPenambah = 0;
			while(idxDitambah < perluTambah.size() && idxPenambah < penambah.size()) {
				penambah[idxPenambah].first--;
				perluTambah[idxDitambah].first++;
				

				int idxGanti = tempAdj[penambah[idxPenambah].second].back();
				tempAdj[penambah[idxPenambah].second].pop_back();
				tempAns[idxGanti] = perluTambah[idxDitambah].second + 'a';

				// printf("karakter: %c mau diganti dengan %c di idx: %d\n", );

				// cout<<"[PENAMBAH] diganti di idx: "<<idxGanti<<" sekarang tempans jd: "<<tempAns<<endl;
				change++;

				if(penambah[idxPenambah].first == 0) {
					idxPenambah++;
				}

				if(perluTambah[idxDitambah].first == freqKar){
					idxDitambah++;
				}
			}

			if(minChange > change){
				minChange = change;
				ans = tempAns;
			}
		}


		cout<<minChange<<endl<<ans<<endl;
	}
	
	return 0;
};