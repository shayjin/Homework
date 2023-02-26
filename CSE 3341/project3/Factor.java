class Factor {
	Id id;
	int constant;
	Expr expr;
	Boolean input;
	
	void parse() {
		if (Parser.scanner.currentTok() == Fun.ID) {
			id = new Id();
			id.parse();
		} else if (Parser.scanner.currentTok() == Fun.CONST) {
			constant = Parser.scanner.getCONST();
			Parser.scanner.nextTok();
		} else if (Parser.scanner.currentTok() == Fun.LPAREN) {
			Parser.scanner.nextTok();
			expr = new Expr();
			expr.parse();
			Parser.expectedToken(Fun.RPAREN);
			Parser.scanner.nextTok();
		} else if(Parser.scanner.currentTok() == Fun.READ) {
			Parser.scanner.nextTok();
			Parser.expectedToken(Fun.LPAREN);
			Parser.scanner.nextTok();
			Parser.expectedToken(Fun.RPAREN);
			Parser.scanner.nextTok();
			input = true;
		} else {
			System.out.println("ERROR: Expected ID, CONST, LPAREN, or READ, recieved " + Parser.scanner.currentTok());
			System.exit(0);
		}
	}
	
	void semantic() {
		if (id != null) {
			id.semantic();
		} else if (expr != null) {
			expr.semantic();
		}
	}
	
	void print() {
		if (id != null) {
			id.print();
		} else if (expr != null) {
			System.out.print("(");
			expr.print();
			System.out.print(")");
		} else if (input != null) {
			System.out.print("read()");
		} else {
			System.out.print(constant);
		}
	}

	int execute() {

		if (id != null) return id.returnId();
		else if (expr != null) return expr.execute();
		else if (input != null && input) {
			int value = Interpretor.scanner.getCONST();
			Interpretor.scanner.nextTok();
			if (Interpretor.scanner.currentTok() == Fun.EOS) {
				System.out.println("input error");
				System.exit(-1);
				return 0;
			}
			return value;
		}
		else return constant;
	}
}
