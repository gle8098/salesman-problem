#include <limits>
#include <set>
#include <cstring>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include "GraphAlgorithms.h"
#include "ListWeighedGraph.h"

using namespace std;

using std::shared_ptr;
using std::make_pair;

shared_ptr<IWeighedGraph> primFindMST(const shared_ptr<IWeighedGraph>& graph) {
    std::vector<int> keys(graph->VerticesCount(), std::numeric_limits<int>::max()); // Дубликат ключей в очереди с приор.
    std::vector<int> parents(graph->VerticesCount(), -1); // Остовное дерево в неявном виде
    std::set<std::pair<int, int>> queue; // Очередь с приоритетом
    std::vector<int> used(graph->VerticesCount(), false);

    // Предстартовая подготовка
    int startVertex = 0;
    keys[startVertex] = 0;
    queue.insert(make_pair(0, startVertex));

    // Основной цикл по вершинам
    while (!queue.empty()) {
        int vert = (*queue.begin()).second;
        queue.erase(make_pair(keys[vert], vert));
        used[vert] = 1;

        for (auto& edge : graph->GetNextVertices(vert)) {
            int childVert = edge.getVertex();
            if (used[childVert] == 0 && keys[childVert] > edge.getWeight()) {
                parents[childVert] = vert;

                // Релаксируем вершину
                queue.erase(make_pair(keys[childVert], childVert));
                keys[childVert] = edge.getWeight();
                queue.insert(make_pair(edge.getWeight(), childVert));
            }
        }
    }

    // Собираем дерево из parents
    shared_ptr<IWeighedGraph> ans = std::make_shared<ListWeighedGraph>(graph->VerticesCount());
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        if (parents[i] != -1) {
            ans->AddEdge(parents[i], i, keys[i]);
        }
    }

    return ans;
}

vector<int> Find2ApprTSPRoute(const shared_ptr<IWeighedGraph> &graph) {
    shared_ptr<IWeighedGraph> mst = primFindMST(graph);

    stack<int> st;
    st.push(0);

    vector<int> res;

    while (!st.empty()) {
        int vert = st.top();
        st.pop();
        res.push_back(vert);
        for (Edge child : mst->GetNextVertices(vert)) {
            int childVert = child.getVertex();
            st.push(childVert);
        }
    }

    res.push_back(0);
    return res;
}

vector<int> FindExactTSPRoute(const std::shared_ptr<IWeighedGraph> &graph) {
    int minPathWeight = -1;
    vector<int> minPath;

    vector<int> path(graph->VerticesCount());
    for (int i = 0; i < path.size(); ++i) { // Заполняем первый путь: 0, 1, ..., n-1
        path[i] = i;
    }

    do {
        int pathWeight = GetPathWeight(graph, path) + graph->getEdgeWeight(path[0], path[path.size() - 1]);

        if (pathWeight < minPathWeight || minPathWeight == -1) {
            minPathWeight = pathWeight;
            minPath = path;
        }
    } while (std::next_permutation(path.begin(), path.end()));

    minPath.push_back(minPath[0]);
    return minPath;
}