import java.util.ArrayList;
import java.util.List;

public class ParseTree {

    private NodeType type;
    private String value;
    private List<ParseTree> children;

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
            System.out.println(this.type);
        } 

        for (int i = 0; i < this.children.size(); i++) {
            ParseTree node = this.children.get(i);
            node.prettyPrint();
        }
    }
}   
