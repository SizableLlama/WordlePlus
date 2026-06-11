#include <iostream>
//#include <SDL2>
//#include <random>
#include <vector>
#include <string>
//#include <array>
#include <cctype>

using namespace std;
bool in(char comparitor, const string& input);
bool in(char comparitor,const vector<char>& input);
string toLower(const string& String);
string printVector(const vector<char>& v);

string wordGenerator(){
	vector<string> wordArray={"apple", "beach", "cloud", "dance", "eagle", "flame", "grape", "house", "image", "juice", "koala", "lemon", "music", "night", "ocean", "piano", "queen", "river", "smile", "table", "uncle", "voice", "water", "xenon",
               "yacht", "zebra", "alarm", "bread", "candy", "dream", "earth", "field", "ghost", "heart", "ivory", "jelly", "knife", "light", "mouse", "nurse", "onion", "paper", "quiet", "radio", "stone", "tiger", "under", "vivid",
               "whale", "young"};
	int pos = rand() % 51;
	string word=wordArray[pos];
	cout<<word<<" \n";
	return word;
};

bool guessCheckLen(string& guess){
	if(guess.length() == 5){
		//cout<<"Invalid guess.\n";
		return true;
	}
	else{
		return false;
	}
}

void appendingArrays(string word,string guess, vector<char>& correctArray, vector<char>& wrongPlaceArray,vector<char>& wrongLetterArray){
	//x<6 instead of 7, since 0? 0,1,2,3,4,5 could also be 5
	for(int x=0;x<5;x++){
		if(guess[x]==word[x]){
			correctArray.at(x)=guess[x];
		}
		else if(in(guess[x],word)){
			if(!in(guess[x],wrongPlaceArray)){
				wrongPlaceArray.push_back(guess[x]);
			}
		}
		else{
			if(!in(guess[x],wrongLetterArray)){
				wrongLetterArray.push_back(guess[x]);
			}
		}
	}

}

vector<char> alphabet={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(){
	string word = wordGenerator();

	int counter=0;
	vector<char> correctArray={'_','_','_','_','_'};
	vector<char> wrongPlaceArray={};
	vector<char> wrongLetterArray={};
	string guess;
	while(counter<6){
		cout<<"Please guess a five letter word.\n:";
		cin>>guess;
		guess=toLower(guess);
		//Made it false, could work? Hopefully?
		if(!guessCheckLen(guess)){
			cout<<"Invalid guess.\n";
			continue;
		};

		appendingArrays(word,guess,correctArray,wrongPlaceArray,wrongLetterArray);
		counter++;




		cout<<"Correct letter correct place: "<<printVector(correctArray)<<"\nCorrect letter wrong place: "<<printVector(wrongPlaceArray)<<"\n Wrong letter: "<<printVector(wrongLetterArray);

		if (guess==word){
			cout<<"You win in "<<counter<<" attempts!\n";
			return 0;
		}
	if (counter==6){
		cout<<"You lose! The word was "<<word<<".\n";
	}

	}
	return 0;
}

bool in(char comparitor,const vector<char>& input){
	for(size_t x=0; x<input.size(); x++){
		if(comparitor==input.at(x)){
			return true;
		};
	};
	return false;
}

bool in(char comparitor, const string& input){
	for(size_t x=0; x<input.length(); x++){
		if(comparitor==input.at(x)){
			return true;
		};
	};
	return false;
}





string toLower(const string& String){
	string lowerString;
	for(size_t x=0; x<String.length(); x++){
		lowerString=lowerString + (char)tolower(String[x]);
	}
	return lowerString;
}

string printVector(const vector<char>& v){
	string String;
	for(size_t x=0; x < v.size(); x++){
        	String=String+v.at(x);
			//std::print("{}", v[x]);
    };
	cout<<String;
	return String;
};
