#include <vector>

struct Node {
	int id;
	std::vector<int> neighbours;
	std::vector<int> available_colors;
};