#include <bits/stdc++.h>

using namespace std;

#define int long long int

bool showSolution = false;

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

void make_set(int v, vector<int> &pai, vector<int> &rank)
{
    pai[v] = v;
    rank[v] = 0;
}

int find_set(int v, vector<int> &pai)
{
    if (pai[v] == v)
        return v;
    return (pai[v] = find_set(pai[v], pai));
}

void unite(int x, int y, vector<int> &pai, vector<int> &rank)
{
    x = find_set(x, pai);
    y = find_set(y, pai);

    if (x != y)
    {
        if (rank[x] < rank[y])
            swap(x, y);
        pai[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
}

void kruskal(vector<tuple<int, int, int>> edges, vector<int> &pai, vector<int> &rank, const int &n, int &custo,
             ofstream &output)
{
    sort(edges.begin(), edges.end());

    for (int v = 0; v < n; v++)
        make_set(v, pai, rank);

    for (auto e : edges)
    {
        auto [w, v, u] = e;

        if (find_set(v, pai) != find_set(u, pai))
        {
            if (showSolution)
            {
                cout << "(" << v + 1 << "," << u + 1 << ") ";
                output << "(" << v + 1 << "," << u + 1 << ") ";
            }
            unite(v, u, pai, rank);
            custo += w;
        }
    }
}

signed main(int argc, char *argv[])
{
    string inputFile = "";
    string outputFile = "";
    bool showHelp = false;

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
        else if (arg == "-s")
        {
            showSolution = true;
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

    vector<tuple<int, int, int>> edges;
    vector<int> pai(n);
    vector<int> rank(n);
    int custo = 0;

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        input >> v >> u >> w;

        edges.push_back(make_tuple(w, v - 1, u - 1));
    }

    kruskal(edges, pai, rank, n, custo, output);

    if (!showSolution)
    {
        cout << custo;
        output << custo;
    }

    return 0;
}