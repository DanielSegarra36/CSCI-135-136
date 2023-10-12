/*
  Author: Daniel Segarra
  Course: 135
  Instructor: Eric Schweitzer
  Assignment: Project 1B

  This program reads a file, by the name of engsents,
	line by line.
	Each line is then tested to see if it meets
	a certain criteria/English standard.
	If the line is a valid sentence in English,
	then the sentence is translated into Elbonian
	and copied into a new file named elbsents.
	If the sentence does not meet the criteria for a
	legal English sentence then it cannot be translated
	into Elbonian. In this case, a line stating that an illegal
	sentence was encountered is written into the elbsents file.
*/
/*
	Test Cases:
		Various incorrect sentences were tested with
		non alphanumeric symbols, numbers, and words
		with mixed uppercase and lowercase letters.
		These test cases can be found in the engsents file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void lowercase(string&);
// Pre: Takes a standard sentence. (Not case sensitive)
// Post: Any capital letters from the English alphabet
//	will be converted to its equivalent lowercase form.
int WordCount(string sent);
// Pre: Takes a sentence of any length
// Post: Returns the amount of words (letter(s) separated by whitespaces)
//	in the sentence.
void ThreeWordSentence(string &a, string &b, string&c, string &sent);
// Pre: Takes a sentence made up of no more and no less than three words.
//	Three string variables must be entered by the user to store the words.
// Post: Separtes the sentence into the four words and assigns them to the arguments.
void FourWordSentence(string &a, string &b, string &c, string &d, string &sent);
// Pre: Takes a sentence made up of no more and no less than four words.
//	Four string variables must be entered by the user to store the words.
// Post: Separtes the sentence into the four words and assigns them to the arguments.
bool nouns(string&);
bool pronouns(string&);
bool adjectives(string&);
bool verbs(string&);
// For the preceeding four functions:
// Pre: Takes a string of no more and no less than one word (no whitespaces).
//	User must have the appropriate file for each function:
//		nouns, pronouns, adjectives, and verbs.
// Post: Returns true or false based on whether or not the argument matches
//	a word in the corresponding file.
string elbConcat(string &adj, string &noun);
// Pre: Takes an adjective and noun to concatenate
//	for the proper Elbonian translation.
// Post: Returns the proper Elbonian translation of the adjective and noun.

int main(){
// Open both files
	ifstream english;
	english.open("engsents");
	if(english.fail()){
		cout << "\"engsents\" file failed to open.\n";
	}
	ofstream elbonian;
	elbonian.open("elbsents");

	string sentence;
	int wordCount;

	while(getline(english, sentence)){
		string originalSentence = sentence;
		lowercase(sentence);
		string word1, word2, word3, word4;
		wordCount = WordCount(sentence);

		switch (wordCount){
		case 3:
	//		test 1,3,5
			ThreeWordSentence(word1, word2, word3, sentence);
			if (nouns(word1) && verbs(word2) && nouns(word3)){
				string word1, word2, word3, word4;
				ThreeWordSentence(word1, word2, word3, originalSentence);
				elbonian << word2 + " " + word1 + " " + word3 << endl;
			}
			else if(pronouns(word1) && verbs(word2) && nouns(word3)){
				string word1, word2, word3, word4;
				ThreeWordSentence(word1, word2, word3, originalSentence);
				elbonian << word2 + " " + word1 + " " + word3 << endl;
			}
			else if(pronouns(word1) && verbs(word2) && pronouns(word3)){
				string word1, word2, word3, word4;
				ThreeWordSentence(word1, word2, word3, originalSentence);
				elbonian << word2 + " " + word1 + " " + word3 << endl;
			}
			else{
				elbonian << "Illegal sentence found.\n";
			}
			break;
		case 4:
	//		test 2,4
			FourWordSentence(word1, word2, word3, word4, sentence);
			if (nouns(word1) && verbs(word2) && adjectives(word3) && nouns(word4)){
				string word1, word2, word3, word4;
				FourWordSentence(word1, word2, word3, word4, originalSentence);
				elbonian << word2 + " " + word1 + " " + elbConcat(word3,word4) << endl;
			}
			else if(pronouns(word1) && verbs(word2) && adjectives(word3) && nouns(word4)){
				string word1, word2, word3, word4;
				FourWordSentence(word1, word2, word3, word4, originalSentence);
				elbonian << word2 + " " + word1 + " " + elbConcat(word3,word4) << endl;
			}
			else{
				elbonian << "Illegal sentence found.\n";
			}
			break;
		default:
			elbonian << "Illegal sentence found.\n";
		}
	}

}

void lowercase(string &changeMe){
	int x=0;
	while(x<changeMe.length()){
		if(changeMe[x]>='A' && changeMe[x]<='Z'){
			changeMe[x] += 0x20;
		}
		x++;
	}
}

int WordCount(string sent){
	int word = 0;
	int reader = 0;
	while(reader<sent.length()){
// Reads until first whitespace/tab
// Reader ends at first whitespace
		while(sent[reader]!=' ' && sent[reader]!='\t' && reader!=sent.length()){
			reader++;
		}
		word++;
// Loop that reads sentence until first non-whitespace character
		while((sent[reader]==' ') || (sent[reader]=='\t')){
			reader++;
		}
	}
	return word;
}

void ThreeWordSentence(string &a, string &b, string&c, string &sent){
	int startWord = 0;
	int reader = 0;
// Reads until first whitespace/tab (MUST BE A CHARACTER)
// Reader ends at first whitespace
	while(sent[reader]!=' ' && sent[reader]!='\t'){
		reader++;
	}
// Uses index of first whitespace
// Stores first word
	for(int i = 0; i<reader; i++){
		a+=sent[i];
	}
// Loop that reads sentence until first non-whitespace character
	while((sent[reader]==' ') || (sent[reader]=='\t')){
		reader++;
	}
// Reader is at second word
	startWord=reader;
// Reads until next whitespace
	while(sent[reader]!=' ' && sent[reader]!='\t'){
		reader++;
	}
// Stores second word
	for(int i = startWord; i<reader; i++){
		b+=sent[i];
	}
// Loop that reads sentence until first non-whitespace character
	while((sent[reader]==' ') || (sent[reader]=='\t')){
		reader++;
	}
// Reader is at third word
	startWord=reader;
// Reads until next whitespace
	while(sent[reader]!=' ' && sent[reader]!='\t' && reader!=sent.length()){
		reader++;
	}
// Stores third word
	for(int i = startWord; i<=reader-1; i++){
		c+=sent[i];
	}
}

void FourWordSentence(string &a, string &b, string &c, string &d, string &sent){
	int startWord = 0;
	int reader = 0;
// Reads until first whitespace/tab (MUST BE A CHARACTER)
// Reader ends at first whitespace
	while(sent[reader]!=' ' && sent[reader]!='\t'){
		reader++;
	}
// Uses index of first whitespace
// Stores first word
	for(int i = 0; i<reader; i++){
		a+=sent[i];
	}
// Loop that reads sentence until first non-whitespace character
	while((sent[reader]==' ') || (sent[reader]=='\t')){
		reader++;
	}
// Reader is at second word
	startWord=reader;
// Reads until next whitespace
	while(sent[reader]!=' ' && sent[reader]!='\t'){
		reader++;
	}
// Stores second word
	for(int i = startWord; i<reader; i++){
		b+=sent[i];
	}
// Loop that reads sentence until first non-whitespace character
	while((sent[reader]==' ') || (sent[reader]=='\t')){
		reader++;
	}
// Reader is at third word
	startWord=reader;
// Reads until next whitespace
	while(sent[reader]!=' ' && sent[reader]!='\t'){
		reader++;
	}
// Stores third word
	for(int i = startWord; i<reader; i++){
		c+=sent[i];
	}
// Loop that reads sentence until first non-whitespace character
	while((sent[reader]==' ') || (sent[reader]=='\t')){
		reader++;
	}
// Reader is at fourth word
	startWord=reader;
// Reads until next whitespace
	while(sent[reader]!=' ' && sent[reader]!='\t' && reader!=sent.length()){
		reader++;
	}
// Stores third word
	for(int i = startWord; i<reader; i++){
		d+=sent[i];
	}
}

bool nouns(string &word){
	bool result = false;
	string fileWord;
// Opens Nouns
	ifstream nouns;
	nouns.open("nouns");
	if(nouns.fail()){
		cout << "\"nouns\" file failed to open.\n";
	}
	while (nouns>>fileWord){
		if(fileWord==word){
			result = true;
			return result;
		}
	}
	nouns.close();
	return result;

}

bool pronouns(string &word){
	bool result = false;
	string fileWord;
// Opens Pronouns
	ifstream pronouns;
	pronouns.open("pronouns");
	if(pronouns.fail()){
		cout << "\"pronouns\" file failed to open.\n";
	}
	while (pronouns>>fileWord){
		if(fileWord==word){
			result = true;
			return result;
		}
	}
	pronouns.close();
	return result;

}

bool adjectives(string &word){
	bool result = false;
	string fileWord;
// Opens Adjectives
	ifstream adjectives;
	adjectives.open("adjectives");
	if(adjectives.fail()){
		cout << "\"adjectives\" file failed to open.\n";
	}
	while (adjectives>>fileWord){
		if(fileWord==word){
			result = true;
			return result;
		}
	}
	adjectives.close();
	return result;

}

bool verbs(string &word){
	bool result = false;
	string fileWord;
// Opens Verbs
	ifstream verbs;
	verbs.open("verbs");
	if(verbs.fail()){
		cout << "\"verbs\" file failed to open.\n";
	}
	while (verbs>>fileWord){
		if(fileWord==word){
			result = true;
			return result;
		}
	}
	verbs.close();
	return result;
}

string elbConcat(string &adj, string &noun){
	string concatWord;
	string adjEnd;
	for(int j=1; j<adj.length();j++){
		adjEnd+=adj[j];
	}
	concatWord = adj[0] + noun + adjEnd;
	return concatWord;
}
