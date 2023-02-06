public class Parser {
    private Scanner S;

    public Parser(Scanner S) {
        this.S = S;
    }

    public ParseTree parse() {
        return new ParseTree();
    }
}
