//
//  Problem URL : https://app.codesignal.com/interview-practice/task/yXDg4rAk9ooEjLjdj
//  Difficulty : Easy
// Time Complex Prediction : O(n)
//
#include "interview-practice.h"

std::string amendTheSentence(std::string s) {
	std::string answer = "";

	if (s.empty())
		return answer;

	answer += tolower(s.front());

	for (int i = 1; i < s.size(); i++)
	{
		if (islower(s.at(i)))
		{
			answer += s.at(i);
		}
		else
		{
			answer += " ";
			answer += tolower(s.at(i));
		}
	}

	return answer;
}