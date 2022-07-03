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
typedef tuple<int,int,int> tiii;
typedef vector<ii> vii;

struct CustomComparator {
	bool operator()(const tiii &a, const tiii &b) const{
		if(get<2>(a) == get<2>(b)) {
			return get<1>(a) > get<1>(b);
		}
		return get<2>(a) > get<2>(b);
	}
};

class FreqStack {
public:
    FreqStack() {
        cnt.clear();
        s.clear();
        lastIndexesMap.clear();
        idx = 0;
    }
    
    void push(int val) {

        cnt[val]++;
        if(cnt[val] > 1) {
        	int sz = lastIndexesMap[val].size();
        	int lastIdx = lastIndexesMap[val][sz-1];
        	s.erase(make_tuple(val, lastIdx, cnt[val]-1));
        }

        s.insert(make_tuple(val, idx, cnt[val]));
        lastIndexesMap[val].pb(idx);
        idx++;
    }

    void printTuple(tiii a) {
    	printf("tuple: %d %d %d\n", get<0>(a), get<1>(a), get<2>(a));
    }
    
    int pop() {
        tiii tup = *s.begin();
        // printf("popped: "); printTuple(tup);
        s.erase(tup);
        int angka = get<0>(tup);
        cnt[angka]--;
        lastIndexesMap[angka].pop_back();
        if(lastIndexesMap[angka].size() > 0) {
        	assert(cnt[angka] > 0);
        	int newSz = lastIndexesMap[angka].size();
        	int newIdx = lastIndexesMap[angka][newSz-1];
        	s.insert(make_tuple(angka, newIdx, cnt[angka]));
        }
        
        return angka;
    }
private:
	set<tiii, CustomComparator> s;
	map<int,int> cnt;
	map<int, vi> lastIndexesMap;
	int idx;
};


int main(){
	FreqStack fs;
	string cmd;
	while(cin>>cmd) {
		for(int i=0;i<cmd.size();i++){
			cmd[i] = tolower(cmd[i]);
		}
		// cout<<"cmd: "<<cmd<<endl;
		if(cmd == "push") {
			int bil;
			cin>>bil;
			fs.push(bil);
		}else{
			printf("%d\n", fs.pop());
		}
	}

	
	return 0;
};