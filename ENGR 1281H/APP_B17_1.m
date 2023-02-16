%Prompt the user for all inputs? Compute the equivalent resistance of the resistors using the two functions described above. 
%Compute the equivalent resistance of the resistors using the two functions described above. 
%Display this value to the screen 
%Prompt the user to see if he/she wants to quit. 
%Repeat the program if necessary 
%Use the program to determine which circuits (A-D) on the following page give an equivalent resistance of 1300.  
%Write the answer on the top of the script file that you turn in. Box-in your answer to make this very clear. 

fprintf ('\n')  
fprintf ('\n************************************************') 
fprintf ('\n*  Name:  Jay Shin     Date: 10/3/2020         *') 
fprintf ('\n*  Seat:  00    File:  APP_B17_01.m            *') 
fprintf ('\n*  Instructor: Brooke Morin    12:40-2:45      *')          
fprintf ('\n*  ANSWER: A and D                             *') 
fprintf ('\n************************************************') 
fprintf ('\n') 
  
cont = 'yes'; 
while cont == 'yes' || cont == 'YES' || cont == 'y' || cont == 'Y' 
    %Prompt the user for all inputs? Compute the equivalent resistance of the resistors using the two functions described above. 
    pNumber = input('Enter the number of parallel resistors: '); 
     
    for i=1:1:pNumber 
      fprintf(1, 'Enter resistance for parallel resistor %d: ', i); 
      pr(i) = input(''); 
    end 
 
   %Compute the equivalent resistance of the resistors using the two functions described above. 
   %Display this value to the screen 
    fprintf(1, 'The equivalent resistance for parallel resistors is '); 
    parallel(pr, pNumber); 
     
    sNumber = input('Enter number of series resistors: '); 
    for i=1:1:sNumber 
       fprintf(1, 'Enter resistance for series resistor %d: ', i); 
       sr(i) = input(''); 
    end 
   
    fprintf(1, 'The equivalent resistance for series resistors is '); 
    series(sr, sNumber); 
  
    %?Prompt the user to see if he/she wants to quit.  
    cont = input('\nWould you like to continue? (Type yes to continue): ', 's'); 
end 
%Repeat the program if necessary 
%Use the program to determine which circuits (A-D) on the following page give an equivalent resistance of 1300. 
%Write the answer on the top of the script file that you turn in. Box-in your answer to make this very clear. 

function [totalInverse] = parallel(pr, size)
    total = 0;

    for i=1:1:size
        total = total + 1/pr(i);
    end
    
    total = 1 / total;
    disp(totalInverse);
end

function [total] = series(sr, size)
    total = 0;
    
    for i=1:1:size
        total = total + sr(i);
    end

    disp(total);
end