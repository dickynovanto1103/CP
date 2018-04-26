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

// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.
const int MAXS = 100001;
 
// Maximum number of characters in input alphabet
const int MAXC = 26;
 
// OUTPUT FUNCTION IS IMPLEMENTED USING out[]
// Bit i in this mask is one if the word with index i
// appears when the machine enters this state.
int out[MAXS+2];
 
// FAILURE FUNCTION IS IMPLEMENTED USING f[]
int f[MAXS+2];
 
// GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][]
int g[MAXS][MAXC+2];
 
// Builds the string matching machine.
// arr -   array of words. The index of each keyword is important:
//         "out[state] & (1 << i)" is > 0 if we just found word[i]
//         in the text.
// Returns the number of states that the built machine has.
// States are numbered 0 up to the return value - 1, inclusive.
int buildMatchingMachine(string arr[], int k)
{
    // Initialize all values in output function as 0.
    memset(out, 0, sizeof out);
 
    // Initialize all values in goto function as -1.
    memset(g, -1, sizeof g);
 
    // Initially, we just have the 0 state
    int states = 1;
 
    // Construct values for goto function, i.e., fill g[][]
    // This is same as building a Trie for arr[]
    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int currentState = 0;
 
        // Insert all characters of current word in arr[]
        for (int j = 0; j < word.size(); ++j)
        {
            // printf("i: %d j: %d\n",i,j);
            int ch = word[j] - 'a';
 
            // Allocate a new node (create a new state) if a
            // node for ch doesn't exist.
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
 
            currentState = g[currentState][ch];
        }
 
        // Add current word in output function
        out[currentState] |= (1 << i);
    }
    // printf("test\n");
    // For all characters which don't have an edge from
    // root (or state 0) in Trie, add a goto edge to state
    // 0 itself
    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;
 
    // Now, let's build the failure function
 
    // Initialize values in fail function
    memset(f, -1, sizeof f);
 
    // Failure function is computed in breadth first order
    // using a queue
    queue<int> q;
 
     // Iterate over every possible input
    for (int ch = 0; ch < MAXC; ++ch)
    {
        // All nodes of depth 1 have failure function value
        // as 0. For example, in above diagram we move to 0
        // from states 1 and 3.
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }
 
    // Now queue has states 1 and 3
    while (q.size())
    {
        // printf("hai\n");
        // Remove the front state from queue
        int state = q.front();
        q.pop();
 
        // For the removed state, find failure function for
        // all those characters for which goto function is
        // not defined.
        for (int ch = 0; ch <= MAXC; ch++)
        {
            
            
            // If goto function is defined for character 'ch'
            // and 'state'
            if (g[state][ch] != -1)
            {
                // Find failure state of removed state
                int failure = f[state];
 
                // Find the deepest node labeled by proper
                // suffix of string from root to current
                // state.
                while (g[failure][ch] == -1)
                      failure = f[failure];
 
                failure = g[failure][ch];
                f[g[state][ch]] = failure;
 
                // Merge output values
                out[g[state][ch]] |= out[failure];
 
                // Insert the next level node (of Trie) in Queue
                q.push(g[state][ch]);
            }
        }
    }
 
    return states;
}
 
// Returns the next state the machine will transition to using goto
// and failure functions.
// currentState - The current state of the machine. Must be between
//                0 and the number of states - 1, inclusive.
// nextInput - The next character that enters into the machine.
int findNextState(int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a';
 
    // If goto is not defined, use failure function
    while (g[answer][ch] == -1)
        answer = f[answer];
 
    return g[answer][ch];
}
 
vector<vii> AdjList;
map<string,int> mapper;
map<string,int>::iterator it;
// This function finds all occurrences of all array words
// in text.
void searchWords(string arr[], int k, string text)
{
    // Preprocess patterns.
    // Build machine with goto, failure and output functions

    buildMatchingMachine(arr, k);
    // printf("halo\n");
    // Initialize current state
    int currentState = 0;
 
    // Traverse the text through the nuilt machine to find
    // all occurrences of words in arr[]
    for (int i = 0; i < text.size(); ++i)
    {
        currentState = findNextState(currentState, text[i]);
 
        // If match not found, move to next state
        if (out[currentState] == 0)
             continue;
 
        // Match found, print all matching words of arr[]
        // using output function.
        for (int j = 0; j < k; ++j)
        {
            if (out[currentState] & (1 << j))
            {
                int idx = mapper[arr[j]];
                AdjList[idx].pb(ii(i - arr[j].size() + 1, i));
                // cout << "Word " << arr[j] << " appears from "
                //      << i - arr[j].size() + 1 << " to " << i << endl;
            }
        }
    }
}



int main(){
    string text;


    string arr[MAXS];

    int k[MAXS];
    AdjList.assign(100001, vii());

    int q;

    cin>>text;

    scanf("%d",&q);
    int cnt = 0;
    for(int i=0;i<q;i++){
        cin>>k[i]>>arr[i];
        // printf("k[%d]: %d\n",i,k[i]);
        if(mapper.find(arr[i]) == mapper.end()) {
            // cout<<arr[i]<<" -> "<<cnt<<endl;
            mapper[arr[i]] = cnt++;
        }
    }

    searchWords(arr, q, text);
    // printf("text: "); cout<<text<<endl;
    // for(int i=0;i<cnt;i++) {
    //  printf("node: %d:",i);
    //  for(int j=0;j<AdjList[i].size();j++){
    //      ii v = AdjList[i][j];
    //      if(j){printf(" ");}
    //      printf("(%d,%d),",v.first, v.second);
    //  }
    //  printf("\n");
    // }
    for(int i=0;i<q;i++){
        int idx = mapper[arr[i]];
        int ukuran = AdjList[idx].size();
        if(ukuran < k[i]) {
            printf("-1\n");
        }else{
            int jarakMin = 0;
            int titikAwal = 0;
            for(int j=0;j<k[i];j++) {
                ii front = AdjList[idx][j];
                if(j==0){jarakMin += (front.second - front.first + 1); titikAwal = front.first;}
                else{jarakMin = front.second - titikAwal + 1;}
            }
            // printf("jarakMin: %d\n",jarakMin);
            int idxAwal = 0, idxAkhir = k[i]-1;
            while(idxAkhir<(ukuran-1)) {
                idxAkhir++;
                ii front = AdjList[idx][idxAkhir];
                int akhir = front.second;
                // jarakMin = front.second - titikAwal + 1;

                idxAwal++;
                front = AdjList[idx][idxAwal];
                int awal = front.first;

                // printf("awal: %d akhir: %d\n",awal, akhir);
                jarakMin = min(jarakMin, akhir - awal + 1);
            }
            printf("%d\n",jarakMin);
        }
    }

    return 0;
};