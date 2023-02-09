import java.util.ArrayList;
import java.util.List;

import org.w3c.dom.Node;

public class ParseTree {

    private NodeType type;
    private String value;
    private List<ParseTree> children;
    private static int indent = 0;
    private static int space = 1;
    private final int offset = 4;
    private static boolean start = true;
    private static NodeType prev;
    private static String prevVal;

    static String tempVar = "";

    private static String recent = "";

    private static List<List<String>> variables = new ArrayList<List<String>>();
    private static List<List<String>> references = new ArrayList<List<String>>();

    public ParseTree() {
        this.children = new ArrayList<ParseTree>();
    }

    public ParseTree(NodeType type) {
        this.type = type;
        this.children = new ArrayList<ParseTree>();
    }

    public ParseTree(NodeType type, String value) {
        this.type = type;
        this.value = value;
        this.children = new ArrayList<ParseTree>();
    }

    public List<ParseTree> getChildren() {
        return this.children;
    }

    public void add(ParseTree parseTree) {
        if (parseTree.type != null) {
            children.add(parseTree);
        }
    }

    public void prettyPrint() {
        if (this.children.size() == 0) {
            if (start) {
                if (prev == NodeType.RBRACE && this.type != NodeType.ELSE) {
                    System.out.println();
                } 

                if (this.type == NodeType.RBRACE) {
                    indent -= offset;
                } 

                if (this.type == NodeType.ELSE) printSpaces(space);
                else printSpaces(indent);
                start = false;
            } else {
                if (
                    this.type != NodeType.SEMICOLON && 
                    this.type != NodeType.RPAREN && 
                    this.type != NodeType.LPAREN &&
                    this.type != NodeType.COMMA &&
                    prev != NodeType.LPAREN
                ) printSpaces(space);
            }

            printToken(this.type, this.value);

            if (this.type == NodeType.LBRACE) {
                indent += offset;
                System.out.println();
                start = true;
            } else if (this.type == NodeType.SEMICOLON) {
                start = true;
                System.out.println();
            } else if (this.type == NodeType.RBRACE) {
                start = true;
            }

            prev = this.type;
            prevVal = this.value;
        } 

        for (int i = 0; i < this.children.size(); i++) {
            ParseTree node = this.children.get(i);
            node.prettyPrint();
        }
    }

    public void printToken(NodeType type, String value) {
        String token = "";
        
        switch (type) {
            case LBRACE: token = "{"; break;
            case RBRACE: token = "}"; break;
            case REF: token = "reference"; break;
            case ADD: token = "+"; break;
            case SUB: token = "-"; break;
            case MULT: token = "*"; break;
            case ID: token = value; break;
            case CONST: token = value; break;
            case ASSIGN: token = "="; break;
            case EQUAL: token = "=="; break;
            case LPAREN: token = "("; break;
            case RPAREN: token = ")"; break;
            case SEMICOLON: token = ";"; break;
            case COMMA: token = ","; break;
            case INSTANCE: token = "inst"; break;
            case LESS: token = "<"; break;
            case LESSEQUAL: token = "<="; break;
            case NEGATION: token = "!"; break;
            case READ: token = "read()"; break;
            default: token = type.toString().toLowerCase();
        }

        System.out.print(token);

        if (type == NodeType.LBRACE) {
            variables.add(new ArrayList<String>());
            references.add(new ArrayList<String>());
        } else if (prev == NodeType.COMMA) {
            if (recent == "ref") {
                List<String> temp = references.get(references.size() - 1);

                if (variables.get(variables.size() - 1).contains(token)) {
                    throw new IllegalStateException("duplicate variables");
                }
    
                temp.add(token);

                references.set(references.size() - 1, temp);
            } else if (recent == "int") {
                List<String> temp = variables.get(variables.size() - 1);

                if (variables.get(variables.size() - 1).contains(token)) {
                    throw new IllegalStateException("duplicate variables");
                }
    
                temp.add(token);

                variables.set(variables.size() - 1, temp);
            }


        } else if (prev == NodeType.INT) {
            List<String> temp = variables.get(variables.size() - 1);

            if (variables.get(variables.size() - 1).contains(token)) {
                throw new IllegalStateException("duplicate variables");
            }

            temp.add(token);
            variables.set(variables.size() - 1, temp);
            recent = "int";
        } else if (prev == NodeType.REF) {
            List<String> temp = references.get(references.size() - 1);

            if (references.get(references.size() - 1).contains(token)) {
                throw new IllegalStateException("duplicate variables");
            }

            temp.add(token);
            references.set(references.size() - 1, temp);

            recent = "ref";
        } else if (type == NodeType.RBRACE) {
            variables.remove(variables.size() - 1);
        } else if (type == NodeType.ASSIGN) {
            tempVar = prevVal;
        } else if (type == NodeType.SHARE) {
            boolean contains = false;

            for (List<String> scope : references) {
                if (scope.contains(tempVar)) {
                    contains = true;
                }
            }

            if (!contains) {
                throw new IllegalStateException("int variable " + tempVar + " used in 'id = share id' assignment");
            }
        } else if (type == NodeType.ID) {
            boolean contains = false;
            boolean contains2 = false;

            for (List<String> scope : variables) {
                if (scope.contains(token)) {
                    contains = true;
                }
            }

            for (List<String> scope : references) {
                if (scope.contains(token)) {
                    contains2 = true;
                }
            }

            if (!contains && !contains2) {
                throw new IllegalStateException(token + " is an undeclared varialble. ");
            }

            if (prev == NodeType.SHARE) {
                if (!contains2) {
                    throw new IllegalStateException("int variable used in 'id = share id' assignment");
                }
            }
        }
    }

    public void printSpaces(int space) {
        for (int i = 0; i < space; i++) {
            System.out.print(" ");
        }
    }
} 