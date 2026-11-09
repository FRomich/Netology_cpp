#include <iostream>
#include <fstream>

namespace 
{
    static void dfs(int node, int** graph, int* visited, int& count, int n)
    {
        visited[node] = ++count;

        for (int j = 0; j < n; ++j)
        {
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                dfs(j, graph, visited, count, n);
            }
        }
    }
}

int main()
{
    std::string pathFile = "input.txt";

    std::ifstream file(pathFile);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << pathFile << '\n';
        return 1;
    }

    int n;

    file >> n;

    int** graph = new int* [n];

    for (int i = 0; i < n; ++i)
    {
        graph[i] = new int[n];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            file >> graph[i][j];
        }
    }

    file.close();

    int* visited = new int[n] {};
    int count = 0;

    dfs(0, graph, visited, count, n);

    std::cout << "Order of vertex traversal:";
    for (int j = 0; j < n; ++j) 
    {
        std::cout << visited[j] << " ";
    }

    delete[] visited;

    for (int i = 0; i < n; ++i)
    {
        delete[] graph[i];
    }

    delete[] graph;

    return 0;
}
