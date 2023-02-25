class Assign implements Stmt {
	// type is 1 if "new" assignment, 2 if "ref" assignment, 3 if "<expr>" assignment
	int type;
	// assignTo is the id on the LHS of assignment
	Id assignTo;
	// assignFrom is the id on RHS of "ref" assignment
	Id assignFrom;
	Expr expr;
	
	public void parse() {
		assignTo = new Id();
		assignTo.parse();
		Parser.expectedToken(Fun.ASSIGN);
		Parser.scanner.nextTok();
		if (Parser.scanner.currentTok() == Fun.NEW) {
			type = 1;
			Parser.scanner.nextTok();
			Parser.expectedToken(Fun.INSTANCE);
			Parser.scanner.nextTok();
		} else if (Parser.scanner.currentTok() == Fun.SHARE) {
			type = 2;
			Parser.scanner.nextTok();
			assignFrom = new Id();
			assignFrom.parse();
		} else {
			type = 3;
			expr = new Expr();
			expr.parse();
		}
		Parser.expectedToken(Fun.SEMICOLON);
		Parser.scanner.nextTok();
	}
	
	public void semantic() {
		assignTo.semantic();
		if (type == 1) {
			if (assignTo.checkType() != Fun.REF) {
				System.out.println("ERROR: int variable used in new assignment");
				System.exit(0);
			}
		} else if (type == 2) {
			if (assignTo.checkType() != Fun.REF) {
				System.out.println("ERROR: int variable used in ref assignment");
				System.exit(0);
			}
			if (assignFrom.checkType() != Fun.REF) {
				System.out.println("ERROR: int variable used in ref assignment");
				System.exit(0);
			}
		} else {
			expr.semantic();
		}
	}
	
	public void print(int indent) {
		for (int i=0; i<indent; i++) {
			System.out.print("\t");
		}
		assignTo.print();
		System.out.print("=");
		if (type == 1) {
			System.out.print("new inst");
		} else if (type == 2) {
			System.out.print("share ");
			assignFrom.print();
		} else {
			expr.print();
		}
		System.out.println(";");
	}

	public void execute() {
		if (type == 1) {
			assignTo.allocateOnHeap();
		} else if (type == 2) {
			assignTo.assign(assignFrom);
		} else if (type == 3) {
			assignTo.assignExpr(expr);
		}
	}
}
