%Your game will have 3 possible stories.  
%The user will have a choice which story is used.  
%The inputs for each story are listed on the next page. 
%The user should be asked for a word to fill in each appropriate blank.  To do this you MUST use a function.  
%The function should take the “Type” of word as a string and should return the string that the user inputs.   
%Hint: You may want to use an fprintf statement to tell the user what kind of word to enter and then an input statement to get the word. 
%Make sure the variables you use correspond to the inputs listed for the story and what is used in the fprintf statements provided. 
%The user should enter the filename for the output text file. 
%The story should print to the screen and print to the text file. 
%The command to print to the screen with the story is included for you in the MATLAB file, EWA_04_Output.m.   
%You must copy this statement and modify it to also print to the text file.   
%The user should have the choice to play again or quit.  

%%('\n************************************************') 
%%('\n*  Name:  Jay Shin     Date: 10/9/2020         *') 
%%('\n*  Seat:  00    File:  EWA_04.m                *') 
%5%('\n*  Instructor: Brooke Morin    12:40-2:45     *')           
%%('\n************************************************') 
%%('\n') 
%Your game will have 3 possible stories.  
%The user will have a choice which story is used.  
cont = true; 
while cont 
    while true 
        storyChoice = input('Which story would you like? 1, 2, or 3?: '); 
        if storyChoice == 1 || storyChoice == 2 || storyChoice == 3 
            break; 
        end 
    end 
    %The inputs for each story are listed on the next page. 
    %The user should be asked for a word to fill in each appropriate blank.  To do this you MUST use a function.  
    %The function should take the “Type” of word as a string and should return the string that the user inputs.   
    %Hint:You may want to use an fprintf statement to tell the user what kind of word to enter and then an inputs tatement to get the word. 
    %Make sure the variables you use correspond to the inputs listed for the story and what is used in the fprintfstatements provided. 
    %The user should enter the filename for the output text file. 
    fileName = input('What would you like to name the text file?: ', 's'); 
    fileName1=[fileName,'.txt']; 
    file = fopen(fileName1, 'w'); 
    %The story should print to the screen and print to the text file.   
    switch storyChoice 
        case 1 
            adjective1 = input('Enter adjective1: ', 's'); 
            adjective2 = input('Enter adjective2: ', 's'); 
            adjective3 = input('Enter adjective3: ', 's'); 
            plural_noun1 = input('Enter plural_noun1: ', 's'); 
            game_sport = input('Enter game_sport: ', 's'); 
            place_on_OSU_campus = input('Enter place_on_OSU_campus: ', 's'); 
            animal = input('Enter animal: ', 's'); 
            place = input('Enter place: ', 's'); 
            activity_class = input('Enter activity_class: ', 's'); 
            name1 = input('Enter name1: ', 's');
            past_tense_verb1 = input('Enter past_tense_verb1: ', 's'); 
            fprintf(1, '\n\nOne %s autumn morning, %s took a/an %s for a walk. \nBecause %s was late for %s, 
he/she %s \nall the way to the %s. On the way there %s passed\nthrough the %s where he/she saw a/an %s, but 
excited Brutus. \n%s also saw a large, %s group of %s, playing %s.\nWhen  %s arrived at the %s, he/she realized 
it was Friday\nand he/she didn''t have %s today.\n\n',adjective1, name1, animal, name1, activity_class, 
past_tense_verb1, place, name1,place_on_OSU_campus, adjective2, name1, adjective3, plural_noun1, game_sport, 
name1, place, activity_class); 
            fprintf(file, '\n\nOne %s autumn morning, %s took a/an %s for a walk. \nBecause %s was late for %s, 
he/she %s \nall the way to the %s. On the way there %s passed\nthrough the %s where he/she saw a/an %s, but 
excited Brutus. \n%s also saw a large, %s group of %s, playing %s.\nWhen  %s arrived at the %s, he/she realized 
it was Friday\nand he/she didn''t have %s today.\n\n',adjective1, name1, animal, name1, activity_class, 
past_tense_verb1, place, name1,place_on_OSU_campus, adjective2, name1, adjective3, plural_noun1, game_sport, 
name1, place, activity_class); 
        case 2 
            adjective1 = input('Enter adjective1: ', 's'); 
            adjective2 = input('Enter adjective2: ', 's'); 
            adjective3 = input('Enter adjective3: ', 's'); 
            adjective4 = input('Enter adjective4: ', 's'); 
            adjective5 = input('Enter adjective5: ', 's'); 
            adjective6 = input('Enter adjective6: ', 's'); 
            plural_noun1 = input('Enter plural_noun1: ', 's'); 
            plural_noun2 = input('Enter plural_noun2: ', 's'); 
            present_verb1 = input('Enter present_verb1: ', 's'); 
            present_verb2 = input('Enter present_verb2: ', 's'); 
            present_verb3 = input('Enter present_verb3: ', 's'); 
            noun1 = input('Enter noun1: ', 's'); 
            name1 = input('Enter name: ', 's'); 
            verb1 = input('Enter verb1: ', 's'); 
            family_member1 = input('Enter family_member1: ', 's'); 
            fprintf(1, '\n\nIn a/an %s galaxy not unlike ours, on a/an %s planet not \nunlike this one, there 
live a/an %s but curious group of %s.  \nEach of them are required to %s with a %s everyday, and if \nanyone 
forgets they are publicly shamed for their %s insubordination.  \nOne day, %s forgot this duty and decided 
to %s instead of \ntaking his/her punishment.  Obviously, the rest of the %s were \n%s and %s by his/her 
actions. There were not enough \n%s on the entire %s planet or in the %s \ngalaxy to excuse %s of his/her 
actions.  %s had no choice but to \n%s.  Surprisingly this was enough to gain %s the forgiveness of 
\nhis/her %s who eventually convinced the colony of %s \nto %s  %s. Needless to say, things either turned out 
good \nor bad for %s; it all depends on perspective.\n\n',adjective1, adjective2, adjective3, plural_noun1, 
present_verb1, noun1, adjective4, name1, present_verb2, plural_noun1, adjective5, adjective6, 
plural_noun2,adjective2,adjective1,name1,name1,verb1,name1,family_member1, plural_noun1, 
present_verb3,name1,name1); 
            fprintf(file, '\n\nIn a/an %s galaxy not unlike ours, on a/an %s planet not \nunlike this one, 
there live a/an %s but curious group of %s.  \nEach of them are required to %s with a %s everyday, and if 
\nanyone forgets they are publicly shamed for their %s insubordination.  \nOne day, %s forgot this duty and 
decided to %s instead of \ntaking his/her punishment.  Obviously, the rest of the %s were \n%s and %s by 
his/her actions. There were not enough \n%s on the entire %s planet or in the %s \ngalaxy to excuse %s of 
his/her actions.  %s had no choice but to \n%s.  Surprisingly this was enough to gain %s the forgiveness of 
\nhis/her %s who eventually convinced the colony of %s \nto %s  %s. Needless to say, things either turned out 
good \nor bad for %s; it all depends on perspective.\n\n',adjective1, adjective2, adjective3, plural_noun1, 
present_verb1, noun1, adjective4, name1, present_verb2, plural_noun1, adjective5, adjective6, 
plural_noun2,adjective2,adjective1,name1,name1,verb1,name1,family_member1, plural_noun1, 
present_verb3,name1,name1); 
        case 3 
            adjective1 = input('Enter adjective1: ', 's'); 
            adjective2 = input('Enter adjective2: ', 's'); 
            adjective3 = input('Enter adjective3: ', 's'); 
            occupation1 = input('Enter occupation1: ', 's'); 
            occupation2 = input('Enter occupational2: ', 's'); 
            type_of_shelter = input('Enter type_of_shelter: ', 's'); 
            number1 = input('Enter number1: ', 's'); 
            number2 = input('Enter number2: ', 's'); 
            unit_of_time = input('Enter unit_of_time: ', 's'); 
            present_verb1 = input('Enter present_verb1: ', 's'); 
            adverb = input('Enter adverb: ', 's'); 
            fprintf(1, '\n\nOnce upon a time there was a/an %s %s who sought the aid of a/an\n%s %s to help her 
escape from the dreadful %s\nshe has been locked in for the past %s %s. Finally after\nseveral newspaper ads 
and a couple of smoke signals the %s \n%s %s his way past the fire breathing dragon, through the \n%s foot deep 
moat, and up the %s tower.  At last the %s \n%s was saved and the couple was free to live %s ever 
after.\n\n',adjective1,occupation1,adjective2,occupation2,type_of_shelter,number1,unit_of_time,adjective2,occup
ation2,present_verb1,number2,adjective3,adjective1,occupation1,adverb); 
            fprintf(file, '\n\nOnce upon a time there was a/an %s %s who sought the aid of a/an\n%s %s to help 
her escape from the dreadful %s\nshe has been locked in for the past %s %s. Finally after\nseveral newspaper 
ads and a couple of smoke signals the %s \n%s %s his way past the fire breathing dragon, through the \n%s foot 
deep moat, and up the %s tower.  At last the %s \n%s was saved and the couple was free to live %s ever 
after.\n\n',adjective1,occupation1,adjective2,occupation2,type_of_shelter,number1,unit_of_time,adjective2,occup
ation2,present_verb1,number2,adjective3,adjective1,occupation1,adverb); 
    end 
    fclose(file); 
    a = input('Would you like to continue? Type yes to continue: ', 's'); 
    switch a 
        case {'yes', "Yes"} 
            cont = true;
        otherwise 
            cont = false; 
    end 
end 
%The command to print to the screen with the story is included for you in the MATLAB file, EWA_04_Output.m.   
%You must copy this statement and modify it to also print to the text file.   
%The user should have the choice to play again or quit.  