#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(std::size_t vertices_count) {
    for (int i = 0; i < vertices_count; i++) {
        for (int j = 0; j < vertices_count; j++) {
            g[i][j] = false;
        }
    }
}

MatrixGraph::MatrixGraph(const IGraph * graph) {
    size = graph->VerticesCount();
    for (int i = 0; i < size; i++) {
        std::vector<int> vertices_;
        vertices_ = graph->FindAllAdjacentOut(i);
        for (auto el: vertices_) {
            MatrixGraph::AddEdge(i, el);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    g[from][to] = true;
    g[to][from] = true;
}

std::vector<int> MatrixGraph::FindAllAdjacentIn(int vertex) const {
    std::vector<int> vertices_;
    for (int i = 0; i < size; i++) {
        if (g[i][vertex]) {
            vertices_.push_back(i);
        }
    }
    return vertices_;
}

std::vector<int> MatrixGraph::FindAllAdjacentOut(int vertex) const {
    std::vector<int> vertices_;
    for (int to = 0; to < size; to++) {
        if (g[vertex][to]) {
            vertices_.push_back(to);
        }
    }
    return vertices_;
}
