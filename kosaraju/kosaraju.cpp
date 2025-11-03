#include <bits/stdc++.h>

using namespace std;

#define ll long long int

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

void dfs_rec(ll v, vector<vector<ll>> &adj, stack<ll> &posOrdem, vector<bool> &visited)
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

void dfs(vector<vector<ll>> &adj, stack<ll> &posOrdem)
{
    ll n = adj.size();

    vector<bool> visited(n, false);

    for (ll v = 0; v < n; v++)
    {
        if (!visited[v])
            dfs_rec(v, adj, posOrdem, visited);
    }
}

void dfs_recR(ll v, vector<vector<ll>> &adjR, vector<bool> &visited, ofstream &output)
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

void dfsR(vector<vector<ll>> &adjR, stack<ll> &posOrdem, ofstream &output)
{
    ll n = adjR.size();

    vector<bool> visited(n, false);

    while (!posOrdem.empty())
    {
        ll v = posOrdem.top();
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

void kosaraju(vector<vector<ll>> &adj, vector<vector<ll>> &adjR, ofstream &output)
{
    stack<ll> posOrdem;
    dfs(adj, posOrdem);
    dfsR(adjR, posOrdem, output);
}

int main(int argc, char *argv[])
{
    string inputFile = "";
    string outputFile = "";
    bool showHelp = false;
    ll startVertex = 1;

    if (argc < 1)
        return 1;

    for (ll i = 1; i < argc; i++)
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

    ll n, m;
    input >> n >> m;

    vector<vector<ll>> adj(n, vector<ll>());
    vector<vector<ll>> adjR(n, vector<ll>());

    for (ll i = 0; i < m; i++)
    {
        ll v, u;
        input >> v >> u;

        adj[v - 1].push_back(u - 1);
        adjR[u - 1].push_back(v - 1);
    }

    kosaraju(adj, adjR, output);

    return 0;
}