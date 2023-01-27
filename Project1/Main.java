import java.io.IOException;

class Main {
	public static void main(String[] args) throws IOException {

		// Initialize the scanner with the input file
		Scanner S = new Scanner(args[0]);
		
		// Print the token stream
		while (S.currentTok() != Fun.EOS && S.currentTok() != Fun.ERROR) {

			// Print the current token, with any extra data needed
			System.out.print(S.currentTok());

			if (S.currentTok() == Fun.ID) {
				String value = S.getID();
				System.out.print("[" + value + "]");
			} else if (S.currentTok() == Fun.CONST) {
				int value = S.getCONST();
				System.out.print("[" + value + "]");
			}

			System.out.print("\n");

			// Advance to the next token
			S.nextTok();
		}

	}
}