/*
    FILE: 02_String_Functions_Study_Notes.cpp
    TOPIC: string functions, substrings, finding text, replacing text, and simple tests.

    Main idea:
    Each function takes a string, performs one focused operation, and returns the result.
    The test section at the bottom checks whether each function produces the expected output.
*/

#include <iomanip>   // setw, left, right: used to align test output
#include <iostream>  // cout
#include <string>    // string class
#include <algorithm> // replace algorithm

using namespace std;

void runAllTests();

/*
    Passing strings:
    Your original code used const string STR.
    That works, but it copies the string into the function.

    This rewritten version uses const string& STR.
    const = the function will not modify STR.
    & = pass by reference, so C++ does not copy the whole string.
*/

int stringLength(const string& STR) {
    // .length() returns how many characters are in the string.
    return static_cast<int>(STR.length());
}

char charAt(const string& STR, int IDX) {
    // STR[IDX] gets the character at index IDX.
    // Indexes start at 0, not 1.
    // Example: "Cat" -> C is index 0, a is index 1, t is index 2.
    return STR[IDX];
}

string stringAppend(const string& LEFT, const string& RIGHT) {
    // + joins two strings together.
    return LEFT + RIGHT;
}

string stringInsert(const string& STR, const string& TO_INSERT, int IDX) {
    // Make a copy because STR is const and cannot be changed directly.
    string result = STR;

    // insert(position, text) inserts TO_INSERT before the character at IDX.
    result.insert(IDX, TO_INSERT);
    return result;
}

int stringFind(const string& STR, char C) {
    // find returns the index of the first match.
    // If it does not find the character, it returns string::npos.
    size_t pos = STR.find(C);

    if (pos == string::npos) {
        return -1;
    }

    return static_cast<int>(pos);
}

string stringSubstring(const string& STR, int IDX, int LEN) {
    // substr(start, length) returns part of a string.
    // Example: "natural" from "Such a natural mystic" starts at index 7 and has length 7.
    return STR.substr(IDX, LEN);
}

string stringReplace(const string& STR, const string& TEXT_TO_REPLACE, const string& REPLACE_WITH) {
    string result = STR;

    // Find where the text starts.
    size_t pos = result.find(TEXT_TO_REPLACE);

    // Only replace if the text was actually found.
    if (pos != string::npos) {
        // replace(startIndex, howManyCharactersToRemove, newText)
        result.replace(pos, TEXT_TO_REPLACE.length(), REPLACE_WITH);
    }

    return result;
}

string firstWord(const string& STR) {
    // Find the first space. Everything before that space is the first word.
    size_t pos = STR.find(' ');

    // If there is no space, the whole string is one word.
    if (pos == string::npos) {
        return STR;
    }

    return STR.substr(0, pos);
}

string removeFirstWord(const string& STR) {
    // Find the first space.
    size_t pos = STR.find(' ');

    // If there is no space, there is no second word, so return empty string.
    if (pos == string::npos) {
        return "";
    }

    // pos + 1 skips the space itself.
    return STR.substr(pos + 1);
}

string secondWord(const string& STR) {
    // Remove the first word, then take the first word of what remains.
    return firstWord(removeFirstWord(STR));
}

string thirdWord(const string& STR) {
    // Remove two words, then take the first word of what remains.
    return firstWord(removeFirstWord(removeFirstWord(STR)));
}

string nthWord(const string& STR, int N) {
    string result = STR;

    // If N is 1, do not remove anything.
    // If N is 2, remove one word.
    // If N is 3, remove two words.
    for (int i = 1; i < N; i++) {
        result = removeFirstWord(result);
    }

    return firstWord(result);
}

string substitute(const string& STR, const string& TARGET, const string& REPLACEMENT) {
    string result = STR;

    /*
        Your original test cases replace one character with one character.
        Example: replace "x" with "o".

        std::replace works on characters, not full strings.
        That is why this uses TARGET[0] and REPLACEMENT[0].
    */
    if (!TARGET.empty() && !REPLACEMENT.empty()) {
        replace(result.begin(), result.end(), TARGET[0], REPLACEMENT[0]);
    }

    return result;
}

int main() {
    cout << "Testing your functions...\n\n";
    runAllTests();
    return 0;
}

/*
    Test helper functions
    ---------------------
    These compare the actual answer from your function to the expected answer.
    There are three versions because the tests compare strings, chars, and ints.
*/
void test(const string& MESSAGE, const string& LHS, const string& RHS) {
    cout << setw(30) << right << MESSAGE << ": " << left;
    if (LHS == RHS) {
        cout << "    PASSED\n";
    }
    else {
        cout << " -->FAILED   \"" << LHS << "\" != \"" << RHS << "\"\n";
    }
}

void test(const string& MESSAGE, char LHS, char RHS) {
    cout << setw(30) << right << MESSAGE << ": " << left;
    if (LHS == RHS) {
        cout << "    PASSED\n";
    }
    else {
        cout << " -->FAILED '" << LHS << "' != '" << RHS << "'\n";
    }
}

void test(const string& MESSAGE, int LHS, int RHS) {
    cout << setw(30) << right << MESSAGE << ": " << left;
    if (LHS == RHS) {
        cout << "    PASSED\n";
    }
    else {
        cout << " -->FAILED " << LHS << " != " << RHS << "\n";
    }
}

void runAllTests() {
    test("Testing length()", stringLength("Fun"), 3);
    test("Testing length()", stringLength("TheEnd"), 6);
    test("Testing at()", charAt("California", 3), 'i');
    test("Testing at()", charAt("Angeles", 2), 'g');
    test("Testing append()", stringAppend("There's a ", "Cat on the tree."), "There's a Cat on the tree.");
    test("Testing append()", stringAppend("It is my ", "first exam."), "It is my first exam.");
    test("Testing insert()", stringInsert("If you safely.", "pass ", 7), "If you pass safely.");
    test("Testing insert()", stringInsert("Happy.", "Be ", 0), "Be Happy.");
    test("Testing find()", stringFind("Have to face reality now.", 'o'), 6);
    test("Testing find()", stringFind("Have to face reality now.", 'e'), 3);
    test("Testing substr()", stringSubstring("Such a natural mystic", 7, 7), "natural");
    test("Testing substr()", stringSubstring("Such a natural mystic", 0, 4), "Such");
    test("Testing replace()", stringReplace("Strings are not the way", "Strings", "Things"), "Things are not the way");
    test("Testing replace()", stringReplace("Show me the things", "things", "way"), "Show me the way");
    test("Testing firstWord()", firstWord("We'll cross that bridge when we come to it"), "We'll");
    test("Testing firstWord()", firstWord("five birds are flying in the sky"), "five");
    test("Testing firstWord()", firstWord("you have to repeat your test"), "you");
    test("Testing removeFirstWord()", removeFirstWord("We'll cross that bridge when we come to it"), "cross that bridge when we come to it");
    test("Testing removeFirstWord()", removeFirstWord("Nothing"), "");
    test("Testing removeFirstWord()", removeFirstWord(removeFirstWord("We'll cross that bridge when we come to it")), "that bridge when we come to it");
    test("Testing secondWord()", secondWord("We'll cross that bridge when we come to it"), "cross");
    test("Testing secondWord()", secondWord("five birds are flying in the sky"), "birds");
    test("Testing secondWord()", secondWord("you have to repeat your test"), "have");
    test("Testing thirdWord()", thirdWord("We'll cross that bridge when we come to it"), "that");
    test("Testing thirdWord()", thirdWord("five birds are flying in the sky"), "are");
    test("Testing thirdWord()", thirdWord("you have to repeat your test"), "to");
    test("Testing nthWord(1)", nthWord("We'll cross that bridge when we come to it", 1), "We'll");
    test("Testing nthWord(2)", nthWord("We'll cross that bridge when we come to it", 2), "cross");
    test("Testing nthWord(3)", nthWord("We'll cross that bridge when we come to it", 3), "that");
    test("Testing nthWord(4)", nthWord("We'll cross that bridge when we come to it", 4), "bridge");
    test("Testing nthWord(5)", nthWord("We'll cross that bridge when we come to it", 5), "when");
    test("Testing nthWord(6)", nthWord("We'll cross that bridge when we come to it", 6), "we");
    test("Testing nthWord(7)", nthWord("We'll cross that bridge when we come to it", 7), "come");
    test("Testing nthWord(8)", nthWord("We'll cross that bridge when we come to it", 8), "to");
    test("Testing nthWord(9)", nthWord("We'll cross that bridge when we come to it", 9), "it");
    test("Testing substitute()", substitute("The Gxxgle", "x", "o"), "The Google");
    test("Testing substitute()", substitute("$chool of Mine$", "$", "s"), "school of Mines");
    test("Testing substitute()", substitute(substitute("D--", "-", "+"), "D", "C"), "C++");
}
