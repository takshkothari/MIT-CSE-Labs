#include<stdio.h>
#define MAX 50

typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;

edge_list elist, spanlist;
int graph[MAX][MAX], n;

int find(int belongs[], int vno) {
    return (belongs[vno]);
}

void applyUnion(int belongs[], int c1, int c2) {
    int i;
    for (i = 0; i < n; i++) {
        if(belongs[i] == c2)
            belongs[i] = c1;
    }
}

void sort() {
    int i, j;
    edge t;
    for (i = 1; i < elist.n; i++) {
        for (j = 0; j < elist.n - 1; j++) {
            if(elist.data[j].w > elist.data[j+1].w) {
                t = elist.data[j];
                elist.data[j] = elist.data[j + 1];  
                elist.data[j + 1] = t;
            }
        }
    }
}

void print() {
    int i, cost = 0;
    for (i = 0; i < spanlist.n; i++) {
        printf("\n%d -> %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }
    printf("\nspanning tree cost is %d\n", cost);
}

void kruskal() {
    int belongs[MAX], i, j, c1, c2;
    elist.n = 0;
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = graph[i][j];
                elist.n++;
            }
        }
    }
    sort();
    for (i = 0; i < n; i++)
        belongs[i] = i;
    spanlist.n = 0;
    for (i = 0; i < elist.n; i++) {  
        c1 = find(belongs, elist.data[i].u);
        c2 = find(belongs, elist.data[i].v);
        if (c1 != c2) {  
            spanlist.data[spanlist.n] = elist.data[i];  
            spanlist.n = spanlist.n + 1;  
            applyUnion(belongs, c1, c2);         
        }
    }
}

void main() {
    int i, j;
    printf("enter number of vertices: ");
    scanf("%d", &n);
    printf("enter adjacency matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    kruskal();
    print();
}