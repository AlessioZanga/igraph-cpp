#include <gtest/gtest.h>

#include "directed_graph.ipp"

#define N {"1", "2", "3", "4", "5"}
#define N_SIZE 5

using namespace igraph;

TEST(TestDirectedGraph, DefaultContructor) {
    DirectedGraph g0, g1(N);
    ASSERT_EQ(g1.size(), N_SIZE);
}

TEST(TestDirectedGraph, CopyConstructor) {
    DirectedGraph g0(N);
    DirectedGraph g1(g0);
    ASSERT_EQ(g0.size(), g1.size());
}

TEST(TestDirectedGraph, AssignmentConstructor) {
    DirectedGraph g0(N);
    DirectedGraph g1 = g0;
    ASSERT_EQ(g0.size(), g1.size());
}

TEST(TestDirectedGraph, Destructor) {
    DirectedGraph *g = new DirectedGraph(N);
    ASSERT_EQ(g->size(), N_SIZE);
    delete g;
}

TEST(TestDirectedGraph, EdgesConstructor) {
    Nodes nodes = {"A", "B", "C", "D"};
    Edges edges = {
        {"A", "B"},
        {"A", "C"},
        {"B", "C"},
        {"A", "D"},
        {"B", "D"},
        {"C", "D"}
    };
    DirectedGraph g(edges);
    ASSERT_EQ(g.get_nodes(), nodes);
    ASSERT_EQ(g.get_edges(), edges);
}

TEST(TestDirectedGraph, IsDirected) {
    DirectedGraph g(N);
    ASSERT_TRUE(g.is_directed());
}

TEST(TestDirectedGraph, IsDag) {
    FAIL();
}

TEST(TestDirectedGraph, FromUndirected) {
    Graph ug(N);
    DirectedGraph g(ug);
    ASSERT_EQ(g.size(), ug.size());
    ASSERT_TRUE(g.is_directed());
}

TEST(TestDirectedGraph, ToUndirected) {
    DirectedGraph g(N);
    Graph ug = g.to_undirected();
    ASSERT_EQ(g.size(), ug.size());
    ASSERT_FALSE(ug.is_directed());
}

TEST(TestDirectedGraph, Parents) {
    FAIL();
}

TEST(TestDirectedGraph, Family) {
    FAIL();
}

TEST(TestDirectedGraph, Children) {
    FAIL();
}

TEST(TestDirectedGraph, Ancestrors) {
    FAIL();
}

TEST(TestDirectedGraph, Descendants) {
    FAIL();
}
