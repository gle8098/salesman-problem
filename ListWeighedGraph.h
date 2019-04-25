#pragma once

#include "IWeighedGraph.h"

class ListWeighedGraph : public IWeighedGraph {
private:
    const std::size_t verticesCount;
    std::vector<std::vector<Edge>> verticesNext;

public:
    // Создает граф с verticesCount вершинами без ребер
    explicit ListWeighedGraph(std::size_t verticesCount);

    void AddEdge(int from, int to, int weight) override;
    int VerticesCount() const override;
    std::vector<Edge> GetNextVertices(int vertex) const override;
    int getEdgeWeight(int startVertex, int endVertex) const override;
};
