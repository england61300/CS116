// England, Devin
// Mad Libs Story
// A program to make a small mad libs story

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Variables
    string name, noun, verb, adjective, adverb, pluralNoun, place, color, animal, month, bug, randomWord, game, food;
    int age, favoriteNumber;
    double earthWeight, marsWeight;
    
    // User input
    cout << "Welcome to Mad Libs! Please enter the following words:" << endl;
    cout << "First Name: ";
    getline(cin, name);
    cout << "Enter a noun: ";
    getline(cin, noun);
    cout << "Enter a verb (past tense): ";
    getline(cin, verb);
    cout << "Enter an adjective: ";
    getline(cin, adjective);
    cout << "Enter an adverb: ";
    getline(cin, adverb);
    cout << "Enter a plural noun: ";
    getline(cin, pluralNoun);
    cout << "Enter a place: ";
    getline(cin, place);
    cout << "Enter a color: ";
    getline(cin, color);
    cout << "Enter an animal: ";
    getline(cin, animal);
    cout << "Enter a month: ";
    getline(cin, month);
    cout << "Enter a bug: ";
    getline(cin, bug);
    cout << "Enter a random word: ";
    getline(cin, randomWord);
    cout << "Enter a game: ";
    getline(cin, game);
    cout << "Enter a food: ";
    getline(cin, food);
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your favorite number: ";
    cin >> favoriteNumber;
    cout << "Enter your weight on Earth (in lbs): ";
    cin >> earthWeight;
    cin.ignore(); // To avoid issues with getline after cin
    
    // Calculations
    marsWeight = earthWeight * 0.38; // Approximate Mars gravity factor
    int ageInDays = age * 365;
    
    // Output story
    cout << "\nHere is your Mad Lib story!\n";
    cout << "One mysterious " << month << " night, " << name << " found a secret map hidden inside a " << color << " " << noun << ". "
         << "It led to the lost treasure of the ancient " << animal << " tribe. With a heart full of excitement, "
         << name << " embarked on a journey to " << place << " where the treasure was said to be hidden. "
         << "On the way, " << name << " had to " << verb << " past a swarm of " << bug << "s, cross a river filled with " << pluralNoun << ", "
         << "and solve a puzzle using only a " << randomWord << " and a piece of " << food << ". "
         << "After a long journey, " << name << " discovered a hidden cave where a " << adjective << " chest lay waiting. "
         << "But before opening it, " << name << " had to win a game of " << game << " against a mischievous guardian! "
         << "Finally, after an epic battle of wits and skill, the treasure was revealed to be " << favoriteNumber << " golden coins. "
         << "And a note that said, did you know that if you weighed " << earthWeight << " lbs on Earth, you would weigh "
         << fixed << setprecision(2) << marsWeight << " lbs on Mars? "
         << "With treasure in hand and an adventure for the ages, " << name << " knew this was only the beginning!" << endl;
    
    return 0;
}
