#pragma once

// Класс для взвешенного ребра
class Edge {
private:
    int vertex;
    int weight;
public:
    Edge(int vertex, int weight);

    int getVertex() const;
    int getWeight() const;

    // Оператор сравнения
    bool operator==(const Edge &rhs) const;
};
