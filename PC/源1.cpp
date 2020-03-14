#include <vector>
#include <queue>
#include <iostream>
#include <string>

using Map = std::vector<std::vector<char>>;

char stepArr[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct Node
{
	int x;
	int y;
	int step;
	Node(int x1, int y1, int step1) :x(x1), y(y1), step(step1) {}
};

int BFS(Map& map, int n)
{
	Node node(1, 1, 0);
	std::queue<Node>q;
	while (!q.empty())q.pop();
	q.push(node);
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (node.x == n - 2 && node.y == n - 2)
		{
			return node.step;
		}
		map[node.x][node.y] = 2;
		for (auto& i : stepArr)
		{
			int x = node.x + i[0];
			int y = node.y + i[1];
			if (x >= 0 && y >= 0 && x < n && y < n && map[x][y] == 0)
			{
				map[x][y] = 2;
				Node next(x, y, node.step + 1);
				q.push(next);
			}
		}
	}
	return-1;
}

int main(int argc, char* argv[])
{
	int n;
	std::cin >> n;
	Map map = Map(n, std::vector<char>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cin >> map[i][j];
		}
	}
	auto r = BFS(map, n);
	std::cout << (r == -1 ? "No solution" : std::to_string(r)) << std::endl;
}
