#include <vector>

struct Node {
	int id;
	std::vector<int> neightbours;
	std::vector<int> available_colors;
};