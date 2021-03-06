#pragma once

#include <structures/graph.hpp>

namespace igraph {

namespace structures {

Graph chordal(const Graph &other) {
    igraph_t chordal;
    igraph_bool_t is_chordal;
    igraph_is_chordal(&other.graph, 0, 0, &is_chordal, 0, &chordal);
    Graph out(&chordal);
    igraph_destroy(&chordal);
    return out;
}

}  // namespace structures

}  // namespace igraph
