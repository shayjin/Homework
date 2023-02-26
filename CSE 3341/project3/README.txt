Name: Jay Shin
Anyone I had discussions with: Nobody

Files: 
    - Assign.java, Cmpr.java, Cond.java, Decl.java, DeclInt.java, DeclRef.java, DeclSeq.java, Expr.java, 
      Factor.java, Fun.java, Id.java, IdList.java, If.java, Loop.java, Output.java, Parser.java,Program.java,
      Stmt.java, StmtSeq.java, Term.java: Java classes that represent each grammar rule.  
    - Main.java: Main Java class that tokenizes and parses the input program to executives the program and store the outputs.  
                 It can be compiled with the command "Javac Main.java" and 
                 executed with the command "Java Main Correct/#.code Correct/#.data" (replace # with the same numbers).
    - Scanner.java: Scanner class from project 1.
    - Fun.java: Enumuration for all reserved keywords and special symbols for the "Fun" language. 
    - Parser.java: Parser class from project 2.
    - Interpretor.java: Interpretor for project 3. Can allocate variables and assign values to variables in the closest scope. 
    - tester.sh: Test shell script. It can be run by the command "sh tester.sh". 
    - Correct: A folder that contains 30 correct test cases, their data inputs, and their expected outputs. 
    - Error: A folder that contains 2 incorrect test cases. 
    - README.txt: Description and overview of this project.

Overall Design: Pretty straightforward. The pattern was really similar to project 2. Just following the path 
                in the parse tree and calling and calling and calling until I reach dead end. 
                I created execute() functions in most of the files, which in most cases, called another class's execute() function.
                When it was a dead end, it printed a statement, calculated / read a value, or assigned a value to a variable. 
                When it entered a new scope with the keywords such as if and while, I called Interpretor.addContext()
                before entering the scope and Interpretor.deleteContext() after getting out of the scope.
                This created a new HashMap in the Stack stack, which was retrieved to add new variables in the scope
                and removed to get out of the scope. 
                Before entering begin, I put all the variables that were declared, in the HashMap global.
                I also created an extra HashMap to keep track of shared variables. This wasn't the most efficient way,
                but I couldn't think of any other ways. 
                When the non-terminal had multiple options for actions, for example, "Assign" can do 
                "new" assignment, "ref" assignment, and "<expr>" assignment, I split them up into if statments
                and provided them with corresponding actions. 

How I Tested: I built everything incremently. I followed the path in the grammar rules and whenever I reached a dead end, 
              I just ran the program with couple print statments in the middle to see if it was calling proper functions 
              and printing proper outputs. I also printed the the lists for all variables, to see if they are storing proper
              variables. Once I saw that it was working properly, I moved on to the next path in the parse tree. 
              Java algorithms to verify and cover edge cases. 

Speical features + comments: Nothing really. Just a basic executor. 
Bugs: "The heap can be represented by an array or list of integers. We will want the reference variables 
       to behave like references; we will simulate this by having the reference variables store an index 
       into the heap. "
      The description for crerating the heap of integers made no sense to me, especially "store an index" part,
      so I just implemented the heap in a differernt way. It's possible to implement the executor without using 
      heap and I still don't really understand why it is needed. 