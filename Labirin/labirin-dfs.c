#include <stdio.h>
#include <stdlib.h>

int **maze;
int **visited;
int rows = 5; 
int cols = 6; 
int path_count = 0;

void printPath(int **path, int path_len) {
    printf("Jalur %d: ", ++path_count);
    for (int i = 0; i < path_len; i++) {
        printf("(%d, %d)", path[i][0], path[i][1]);
        if (i != path_len - 1)
            printf(" -> ");
    }
    printf("\n");
}

void dfs(int x, int y, int **path, int path_len) {
    if (x < 0 || y < 0 || x >= rows || y >= cols) return;
    if (visited[x][y] || maze[x][y] == 0) return;

    path[path_len] = malloc(2 * sizeof(int));
    path[path_len][0] = x;
    path[path_len][1] = y;
    path_len++;

    visited[x][y] = 1;

    if (x == 4 && y == 5) {
        printPath(path, path_len);
    } else {
        dfs(x + 1, y, path, path_len);
        dfs(x - 1, y, path, path_len);
        dfs(x, y + 1, path, path_len);
        dfs(x, y - 1, path, path_len);
    }

    visited[x][y] = 0;
    free(path[path_len - 1]);
}

int main() {
    int maze_input[5][6] = {
        {1, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1},
    };

    maze = malloc(rows * sizeof(int *));
    visited = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        maze[i] = malloc(cols * sizeof(int));
        visited[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            maze[i][j] = maze_input[i][j];
            visited[i][j] = 0;
        }
    }

    printf("Labirin:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int **path = malloc(rows * cols * sizeof(int *));

    printf("Semua kemungkinan jalur dari awal ke akhir:\n");
    dfs(0, 0, path, 0);


    for (int i = 0; i < rows; i++) {
        free(maze[i]);
        free(visited[i]);
    }
    free(maze);
    free(visited);
    free(path);

    return 0;
}