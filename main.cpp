#include <iostream>
#include "ListWeighedGraph.h"
#include "GraphAlgorithms.h"
#include "gtest/gtest.h"
#include "MertixCompleteGraphGenerator.h"

void runTest(int verticesCount) {
    std::shared_ptr<IWeighedGraph> graph = generateMatrixCompleteGraph(verticesCount);
    int foundValue = GetPathWeight(graph, Find2ApprTSPRoute(graph));
    int realValue = GetPathWeight(graph, FindExactTSPRoute(graph));
    float ratio = foundValue / static_cast<float>(realValue);
    std::cout << "Found value: " << foundValue << ". Real value: " << realValue << ". Ratio: " << ratio << std::endl;
    ASSERT_LE(foundValue, realValue * 2);
}

void runTests(int verticesCount) {
    std::cout << "Running tests for " << verticesCount << " vertices" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "-- Test " << i << std::endl;
        runTest(verticesCount);
    }
    std::cout << "Done" << std::endl;
}

TEST(Find2ApprTSPRouteTest, GraphOf3Vertices) {
    runTests(3);
}
TEST(Find2ApprTSPRouteTest, GraphOf4Vertices) {
    runTests(4);
}
TEST(Find2ApprTSPRouteTest, GraphOf5Vertices) {
    runTests(5);
}
TEST(Find2ApprTSPRouteTest, GraphOf6Vertices) {
    runTests(6);
}
TEST(Find2ApprTSPRouteTest, GraphOf7Vertices) {
    runTests(7);
}
TEST(Find2ApprTSPRouteTest, GraphOf8Vertices) {
    runTests(8);
}
TEST(Find2ApprTSPRouteTest, GraphOf9Vertices) {
    runTests(9);
}
TEST(Find2ApprTSPRouteTest, GraphOf10Vertices) {
    runTests(10);
}
TEST(Find2ApprTSPRouteTest, GraphOf11Vertices) {
    runTests(11);
}

int mainRunDoubleAppr() {
    int verticesCount, edgesCount;
    std::cin >> verticesCount >> edgesCount;

    std::shared_ptr<ListWeighedGraph> graph = std::make_shared<ListWeighedGraph>(verticesCount);
    for (int i = 0; i < edgesCount; ++i) {
        int vertA, vertB, weight;
        std::cin >> vertA >> vertB >> weight;
        graph->AddEdge(vertA, vertB, weight);
        graph->AddEdge(vertB, vertA, weight);
    }

    for (int val : Find2ApprTSPRoute(graph)) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
