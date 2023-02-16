%Read in the data from APP_B20_1_freq_out.txt and store it to a matrix.  
%From this matrix, extract the rotor frequency values from the data and store to a new matrix. 
%Use the max()function to find maximum rotor frequency. Hint: The max function used on a matrix returns a vector.  
%You want to find the max of the entire matrix.  
%Use a while loop to find the minimum rotor frequency. 
%Print the maximum and minimum rotor frequency to the screen. 
%Create a vector of the 8 values for Speaker Frequency using vector notation ranging from 40 HZ to 75 HZ. 
%Create a vector of the 20 values for Speaker Voltage Input using a for loop for voltages ranging from .05 V to 1 V. 
%Create a mesh plot of the data using the function mesh(X,Y,Z)where X is speaker frequency, Y is voltage input, and z is rotor frequency output.  
%Label the figure appropriately. 

%%('************************************************') 
%%('*  Name:  Jay Shin     Date: 10/12/2020        *') 
%%('*  Seat:  00    File:  APP_B20_1.m             *') 
%%('*  Instructor: Brooke Morin    12:40-2:45      *')           
%%('************************************************') 
%Read in the data from APP_B20_1_freq_out.txt and store it to a matrix.  
freq = load('APP_B20_1_freq_out.txt'); 
%From this matrix, extract the rotor frequency values from the data and store to a new matrix. 
rotorF = freq(2:end, 2:end); 
%Use the max()function to find maximum rotor frequency. Hint: The max function used on a matrix 
returns a vector.  
%You want to find the max of the entire matrix.  
M = max(max(rotorF)); 
%Use a while loop to find the minimum rotor frequency. 
m = rotorF(1, 1); 
i = 1; 
j = 1; 
while i <= 20 
    if rotorF(i, j) < m 
        m = rotorF(i, j); 
    end 
    if j == 8 
        j = 0; 
        i = i + 1; 
    end 
    j = j + 1; 
end 
%Print the maximum and minimum rotor frequency to the screen. 
fprintf(1, 'Maximum Rotor Frequency: %f\nMinimum Rotor Frequency: %f', M, m); 
%Create a vector of the 8 values for Speaker Frequency using vector notation ranging from 40 HZ 
to 75 HZ. 
speakerF = linspace(40, 75, 8); 
%Create a vector of the 20 values for Speaker Voltage Input using a for loop for voltages ranging 
from .05 V to 1 V. 
for i=1:1:20 
    speakerV(i) = i*0.05; 
end 
%Create a mesh plot of the data using the function mesh(X,Y,Z)where X is speaker frequency, Y is 
voltage input, and z is rotor frequency output.  
mesh(speakerF, speakerV, rotorF); 
%Label the figure appropriately. 
xlabel('Speaker Frequency (Hz)'); 
ylabel('Voltage Input (V)'); 
zlabel('Rotor Frequency Output (Hz)'); 
title('Relationship between Speaker Frequency & Voltage Input & Frequency Output'); 
 