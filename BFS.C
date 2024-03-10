#include<stdio.h>
#include<conio.h>

int a[20][20] , visited[20] , q[20] , n; // q is queue and visited is a visited array
int front = 0;
int rear = -1;

int bfs(int v){
    visited[v] = 1; // Mark the first vertex to be visited
    q[rear++] = v;

    while(front <= rear){
        v = q[front++];
        printf("%d ",v); //Show visited vertex

        for(int i = 1; i <= n; i++){
            if(a[v][i] && !visited[i]){ // checking for any adjacent unvisited vertex
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main(){
    int v;
    printf("Enter the starting vertex\n");
    scanf("%d",&v);

    printf("Enter the number of vertices\n");
    scanf("%d",&n);   

    for(int i = 1; i <= n ; i++){
        visited[i] = 0;
        q[i] = 0;
    } 

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d",a[i][j]);
        }
    }

    bfs(v);

    printf("The visited vertices are\n");
    for(int i = 1; i <= n; i++){
        if(visited[i]){
            printf("%d ",i);
        }else{
            break;
        }
    }
    return 0;
}