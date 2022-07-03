# bowlingLeague

 This program calculates a bowling league's average bowling scores.  
<br>
The assignment prompt:
You will need to read the input data from the file BowlingScores.txt.
<br>
You must use three arrays:
    1) a one-dimensional array to store the bowler's names.
    2) a (parallel) two-dimensional array to store the bowling scores.
    3) a one-dimensional array to store the bowler's average score.
<br>
Your program must contain at least the following functions:
    1) a function called GetBowlingData to read and store data into two arrays. 
    The function should take as input parameters the file name and both empty arrays, which it should fill from the file 
    (BowlingScores.txt) and return a status of either success or failure (i.e true or false).
    2) a function called GetAverageScore that is used to calculate the average bowling score. 
    The function should take as input the populated arrays and return the average score of each bowler in a separate array.
    3) a function called PrettyPrintResults to output the results, i.e., bowler name, scores and average.