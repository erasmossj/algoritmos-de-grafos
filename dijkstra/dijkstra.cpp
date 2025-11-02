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
    cout << "-i <vertice> : define o vertice inicial (padrao = 1)" << endl;

    return;
}

void dijkstra(int v0, vector<vector<pair<int, int>>> &adj, vector<int> &dist)
{
    int n = adj.size();

    dist[v0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int v = 0; v < n; v++)
        pq.push({v, dist[v]});

    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();

        for (auto u : adj[v.first])
        {
            if (dist[u.first] > dist[v.first] + u.second)
            {
                dist[u.first] = dist[v.first] + u.second;
                pq.push({u.first, dist[u.first]});
            }
        }
    }
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

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    vector<int> dist(n, INT_MAX);

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        input >> v >> u >> w;

        adj[v - 1].push_back({u - 1, w});
        adj[u - 1].push_back({v - 1, w});
    }

    dijkstra(startVertex - 1, adj, dist);

    for (int v = 0; v < n; v++)
    {
        cout << v + 1 << ":" << dist[v] << " ";
        output << v + 1 << ":" << dist[v] << " ";
    }

    return 0;
}