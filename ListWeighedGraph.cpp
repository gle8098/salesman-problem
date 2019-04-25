#include <algorithm>
#include "ListWeighedGraph.h"

ListWeighedGraph::ListWeighedGraph(std::size_t verticesCount) :
        verticesCount(verticesCount),
        verticesNext(verticesCount)
{}

void ListWeighedGraph::AddEdge(int from, int to, int weight) {
    auto& listNext = verticesNext[from];
    Edge tempEdge(to, weight);
    if (std::find(listNext.begin(), listNext.end(), tempEdge) != listNext.end()) {
        // В графе уже есть это ребро
        return;
    }

    verticesNext[from].emplace_back(to, weight);
}

int ListWeighedGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<Edge> ListWeighedGraph::GetNextVertices(int vertex) const {
    return verticesNext[vertex];
}

int ListWeighedGraph::getEdgeWeight(int startVertex, int endVertex) const {
    for (const Edge& edge : verticesNext[startVertex]) {
        if (edge.getVertex() == endVertex) {
            return edge.getWeight();
        }
    }

    return 0;
}
