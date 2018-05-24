#include "Graph.cpp";
using std::vector;

class Solver {
public:
	Graph* graph;
	Solver(Graph* give_graph) : graph(give_graph) {};

	void solve() {
		int size = graph->nodes.size();
		for (int number_colors = 2; number_colors < size; number_colors++)
		{
			setup_colors(40);
		}
	}

private:

	void setup_colors(int number_colors)
	{
		int size = graph->nodes.size();

		for (int node = 0; node < size; node++)
		{
			for (int color = 0; color < number_colors; color++)
			{
				graph->nodes[node]->available_colors.push_back(1);
			}
		}
	}
};