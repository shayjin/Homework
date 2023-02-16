fprintf ('\n')  
fprintf ('\n************************************************') 
fprintf ('\n*  Name:  Jay Shin     Date: 10/5/2020         *') 
fprintf ('\n*  Seat:  00    File:  EWA_03.m                *') 
fprintf ('\n*  Instructor: Brooke Morin    12:40-2:45      *')          
fprintf ('\n************************************************') 
fprintf ('\n') 
  
win = 0; 
loss = 0; 
cont = 'a'; 
while cont == 'a' 
    %Display the rules of the game to the user.  
    fprintf(1, 'Guess the number in the range 0 <= x <= 10 in less than 4 tries\n'); 
    %Select a random integer number in the range 0 <= x <= 10.  
    %?Hint: use the command randi([0 10],1)to generate the random integer 
    ans = randi([0 10], 1); 
    %Prompt the user to guess the number.  
    guess = input('guess the number: '); 
    %Use one or more if – else if – else structures to determine if the correct number was guessed, or if it was too big or too  
    %small. 
    %enters the while loop if a wrong answer is inputted 
    wrong = 0; 
    while true 
        %escapes the loop if user guessed 4 times and evalutes outside 
        if wrong == 3 
            break; 
        end 
        %checks user's guesses 
        if isempty(guess) 
            fprintf(1, 'Enter something!'); 
            wrong = wrong + 1; 
            fprintf('\nguess the number (%i tries left): ', 4-wrong); 
            guess = input(''); 
        elseif guess > ans 
            fprintf(1, 'too big'); 
            wrong = wrong + 1; 
            fprintf('\nguess the number (%i tries left): ', 4-wrong); 
            guess = input(''); 
        elseif guess < ans 
            fprintf(1, 'too small'); 
            wrong = wrong + 1; 
            fprintf('\nguess the number (%i tries left): ', 4-wrong); 
            guess = input(''); 
        elseif ~(guess >= 0 && guess <= 10) 
            wrong = wrong + 1; 
            fprintf(1, 'Enter a number in the range 0 <= x <= 10 (%i tries left): ', 4-wrong); 
            guess = input(''); 
        elseif ans == guess 
            break; 
        else 
            wrong = wrong + 1; 
            fprintf(1, 'Enter a valid number (%i tries left): ', 4-wrong); 
            guess = input(''); 
        end 
    end 
  
    %Determine if the user has made too many incorrect guesses and if so print a condolence message.  
    if ans == guess 
        fprintf(1, 'Congratulations! %i is correct. you won!\n', ans); 
        win = win + 1; 
    elseif ans ~= guess 
        fprintf(1, '%i was the answer. you lost!\n', ans); 
        loss = loss + 1; 
    end 
    %Keep track of the “Wins” and “Losses” . 
    %At the end of each game prompt the user to choose one of the following:(a) play again(b) see statistics(c) reset  
    %statistics(d) quit 
    %Use a Switch– Case structure to implement this choice 
    cont = input('Type a to play again, type b to see statistics, type c to reset statstics, type d to quit: ', 's'); 
     
    while true 
        switch cont 
            case {'a', 'A'} 
                break; 
            case {'b', 'B'} 
                fprintf(1, 'Statistics: \nWins: %i\nLoses: %i\n', win, loss); 
                cont = input('Type a to play again, type b to see statistics, type c to reset statstics, type d to quit: ', 's'); 
            case {'c', 'C'} 
                win = 0; 
                loss = 0; 
                fprintf(1, 'Statistics Reseted\nWins: %i\nLoses: %i\n', win, loss); 
                cont = input('Type a to play again, type b to see statistics, type c to reset statstics, type d to quit: ', 's'); 
            case {'d', 'D'} 
                fprintf(1, 'Quitting the game...'); 
                break; 
            otherwise 
                cont = input('Type a to play again, type b to see statistics, type c to reset statstics, type d to quit: ', 's'); 
        end 
    end 
end