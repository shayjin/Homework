Name: Jay Shin (shin.810@osu.edu)
Anyone I had discussions with: Nobody

Files (for project 2): 
    - Parser.java: A class that uses Scanner from project 1 to read input text files to tokenize & parse them. 
                   It parses all tokens by following the grammar rule from the project description. 
                   When and error is found while parsing, it outputs an error message and stops parsing. 
    - ParseTree.java: A class that represents a parse tree. Can have children of the same type. 
                      Does semantic checking while pretty-printing. 
    - NodeType.java: Enumration for all type of Nodes specified in the grammar rule. 
    - Main.java: Main Java class that initializes the instances of Scanner and Parser and runs them.  
                 It can be compiled with the command "Javac Main.java" and 
                 executed with the command "Java Main Correct/#.code" (replace # with a number).
    - tester.sh: Test shell script. It can be run by the command "sh tester.sh". 
    - Correct: A folder that contains 13 correct test cases and their expected outputs. 
    - Error: A folder that contains 4 incorrect test cases. 
    - README.txt: Description and overview of this project.

Files (from project 1):
    - Fun.java: Enumuration for all reserved keywords and special symbols for the "Fun" language. 
    - Scanner.java: A class that reads input text files and outputs a stream of tokens from the Fun.java enumeration. 


Overall Design: 
    ParseTree: I designed the ParseTree.java class and an object of it represents a single node in the tree.
               Each tree contains a List of children nodes and each child contains their List of children nodes and so on. 
               ParseTree has 3 types of constructors:
                  1. ParseTree() takes no arguments -> doesn't have a type -> will be discarded when added. 
                  2. ParseTree(NodeType type, String value) represents tokens with values: ID & CONST. 
                  3. ParseTree(NodeType type) is the default -> represents for all tokens other than ID and CONST. 
    Parser: In the Parser.java class, I implemented every single grammar rules specified in the project 2 description. 
            I used Scanner from project 1 to tokenize through the text file and compared the actual token with the expected token. 
            If an unexpected token was present or a token was at a wrong place, I exited the system with an appropriate error message. 
            If a token was present at the right place, I recursively followed the grammar rules and called necesassary functions until the end of the branch is reached. 
    How I Tested: I built everything incremently. I followed the path in the grammar rules and whenever I reached a dead end, 
                  I added a print statement in the ParseTree.add(ParseTree parseTree) function and ran the program to see the 
                  types of nodes that were added so far. Once I saw that it was working properly, I moved on to the next path in the parse tree. 
                  Some Java algorithms to verify and cover edge cases. 

Speical features + comments: Nothing really. Just a basic parser. 
Bugs: In project 1, the "READ" token didn't have parenthesis after, but in project 2, "READ" token was represented as "read()" in the example text files. 
      I just followed the text files from project 2 and represented it as "read()". 