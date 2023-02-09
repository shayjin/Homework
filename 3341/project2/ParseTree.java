import java.util.ArrayList;
import java.util.List;

public class ParseTree {

    private NodeType type;
    private String value;
    private List<ParseTree> children;
    private static int indent = 0;
    private static int space = 1;
    private static boolean start = true;

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
                if (this.type == NodeType.RBRACE) indent -= space;
                printSpaces(indent);
                start = false;
            } else {
                if (this.type != NodeType.SEMICOLON) printSpaces(space);
            }

            printToken(this.type, this.value);

            if (this.type == NodeType.LBRACE) {
                indent += space;
                System.out.println();
                start = true;
            } else if (this.type == NodeType.SEMICOLON) {
                System.out.println();
                start = true;
            } else if (this.type == NodeType.RBRACE) {
                System.out.println();
                start = true;
            }
        } 

        for (int i = 0; i < this.children.size(); i++) {
            ParseTree node = this.children.get(i);
            node.prettyPrint();
        }
    }

    public void printToken(NodeType type, String value) {
        String token = "";
        
        switch (type.toString()) {
            case "LBRACE": token = "{"; break;
            case "RBRACE": token = "}"; break;
            case "REF": token = "reference"; break;
            case "ADD": token = "+"; break;
            case "SUB": token = "-"; break;
            case "MULT": token = "*"; break;
            case "ID": token = value; break;
            case "CONST": token = value; break;
            case "ASSIGN": token = "="; break;
            case "SEMICOLON": token = ";"; break;
            default: token = type.toString().toLowerCase();
        }

        System.out.print(token);

    }

    public void printSpaces(int space) {
        for (int i = 0; i < space; i++) {
            System.out.print(" ");
        }
    }

}   
