//  Problem URL : https://app.codesignal.com/interview-practice/task/kfus4H4CSZBjCukwo
//  Difficulty : Hard
// Time Complex Prediction : O(m log m)
//  Note : Graph, Kruskal's Algorithm, Union_Find
#include "interview-practice.h"

namespace networkWires
{
	struct Union_Find
	{
		std::vector<int> parent;
		std::vector<int> height;

		Union_Find(int n) :height(n, 1)
		{
			parent.reserve(n);
			for (int i = 0; i < n; i++)
				parent[i] = i;
		}

		int find(int n)
		{
			if (parent[n] == n)
				return n;
			else
				return find(parent[n]);
		}

		void join(int x, int y)
		{
			int parent_x = find(x);
			int parent_y = find(y);

			if (height[parent_x] < height[parent_y])
			{
				height[parent_y] += height[parent_x];
				parent[parent_x] = parent_y;
			}
			else
			{
				height[parent_x] += height[parent_y];
				parent[parent_y] = parent_x;
			}
		}
	};

	struct Edge
	{
		Edge(int x, int y, int w) :n1(x), n2(y), weight(w) {}
		int n1;
		int n2;
		int weight;

		bool operator<(const Edge& re) const
		{
			return weight < re.weight;
		}
	};

	int networkWires(int n, std::vector<std::vector<int>> wires)
	{
		Union_Find union_find(n);
		std::vector<Edge> edges;
		int answer = 0;

		for (int i = 0; i < wires.size(); i++)
		{
			edges.push_back(Edge(wires[i][0], wires[i][1], wires[i][2]));
		}

		std::sort(edges.begin(), edges.end());

		for (int i = 0; i < edges.size(); i++)
		{
			const Edge& edge = edges.at(i);

			if (union_find.find(edge.n1) != union_find.find(edge.n2))
			{
				union_find.join(edge.n1, edge.n2);
				answer += edge.weight;
			}
		}

		return answer;
	}

}