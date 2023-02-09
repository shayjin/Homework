import java.io.IOException;

class Main {
	public static void main(String[] args) throws IOException {

		// Initialize the scanner with the input file
		Scanner S = new Scanner(args[0]);
		Parser P = new Parser(S);

		ParseTree parseTree = P.parse();
		parseTree.prettyPrint();
	}
}