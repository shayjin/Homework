class Term {
	Factor factor;
	Term term;
	
	void parse() {
		factor = new Factor();
		factor.parse();
		if (Parser.scanner.currentTok() == Fun.MULT) {
			Parser.scanner.nextTok();
			term = new Term();
			term.parse();
		}				
	}
	
	void semantic() {
		factor.semantic();
		if (term != null) {
			term.semantic();
		}
	}
	
	void print() {
		factor.print();
		if (term != null) {
			System.out.print("*");
			term.print();
		}
	}

	int execute() {
		if (term != null) {
			return factor.execute() * term.execute();
		} else {
			return factor.execute();
		}
	}
}
