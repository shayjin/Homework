class StmtSeq {
	Stmt stmt;
	StmtSeq ss;
	
	void parse() {
		if (Parser.scanner.currentTok() == Fun.ID) {
			stmt = new Assign();
		} else if (Parser.scanner.currentTok() == Fun.WRITE) {
			stmt = new Output();
		}  else if (Parser.scanner.currentTok() == Fun.IF) {
			stmt = new If();
		} else if (Parser.scanner.currentTok() == Fun.WHILE) {
			stmt = new Loop();
		}  else if (Parser.scanner.currentTok() == Fun.INT || Parser.scanner.currentTok() == Fun.REF) {
			stmt = new Decl();
		} else {
			System.out.println("ERROR: Bad start to statement: " + Parser.scanner.currentTok());
			System.exit(0);
		}
		stmt.parse();
		if ((Parser.scanner.currentTok() != Fun.END) 
			&& (Parser.scanner.currentTok() != Fun.RBRACE)) {
			ss = new StmtSeq();
			ss.parse();
		}
	}
	
	void semantic() {
		stmt.semantic();
		if (ss != null) {
			ss.semantic();
		}
	}
			
	void print(int indent) {
		stmt.print(indent);
		if (ss != null) {
			ss.print(indent);
		}
	}

	void execute() {
		stmt.execute();
		if (ss != null) ss.execute();
	}
}
