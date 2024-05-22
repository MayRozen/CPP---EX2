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
    cout << "Graph addition test passed!" << endl;
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
    cout << "Graph multiplication test passed!" << endl;
}

TEST_CASE("Invalid operations")
{
    Graph check;
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(graph2);
    Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph5);
    CHECK(g5 * g1 == check); // If we got an empty graph so these matrices can not be multiplied
    CHECK(g5 * g2 == check);

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
    cout << "Invalid operations test passed!" << endl;
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
        // Create the expected result graph with doubled weights
        vector<vector<int>> expectedData(100, vector<int>(100, 0));
        for(size_t i = 0; i < 100; i++) {
            for(size_t j = 0; j < 100; j++) {
                expectedData[i][j] = bigGraphData[i][j] * 2;
            }
        }
        Graph expectedGraph;
        expectedGraph.loadGraph(expectedData);

        // Checking if the + operator is working as we expect
        CHECK(g3 == expectedGraph);
        cout << "Graph addition test passed!" << endl;
    }
    cout << "Operators with big graph test passed!" << endl;
}

TEST_CASE("Test graph subtraction") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);
    Graph g3 = g1 - g2;

    Graph gCheck;
    vector<vector<int>> graphCh = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    gCheck.loadGraph(graphCh);
    // Checking if the - operator is working as we expect
    CHECK(g3 == gCheck); // Subtraction should result in a graph with all weights 0
    cout << "Graph subtraction test passed!" << endl;
}

TEST_CASE("Test unary minus operator") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 0},
        {1, 0, 1},
        {0, -1, 0}};
    g1.loadGraph(graph1);
    -g1; // Apply unary minus operator

    Graph gCheck;
    vector<vector<int>> graphCh = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, -1, 0}};
    gCheck.loadGraph(graphCh);

    // Checking if the unary minus operator is working as we expect
    CHECK(g1 == gCheck);
    cout << "Unary minus operator test passed!" << endl;
}

TEST_CASE("Test unary plus operator") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, -1, 0},
        {1, 0, 1},
        {0, -1, 0}};
    g1.loadGraph(graph1);
    +g1; // Apply unary plus operator

    Graph gCheck;
    vector<vector<int>> graphCh = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    gCheck.loadGraph(graphCh);

    // Checking if the unary plus operator is working as we expect
    CHECK(g1 == gCheck);
    cout << "Unary plus operator test passed!" << endl;
}

TEST_CASE("Test graph addition and assignment operator") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(graph2);

    g1 += g2;

    Graph gCheck;
    vector<vector<int>> graphCh = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}};
    gCheck.loadGraph(graphCh);
    // Checking if the += operator is working as we expect
    CHECK(g1 == gCheck); // Addition should result in a graph with weights doubled
    cout << "Graph addition and assignment operator test passed!" << endl;
}

TEST_CASE("Test graph multiplication by scalar") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    int scalar = 5;
    g *= scalar; // Multiply the graph by scalar
    // Checking if the *= operator is working as we expect
    Graph gCheck;
    vector<vector<int>> gCh = {
        {0, 5, 0},
        {5, 0, 5},
        {0, 5, 0}};
    gCheck.loadGraph(gCh);

    CHECK(g == gCheck);
    cout << "Graph multiplication by scalar test passed!" << endl;
}

TEST_CASE("Test comparison operators with equal graphs") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    g2.loadGraph(graph1);

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
    cout << "Comparison operators with equal graphs test passed!" << endl;
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

    CHECK(g1 < g2); // Need to print: "Error! not equals weight"
    CHECK(g1 <= g2);
    CHECK_FALSE(g1 > g2); // Need to print: "Error! not equals weight"
    CHECK_FALSE(g1 >= g2);
    cout << "Comparison operators between different graphs test passed!" << endl;
}

TEST_CASE("Test comparison operators") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, -2, 0},
        {0, -7, 0},
        {9, 0, -1}};
    g2.loadGraph(graph2);

    CHECK_FALSE(g1 == g2);
    CHECK(g1 != g2);
    cout << "Comparison operators test passed!" << endl;
}

TEST_CASE ("testPreIncrement") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    // Perform pre-increment (++n)
    Graph& result = ++g;

    // Check if the original graph is modified
    CHECK(g == result); // CHECK equality after pre-increment
    cout << "Pre-increment (++n) test passed!" << endl;
}

TEST_CASE("testPostIncrement") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    // Perform post-increment (n++)
    Graph result = g++;

    // Check if the original graph is unmodified
    CHECK(g == result); // CHECK inequality after post-increment
    cout << "Post-increment (n++) test passed!" << endl;
}

TEST_CASE("testPreDecrement") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    // Perform pre-decrement (--n)
    Graph& result = --g;

    // Check if the original graph is modified
    CHECK(g == result); // CHECK equality after pre-decrement
    cout << "Pre-decrement (--n) test passed!" << endl;
}

TEST_CASE("testPostDecrement") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    // Perform post-decrement (n--)
    Graph result = g--;

    // Check if the original graph is unmodified
    CHECK(g == result); // CHECK inequality after post-decrement
    cout << "Post-decrement (n--) test passed!" << endl;
}
