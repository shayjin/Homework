%Modify your code and save as a new script file.  Modify the code to: 
%Calculate sqrt(2) using 1E3, 1E4, 1E5, 1E6, 1E7, 1E8, and 1E9 random coordinate pairs.  
%Print to the screen the number of coordinate pairs being generated each time before the pair generating loop begins using fprintf(). 
%Print to the screen the time required for each number of coordinate pairs.  
%Print to the screen the error associated with each number of coordinate pairs.  
%NOTE, with 1E9 coordinate pairs it may take your program close to 1 min to complete.   
%NOTE, to minimize the amount of time your code takes to compute the value remove any unnecessary computations or print statements from inside the loop.?Plot sqrt(2) simulated (y-axis) vs number of coordinate pairs (x-axis) using the semilogx()plotting function.  
%Plot percent error (y-axis) vs number of coordinate pairs (x-axis) using the semilogx()plotting function.  
%Using your plot, estimate the smallest number of coordinate pairs that still meets the accuracy requirement. 
%Plot computational time (y-axis) vs number of coordinate pairs (x-axis) using the loglog()plotting command. 
%Using your plot, estimate the largest number of coordinate pairs that still meets the time requirement. 
%HINT: Use the figure command to open a new figure window. 

for j=1:1:3 
    %Include a for-loop with 1,000 iterations.   
    N_total = 0; 
    N_under_the_curve = 0; 
    for i=1:1:1000 
        %During each iteration, generate a random (x,y) coordinate pair. 
        x = rand() + 1; 
        y = rand(); 
        N_total = N_total + 1; 
        %Determine if the coordinate pair is below the curve, and if so, increment N_under_the_curve.  
        if y^2 <= 1/(4*x) 
            N_under_the_curve = N_under_the_curve + 1; 
        end 
    end 
    %Determine and display your simulated value of sqrt(2).  
    sim = N_under_the_curve/N_total + 1; 
    fprintf(1, 'Simulated value of sqrt(2) is: %f\n', sim); 
    %Determine and display the percent error in your simulated value of sqrt(2).  
    PE = abs(sqrt(2) - sim)/ sqrt(2) * 100; 
    fprintf(1, 'Percent Error is: %f\n', PE); 
    %Run your code at least three times.   
    fprintf(1, '\n'); 
end 
%Record the simulated value of sqrt(2) and the percent error for each run.   
%Answer the following questions in a separate document:  
%Why do the values of sqrt(2) change when you run the code each time?  
%If you used 1,000,000 randomly generated coordinates, would you expect the percent error to increase or decrease? 

%Modify your code and save as a new script file.  Modify the code to: 
%Calculate ?2 using 1E3, 1E4, 1E5, 1E6, 1E7, 1E8, and 1E9 random coordinate pairs.  
g = 1000; 
for j=1:1:7 
    %Include a for-loop with 1,000 iterations.   
    N_total = 0; 
    N_under_the_curve = 0; 
    %Print to the screen the number of coordinate pairs being generated each time before the pair generating loop begins using fprintf(). 
    fprintf(1, 'FOR %i RANDOM COORDINATE PAIRS: \n', g); 
    tic; 
    for i=1:1:g 
        %During each iteration, generate a random (x,y) coordinate pair. 
        x = rand() + 1; 
        y = rand(); 
        N_total = N_total + 1; 
        %Determine if the coordinate pair is below the curve, and if so, increment N_under_the_curve.  
        if y^2 <= 1/(4*x) 
            N_under_the_curve = N_under_the_curve + 1; 
        end 
    end 
    time = toc; 
    %Determine and display your simulated value of 2.  
    sim = N_under_the_curve/N_total + 1; 
    fprintf(1, 'Simulated value of sqrt(2) with: %f\n', sim); 
    %Print to the screen the time required for each number of coordinate pairs.  
    fprintf(1, 'Time it took %f', time); 
    %Print to the screen the error associated with each number of coordinate pairs.  
    PE = abs(sqrt(2) - sim)/ sqrt(2) * 100; 
    fprintf(1, 'Percent Error: %f\n', PE); 
    fprintf(1, '\n'); 
    numOfPoints(j) = g; 
    simVal(j) = sim; 
    perE(j) = PE; 
    times(j) = time; 
    g = g*10; 
    %NOTE, with 1E9 coordinate pairs it may take your program close to 1 min to complete.   
    %NOTE, to minimize the amount of time your code takes to compute the value remove any unnecessary computations or print statements from inside the loop. 
end 
%Plot srqt(2) simulated (y-axis) vs number of coordinate pairs (x-axis) using the semilogx() plotting function.  
semilogx(numOfPoints, simVal, '-o'); 
title('Simulated sqrt(2)'); 
xlabel('number of coordinate pairs'); 
ylabel('simulated sqrt(2)'); 
%Plot percent error (y-axis) vs number of coordinate pairs (x-axis) using the semilogx()plotting function.  
figure(2); 
semilogx(numOfPoints, perE, '-o'); 
title('Percent Error'); 
xlabel('number of coordinate pairs'); 
ylabel('percent error (%)'); 
%Using your plot, estimate the smallest number of coordinate pairs that still meets the accuracy requirement.

%Plot computational time (y-axis) vs number of coordinate pairs (x-axis) using the loglog()plotting command. 
figure(3); 
loglog(numOfPoints, times, '-o'); 
title('Time it Took to Complie'); 
xlabel('number of coordinate pairs'); 
ylabel('computational time (s'); 
%Using your plot, estimate the largest number of coordinate pairs that still meets the time requirement. 
%HINT: Use the figure command to open a new figure window. 