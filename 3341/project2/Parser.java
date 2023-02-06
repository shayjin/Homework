import java.io.IOException;

public class Parser {
    private Scanner S;

    public Parser(Scanner S) {
        this.S = S;
    }

    public ParseTree parse() throws IllegalStateException, IOException {
        return parseProg();
    }

    public ParseTree parseProg() throws IllegalStateException, IOException {
        ParseTree parseTree = new ParseTree();

        if (S.currToken != Fun.PROGRAM) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(Node.PROGRAM));
        S.nextTok();

        if (S.currToken != Fun.LBRACE) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(Node.LBRACE));
        S.nextTok();

        parseTree.add(parseDeclSeq(new ParseTree(Node.DECLSEQ)));

        if (S.currToken != Fun.BEGIN) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(Node.BEGIN));
        S.nextTok();

        return parseTree;
    }

    public ParseTree parseDeclSeq(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseDecl(new ParseTree(Node.DECL)));

        if (S.currentTok() == Fun.INT) {
            parseTree.add(parseDeclSeq(root));
        }

        return parseTree;
    }

    public ParseTree parseDecl(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        parseTree.add(parseDeclInt(new ParseTree(Node.DECLINT)));
        parseTree.add(parseDeclRef(new ParseTree(Node.DECLREF)));

        return parseTree;
    }

    public ParseTree parseDeclInt(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.INT) {
            return new ParseTree();
        }

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(Node.INT));
        S.nextTok();

        parseTree.add(parseIdList(new ParseTree(Node.IDLIST)));

        if (S.currentTok() != Fun.SEMICOLON) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(Node.SEMICOLON));
        S.nextTok();

        return parseTree;
    }
    
    public ParseTree parseIdList(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.ID) {
            throw new IllegalStateException("error msg");
        }

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(Node.ID, S.getID()));
        S.nextTok();

        while (S.currentTok() == Fun.COMMA) {
            parseTree.add(new ParseTree(Node.COMMA));
            S.nextTok();

            parseTree.add(parseIdList(root));
        }

        return parseTree;
    }

    public ParseTree parseDeclRef(ParseTree root) {
        return new ParseTree();
    }
}