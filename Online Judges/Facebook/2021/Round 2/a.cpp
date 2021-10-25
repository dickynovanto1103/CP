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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e6 + 6;

int personWears[maxn];
map<int, vi> styleToPersons;
int sudahGanti[maxn];

int a[maxn];

void printVec(vi v) {
	for(int el: v) {
		printf("%d ", el);
	}
	printf("\n");
}

void removePersonFromOldStyle(int person) {
	int personStyle = personWears[person];
	vi listOfPeopleUsingStyle = styleToPersons[personStyle];
	vi newPersons;
	for(int el: listOfPeopleUsingStyle) {
		if(el == person) {continue;}
		newPersons.pb(el);
	}

	styleToPersons[personStyle] = newPersons;
}

int main(){
	int tc,i,j,n,m;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d %d",&n,&m);
		// listNotUsed.clear();
		styleToPersons.clear();
		cerr<<"Case "<<tt<<endl;
		int cntBelumGanti = m;
		for(i=0;i<m;i++){
			int style;
			scanf("%d",&style);
			personWears[i] = style;
			styleToPersons[style].pb(i);
			sudahGanti[i] = false;
		}
		int cnt = 0;

		for(i=0;i<n;i++){
			bool booked[m+10];
			memset(booked, false, sizeof booked);
			map<int, vi> tempMap = styleToPersons;
			bool done[m+10];
			memset(done, false, sizeof done);
			for(j=0;j<m;j++){
				scanf("%d",&a[j]);
				int style = a[j];
				if(styleToPersons[style].size() > 0) {
					int person = styleToPersons[style].back(); styleToPersons[style].pop_back();
					booked[person] = true;
					done[j] = true;
				}else {
					//ignore for now, will be processed later
				}
			}
			// styleToPersons = tempMap;
			set<int> listOrangBisaDiambil;
			int potentialPerson = -1;
			for(j=0;j<m;j++){
				if(booked[j]) {continue;}
				if(!sudahGanti[j]) {
					potentialPerson = j;
				}
				listOrangBisaDiambil.insert(j);
			}
			debug printf("i: %d\n", i);

			debug printf("list orang bs diambil\n");
			// debug printVec(listOrangBisaDiambil);

			
			//process sisanya
			for(j=0;j<m;j++){
				int style = a[j];
				if(!done[j]) {
					if(cntBelumGanti == 0) {
						//ambil random person
						debug printf("picking random person\n");
						assert(listOrangBisaDiambil.size() > 0);
						int person = *listOrangBisaDiambil.begin(); 
						listOrangBisaDiambil.erase(person);

						debug printf("person picked: %d\n", person);
						removePersonFromOldStyle(person);

						styleToPersons[style].pb(person);
						personWears[person] = style;
						cnt++;
					}else{
						assert(cntBelumGanti > 0);

						assert(listOrangBisaDiambil.size() > 0);
						assert(potentialPerson != -1);

						int person = potentialPerson;
						listOrangBisaDiambil.erase(person);
						int personStyle = personWears[person];
						// printf("person: %d personStyle: %d\n", person, personStyle);
						//remove the person from personStyle first
						removePersonFromOldStyle(person);
						styleToPersons[style].pb(person);
						// printf("pushed to map style: %d person: %d\n", style, person);
						personWears[person] = style;
						cntBelumGanti--;
						sudahGanti[person] = true;
					}
				}
			}

			styleToPersons = tempMap;
		}

		printf("Case #%d: %d\n", tt, cnt);
	}
	
	return 0;
};