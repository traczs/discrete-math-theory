#include <stdio.h>
int n,k,m,b[100],edge[10000][2]; // n < 100 so max edges <= (99 choose 2)
long int totalDom=0;
long int totalInd=0;
long int totalClq=0;
long int totalVC=0;

//================================================================
// Return TRUE if the subset represented by b[1..n] corresponds to
// to a dominating set in the input graph.
//================================================================
int IsDominating() {
	int i,u,v,dom[100];
	// Initialze vertices dominated to be member of the k-subset
	for (i=1; i<=n; i++) {
		if (b[i] == 1) dom[i] = 1;
		else dom[i] = 0;
	}

	// Test each edge to see if endpoint is adjacent to an element of the subset
	for (i=1; i<=m; i++) {
		u = edge[i][0];
		v = edge[i][1];
		if (b[u]== 1) dom[v] = 1; // u is in the subset and dominates v
		if (b[v]== 1) dom[u] = 1; // v is in the subset and dominates u
	}

	// Check if any vertex not dominated
	for (i=1; i<=n; i++) if (dom[i] == 0) return 0;
	return 1;
}

//================================================================
// Return TRUE if the subset represented by b[1..n] corresponds to
// to an indepenednt set in the input graph.
//================================================================
int IsIndipendent() {
	int i,u,v;
	
	// Test each edge to see if the subset endpoints are adjacent
	for (i=1; i<=m; i++) {
		u = edge[i][0];
		v = edge[i][1];
		if(b[u]==1 && b[v]==1) return 0;
	}
	return 1;
}

//================================================================
// Return TRUE if the subset represented by b[1..n] corresponds to
// to a clique in the input graph.
//================================================================
int IsClique() {
	int i,u,v;
	
	// Test each edge to see if the subset endpoints are adjacent
	for (i=1; i<=m; i++) {
		u = edge[i][0];
		v = edge[i][1];
		if(b[u]==0 && b[v]==0) return 0;
	}
	printf("\n");
	return 1;
}

//================================================================
// Return TRUE if the subset represented by b[1..n] corresponds to
// to a clique in the input graph.
//================================================================
int IsVertexCover() {
	int i,u,v;
	
	// Test each edge to see if the subset endpoints are adjacent
	for (i=1; i<=m; i++) {
		u = edge[i][0];
		v = edge[i][1];
		if(b[u]==0 || b[v]==0) return 0;
	}
	return 1;
}

//============================================================
// Recursively generate all binary strings of length n with
// k 1s (equivalent to subset of size k)
//============================================================
void GenStrings(int t, int d) {

	if (t > n) {
		if (IsDominating()) {
			totalDom++;	
		}
		if (IsIndipendent()){
			totalInd++;	
		}
		if (IsClique()){
			totalClq++;	
		}
		if (IsVertexCover()){
			totalVC++;
		}
	}
	else {

		if (n-t+1 > k-d) { // Still room to add 0s
			b[t] = 0;
			GenStrings(t+1, d);
		}
		if (d < k) { // Still room to add 1s
			b[t] = 1;
			GenStrings(t+1, d+1);
		}
	}
}
//---------------------------------------------------
int main() {
	printf("enter # of vertices:");
	scanf("%d", &n);
	printf("enter # of edges:");
	scanf("%d", &m);
	printf("enter set size number:");
	scanf("%d",&k);
	for ( int i=1; i<=m; i++) 
	{
		printf("enter edge %d starting vertex (number)\n",i);
		scanf("%d", &edge[i][0]); // read edge i
		printf("enter edge %d ending vertex (number)\n",i);
		scanf("%d",&edge[i][1]); // read edge i
	}
	GenStrings(1,0);
	if(totalDom == 0)
	{ 
		printf(" (a) NO dominating set\n");
	}
	else
	{
		printf(" (a) YES, there's a dominating set\n");
	}
	if (totalInd == 0)
	{ 
		printf(" (b) NO indipendent set\n");
	}
	else
	{
		printf(" (b) YES,there's an indipendent set\n");
	}
	if (totalClq == 0)
	{ 
		printf(" (c) NO clique\n");
	}
	else
	{
		printf(" (c) YES, there's a clique\n");
	}
	if (totalVC == 0)
	{ 
		printf(" (d) NO vertex cover\n");
	}
	else
	{
		printf(" (d) YES, there's vertex cover\n");
	}
}
