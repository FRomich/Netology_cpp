#include <iostream>
#include <fstream>
#include <vector>

namespace
{
    static void printGrath(std::vector<std::vector<int>> adj)
    {
        std::cout << "Text view of the grath: \n";

        for (size_t i = 0; i < adj.size(); ++i) 
        {
            int count = 0;
            std::cout << i + 1 << ": ";

            for (size_t j = 0; j < adj.size(); ++j)
            {
                if (adj[i][j] == 1) 
                {
                    std::cout << j + 1 << " ";
                    count++;
                }
            }
            if (count == 0)
                std::cout << "no adjacent";
            std::cout << '\n';
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

    printGrath(adj);

}