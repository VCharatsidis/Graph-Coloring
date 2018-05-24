// reading a text file
#include "GraphMaker.cpp"
using namespace std;

int main() {
	
	//Test GraphReader nodes
	GraphMaker* gr = new GraphMaker();

	gr->read("1000_9");
	Graph* graph = gr->graph;

	int graph_size = graph->nodes.size();

	for (int i = 0; i < graph_size; i++)
	{
		int node_id = graph->nodes[i]->id;
		//std::cout << "node id " + std::to_string(node_id) << std::endl;
	}

	//Test GraphReader edges
	int number_edges = 0;
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
	std::cout << "number of edges = "+std::to_string(number_edges/2) << std::endl;

	return 0;
}