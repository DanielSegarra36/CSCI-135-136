/*
  Author: Daniel Segarra
  Course: 136
  Instructor: Ilya Korsunsky
  Assignment: Lab 11

  This program does checks a user-inputed sentence and checks
  to see if it is well-formed by the following standard:
    True:
      If every opening bracket has a matching closing bracket
      or if the are no brackets at all (nothing = nothing)
    False:
      If an opening/closing bracket is missing it's corresponding
      opening/closing bracket.
*/

#include <iostream>
#include <string>
using namespace std;

// Post: Returns true if charcter is a opening or closing bracket
bool isBracket(char c);

// Post: Returns true if sentence is well-formed and false if not.
bool wellFormed(string s);

// Post:
// Returns true: if the first character is an opening bracket and
//   if the last character is its corresponding closing bracket.
// Returns false: if first and last characters of the string
//   are not corresponding open/close brackets.
bool match(string s);

// Pre: the string is already well-formed.
// Post: returns the amount of bracket pairs in the string
int nestLevel(string s);

/****************************************************************************************************/
// 																							MAIN																								//
/****************************************************************************************************/

int main(){
  // system("open https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  // TASK 0 - detect if sentence if well-formed
  string sentence;
  cout << "Enter a sentence using only brackets: ";
  getline (cin, sentence);
  if (wellFormed(sentence))
    cout << "Your sentence is well-formed!\n";
  else
    cout << "Your sentence is NOT well-formed...\n";
  // TASK 1 - Find nest-level of sentence
  cout << "Nest-level of your sentence: " << nestLevel(sentence) << endl;
  // TASK 2 - modify TASK 0 to ignore non-bracket characters (DONE)
} /**************************************		END OF MAIN		*******************************************/


/****************************************************************************************************/
// 																			FUNCTION DEFINITIONS																				//
/****************************************************************************************************/

// TASK 0 & 2(modified version of TASK 0)
bool wellFormed(string s){
  if (s=="") // if string is empty
    return true;

  // first and last characters are corresponding open/close brackets,
  // check next two
  if (match(s))
    return (wellFormed(s.substr(1,s.length()-2)));

  // if FIRST char is not a bracket and string is not just one char
  if ( !isBracket(s[0]) && s.length()!=1 )
    return (wellFormed(s.substr(1,s.length()-1)));

  // if LAST char is not a bracket and string is not just one char
  if ( !isBracket(s[s.length()-1])  && s.length()!=1)
    return (wellFormed(s.substr(0,s.length()-1)));

  // if only one char but not any sort of bracket char
  if ( !isBracket(s[0]) && s.length() == 1 )
    return true;

  return false;
}

bool isBracket(char c){
  return c == '{' || c == '[' || c == '(' || c == '<' ||
         c == '}' || c == ']' || c == ')' || c == '>' ;
}

bool match(string s){
  int lastChar = s.length()-1;
  return ( s[0] == '{' && s[lastChar] == '}' )  ||  ( s[0] == '[' && s[lastChar] == ']' )  ||
         ( s[0] == '(' && s[lastChar] == ')' )  ||  ( s[0] == '<' && s[lastChar] == '>' ) ;
}

int nestLevel(string s){
  static int count = 0;
  // if empty or no further nesting possible
  if (s==""){
    int total = count;
    count = 0; // reset count (for future calls since count is static)
    return total;
  }
  count++;
  return nestLevel(s.substr(1,s.length()-2));
}

// Alternative:
// void nestLevel(string s, int &counter);
//
// int nestLevel(string s){
//   int count = 0;
//   nestLevel(s, count);
//   return count;
// }
//
// void nestLevel(string s, int &counter){
//   if (s=="") return;
//   counter++;
//   nestLevel(s.substr(1,s.length()-2), counter);
// }

////// TEST CASES
// string test = "<{[()]}>";
// string test1 = "";
// string test2 = "<{[((()))]}>";
// string test3 = "<>";
// string test4 = "<{[(<)]}>";
// string test5 = "aaaa<{[()]}>";
// string test6 = "aaaa<{[()]}>aa";
// string test7 = "aaa<{[()]}>aaaaaaaaa";
// string test8 = "aaa<{[(<)]}>aaaaaaaaa";
// string test9 = "aaa<{a[(a)]}>aaaaaaaaa";
