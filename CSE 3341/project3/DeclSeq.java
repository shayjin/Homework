class DeclSeq {
	Decl decl;
	DeclSeq ds;
	
	void parse() {
		decl = new Decl();
		decl.parse();
		if (Parser.scanner.currentTok() != Fun.BEGIN) {
			ds = new DeclSeq();
			ds.parse();
		}
	}
	
	void semantic() {
		decl.semantic();
		if (ds != null) {
			ds.semantic();
		}
	}
	
	void print(int indent) {
		decl.print(indent);
		if (ds != null) {
			ds.print(indent);
		}
	}

	void execute() {
		decl.execute();
		if (ds != null ) ds.execute();
	}
}
