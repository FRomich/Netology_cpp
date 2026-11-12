#include <iostream>
#include <fstream>
#include <vector>

namespace
{
    static bool dfs(const std::vector<std::vector<int>>& adj, int v, std::vector<bool>& visited, int prev)
    {
        visited[v] = true;

        for (int i = 0; i < adj.size(); ++i)
        {
            if (adj[v][i] == 0)
                continue;

            if (!visited[i])
            {
                if (dfs(adj, i, visited, v))
                    return true;
            }
            else if (i != prev)
            {
                return true;
            }
        }
        return false;
    }

    static bool hasCycle(const std::vector<std::vector<int>>& adj)
    {
        std::vector<bool> visited(adj.size(), false);

        for (int v = 0; v < adj.size(); ++v)
        {
            if (!visited[v])
                if (dfs(adj, v, visited, -1))
                    return true;
        }
        return false;
    }
}


int main()
{
    std::string pathFile = "input2.txt";

    std::ifstream file(pathFile);

    if (!file.is_open())
    {
        std::cerr << "Error opening file " << pathFile << '\n';
        return 1;
    }

    int n;

    file >> n;

    std::vector<std::vector<int>> adj(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            file >> adj[i][j];
        }
    }

    std::cout << "The graph has " << n << " vertices. \n";

    if (hasCycle(adj))
        std::cout << "The graph contains a cycle!";
    else 
        std::cout << "The graph contains no cycles!";

    return 0;
}

