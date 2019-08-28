//  Problem URL : https://app.codesignal.com/interview-practice/task/mkobsYSSQo3JpvYNN
//  Difficulty : Hard
//  Time Complex Prediction : O(hw) h : matrix's height, w : matrix's width
//  Note : Dynamic Programming, Bottom-up strategy
#include "interview-practice.h"

int maximalSquare(std::vector<std::vector<char>> matrix)
{
	if (matrix.empty())
		return 0;

	const int height = matrix.size();
	const int width = matrix.front().size();
	std::vector<std::vector<int>> matrix_int(height, vector<int>(width));

	int answer = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrix_int[i][j] = matrix[i][j] - '0';
			answer = max(matrix_int[i][j], answer);
		}
	}

	std::vector<std::vector<int>> dp(matrix_int);

	for (int i = 1; i < height; i++)
	{
		for (int j = 1; j < width; j++)
		{
			if (dp[i][j] == 0)
				continue;

			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			answer = max(dp[i][j], answer);
		}
	}

	return answer * answer;
}
