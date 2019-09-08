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
            SCCUtil(i, disc, low, st, stackMember); 
        }
}

int main(){
	int n, m, k, i, j, l, aux, nInicio, nFin;

	while( scanf("%d %d", &n, &m) == 2 ){
		countSCCs = 0;
		Graph g(n);
		for(i = 0; i < m; i++){
			scanf("%d", &k);
			if( k > 1 ){
				for(j = 0; j < k; j++){
					scanf("%d", &aux);
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
				scanf("%d %d", &j, &l);
				g.addEdge(j-1, l-1);
			}
		}
		g.SCC();
		if( countSCCs == 1 ) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}