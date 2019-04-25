#include "MertixCompleteGraphGenerator.h"
#include "ListWeighedGraph.h"
#include <vector>
#include <algorithm>
#include <random>

using std::vector;
using std::pair;
using std::make_pair;

std::default_random_engine generator;
std::normal_distribution<> distribution {0, 1000};

std::shared_ptr<IWeighedGraph> generateMatrixCompleteGraph(int verticesCount) {
    std::shared_ptr<IWeighedGraph> graph = std::make_shared<ListWeighedGraph>(verticesCount);

    vector<pair<int, int>> points;
    for (int i = 0; i < verticesCount; ++i) {
        int x = static_cast<int>(std::round(distribution(generator)));
        int y = static_cast<int>(std::round(distribution(generator)));
        int pointIndex = points.size();

        for (int j = 0; j < points.size(); ++j) {
            int curX = points[j].first;
            int curY = points[j].second;
            int weight = static_cast<int>(std::round(std::sqrt( (x - curX) * (x - curX) + (y - curY) * (y - curY) )));
            graph->AddEdge(j, pointIndex, weight);
            graph->AddEdge(pointIndex, j, weight);
        }

        points.emplace_back(x, y);
    }

    return graph;
}