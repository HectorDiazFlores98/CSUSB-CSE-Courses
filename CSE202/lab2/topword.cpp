#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;


//This function will check to make sure the current word is not a part of the "Common word list"
void checkCommWord(string &Temp, map<string,int> &WordCounter)
{

	//the vector will hold the refrences to the common words
	vector<string>CommonVect = {"the", "be", "to", "of", "and", "a",
	"in", "that", "have", "I", "it", "for",
	"not", "on", "with", "he", "as", "you",
	"do", "at", "this", "but", "his", "by",
	"from", "they", "we", "say", "her", "she",
	"or", "an", "will", "my", "one", "all",
	"would", "there", "their", "what", "so",
	"up", "out", "if", "about", "who", "get",
	"which", "go", "me", "when", "make", "can",
	"like", "time", "no", "just", "him", "know",
	"take", "people", "into", "year", "your",
	"good", "some", "could", "them", "see",
	"other", "than", "then", "now", "look",
	"only", "come", "its", "over", "think",
	"also", "back", "after", "use", "two",
	"how", "our", "work", "first", "well",
	"way", "even", "new", "want", "because",
	"any", "these", "give", "day", "most",
	"us", "is", "are"
	};
	
	//if the temp word is a common word it will trigger the bool
	bool commonWord = false;
	
	//go through the vector of common words
	for(int i = 0; i <= CommonVect.size()-1;i++)
	{
		//if the temporary word is part of the common words, do nothing.
		if(Temp == CommonVect[i])
		{
			commonWord = true;
			break;
		}
	
	}
	//if it is not a common word the count will go up by one
	if(commonWord == false)
	{
		WordCounter[Temp]+=1;
	}
		
	
}

//this function will go through the map and check to see which word in the map is the highest counted word
void checkHighest(map<string,int>&WordCounter, string &currentHighest, int &counter)
{

	//this iterator will go though the map and compare it to the 'counter'
	for(std::map<string,int>::iterator IT = WordCounter.begin(); IT !=WordCounter.end();IT++)
	{
	    //if the counter is less than current object in the index it will be set to it
		if(counter < IT->second)
		{
			currentHighest = IT->first;
			counter = IT->second;

		}
	}
}



int main()
{
	//this will be the temp string to hold the current word
	string Temp = "";
	//this will hold the current highest occuring word
	string currentHighest ="";
	
	//this map will hold all the words that are occuring in the string that are not part of the common words vector
	map<string,int>WordCounter;
	
	int counter = 0 ;
	string Test;
	
	getline(cin, Test);
	//this iterator will split up the string into words
		for(string::iterator it=Test.begin(); it != Test.end(); it++)
		{
		    //if it is not a space push back the char
			if(!isspace(*it) or it == Test.end()-1)
			{
			    Temp.push_back(*it);
			}
			else
			{
			    checkCommWord(Temp,WordCounter);
			    Temp.clear();
			}
		}
	
	//checks one last time for a common word and checks the highest word.
	checkCommWord(Temp,WordCounter);
	checkHighest(WordCounter, currentHighest, counter);
	
	cout << "The highest counted non common word is: " << currentHighest<< "\n";
	cout << "It appears: " << WordCounter[currentHighest] << " times\n";
}