//
//  wordBoggle.cpp
//  CodeSignal
//
//  Created by 차경준 on 24/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/v3uf4PGocp2CH62nn
//  Difficulty : Medium
//  Note : Backtracking, Recursion

#include <algorithm>
#include "interview-practice.h"

bool rec(vector<vector<char>>& board, string& word, vector<vector<bool>> visited, int xpos, int ypos, int index)
{
    int height = board.size();
    int width = board.front().size();
    int length = word.length();
    
    if(index >= length ||
       xpos >= height ||
       ypos >= width ||
       xpos < 0 ||
       ypos < 0 ||
       visited[xpos][ypos])
        return false;
    
    if(word.at(index) == board[xpos][ypos])
    {
        if(index == length -1)
            return true;
        else
        {
            index++;
            visited[xpos][ypos] = true;
            cout << board[xpos][ypos] << endl;
            return rec(board, word, visited, xpos+1, ypos, index) ||
            rec(board, word, visited, xpos, ypos+1, index) ||
            rec(board, word, visited, xpos+1, ypos+1, index) ||
            rec(board, word, visited, xpos-1, ypos, index) ||
            rec(board, word, visited, xpos, ypos-1, index) ||
            rec(board, word, visited, xpos-1, ypos-1, index) ||
            rec(board, word, visited, xpos+1, ypos-1, index) ||
            rec(board, word, visited, xpos-1, ypos+1, index);
        }
    }
    else
        return false;
    
}

std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words)
{
    vector<string> answer;
    int height = board.size();
    int width = board.front().size();
    
    for(int i=0; i<words.size(); i++)
    {
        bool found = false;
        string& word = words.at(i);
        
        for(int x=0; x<height; x++)
        {
            for(int y=0; y<width; y++)
            {
                vector<vector<bool>> visited(height, vector<bool>(width, false));
                
                if(rec(board, word, visited, x, y, 0))
                {
                    found = true;
                    break;
                }
            }
            
            if(found)
            {
                answer.push_back(word);
                break;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
