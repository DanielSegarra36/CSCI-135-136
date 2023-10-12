/*
    Author: Daniel Segarra
    Course: 135
    Instructor: Raffi Khatchadourian
    Assignment: Project 3

    1. This program asks the user for a sentence.
    2. The sentence is then tested to see if it meets
      a certain criteria/English standard:
        Case 1 - <noun><verb><noun>
        Case 2 - <noun><verb><adjective><noun>
        Case 3 - <pronoun><verb><noun>
        Case 4 - <pronoun><verb><adjective><noun>
        Case 5 - <pronoun><verb><pronoun>
    3. A message of confirmation is printed to the screen
      if the sentence meets a certain criteria.
      OR
      A message stating that the sentence is not a legal
      English sentence is printed to the screen, in the case
      that the sentence fails to meet any of the criteria.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// forward declarations (So that these classes may have access to Sentence class)
class Noun;
class Pronoun;
class Adjective;
class Verb;

// CLASSES
class Sentence{
  public:
    friend class Noun;
    friend class Pronoun;
    friend class Adjective;
    friend class Verb;
    // Four ways to initialize sentence
    Sentence(); // default: sentence is empty
    Sentence(string); // constructor that takes string var to set as sentence
    void Prompt(); // Prompt that takes user input
    // Initialize object's sentence via extraction operator ">>"
    friend istream& operator >>(istream& inputStream, Sentence& obj);
    /*
      UserSentVect():
      Reads through input until first non-whitespace. (Marks beginning of first word).
      Stores that word in wordsFromSent vector.
      Continues that process until end of input/sentence.
    */
    vector<string> UserSentVect();
    void lowercase(); // Takes uppercase characters and sets them to their lowercase equivalents
    int WordCount(); // accesses wordsFromSent's vector size to determine word count
    friend ostream& operator <<(ostream& outputStream, const Sentence& obj);
  private:
    string sentence;
    vector<string> wordsFromSent; // stores words from sentence individually
};
class Noun{
  public:
    Noun(); // reads nouns file adn stores all words in vector
    bool nounCheck(int wordPlace, Sentence obj);
  private:
    vector <string> nounBank;
};
class Pronoun{
  public:
    Pronoun(); // reads pronouns file adn stores all words in vector
    bool pronounCheck(int wordPlace, Sentence obj);
  private:
    vector <string> pronounBank;
};
class Adjective{
  public:
    Adjective(); // reads adjectives file adn stores all words in vector
    bool adjectiveCheck(int wordPlace, Sentence obj);
  private:
    vector <string> adjectiveBank;
};
class Verb{
  public:
    Verb(); // reads verbs file adn stores all words in vector
    bool verbCheck(int wordPlace, Sentence obj);
  private:
    vector <string> verbBank;
};

int main(){
  Sentence userSent; // create object
  userSent.Prompt(); // ask for sentence - store in obj
  userSent.lowercase(); // lowercase sentence
  Noun userNoun;
  Pronoun userPronoun;
  Adjective userAdjective;
  Verb userVerb;
  userSent.UserSentVect();
  // Probably not necessary but made if/else if statements more readable.
  bool case1 = (userNoun.nounCheck(1,userSent))&&(userVerb.verbCheck(2,userSent))
                &&(userNoun.nounCheck(3,userSent));
  bool case2 = (userNoun.nounCheck(1,userSent))&&(userVerb.verbCheck(2,userSent))
                &&(userAdjective.adjectiveCheck(3,userSent))&&(userNoun.nounCheck(4,userSent));
  bool case3 = (userPronoun.pronounCheck(1,userSent))&&(userVerb.verbCheck(2,userSent))
                &&(userNoun.nounCheck(3,userSent));
  bool case4 = (userPronoun.pronounCheck(1,userSent))&&(userVerb.verbCheck(2,userSent))
                &&(userAdjective.adjectiveCheck(3,userSent))&&(userNoun.nounCheck(4,userSent));
  bool case5 = (userPronoun.pronounCheck(1,userSent))&&(userVerb.verbCheck(2,userSent))
                &&(userPronoun.pronounCheck(3,userSent));

  if (userSent.WordCount()==3){
      if (case1)
        cout << "Your sentence is a legal sentence by rule 1.\n";
      else if (case3)
        cout << "Your sentence is a legal sentence by rule 3.\n";
      else if (case5)
          cout << "Your sentence is a legal sentence by rule 5.\n";
      else cout << "Your sentence is not a legal sentence.\n";
  }
  else if (userSent.WordCount()==4){
      if (case2)
        cout << "Your sentence is a legal sentence by rule 2.\n";
      else if (case4)
        cout << "Your sentence is a legal sentence by rule 4.\n";
      else cout << "Your sentence is not a legal sentence.\n";
  }
  else cout << "Your sentence is not a legal sentence.\n";
}

// Sentence - CLASS DEFINITIONS
Sentence::Sentence(): sentence(""){/*string initialized as empty*/}

Sentence::Sentence(string sent): sentence(sent){}

void Sentence::Prompt(){
  cout << "Enter a sentence: ";
  getline(cin, sentence);
}

vector<string> Sentence::UserSentVect()
{
  int startWord = 0;
  int reader = 0;
  while (reader<sentence.length()){
    string wordToStore = ""; // resets to empty string per iteration
  // Loop that reads sentence until first non-whitespace character
    while((sentence[reader]==' ') || (sentence[reader]=='\t' && reader < sentence.length())){
      reader++;
    }
      startWord=reader;
  // Reader ends at first whitespace
    while(sentence[reader]!=' ' && sentence[reader]!='\t' && reader < sentence.length()){
      reader++;
    }
  // Uses index of first whitespace
  // Stores word character by character in a string
    for(int i = startWord; i<reader; i++){
      wordToStore+=sentence[i];
    }
  // adds word to vector
    wordsFromSent.push_back(wordToStore);
  // Loop that reads sentence until first non-whitespace character
    while((sentence[reader]==' ') || (sentence[reader]=='\t')){
      reader++;
    }
  // Reader is at next word
    startWord=reader;
  }
  return wordsFromSent;
}

void Sentence::lowercase() // words in file are all lowercase (comparisons are case sensitive)
{
  int x=0;
	while(x<sentence.length()){
		if(sentence[x]>='A' && sentence[x]<='Z'){
			sentence[x] += 0x20;
		}
		x++;
	}
}

int Sentence::WordCount(){
  return wordsFromSent.size();
}

ostream& operator <<(ostream& outputStream, const Sentence& obj) // outputs sentence from vector in sentence class
{
  for (int i=0;i<obj.wordsFromSent.size();i++)
    outputStream << obj.wordsFromSent[i] << " " ;
  return outputStream;
}

istream& operator >>(istream& inputStream, Sentence& obj){
  getline(inputStream, obj.sentence);
  return inputStream;
}

// Noun - CLASS DEFINITION
Noun::Noun(){
  string fileWord;
  // Opens Nouns
  ifstream nouns;
  nouns.open("nouns");
  if(nouns.fail()){
    cout << "\"nouns\" file failed to open.\n";
  }
  else{
    while (nouns>>fileWord)
      nounBank.push_back(fileWord);
  }
  nouns.close();
}

bool Noun::nounCheck(int wordPlace, Sentence obj){
  bool result = false;
  for (int count=0; count<nounBank.size(); count++){
    if (nounBank[count]==obj.wordsFromSent[wordPlace-1]){
      result = true;
      return result;
    }
  }
  return result;
}

// Pronoun - CLASS DEFINITION
Pronoun::Pronoun(){
  string fileWord;
  // Opens Pronouns
  ifstream pronouns;
  pronouns.open("pronouns");
  if(pronouns.fail()){
    cout << "\"pronouns\" file failed to open.\n";
  }
  else{
    while (pronouns>>fileWord)
      pronounBank.push_back(fileWord);
  }
  pronouns.close();
}

bool Pronoun::pronounCheck(int wordPlace, Sentence obj){
  bool result = false;
  for (int count=0; count<pronounBank.size(); count++){
    if (pronounBank[count]==obj.wordsFromSent[wordPlace-1]){
      result = true;
      return result;
    }
  }
  return result;
}

// Adjective - CLASS DEFINITION
Adjective::Adjective(){
  string fileWord;
  // Opens Adjectives
  ifstream adjectives;
  adjectives.open("adjectives");
  if(adjectives.fail()){
    cout << "\"adjectives\" file failed to open.\n";
  }
  else{
    while (adjectives>>fileWord)
      adjectiveBank.push_back(fileWord);
  }
  adjectives.close();
}

bool Adjective::adjectiveCheck(int wordPlace, Sentence obj){
  bool result = false;
  for (int count=0; count<adjectiveBank.size(); count++){
    if (adjectiveBank[count]==obj.wordsFromSent[wordPlace-1]){
      result = true;
      return result;
    }
  }
  return result;
}

// Verb - CLASS DEFINITION
Verb::Verb(){
  string fileWord;
  // Opens Verbs
  ifstream verbs;
  verbs.open("verbs");
  if(verbs.fail()){
    cout << "\"verbs\" file failed to open.\n";
  }
  else{
    while (verbs>>fileWord)
      verbBank.push_back(fileWord);
  }
  verbs.close();
}

bool Verb::verbCheck(int wordPlace, Sentence obj){
  bool result = false;
  for (int count=0; count<verbBank.size(); count++){
    if (verbBank[count]==obj.wordsFromSent[wordPlace-1]){
      result = true;
      return result;
    }
  }
  return result;
}
