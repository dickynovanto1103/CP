#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1.0)
#define uint64 unsigned long long
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;

struct Photo {
  char orientation;
  unordered_set<string> tags;
  vector<int> ntags;
  int cnt_tags;
  int idx;
  
  Photo() : orientation('-'), cnt_tags(0) {}
  Photo(char orientation, unordered_set<string> tags, int cnt_tags, int idx) {
    this->orientation = orientation;
    this->tags = tags;
    this->cnt_tags = cnt_tags;
    this->idx = idx;
  }

  int get_diff(Photo& other) {
    int ans = 0;
    for(int x : other.ntags){
      if(binary_search(ntags.begin(), ntags.end(), x)){
        ans++;
      }
    }
    return min(ans, (int) min(ntags.size()-ans, other.ntags.size()-ans));
  }

  void union_vertical(Photo& other) {
    for(auto tag: other.tags) {
      this->tags.insert(tag);
    }

    this->orientation = 'H';
    this->cnt_tags = this->tags.size();
  }
};

vector<Photo> listPhoto;
vector<Photo> verListPhoto;
vector<bool> verTaken;
vector<bool> horTaken;
int resultGraph = 0;
int numberGraphTaken = 0;

void get_max_graph(int position) {
  if (numberGraphTaken == listPhoto.size()) {
    return;
  } else {
    int maks_index = -1;
    int maks_diff = 0;
    
    for(int i = 0; i < listPhoto.size(); i++) {
      if (i != position) {
        if (!(horTaken[i])) {
          int diff = listPhoto[position].get_diff(listPhoto[i]);
          if (maks_diff < diff) {
            maks_index = i;
          }
        }
      } 
    }
  }
}

bool cmpB(Photo& a, Photo& b){
  return (a.cnt_tags > b.cnt_tags);
}

void solE() {
  int i,j,k;

  sort(verListPhoto.begin(), verListPhoto.end(), cmpB);
  int ukuran = verListPhoto.size();
  printf("%d\n",ukuran/2);
  // printf("ukuran: %d\n",ukuran);
  for(i=0;i<ukuran;i+=2){
    // printf("i: %d i+1: %d\n",i,i+1);
    printf("%d %d\n",verListPhoto[i].idx, verListPhoto[i+1].idx);
  }
}



void solB() {

  int i,j,k;
  sort(listPhoto.begin(), listPhoto.end(), cmpB);
  // random_shuffle(listPhoto.begin(), listPhoto.end());
  int ukuran = listPhoto.size();
  printf("%d\n",ukuran);
  for(i=0;i<ukuran;i++){
    printf("%d\n",listPhoto[i].idx);
  }
}

void solC() {
  int i,j,k;
  // sort(listPhoto.begin(), listPhoto.end(), cmpB);
  // sort(verListPhoto.begin(), verListPhoto.end(), cmpB);
  // random_shuffle(listPhoto.begin(), listPhoto.end());
  // random_shuffle(verListPhoto.begin(), verListPhoto.end());
  int ukuran1 = listPhoto.size();
  int ukuran2 = (int)verListPhoto.size() / 2;
  int ukuran = ukuran1 + ukuran2;
  printf("%d\n",ukuran);
  int idx = 0;
  
  for(i=0;i<ukuran2*2;i+=2){
    // total.pb(verListPhoto[i]);
    // total.pb(verListPhoto[i+1]);
    // total.pb(listPhoto[idx++]);
    printf("%d %d\n",verListPhoto[i].idx, verListPhoto[i+1].idx);
    // printf("%d\n",listPhoto[idx++].idx);
  }


  for(i=idx;i<ukuran1;i++){
    // total.pb(listPhoto[i]);
    printf("%d\n",listPhoto[i].idx);
  }
  
}


int main(){
  srand(time(NULL));
  int n;
  cin>>n;
  /* baca input */
  for(int i=0;i<n;++i){
    cin.get();
    Photo temp;
    cin>>temp.orientation>>temp.cnt_tags;
    for(int j=0;j<temp.cnt_tags;++j){
      string str_tmp;
      cin>>str_tmp;
      temp.tags.insert(str_tmp);
    }
    temp.idx = i;
    if(temp.orientation == 'V'){
      verListPhoto.pb(temp);
    }
    else{
      listPhoto.pb(temp);
    }
  }
  solC();
  return 0;
  /* construct graph di vertical list photo*/
  int ukuran = verListPhoto.size();
  random_shuffle(verListPhoto.begin(), verListPhoto.end());
  verTaken.assign(ukuran, 0);
  for(int i=0;i<ukuran - 1;++i) {
    if(verTaken[i]) continue;
    int idx = -1;
    int mi = -1;
    for(int j=i+2;j<ukuran;++j){
      if(verTaken[j]) continue;
      if(idx == -1){
        idx = j;
        mi = verListPhoto[i].get_diff(verListPhoto[j]);
      }
      else{
        int tmp = verListPhoto[i].get_diff(verListPhoto[j]); 
        if(tmp < mi){
          idx = j;
          mi = tmp;
        }
      }
    }
    verTaken[i] = true;
    verTaken[idx] = true;
    verListPhoto[i].union_vertical(verListPhoto[idx]);
    listPhoto.pb(verListPhoto[i]);
  }

  /*graph solution*/
  int ukuranHorizontal = listPhoto.size();
  horTaken.assign(ukuranHorizontal, 0);
  
	return 0;
};