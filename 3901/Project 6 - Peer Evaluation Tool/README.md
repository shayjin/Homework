# project6-team5
* enter "bundle install".
* enter "rails s" to execute the program.

The program creates a web application for presentation evaluations. The application will enable each audience member 
to log in to a personal account and in this account they will be able to submit feedback and evaluations for each
of the presenters in a group. The application will then log these evaluations into a database and make a collection 
of feedback that can be viewed as constructive criticism for the specified presenter. Each person who presented should be
able to see the scores/grades and comments/feedback for each of the presentations given for the class. In addition to 
helping students, this collection of information should also be useful for instructors when giving individual grades
and enable them access grades/feedback and enable them to create instances for a new presentation evaluation.

The Gemfile contains each of the versions required for each gem. If RubyMine is running a version of Ruby other than 3.1.0,
click the down arrow in the RubyMine terminal (next to the '+') and choose "Settings". In the pop-up menu choose:
Languages & Frameworks -> Ruby SDK & Gems -> (make sure v 3.0.1 is selected)

After entering the rails command above you should see the Application information consisting of the Rails and Puma server info,
the thread and PID info, and also a link with HTTP/IP information for where the application can be accessed in a web browser.

After opening the web page a "Log in" page will pop up, and you can either log in with an existing account or 
create a new account with the "Sign Up" link. After accessing the account, there will be a welcome page and 
in the top left are options to view Grades, enter Peer Evaluations, edit the profile of the account, and an option to 
return to the welcome screen. On the top right of the page is an option to sign out of the account.

Each account will have attributes for a group number, course name, account name, email address, password, and also an option to delete 
the account. Accounts can be either a student or a professor account, and theseSQLite3 is used to create a database for the application with tables and attributes. Rails and Puma are used to build the application and establish a server,
and javascript and CSS are used to style the user interface of the web page. 

If at any point you wish to kill the server, enter "Ctrl+c" in the terminal to do so and stop the program from running.