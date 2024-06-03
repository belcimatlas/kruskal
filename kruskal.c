/*
#include <stdio.h>
typedef struct {
	int u,v,w;
}EDGE;

typedef struct {
	EDGE edge_data[100];
	int n;
}EDGE_LIST;

void kruskal() {
	int belongs[100], i, j, n=5;
	elist.n=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(graph[i][j]!=0){
				elist.data[elist.n].u=i;
				elist.data[elist.n].v=j;
				elist.data[elist.n].w=graph[i][j];
				elist.n++;
			}
		}
	}
	sort();
	for(i=0;i<n;i++){
		belongs[i]=i;
	}
	spanlist.n=0;
	for(i=0;i<n;i++){
		cno1=find(belongs, elist.data[i].u);
		cno2=find(belongs, elist.data[i].v);
		if(cno1==cno2){
			spanlist.data[spanlist.n]=elist.data[i];
			spanlist.n=spanlist.n+1;
			apply(belongs, cno1, cno2);
		}
	}
}
int find(int belongs[], int vertexno){
	return belongs[vertexno];
}
void apply(int belongs[], int cno1, int cno2){
	int i;
	for(i=0;i<n;i++){
		if(belongs[i]==cno2){
			belongs[i]=cno1;
		}
	}
}
*/
#include <stdio.h>

#define MAX_VERTICES 100

typedef struct {
    int u, v, w;
} EDGE;

typedef struct {
    EDGE data[MAX_VERTICES];
    int n;
} EDGE_LIST;

EDGE_LIST elist, spanlist;

int graph[MAX_VERTICES][MAX_VERTICES];

void kruskal(int n);
int find(int belongs[], int vertexno, int n);
void apply(int belongs[], int cno1, int cno2, int n);
void sort(int n);
void printSpanningTree();

void kruskal(int n) {
    int belongs[MAX_VERTICES], i, j;
    elist.n = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = graph[i][j];
                elist.n++;
            }
        }
    }

    sort(elist.n);

    for (i = 0; i < n; i++) {
        belongs[i] = i;
    }

    spanlist.n = 0;

    for (i = 0; i < elist.n; i++) {
        int cno1 = find(belongs, elist.data[i].u, n);
        int cno2 = find(belongs, elist.data[i].v, n);

        if (cno1 != cno2) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n++;
            apply(belongs, cno1, cno2, n);
        }
    }
}

int find(int belongs[], int vertexno, int n) {
    return belongs[vertexno];
}

void apply(int belongs[], int cno1, int cno2, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (belongs[i] == cno2) {
            belongs[i] = cno1;
            
        }
    }
    for(j=0;j<n;j++){
        printf("*%d*\t",belongs[j]);
	}
    printf("\n");
}

void sort(int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (elist.data[j].w > elist.data[j + 1].w) {
                EDGE temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
        }
    }
}

void printSpanningTree() {
    int i, total_weight = 0;
    printf("Edges in the Spanning Tree:\n");
    for (i = 0; i < spanlist.n; i++) {
        printf("(%d, %d) - Weight: %d\n", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        total_weight += spanlist.data[i].w;
    }
    printf("Total Weight of the Spanning Tree: %d\n", total_weight);
}

int main() {
    int n = 5; //ornek graf 5 dugumlu 
    //ornek graf
    graph[0][1] = 1;
    graph[0][2] = 5;
    graph[0][3] = 0;     //kenar yok anlamina gelir
    graph[0][4] = 3;
    graph[1][2] = 0;
    graph[1][3] = 0;
    graph[1][4] = 0;
    graph[2][3] = 2;
    graph[2][4] = 0;        
    graph[3][4] = 4;

    kruskal(n);
    printSpanningTree();

    return 0;
}

