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
    cout << "-i <vertice> : define o vertice inicial (padrao = 1)" << endl;
    cout << "-s : mostra a solucao" << endl;

    return;
}

void prim(ll v0, vector<vector<pair<ll, ll>>> &adj, bool showSolution, ll &custoTotal, ofstream &output)
{
    ll n = adj.size();

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vector<bool> visited(n, false);

    visited[v0] = true;

    for (auto [u, custo] : adj[v0])
        pq.push({custo, u, v0});

    while (!pq.empty())
    {
        auto [custo, u, v] = pq.top();
        pq.pop();

        if (!visited[u])
        {
            visited[u] = true;
            custoTotal += custo;

            if (showSolution)
            {
                output << "(" << v + 1 << "," << u + 1 << ") ";
                cout << "(" << v + 1 << "," << u + 1 << ") ";
            }

            for (auto [w, custoW] : adj[u])
                if (!visited[w])
                    pq.push({custoW, w, u});
        }
    }

    return;
}

int main(int argc, char *argv[])
{
    string inputFile = "";
    string outputFile = "";
    bool showHelp = false;
    bool showSolution = false;
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
        else if (arg == "-s")
        {
            showSolution = true;
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

    vector<vector<pair<ll, ll>>> adj(n, vector<pair<ll, ll>>());
    ll custo = 0;

    for (ll i = 0; i < m; i++)
    {
        ll v, u, w;
        input >> v >> u >> w;

        adj[v - 1].push_back({u - 1, w});
        adj[u - 1].push_back({v - 1, w});
    }

    prim(startVertex - 1, adj, showSolution, custo, output);

    if (!showSolution)
    {
        output << custo;
        cout << custo;
    }

    return 0;
}