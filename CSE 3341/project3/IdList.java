class IdList {
	Id id;
	IdList list;
	
	void parse() {
		id = new Id();
		id.parse();
		if (Parser.scanner.currentTok() == Fun.COMMA) {
			Parser.scanner.nextTok();
			list = new IdList();
			list.parse();
		} 
	}
	
	// Called by DeclInt.semantic
	void semanticIntVars() {
		id.doublyDeclared();
		id.addToScopes(Fun.INT);
		if (list != null) {
			list.semanticIntVars();
		}
	}
	
	// Called by DeclClass.semantic
	void semanticRefVars() {
		id.doublyDeclared();
		id.addToScopes(Fun.REF);
		if (list != null) {
			list.semanticRefVars();
		}
	}
	
	void print() {
		id.print();
		if (list != null) {
			System.out.print(",");
			list.print();
		}
	}

	void executeId() {
		id.allocateId();

		if (list != null) list.executeId();
	}

	void executeRef() {
		id.allocateRef();

		if (list != null) list.executeRef();
	}
}
