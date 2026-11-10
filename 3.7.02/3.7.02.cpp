#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void bfs(int start, const std::vector<std::vector<int>>& adj, std::vector<int>& visited)
{
   
    std::queue<int> frontier;
    std::vector<bool> flags(adj.size(), false);


    flags[start] = true;
    frontier.push(start);


    while (!frontier.empty()) 
    {
        int node = frontier.front();
        frontier.pop();

        visited.push_back(node);

        for (int next = 0; next < adj[node].size(); ++next)
        {
            if (adj[node][next] && !flags[next])
            {
                flags[next] = true;
                frontier.push(next);
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

    std::vector<std::vector<int>> adj(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            file >> adj[i][j];
        }
    }

    std::cout << "The graph has " << n << " vertices. \n";
    std::cout << "Enter the number of the vertex from which the traversal should begin: ";

    int numVertics;
    std::cin >> numVertics;

    if (numVertics > n && n < 1)
    {
        std::cout << "invalid vertex number";
    }

    std::vector<int> visited;

    bfs(numVertics - 1, adj, visited);

    std::cout << "Order of vertex traversal: ";
    for (int i = 0; i < visited.size(); ++i) 
    {
        std::cout << visited[i] + 1 << " ";
    }
}

