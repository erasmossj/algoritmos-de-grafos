#include <bits/stdc++.h>

using namespace std;

#define int long long int

void help()
{
    cout << "Uso: ./programa -f <arquivo_entrada>"
         << " [-o <arquivo_saida>]"
         << " [-i <vertice_inicial>] [-s]" << endl;
    cout << "-h : mostra o help" << endl;
    cout << "-f <arquivo> : arquivo que contem o grafo de entrada" << endl;
    cout << "-o <arquivo> : redireciona a saida para o arquivo indicado" << endl;

    return;
}

void dfs_rec(int v, vector<vector<int>> &adj, stack<int> &posOrdem, vector<bool> &visited)
{
    visited[v] = true;

    for (auto u : adj[v])
    {
        if (!visited[u])
        {
            dfs_rec(u, adj, posOrdem, visited);
        }
    }
    posOrdem.push(v);
}

void dfs(vector<vector<int>> &adj, stack<int> &posOrdem)
{
    int n = adj.size();

    vector<bool> visited(n, false);

    for (int v = 0; v < n; v++)
    {
        if (!visited[v])
            dfs_rec(v, adj, posOrdem, visited);
    }
}

void dfs_recR(int v, vector<vector<int>> &adjR, vector<bool> &visited, ofstream &output)
{
    visited[v] = true;

    for (auto u : adjR[v])
    {
        if (!visited[u])
        {
            cout << u + 1 << ' ';
            output << u + 1 << ' ';

            dfs_recR(u, adjR, visited, output);
        }
    }
}

void dfsR(vector<vector<int>> &adjR, stack<int> &posOrdem, ofstream &output)
{
    int n = adjR.size();

    vector<bool> visited(n, false);

    while (!posOrdem.empty())
    {
        int v = posOrdem.top();
        posOrdem.pop();

        if (!visited[v])
        {
            cout << v + 1 << ' ';
            output << v + 1 << ' ';
            dfs_recR(v, adjR, visited, output);
            cout << endl;
            output << endl;
        }
    }
}

void kosaraju(vector<vector<int>> &adj, vector<vector<int>> &adjR, ofstream &output)
{
    stack<int> posOrdem;
    dfs(adj, posOrdem);
    dfsR(adjR, posOrdem, output);
}

signed main(int argc, char *argv[])
{
    string inputFile = "";
    string outputFile = "";
    bool showHelp = false;
    int startVertex = 1;

    if (argc < 1)
        return 1;

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        if (arg == "-h")
        {
            showHelp = true;
        }
        else if (arg == "-f" && i + 1 < argc)
        {
            inputFile = argv[++i];
        }
        else if (arg == "-o" && i + 1 < argc)
        {
            outputFile = argv[++i];
        }
        else if (arg == "-i" && i + 1 < argc)
        {
            startVertex = stoi(argv[++i]);
        }
    }

    if (showHelp)
    {
        help();
        return 0;
    }

    ifstream input(inputFile);
    ofstream output(outputFile);

    int n, m;
    input >> n >> m;

    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> adjR(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int v, u;
        input >> v >> u;

        adj[v - 1].push_back(u - 1);
        adjR[u - 1].push_back(v - 1);
    }

    kosaraju(adj, adjR, output);

    return 0;
}