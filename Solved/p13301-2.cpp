/*
*
* Problema UVA 13301 - Impossible Communication
*
*/

//Tarjan's Algorithm

#include <bits/stdc++.h>
#define NIL -1

using namespace std; 

int countSCCs;

typedef long long ll;
typedef unsigned long long ull;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

typedef vector < pii > vpii;
typedef vector < pll > vpll;

typedef vector <string> vs;
typedef vector < vi > vvi;
typedef vector < vll > vvll;

#define fl(i, a, b)	for (int i(a); i < (b); ++i)

#define all(v) 	(v).begin(), (v).end()
#define srt(v)	sort (all (v))

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define slen(s)	s.length()

#define fr first
#define sc second

#define sz(x) ((int) (x).size())
#define fill (x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1)					cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)				cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)			cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}

// A class that represents an directed graph 
class Graph{
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
  
    // A Recursive DFS based function used by SCC() 
    void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    void SCC();    // prints strongly connected components 
}; 
  
Graph::Graph(int V){
    this->V = V; 
    adj = new list<int>[V]; 
}
  
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); 
} 

void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]){
    // A static variable is used for simplicity, we can avoid use 
    // of static variable by passing a pointer. 
    static int time = 0;
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
    st->push(u); 
    stackMember[u] = true; 
  
    // Go through all vertices adjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;  // v is current adjacent of 'u' 
  
        // If v is not visited yet, then recur for it 
        if (disc[v] == -1){
            SCCUtil(v, disc, low, st, stackMember);
            low[u]  = min(low[u], low[v]); 
        }
        else if (stackMember[v] == true) 
            low[u]  = min(low[u], disc[v]); 
    }
  
    // head node found, pop the stack and print an SCC 
    int w = 0;  // To store stack extracted vertices 
    if (low[u] == disc[u]){ 
        while (st->top() != u){
            w = (int) st->top();
            stackMember[w] = false;
            st->pop();
        }
        countSCCs++;
        w = (int) st->top();
        stackMember[w] = false; 
        st->pop(); 
    } 
} 
  
// The function to do DFS traversal. It uses SCCUtil() 
void Graph::SCC(){
    int *disc = new int[V]; 
    int *low = new int[V]; 
    bool *stackMember = new bool[V]; 
    stack<int> *st = new stack<int>(); 
  
    // Initialize disc and low, and stackMember arrays 
    for (int i = 0; i < V; i++){
        disc[i] = NIL; 
        low[i] = NIL; 
        stackMember[i] = false; 
    }
  
    // Call the recursive helper function to find strongly 
    // connected components in DFS tree with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (disc[i] == NIL){
            if( countSCCs > 1 ) break;
            SCCUtil(i, disc, low, st, stackMember); 
        }
}

int main() {
	FAST_IO;
    int n, m, k, i, j, l, aux, nInicio, nFin;

	while( cin >> n >> m ){
		countSCCs = 0;
		Graph g(n);
		fl(i, 0, m){
			cin >> k;
			if( k > 1 ){
				fl(j, 0, k){
                    cin >> aux;
                    if( j == 0 ){
                        nInicio = aux;
                    }
                    else{
                        g.addEdge(nFin-1, aux-1);
                    }
                    nFin = aux;
				}
                g.addEdge(nFin-1, nInicio-1);
			}
			else{
				cin >> j >> l;
				g.addEdge(j-1, l-1);
			}
		}
		g.SCC();
		if( countSCCs == 1 ) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}