class Cmpr {
	Expr expr1;
	Expr expr2;
	int option;
	
	void parse() {
		expr1 = new Expr();
		expr1.parse();
		if (Parser.scanner.currentTok() == Fun.EQUAL) {
			option = 0;
		} else if (Parser.scanner.currentTok() == Fun.LESS) {
			option = 1;
		} else if (Parser.scanner.currentTok() == Fun.LESSEQUAL) {
			option = 2;
		} else {
			System.out.println("ERROR: Expected EQUAL, LESS, or LESSEQUAL, recieved " + Parser.scanner.currentTok());
			System.exit(0);
		}
		Parser.scanner.nextTok();
		expr2 = new Expr();
		expr2.parse();
	}
	
	void semantic() {
		expr1.semantic();
		expr2.semantic();
	}
	
	void print() {
		expr1.print();
		switch(option) {
			case 0:
				System.out.print("==");
				break;
			case 1:
				System.out.print("<");
				break;
			case 2:
				System.out.print("<=");
				break;
		}
		expr2.print();
	}

	boolean execute() {

		if (option == 0) {
			return expr1.execute() == expr2.execute();
		}
		else if (option == 1) return expr1.execute() < expr2.execute();
		else if (option == 2) return expr1.execute() <= expr2.execute();
		return false;
	}
}
