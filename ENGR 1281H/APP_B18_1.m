%Create a vector for thermal efficiencies using the notation n=[start:step:stop]such that the efficiency vector ? = [.5, .45, .4, .35, .3, .25, .2].  
%Create a vector for change in enthalpy, H, using the same notation (values are given in the description above).  
%Use element by element multiplication to compute Pout from n and H.   
%Plot the power out (y-axis) vs. the change in enthalpy, H, (x-axis).  
%Label the plot appropriately. 

fprintf ('\n')  
fprintf ('\n************************************************') 
fprintf ('\n*  Name:  Jay Shin     Date: 10/6/2020         *') 
fprintf ('\n*  Seat:  00    File:  APP_B18_01.m            *') 
fprintf ('\n*  Instructor: Brooke Morin    12:40-2:45      *')           
fprintf ('\n************************************************') 
fprintf ('\n') 
%Create a vector for thermal efficiencies using the notation n=[start:step:stop]such that the 
efficiency vector ? = [.5, .45, .4, .35, .3, .25, .2].  
n = [0.5:-0.05:0.2]; 
%Create a vector for change in enthalpy, H, using the same notation (values are given in the 
description above).  
H = [100:100:700]; 
%Use element by element multiplication to compute Pout from n and H. 
Pout = n .* H * 1000; 
%Plot the power out (y-axis) vs. the change in enthalpy, H, (x-axis). 
plot(H, Pout, 'o'); 
%Label the plot appropriately. 
xlabel('Change in Enthalpy (MJ/kg)'); 
ylabel('Power Out (MW)'); 
title('Change in Enthalpy and Power Output');