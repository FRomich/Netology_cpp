#include <iostream>
#include <fstream>
#include <vector>
#include <map>

namespace
{
    static void dfs(
        int vertex,
        int component,
        const std::vector<std::vector<int>>& adj,
        std::vector<bool>& visited,
        std::map<int, int>& memberships)
    {
        visited[vertex] = true;
        memberships[vertex] = component;

        for (int next = 0; next < adj.size(); ++next)
        {
            if (adj[vertex][next] == 0 || visited[next])
                continue;

            dfs(next, component, adj, visited, memberships);
        }
    }

    static void connectedСomponents(
        const std::vector<std::vector<int>>& adj,
        std::map<int, int>& memberships)
    {
        memberships.clear();

        std::vector<bool> visited(adj.size(), false);
        int component = 1;

        for (int i = 0; i < adj.size(); ++i)
        {
            if (!visited[i])
            {
                dfs(i, component, adj, visited, memberships);
                ++component;
            }
        }
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

    std::map<int, int> memberships;

    connectedСomponents(adj, memberships);

    std::cout << "Assignment of vertices to connected components: \n";

    for (const auto& [vertex, component] : memberships)
    {
        std::cout << vertex << " - " << component << '\n';
    }

    std::cout << "Number of connected components in a graph: " << memberships.rbegin()->second <<  '\n';

    return 0;
}