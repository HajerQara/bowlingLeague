# bowlingLeague

 This program calculates a bowling league's average bowling scores.  
<br>

The assignment prompt:
You will need to read the input data from the file BowlingScores.txt.
<br>
<br>
You must use three arrays:
    <br>1) a one-dimensional array to store the bowler's names.
    <br>2) a (parallel) two-dimensional array to store the bowling scores.
    <br>3) a one-dimensional array to store the bowler's average score.
<br>
<br>
Your program must contain at least the following functions:
   <br> 1) a function called GetBowlingData to read and store data into two arrays. 
    The function should take as input parameters the file name and both empty arrays, which it should fill from the file 
    (BowlingScores.txt) and return a status of either success or failure (i.e true or false).
   <br> 2) a function called GetAverageScore that is used to calculate the average bowling score. 
    The function should take as input the populated arrays and return the average score of each bowler in a separate array.
   <br> 3) a function called PrettyPrintResults to output the results, i.e., bowler name, scores and average.
<br>
<br>
EDIT: Modified code so that it calculates the average of 5 bowling scores.
<br>
EDIT 2: Modifed code so that it includes a struct and calculates 5 bowling scores. 