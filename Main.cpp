// reading a text file
#include "GraphMaker.cpp"
#include "Solver.cpp"
#include <queue>;
#include "Comparator.cpp"

using namespace std;

void print_neighbours(Graph* graph)
{
	int size = graph->nodes.size();
	int number_edges = 0;

	for (int i = 0; i < size; i++)
	{
		int node_id = graph->nodes[i]->id;

		std::vector<int> neighbours = graph->nodes[i]->neighbours;
		int neighbours_size = neighbours.size();

		std::cout << "neighbours of " + std::to_string(node_id) << std::endl;

		for (int j = 0; j < neighbours_size; j++)
		{
			std::cout << "node id " + std::to_string(neighbours[j]) + ", ";
			number_edges++;
		}

		std::cout << " " << std::endl;
	}
	std::cout << "number of edges = " + std::to_string(number_edges / 2) << std::endl;
}
int main() {
	
	//Test GraphMaker nodes
	GraphMaker* gr = new GraphMaker();

	gr->read("1000_5");
	Graph* graph = gr->graph;

	int graph_size = graph->nodes.size();

	/*for (int i = 0; i < graph_size; i++)
	{
		int node_id = graph->nodes[i]->id;
		std::cout << "node id " + std::to_string(node_id) << std::endl;
	}*/

	//Test GraphMaker edges
	/*int number_edges = 0;
	for (int i = 0; i < graph_size; i++)
	{
		int node_id = graph->nodes[i]->id;
		std::vector<int> neighbours = graph->nodes[node_id]->neighbours;
		int neighbours_size = neighbours.size();
		std::cout << "neighbours of " + std::to_string(node_id) << std::endl;

		for (int j = 0; j < neighbours_size; j++)
		{
			std::cout << "node id " + std::to_string(neighbours[j]) + ", ";
			number_edges++;
		}

		std::cout << " " << std::endl;
	}
	std::cout << "number of edges = "+std::to_string(number_edges/2) << std::endl;*/

	//Test setup_colors
	/*Solver* solver = new Solver(graph);
	solver->solve();

	for (int i = 0; i < graph_size; i++)
	{
		std::cout << "colors of " + std::to_string(i) << std::endl;
		for (int color = 0; color < 40; color++)
		{
			int c = graph->nodes[i]->available_colors[color];
			std::cout << std::to_string(c);
		}
		std::cout << " " << std::endl;
		
	}*/

	//Test solver core
	/*Solver* solver = new Solver(graph);
	solver->solve();

	print_neighbours(solver->core);*/

	//Test core 2
	/*Node* n0 = new Node();
	n0->id = 0;
	n0->neighbours.push_back(1);
	n0->neighbours.push_back(8);
	
	Node* n1 = new Node();
	n1->id = 1;
	n1->neighbours.push_back(0);
	n1->neighbours.push_back(2);
	n1->neighbours.push_back(8);

	Node* n2 = new Node();
	n2->id = 2;
	n2->neighbours.push_back(1);
	n2->neighbours.push_back(3);
	n2->neighbours.push_back(5);
	n2->neighbours.push_back(4);

	Node* n3 = new Node();
	n3->id = 3;
	n3->neighbours.push_back(2);
	n3->neighbours.push_back(5);
	n3->neighbours.push_back(4);

	Node* n4 = new Node();
	n4->id = 4;
	n4->neighbours.push_back(3);
	n4->neighbours.push_back(2);
	n4->neighbours.push_back(5);
	n4->neighbours.push_back(8);

	Node* n5 = new Node();
	n5->id = 5;
	n5->neighbours.push_back(2);
	n5->neighbours.push_back(3);
	n5->neighbours.push_back(4);
	n5->neighbours.push_back(8);

	Node* n6 = new Node();
	n6->id = 6;
	n6->neighbours.push_back(7);
	n6->neighbours.push_back(8);

	Node*n7 = new Node();
	n7->id = 7;
	n7->neighbours.push_back(6);
	n7->neighbours.push_back(8);

	Node* n8 = new Node();
	n8->id = 8;
	n8->neighbours.push_back(6);
	n8->neighbours.push_back(7);
	n8->neighbours.push_back(0);
	n8->neighbours.push_back(1);
	n8->neighbours.push_back(5);
	n8->neighbours.push_back(4);

	Graph* test = new Graph();
	test->nodes.push_back(n0);
	test->nodes.push_back(n1);
	test->nodes.push_back(n2);
	test->nodes.push_back(n3);
	test->nodes.push_back(n4);
	test->nodes.push_back(n5);
	test->nodes.push_back(n6);
	test->nodes.push_back(n7);
	test->nodes.push_back(n8);

	Solver* test_solver = new Solver(test);
	test_solver->solve();
	print_neighbours(test_solver->core);*/

	//Test max_node
	/*Solver* solver = new Solver(graph);
	Node* max = solver->max_node(graph);
	cout << "max node " + std::to_string(max->id) + " neighbours " + std::to_string(max->neighbours.size())<<std::endl;*/

	//Test build_hierarchy
	Solver* solver = new Solver(graph);
	std::priority_queue<Node*, vector<Node*>, Comparator> hierarchy = solver->build_hierarchy(graph);
	cout << "hierarch size " + std::to_string(hierarchy.size()) << std::endl;

	while (!hierarchy.empty())
	{
		Node* node = hierarchy.top();
		cout << "node " + std::to_string(node->id) + " neighbours " + std::to_string(node->neighbours.size()) << std::endl;
		hierarchy.pop();
	}
	return 0;
}