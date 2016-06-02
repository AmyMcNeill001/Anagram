#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//global constant for filepath to dictionary
const string dictionaryLocation
= "//Users//amymcneill//Desktop//AnagramProject//AnagramProject//dictionary.txt";

//class to bundle input’s different data types, eliminate used letters
class Input
{
public:
    string input;
    char letters[15];
    Input();
    Input(string gotIt);
};
class Storage: public Input
{
public:
    bool binary[15];  //to represent whether or not each letter is present in dictionaryWord
    string dictionaryWord;  //for storage of possible word
    vector<char> dictionaryLetters;  //for comparison with input letters
    int length; //for comparison with others
    bool allLetters; //to determine whether the word is composed of entirely inputed letters
    Storage(); //default constructor
    Storage(string compareMe); //constructor with parameter
    void calculator (Input options);
    Storage operator=(Storage rhsObj);
}; //END CLASS STORAGE DECLARATION
int main()
{
    //necessary variables
    string gotIt = "";
    string currentWord = "";
    Storage winner;
    
    //gather input
    cout << "Please enter your letters: " << endl;
    cin >> gotIt;
    Input myWord(gotIt);
    
    //open the dictionary file
    ifstream inFileStream;
    inFileStream.open(dictionaryLocation.c_str());
    while(inFileStream)
    {
        inFileStream >> currentWord;
        
        Storage whileWord(currentWord);
        
        whileWord.calculator(myWord);
        //
        //        if (whileWord.allLetters)
        //            cout << "This is all letters of this anagram!" << endl;
        
        if(whileWord.allLetters == true && whileWord.length > winner.length)
        {
            winner = whileWord;
            cout << "Is this ever happening?" << endl;
        }
    }//END while loop for each dictionary word
    cout << "The longest possible word with these letter is: "<< winner.dictionaryWord << endl;
}//END FUNCTION MAIN
//BEGIN INPUT CONSTRUCTOR DEFINITIONS
Input::Input()
{
    //nothing to do here
}//END Default Constructor Input
Input::Input (string gotIt)
{
    input = gotIt;
    //convert this to populate char array
    for (int ii = 0; ii < 16; ii++)
    {
        letters[ii] = gotIt.at(ii);
    }
}//END Constructor with Parameters
//BEGIN STORAGE FUNCTION DEFINITIONS
Storage::Storage()
{
    dictionaryWord = "";
    length = 0;
    allLetters = false;
    for(int ii = 0; ii < 16; ii++)
    {
        binary[ii] = false;
    }
}//END storage default constructor
Storage::Storage(string compareMe)
{
    length = static_cast<int>(dictionaryWord.size());
    allLetters = false;
    dictionaryWord = compareMe;
    for(int ii = 0; ii < this->length; ii++)
    {
        cout << dictionaryWord.at(ii);
        dictionaryLetters.push_back(dictionaryWord[ii]);
        cout << dictionaryLetters.at(ii);
    }
    //    for (int ii = 0; ii < dictionaryLetters.size(); ii++)
    //    {
    //        cout << dictionaryLetters.at(ii);
    //    }
    for(int ii = 0; ii < 16; ii++)
    {
        binary[ii] = false;
    }
}//END storage constructor with parameter
void Storage::calculator(Input options)
{
    bool flag = false; //to alert any instances of a non-existing letter in the word
    
    for(int ii = 0; ii < dictionaryLetters.size(); ii++)
    {
        bool iterationPresent = false;
        for(int xx = 0; xx < 16; xx++)
        {
            if(dictionaryLetters.at(ii) == options.letters[xx])
            {
                if(this->binary[xx] == false)
                    iterationPresent = true;
                this->binary[xx] = true;
            }
        }
        if(!iterationPresent)
            flag = true;
    }
    
    if(flag)
        allLetters = false;
    else
    {
        allLetters = true;
    }
    
}//END matchCalculator function
Storage Storage::operator=(Storage rhsObj)
{
    for( int ii = 0; ii < 16; ii++)
    {
        this->binary[ii] = rhsObj.binary[ii];
    }
    this->dictionaryWord = rhsObj.dictionaryWord;
    for(int ii = 0; ii < 16; ii++)
    {
        this->dictionaryLetters.at(ii) = rhsObj.dictionaryLetters.at(ii);
    }
    this-> length = rhsObj.length;
    
    return *this;
    
}//END overloaded equality operator









