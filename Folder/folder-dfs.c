#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 10

bool dfs(int graph[N][N], int vertex, bool visited[], char file[N][50], const char* goal) {
    visited[vertex] = true;
    printf("%s\n", file[vertex]);
    
    if (strcmp(file[vertex], goal) == 0) {
        printf("Goal state '%s' ditemukan!\n", goal);
        return true;  
    }
    
    for (int i = 0; i < N; i++) {
        if (graph[vertex][i] && !visited[i]) {
            if (dfs(graph, i, visited, file, goal)) {
                return true;  
            }
        }
    }
    
    return false;  
}

int main() {
    int graph[N][N] = {
        { 0, 1, 0, 0, 0, 0, 1, 1, 0, 0}, 
        { 1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, 
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
        { 0, 1, 0, 0, 1, 1, 0, 0, 0, 0}, 
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}  
    };
    char file[N][50] = {"Documents", "Anime", "Fight", "Comedy", "Aho Girl", "Saiki Kusuo", 
                        "Game", "Kuliah", "Kecerdasan Buatan", "Basis Data"};
    bool visited[N] = {false};
    const char* goal = "Basis Data";
    
    printf("Mencari goal state '%s' menggunakan Algoritma DFS:\n", goal);
    if (!dfs(graph, 0, visited, file, goal)) {
        printf("Goal state '%s' tidak ditemukan dalam graph.\n", goal);
    }
    
    return 0;
}