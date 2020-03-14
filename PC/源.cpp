#include <vector>
#include <queue>
#include <iostream>
#include <string>

using Map = std::vector<std::vector<int>>;

int stepArr[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct Node
{
	int x;
	int y;
	int step;
	Node(int x1, int y1, int step1) :x(x1), y(y1), step(step1) {}
};

int BFS(Map& map, Map& visit, int n)
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
		visit[node.x][node.y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int x = node.x + stepArr[i][0];
			int y = node.y + stepArr[i][1];
			if (x >= 0 && y >= 0 && x < n && y < n && visit[x][y] == 0 && map[x][y] == 0)
			{
				visit[x][y] = 1;
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
	Map map = Map(n, std::vector<int>(n, 0));
	Map visit = Map(n, std::vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cin >> map[i][j];
		}
	}
	auto r = BFS(map, visit, n);
	std::cout << (r == -1 ? "No solution" : std::to_string(r)) << std::endl;
}
