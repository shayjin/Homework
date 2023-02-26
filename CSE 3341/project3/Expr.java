class Expr {
	Term term;
	Expr expr;
	int option;
	
	void parse() {
		term  = new Term();
		term.parse();
		if (Parser.scanner.currentTok() == Fun.ADD) {
			option = 1;
		} else if (Parser.scanner.currentTok() == Fun.SUB) {
			option = 2;
		}
		if (option != 0) {
			Parser.scanner.nextTok();
			expr = new Expr();
			expr.parse();
		}						
	}
	
	void semantic() {
		term.semantic();
		if (expr != null) {
			expr.semantic();
		}
	}
	
	void print() {
		term.print();
		if (option == 1) {
			System.out.print("+");
			expr.print();
		} else if (option == 2) {
			System.out.print("-");
			expr.print();
		}
	}

	int execute() {
		if (option == 1) return term.execute() + expr.execute();
		else if (option == 2) return term.execute() - expr.execute();
		else return term.execute();
	}
}
