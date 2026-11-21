
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

// Function to construct the graph
void createGraph()
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Function for Depth First Search
void DFS(int v)
{
    int i;

    printf("%d ", v);

    visited[v] = 1;

    for(i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// Function for Breadth First Search
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = -1;
    int v, i;

    for(i = 0; i < n; i++)
        visited[i] = 0;

    queue[++rear] = start;
    visited[start] = 1;

    while(front <= rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

// Main function
int main()
{
    int start, i;

    createGraph();

    printf("\nEnter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    // Perform DFS
    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDepth First Search: ");
    DFS(start);

    // Perform BFS
    printf("\nBreadth First Search: ");
    BFS(start);

    return 0;
}
