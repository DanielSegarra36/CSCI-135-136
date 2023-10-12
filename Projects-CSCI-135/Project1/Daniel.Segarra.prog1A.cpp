/*
  Author: Daniel Segarra
  Course: 135
  Instructor: Eric Schweitzer
  Assignment: Project 1A

  This program asks the user for a sentence.
	The sentence is then tested to see if it meets
	a certain criteria/English standard.
	A message of confirmation is printed to the screen
	if the sentence meets a certain criteria.
	A message stating that the sentence is not a legal
	English sentence is printed to the screen, in the case
	that the sentence fails to meet any of the criteria.
*/
/*
	Test Cases:
		Various incorrect sentences were tested with
		non alphanumeric symbols, numbers, and words
		with mixed uppercase and lowercase letters.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Prompt(string&);
void lowercase(string&);
// Pre: Takes a standard sentence. (Not case sensitive)
// Post: Any capital letters from the English alphabet
//	will be converted to its equivalent lowercase form.
int WordCount(string sent);
// Pre: Takes a sentence of any length
// Post: Returns the amount of words (letter(s) separated by whitespaces)
//	in the sentence.
void ThreeWordSentence(string &a, string &b, string&c, string sent);
// Pre: Takes a sentence made up of no more and no less than three words.
//	Three string variables must be entered by the user to store the words.
// Post: Separtes the sentence into the four words and assigns them to the arguments.
void FourWordSentence(string &a, string &b, string &c, string &d, string sent);
// Pre: Takes a sentence made up of no more and no less than four words.
//	Four string variables must be entered by the user to store the words.
// Post: Separtes the sentence into the four words and assigns them to the arguments.
bool nouns(string);
bool pronouns(string);
bool adjectives(string);
bool verbs(string);
// For the preceeding four functions:
// Pre: Takes a string of no more and no less than one word (no whitespaces).
//	User must have the appropriate file for each function:
//		nouns, pronouns, adjectives, and verbs.
// Post: Returns true or false based on whether or not the argument matches
//	a word in the corresponding file.
string GetWord(string sentence, int &readerPos);

int main(){
	string sentence;
	Prompt(sentence);
	lowercase(sentence);
	int wordCount = WordCount(sentence);

	string word1, word2, word3, word4;

	switch (wordCount){
	case 3:
//		test 1,3,5
		ThreeWordSentence(word1, word2, word3, sentence);
		if (nouns(word1) && verbs(word2) && nouns(word3)){
			cout << "Your sentence is a legal sentence by rule 1.\n";
		}else if(pronouns(word1) && verbs(word2) && nouns(word3)){
			cout << "Your sentence is a legal sentence by rule 3.\n";
		}else if(pronouns(word1) && verbs(word2) && pronouns(word3)){
			cout << "Your sentence is a legal sentence by rule 5.\n";
		}
		else{
			cout << "Your sentence is not a legal sentence.\n";
		}
		break;
	case 4:
//		test 2,4
		FourWordSentence(word1, word2, word3, word4, sentence);
		if (nouns(word1) && verbs(word2) && adjectives(word3) && nouns(word4)){
			cout << "Your sentence is a legal sentence by rule 2.\n";
		}else if(pronouns(word1) && verbs(word2) && adjectives(word3) && nouns(word4)){
			cout << "Your sentence is a legal sentence by rule 4.\n";
		}
		else{
			cout << "Your sentence is not a legal sentence.\n";
		}
		break;
	default:
		cout << "Your sentence is not a legal sentence.\n";
	}
}

void Prompt(string &x){
	cout << "Enter a sentence\n";
	getline(cin, x);
}

void lowercase(string &changeMe){
	for (int count = 0; count < changeMe.length(); count++)
		if(changeMe[count]>='A' && changeMe[count]<='Z')
				changeMe[count] += 0x20;
}

int WordCount(string sent){
	int word = 0;
	int reader = 0;
	while(reader<sent.length()){
		while((sent[reader]==' ') || (sent[reader]=='\t'))
			reader++;
		// Reads until first whitespace/tab
		// Reader ends at first whitespace
		while(sent[reader]!=' ' && sent[reader]!='\t' && reader!=sent.length())
			reader++;
		word++;
		// Loop that reads sentence until first non-whitespace character
		while((sent[reader]==' ') || (sent[reader]=='\t'))
			reader++;
	}
	return word;
}

string GetWord(string sentence, int &readerPos){
	int startWord;
	string word = "";
	// Loop that reads sentence until first NON-WHITESPACE character
	// in case of whitespace at beginning of sentence
	// therefore the reader is at index of the beginning of a word
		while( sentence[readerPos]==' ' || sentence[readerPos]=='\t' )
			readerPos++;
		startWord = readerPos;
	// Reads sentence until first whitespace/tab (or end of sentence, if last word)
	// in other words it reads as long as the characters are non-whitespace chars
	// therefore the reader has read first entire word
		while( sentence[readerPos]!=' ' && sentence[readerPos]!='\t' && readerPos!=sentence.length() )
			readerPos++;
	// Uses index of first whitespace
	// Stores first word
		for(int i = startWord; i<readerPos; i++)
			word += sentence[i];
	return word;
}

void ThreeWordSentence(string &a, string &b, string&c, string sent){
	int reader = 0;
	a = GetWord(sent, reader);
	b = GetWord(sent, reader);
	c = GetWord(sent, reader);
}

void FourWordSentence(string &a, string &b, string &c, string &d, string sent){
	int reader = 0;
	a = GetWord(sent, reader);
	b = GetWord(sent, reader);
	c = GetWord(sent, reader);
	d = GetWord(sent, reader);
}

bool nouns(string word){
	string fileWord;
	ifstream nouns;
	nouns.open("nouns");
	if(nouns.fail())
		cout << "\"nouns\" file failed to open.\n";
	while (nouns>>fileWord)
		if(fileWord==word)
			return true;
	return false;
}

bool pronouns(string word){
	string fileWord;
	ifstream pronouns;
	pronouns.open("pronouns");
	if(pronouns.fail())
		cout << "\"pronouns\" file failed to open.\n";
	while (pronouns>>fileWord)
		if(fileWord==word)
			return true;
	return false;
}

bool adjectives(string word){
	string fileWord;
	ifstream adjectives;
	adjectives.open("adjectives");
	if(adjectives.fail())
		cout << "\"adjectives\" file failed to open.\n";
	while (adjectives>>fileWord)
		if(fileWord==word)
			return true;
	return false;
}

bool verbs(string word){
	string fileWord;
	ifstream verbs;
	verbs.open("verbs");
	if(verbs.fail())
		cout << "\"verbs\" file failed to open.\n";
	while (verbs>>fileWord)
		if(fileWord==word)
			return true;
	return false;
}
