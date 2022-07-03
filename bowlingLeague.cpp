/*

Name: Hajer Qara
Date: 6/19/2022
File Name: VowelCounterProgram
Section: ITCS 2530 V0801 2021SS - C++ Programming 1

 bowlingLeague.cpp : 

 Write a program to calculate a bowling league's average bowling scores. 
 You will need to read the input data from the file BowlingScores.txt 

You must use three arrays:
    1) a one-dimensional array to store the bowler's names.
    2) a (parallel) two-dimensional array to store the bowling scores.
    3) a one-dimensional array to store the bowler's average score.

Your program must contain at least the following functions:
    1) a function called GetBowlingData to read and store data into two arrays. 
    The function should take as input parameters the file name and both empty arrays, which it should fill from the file 
    (BowlingScores.txt) and return a status of either success or failure (i.e true or false).
    2) a function called GetAverageScore that is used to calculate the average bowling score. 
    The function should take as input the populated arrays and return the average score of each bowler in a separate array.
    3) a function called PrettyPrintResults to output the results, i.e., bowler name, scores and average.


*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


//Constant Variables 
const int BORDER_LENGTH = 75;
string FILE_NAME = "BowlingScores.txt";
const string ERROR_MESSAGE = "Error in opening the file";
const int NUMBER_OF_ROWS = 10;
const int NUMBER_OF_COLUMNS = 4;

//This function is to read and store data into two arrays.
bool GetBowlingData(string FILE_NAME, string bowlersName[NUMBER_OF_ROWS], int bowlersScores[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS]) {

    //Declared variables
    ifstream dataInput;
    int i = 0;
    int x = 0;

    //Opens the file "BowlingScores.txt"
    dataInput.open(FILE_NAME.c_str());
    if (!dataInput)
    {   //Outputs error message if not file is found or if file is corrupt
        cout << ERROR_MESSAGE << ':' << endl;
        system("pause");
        return false;
    }

    //Notifies the user that the file they inputed will be analyzed
    cout << endl << "Analyzing file " << "\'" << FILE_NAME << "\'..." << endl;


    // Seperates each string into their appointed arrays 
    while (i < NUMBER_OF_ROWS) {
        dataInput >> bowlersName[i]; // inputs name into each row in the array
        int x = 0;
        while (x < NUMBER_OF_COLUMNS) {
            dataInput >> bowlersScores[i][x]; // inputs scores into each row in the array
            x++;
        }
        i++;
    }


    cout << endl;
    dataInput.close(); // Closes the file 

    cout << endl;

    return true;
}

//This function is used to calculate the average bowling score.
int* GetAverageScore(string bowlersName[NUMBER_OF_ROWS], int bowlersScores[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS]) {
    //Declared Variables 
    ifstream dataInput;
    int total = 0;
    int number = 0;
    int average = 0;
    int i = 0;
    int x = 0;

    static int bowlersAverage[NUMBER_OF_ROWS]; // ensures all values when pass through remain for the lifetime of the program

    // Calculates the average score for each player 
    while (i < NUMBER_OF_ROWS) {
        while (x < NUMBER_OF_COLUMNS) {
            number = bowlersScores[i][x];
            total = total + number; // accumulates the players scores 
            average = total / NUMBER_OF_COLUMNS; // calculates average based on how many scores there are 
            bowlersAverage[i] = average; // assigns the average to an index 
            dataInput >> bowlersAverage[i]; // inputs the average into the array 
            x++;
        }
        total = 0;
        x = 0;
        i++;
    }


    return bowlersAverage;
};

//This function is to output results, i.e., bowler name, scores and average.
void PrettyPrintResults(string bowlersName[NUMBER_OF_ROWS], int bowlersScores[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int bowlersAverage[NUMBER_OF_ROWS]) {

    //Declared Varaibles 
    int i = 0;
    int x = 0;

    //Prints out the players name, scores, and average 
    while (i < NUMBER_OF_ROWS) {
        //Prints bowlers name
        cout << "Bowler: " << bowlersName[i] << " ";
        cout << endl << "Scores: ";
        //Prints bowlers scores
        while (x < NUMBER_OF_COLUMNS) {
            cout << bowlersScores[i][x] << " ";
            x++;
        }
        //Print bowlers average 
        cout << endl << "Average: " << bowlersAverage[i] << " " << endl;
        cout << endl;
        x = 0;
        i++;

    }


}

int main()
{
    //Declared variables;
    string greetingMessage;
    int greetingLength;
    int border;
    int halfBorder;

    // Declared arrays
    string bowlersName[NUMBER_OF_ROWS];
    int bowlersScores[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];


    //Greets the user when they first run the program 
    greetingMessage = " Welcome to the Bowling League ";
    greetingLength = static_cast<int>(greetingMessage.length()); // find the number of characters in the greeting message

    border = BORDER_LENGTH - greetingLength; // calculates how much space the message takes up 
    halfBorder = border / 2;
    string asterisk(halfBorder, '*'); // repeats the asterisk based on the length of the half border

    //Prints out the greeting message to the user 
    cout << setfill('*') << setw(BORDER_LENGTH) << "*" << endl;
    cout << asterisk << right << greetingMessage << asterisk << endl;
    cout << setw(BORDER_LENGTH) << "*" << setfill(' ') << endl;

    GetBowlingData(FILE_NAME, bowlersName, bowlersScores);
    int* bowlersAverage = GetAverageScore(bowlersName, bowlersScores);
    PrettyPrintResults(bowlersName, bowlersScores, bowlersAverage);


    system("pause");
    return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////     CODE I TRIED BUT DIDN'T WORK      /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
*
    // Didn't allow allow the function to return the array instead it allowed it to pass as a paramenter
    int GetAverageScore(string bowlersName[NUMBER_OF_ROWS], int bowlersScores[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS],
        int bowlersAverage[NUMBER_OF_COLUMNS]){}


*   //Didn't allow for the array to properly pass through when using the pointer
    int bowlersAverage[NUMBER_OF_ROWS];
    GetAverageScore(bowlersName, bowlersScores);

    //Refractor this in final code to be less lines
    while ( i < NUMBER_OF_ROWS) {
        cout << "Bowler: " << bowlersName[i] << " "; //Prints bowlers name
        i++;
    }
        //Prints bowlers scores
        while (i < NUMBER_OF_ROWS) {
            while ( x < NUMBER_OF_COLUMNS) {
                cout << bowlersScores[i][x] << " ";
                x++;
            }
            x = 0;
            i++;

    }
    //Print bowlers average
    while (i < NUMBER_OF_ROWS){
        cout << endl << "Average: " << bowlersAverage[i] << " " << endl;
        i++;
    }

    //Kept accumulating the scores and finding the total average instead of individual average
    while (i < NUMBER_OF_ROWS) {
        while ( x < NUMBER_OF_COLUMNS) {
           number = bowlersScores[i][x];
           total = total + number;
           average = total / NUMBER_OF_COLUMNS;
           bowlersAverage[i] = average;
           dataInput >> bowlersAverage[i];
           x++;
        }
        x= 0;
        i++;

    }


////////////////////////////////////////////////////*/