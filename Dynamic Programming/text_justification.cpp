// Text Justification - DP Approach
// Author - rudrajit1729

#include<bits/stdc++.h>
#define INF 99999999
using namespace std;

int total(vector<string> line, int i, int j)
{
	string temp = "";
	for(int x = i; x <= j;x++)
		temp += line[x] + " ";
	return temp.size() - 1;
}

int badness(vector<string> line, int i, int j, int page_width)
{
	int tot = total(line, i, j);
	if(tot > page_width)
		return INF;
	else
		return int(pow(page_width - tot, 3));
}

void pretty(vector<string> words, int page_width)
{
	int n = words.size();
	int DP[n+1];
	DP[0] = 0;
	for(int i = 1; i < n; i++)
	{
		vector<int> temp;
		for (int k = 0; k < i; k++)
		{
			int cost = DP[k] + badness(words, k, i, page_width);
			temp.push_back(cost);
		}
		 
		DP[i] = *min_element(temp.begin(), temp.end());
		
	}

	int min = INF;
	for(int i = 0; i <= n; i++)
	{
		if (min > DP[i])
		{
			min = DP[i];
			if(i!=0)
				cout<<words[i-1]<<" ";
		}	
		else
		{
			min = DP[i];
			cout<<"\n"<<words[i-1]<<" ";
		}

	}
}


vector<string> tokenize(string str) 
{ 
   string word = "";
   vector<string> words; 
   for (auto x : str) 
   { 
       if (x == ' ') 
       { 
           words.push_back(word);
           //cout<<word<<endl;
           word = ""; 
       } 
       else
       { 
           word = word + x; 
       } 
   }  
   words.push_back(word);
   return words; 
} 


int main()
{
	string text = "I wanted to smell that burnt midnight again, I wanted to feel that wind. It was a secret wanting, like a song I couldn\'t stop humming, or loving someone I could never have.";

	//pretty(tokenize(text), 51);
	string chap = "One of the most significant changes in Python 3 is that print is turned into a function. In Python 2.6, it is also possible to use print as a function if you include the statement from __future__ import print_function in each module where used. The print() function works almost exactly the same as the print statement described in the previous section.";
	pretty(tokenize(chap), 60);
}
