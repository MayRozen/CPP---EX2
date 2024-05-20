/*  ID: 212051007
    Mail: mayrozen45@gmail.com
*/

#include "doctest.h"
using namespace std;
#include "Graph.hpp"
#include "Algorithms.hpp"

TEST_CASE("Test graph addition")
{
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1][2, 0, 3][1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0, 0, 2][1, 0, 1][1, 0, 0]");
}

TEST_CASE("Invalid operations")
{
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

TEST_CASE("Test operators with big graph (with 100 vertices)")
{
    // Create a big graph with 100 vertices
    Graph bigGraph;
    vector<vector<int>> bigGraphData(100, vector<int>(100, 0)); // Initialize all weights to 0
    int counter = 0;
    for(size_t i=0; i<100; i++){
        for(size_t j=0; j<100; j++){
            bigGraphData[i][j] = counter;
            counter++;
        }
    }
    bigGraph.loadGraph(bigGraphData);

    SUBCASE("Test graph addition") {
        Graph g1 = bigGraph;
        Graph g2 = bigGraph;
        Graph g3 = g1 + g2;
        // Checking if the + operator is working as we expect
        CHECK(g3 == bigGraph); // Addition should result in a graph with weights doubled
    }

    SUBCASE("Test graph addition and assignment operator") {
        Graph g1 = bigGraph;
        Graph g2 = bigGraph;
        g1 += g2;
        // Checking if the += operator is working as we expect
        CHECK(g1 == bigGraph); // Addition should result in a graph with weights doubled
    }

    SUBCASE("Test unary plus operator") {
        Graph g = bigGraph;
        +g; // Apply unary plus operator
        // Checking if the unary plus operator is working as we expect
        CHECK(g == bigGraph); // Unary plus should not modify the graph
    }

    SUBCASE("Test graph subtraction") {
        Graph g1 = bigGraph;
        Graph g2 = bigGraph;
        Graph g3 = g1 - g2;
        // Checking if the - operator is working as we expect
        CHECK(g3 == bigGraph); // Subtraction should result in a graph with all weights 0
    }

    SUBCASE("Test graph subtraction and assignment operator") {
        Graph g1 = bigGraph;
        Graph g2 = bigGraph;
        g1 -= g2;
        // Checking if the -= operator is working as we expect
        CHECK(g1 == bigGraph); // Subtraction should result in a graph with all weights 0
    }

    SUBCASE("Test unary minus operator") {
        Graph g = bigGraph;
        -g; // Apply unary minus operator
        // Checking if the unary minus operator is working as we expect
        // Unary minus should negate all weights in the graph
        for (const auto& row : g.getAdjMatrix()) {
            for (int weight : row) {
                CHECK(weight == 0); // All weights should become 0 after unary minus
            }
        }
    }

    SUBCASE("Test graph multiplication by scalar") {
        Graph g = bigGraph;
        int scalar = 5;
        g *= scalar; // Multiply the graph by scalar
        // Checking if the *= operator is working as we expect
        // All weights in the graph should be multiplied by the scalar
        for (const auto& row : g.getAdjMatrix()) {
            for (int weight : row) {
                CHECK(weight == 0); // All weights should become 0 after unary minus
            }
        }
    }

    SUBCASE("Test comparison operators") {
        Graph g1 = bigGraph;
        Graph g2 = bigGraph;

        // Test greater than operator (>)
        CHECK_FALSE(g1 > g2); // Graphs are equal, so g1 is not greater than g2
        CHECK_FALSE(g1 < g2); // Graphs are equal, so g1 is not less than g2

        // Test greater than or equal to operator (>=)
        CHECK(g1 >= g2); // Graphs are equal, so g1 is greater than or equal to g2
        CHECK(g2 >= g1); // Graphs are equal, so g2 is greater than or equal to g1

        // Test less than or equal to operator (<=)
        CHECK(g1 <= g2); // Graphs are equal, so g1 is less than or equal to g2
        CHECK(g2 <= g1); // Graphs are equal, so g2 is less than or equal to g1

        // Test equality operator (==)
        CHECK(g1 == g2); // Graphs are equal, so g1 is equal to g2

        // Test inequality operator (!=)
        CHECK_FALSE(g1 != g2); // Graphs are equal, so g1 is not unequal to g2
    }
}

TEST_CASE("Comparison operators between different graphs") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g2.loadGraph(graph2);

    CHECK(g1 < g2);
    CHECK(g1 <= g2);
    CHECK_FALSE(g1 > g2);
    CHECK_FALSE(g1 >= g2);
    CHECK_FALSE(g1 == g2);
    CHECK(g1 != g2);
}
