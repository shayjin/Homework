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
    - Executor.java: Executor for project 3. Can allocate variables and assign values to variables in the closest scope. 
    - tester.sh: Test shell script. It can be run by the command "sh tester.sh". 
    - Correct: A folder that contains 30 correct test cases, their data inputs, and their expected outputs. 
    - Error: A folder that contains 2 incorrect test cases. 
    - README.txt: Description and overview of this project.

Overall Design: 



Speical features + comments: Nothing really. Just a basic executor. 
Bugs: "The heap can be represented by an array or list of integers. We will want the reference variables 
       to behave like references; we will simulate this by having the reference variables store an index 
       into the heap. "
      The description for crerating the heap of integers made no sense to me, especially "store an index" part,
      so I just implemented the heap in a differernt way. It's possible to implement the executor without using 
      heap and I still don't really understand why it is needed. 