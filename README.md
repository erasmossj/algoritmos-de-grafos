# Implementação de Algoritmos de Grafos  

Repositório com implementações em **C++** de algoritmos clássicos de grafos, desenvolvidos para estudo e prática acadêmica.

## Visão Geral  
O projeto reúne implementações funcionais e comentadas dos seguintes algoritmos:  
- **Prim** — encontra a árvore geradora mínima (MST) a partir de um vértice inicial.  
- **Kruskal** — calcula a MST utilizando união e busca de conjuntos (Union-Find).  
- **Dijkstra** — determina o menor caminho a partir de uma origem em grafos com pesos não negativos.  
- **Kosaraju** — identifica componentes fortemente conectados em grafos direcionados.

Cada pasta contém o código-fonte e, quando aplicável, arquivos de instância e Makefile para compilação.

## Estrutura do Repositório
```
algoritmos-de-grafos/
│
├── prim/ ← implementação do algoritmo de Prim
├── kruskal/ ← implementação do algoritmo de Kruskal
├── dijkstra/ ← implementação do algoritmo de Dijkstra
├── kosaraju/ ← implementação do algoritmo de Kosaraju
├── Bat1/ ← bateria de testes: instâncias, gabaritos e script Bat1.sh
└── README.md ← README
```

## Como Compilar e Executar  
1. Clone o repositório:  
   ```bash
   git clone https://github.com/erasmossj/algoritmos-de-grafos.git
   cd algoritmos-de-grafos
   ```

2. Entre na pasta do algoritmo desejado:
  ```bash
  cd prim
  ```
3. Compile o código
  ```bash
  make all
  # ou
  g++ -std=c++17 prim.cpp -o prim.bin
  ```
4. Para executar individualmente, execute com os parâmetros indicados (use o -h, para chamar o help):
  ```bash
  ./prim -f arquivo-entrada -i 1 -o arquivo_saida -s
  ```
5. Para executar com as baterias de testes, compile o código e mova os binários (.bin) para a pasta Bat1 e execute o arquivo Bat1.sh:
   ```bash
   ./Bat1.sh
   ```

## Tecnologias

- C++17 (`g++`)
- Make
- Shell script (bateria de testes em `Bat1/`)

## Autor

Desenvolvido por **Erasmo da Silva Sá Junior** — [GitHub](https://github.com/erasmossj) · [LinkedIn](https://www.linkedin.com/in/erasmo-junior-883010309/).
