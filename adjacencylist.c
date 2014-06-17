#include<stdio.h>
#include<stdlib.h>
#define MAXV 1000

struct edgenode{
    int label;
    int weight;
    struct edgenode *next;
};

struct graph{
    struct edgenode *edges[MAXV+1];
    int nvertices; 
    int nedges; 
    int degree[MAXV+1];
};

int main(){
    struct graph *g;
    g = NULL;
    printf("Initializing graph...\n");
    if(g == NULL){
        g = malloc(sizeof(struct graph));
        g->nvertices = 0;
        g->nedges = 0;
        int i;
        for(i=1 ; i<=MAXV ; i++)
            g->degree[i] = 0;
        for(i=1 ; i<=MAXV ; i++)
            g->edges[i] = NULL;
    }
    printf("Enter vertices# and edges#: ");
    scanf("%d %d", &(g->nvertices), &(g->nedges));
    int nedges = g->nedges;
    int i, x, y;
    for(i=1 ; i<=nedges ; i++){
        scanf("%d %d", &x, &y);
        struct edgenode *edgenode;
        edgenode = malloc(sizeof(struct edgenode));
        edgenode->label = y;
        edgenode->weight = NULL;
        edgenode->next = g->edges[x];
        g->edges[x] = edgenode;
        g->degree[x]++;
        g->nedges++;
    }
    int j;
    struct edgenode *p;
    for(j=1 ; j<=g->nvertices ; j++){
        printf("%d: ", j);
        p = g->edges[j];
        while(p != NULL){
            printf(" %d", p->label);
            p=p->next;
        }
        printf("\n");
    }
}
