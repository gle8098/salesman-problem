#pragma once

#include "Edge.h"
#include <vector>

// Интерфейс графа
struct IWeighedGraph {
    virtual ~IWeighedGraph() = default;

    // Добавление ребра от from к to с весом weight.
    virtual void AddEdge(int from, int to, int weight) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<Edge> GetNextVertices(int vertex) const = 0;

    virtual int getEdgeWeight(int startVertex, int endVertex) const = 0;
};
