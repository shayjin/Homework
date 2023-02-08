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

    public void add(ParseTree parseTree) {
        if (parseTree.type != null) {
            children.add(parseTree);
            System.out.println(parseTree.type);
        }
    }
}   
