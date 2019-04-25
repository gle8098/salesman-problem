#pragma once

#include "IWeighedGraph.h"
#include <memory>

// Возвращает минимальное остовное дерево с корнем в вершине 0, найденное алгоритмом Прима.
std::shared_ptr<IWeighedGraph> primFindMST(IWeighedGraph* graph);
// Возвращает путь цикда двойного приближения задачи о коммивояжере
std::vector<int> Find2ApprTSPRoute(const std::shared_ptr<IWeighedGraph> &graph);
// Возвращает точный путь цикда дзадачи о коммивояжере
std::vector<int> FindExactTSPRoute(const std::shared_ptr<IWeighedGraph> &graph);

// Возвращает длину пути (цикла)
inline int GetPathWeight(const std::shared_ptr<IWeighedGraph>& graph, const std::vector<int>& path) {
    int pathWeight = 0;
    for (int i = 1; i < path.size(); ++i) {
        pathWeight += graph->getEdgeWeight(path[i - 1], path[i]);
    }
    return pathWeight;
}
