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
    int binaryNumber; //tracker for number of matches
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
    
//    cout << "Inputted chars: " << endl;
//    for ( int ii = 0; ii < 16; ii++)
//    {
//        cout << myWord.letters[ii];
//    }
    
    //open the dictionary file
    ifstream inFileStream;
    inFileStream.open(dictionaryLocation.c_str());
    while(inFileStream)
    {
        inFileStream >> currentWord;
        
        Storage whileWord(currentWord);
        
        whileWord.calculator(myWord);
        
        cout << whileWord.binaryNumber << endl;
        
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
    allLetters = false;
    binaryNumber = 0;
    dictionaryWord = compareMe;
    length = static_cast<int>(dictionaryWord.length());
//    cout << "LENGTH IS: " << length << endl;
    for(int ii = 0; ii < this->length; ii++)
    {
        dictionaryLetters.push_back(dictionaryWord[ii]);
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
void Storage::calculator(Input myInput)
{
    cout << "Length before calculated: " << length << endl;
    if (this->length > 16)
    {
        cout << "Length is greater than 16!" << endl;
        return;
    }
    else
    {
        cout << "Word being compared: " << dictionaryWord << endl;
        for ( int ii = 0; ii < this->length; ii++)
        {
            for ( int xx = 0; xx < 16; xx++)
            {
//                cout << "ii: " << ii << "  xx:  " << xx << endl;
                if (myInput.letters[xx] == this->dictionaryLetters.at(ii) && !(binary[xx]))
                {
                    binary[xx] = true;
                    binaryNumber++;
//                    cout << "Binary number incremented" << endl;
                }
            }
        }
    }
    if( this->length == this->binaryNumber)
        allLetters = true;
}//END matchCalculator function
Storage Storage::operator=(Storage rhsObj)
{
    for( int ii = 0; ii < 16; ii++)
    {
        this->binary[ii] = rhsObj.binary[ii];
    }
    this->dictionaryWord = rhsObj.dictionaryWord;
    this-> length = rhsObj.length;
    
    return *this;
    
}//END overloaded equality operator











