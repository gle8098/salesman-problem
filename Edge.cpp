#include "Edge.h"

Edge::Edge(int vertex, int weight) :
        vertex(vertex),
        weight(weight)
{}

int Edge::getVertex() const {
    return vertex;
}

int Edge::getWeight() const {
    return weight;
}

bool Edge::operator==(const Edge &rhs) const {
    return rhs.vertex == vertex && rhs.weight == weight;
}