// { Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 10005

struct ListNode {
    int data;
    struct ListNode *next;
};

struct graph {
    struct ListNode *head[N];
};

struct edges {
    int src, dest;
};

void show_graph(struct graph *g, int n, int m) {
    for (int i = 0; i < n; i++) {
        struct ListNode *graph_ptr = g->head[i];
        if (graph_ptr != NULL) {
            printf("%d-->", i);
        }
        while (graph_ptr != NULL) {
            printf("%d ", graph_ptr->data);
            graph_ptr = graph_ptr->next;
        }
        printf("\n");
    }
}

struct graph *create_graph(struct edges arr_edges[], int n, int m) {
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));

    for (int i = 0; i < n; i++) {
        g->head[i] = NULL;
    }

    for (int i = m - 1; i >= 0; i--) {
        int u = arr_edges[i].src, v = arr_edges[i].dest;

        // edge from u->v
        struct ListNode *newNode =
            (struct ListNode *)malloc(sizeof(struct ListNode));

        newNode->data = v;
        newNode->next = g->head[u];
        g->head[u] = newNode;

        // edge from v->u
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

        newNode->data = u;
        newNode->next = g->head[v];
        g->head[v] = newNode;
    }

    return g;
}


 // } Driver Code Ends
// User function Template for C

/*
struct ListNode {
    int data;
    struct ListNode *next;
};

struct graph {
    struct ListNode *head[N];
};
*/


bool dfs(struct graph *g, int sv,int prev, int n, bool * visited){
    
    if(visited[sv]==true){
        return false;

    }
    visited[sv]=true;
    
    if(g->head[sv]==NULL){
        return false;
    }
    
    
    struct ListNode * temp = g->head[sv];
    
    while(temp !=NULL){
        
        
        if(visited[temp->data]==true){
            if(temp->data!=prev)
            return true;
            }
        
        if(dfs(g,temp->data,sv,n,visited)==true){
            return true;
        }
        temp = temp->next;
    }
    
    return false;
}

bool isCycle(struct graph *g, int n, int m) {
    // your code goes here
    bool visited[n];
    
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    
    
    for(int i=0;i<n;i++){
        
         if(visited[i]==true){
             continue;
         }
        
         if(g->head[i]==NULL){
             visited[i]=true;
             continue;
         }
        
          if(dfs(g,i,-1,n,visited)==true){
              return true;
          }
        
     }
    
    return false;
}

// { Driver Code Starts.

int main() {
    int t = 1;

    while (t--) {
        int queries;
        scanf("%d", &queries);
        while (queries--) {
            int n, m;
            scanf("%d %d", &n, &m);
            struct edges arr_edges[m];
            for (int i = 0; i < m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                arr_edges[i].src = u;
                arr_edges[i].dest = v;
            }

            struct graph *g = create_graph(arr_edges, n, m);

            bool ans = isCycle(g, n, m);
            if (ans) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}
  // } Driver Code Ends
