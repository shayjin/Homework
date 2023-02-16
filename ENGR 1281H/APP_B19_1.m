%Read in the pressures from APP_B19_1_drive_pressure.txt.  
%Find the maximum drive pressure NOT using the max()function. 
%Find the maximum drive pressure using max(). 
%Find the minimum drive pressure NOT using the min()function. 
%Find the minimum drive pressure using min(). 
%Find the mean drive pressure NOT using the mean()function.  
%Find the mean drive pressure using mean(). 
%Find the standard deviation of the drive pressure NOT using the std() function.  
%Find the standard deviation of the drive pressure using std(). 
%Print all results to the screen indicating whether the result used the built-in function or not. 
%Verify that the standard deviation is within acceptable limits for stable spinning.   
%Print a message to the screen indicating whether it is or isn’t within acceptable limits. 
%Sort the measurements in ascending order NOT using the sort() function. 
%Print the sorted data to the file “APP_B19_1_drive_pressure_sorted1.txt”. 
%Sort the measurements in ascending order using sort(). 
%Print the sorted data to the file “APP_B19_1_drive_pressure_sorted2.txt”.

%%('************************************************') 
%%('*  Name:  Jay Shin     Date: 10/9/2020         *') 
%%('*  Seat:  00    File:  APP_B19_1.m             *') 
%%('*  Instructor: Brooke Morin    12:40-2:45      *')           
%%('************************************************') 
%Read in the pressures from APP_B19_1_drive_pressure.txt. 
file = load('APP_B19_1_drive_pressure.txt'); 
%Find the maximum drive pressure NOT using the max()function. 
M = file(1, 2); 
for i=1:1:length(file) 
   temp = file(i, 2);  
   if(temp > M) 
       M = temp; 
   end        
end 
%Find the maximum drive pressure using max(). 
maxF = max(file); 
maxF = maxF(2); 
%Find the minimum drive pressure NOT using the min()function. 
m = file(1, 2); 
for i=1:1:length(file) 
    temp = file(i, 2); 
    if(temp < m) 
        m = temp; 
    end  
end 
%Find the minimum drive pressure usingmin(). 
minF = min(file); 
minF = minF(2); 
%Find the mean drive pressure NOT using the mean()function.  
total = 0;  
for i=1:1:length(file) 
    total = total + file(i, 2); 
end 
me = total / length(file); 
%Find the mean drive pressure using mean(). 
meanF = mean(file); 
meanF = meanF(2); 
%Find the standard deviation of the drive pressureNOT using the std() function.  
s = 0; 
for i=1:1:length(file) 
    s = s + (me-file(i, 2))^2; 
end 
sd = sqrt(s/length(file)); 
%Find the standard deviation of the drive pressure using std(). 
stdF = std(file, 1); 
stdF = stdF(2); 
%Print all results to the screen indicating whether the result used the built-in function or not. 
fprintf(1, 'Maximum drive pressure not using max(): %f mbar\n', M); 
fprintf(1, 'Maximum drive pressure using max(): %f mbar\n', maxF); 
fprintf(1, 'Minimum drive pressure not using min(): %f mbar\n', m); 
fprintf(1, 'Minimum drive pressure using min(): %f mbar\n', minF); 
fprintf(1, 'Mean of the drive pressure not using mean(): %f mbar\n', me); 
fprintf(1, 'Mean of the drive pressure using mean(): %f mbar\n', meanF); 
fprintf(1, 'Standard deviation of the drive pressure not using std(): %f mbar\n', sd); 
fprintf(1, 'Standard devation of the drive pressure using std(): %f mbar\n', stdF); 
%Verify that the standard deviation is within acceptable limits for stable spinning.   
acceptableSD = 0.1; 
%Print a message to the screen indicating whether it is or isn’t within acceptable limits. 
if sd < acceptableSD 
    disp('Standard deviation is within acceptable limits for stable spinning.'); 
else 
    disp('Standard deviation is not within acceptable limits for stable spinning.'); 
end 
%Sort the measurements in ascending order NOT using the sort() function. 
data = [M m me sd]; 
temp = data(1); 
for i=1:1:length(data) 
    for j=1:1:length(data)-1 
        if data(j) > data(j+1) 
            temp = data(j+1); 
            data(j+1) = data(j); 
            data(j) = temp; 
        end 
    end 
end 
%Print the sorted data to the file “APP_B19_1_drive_pressure_sorted1.txt”. 
file1 = fopen('APP_B19_1_drive_pressure_sorted1.txt', 'w'); 
fprintf(file1, '%s ',data); 
fclose(file1); 
%Sort the measurements in ascending order using sort(). 
sortFData = sort(data); 
%Print the sorted data to the file “APP_B19_1_drive_pressure_sorted2.txt”. 
file2 = fopen('APP_B19_1_drive_pressure_sorted2.txt', 'w'); 
fprintf(file2, '%s ', sortFData); 
fclose(file2);  