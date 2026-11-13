#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

namespace
{
    static void sortKahn(const std::vector<std::vector<int>>& adj, std::vector<int>& order)
    {
        int n = static_cast<int>(adj.size());
        
        std::vector<int> inDegree(n, 0);

        for (const auto& row : adj) {
            for (int j = 0; j < n; ++j)
                if (row[j])
                    ++inDegree[j];
        }

        std::queue<int> ready;

        for (int i = 0; i < n; ++i)
            if (inDegree[i] == 0)
                ready.push(i);

        while (!ready.empty()) 
        {
            int u = ready.front();
            ready.pop();

            order.push_back(u);

            for (int j = 0; j < n; ++j)
            {
                if (adj[u][j] && --inDegree[j] == 0)
                    ready.push(static_cast<int>(j));
            }
        }

        if (order.size() != n)
            order.clear();
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

    std::vector<int> order;

    sortKahn(adj, order);

    if (order.empty()) {
        std::cout << "Cyclic graph";
    }
    else 
    {
        std::cout << "Topological ordering of vertices: ";
        for (auto vertix : order)
        {
            std::cout << vertix + 1 << " ";
        }
    }
}