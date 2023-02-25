class DeclRef {
	IdList list;
	
	public void parse() {
		Parser.expectedToken(Fun.REF);
		Parser.scanner.nextTok();
		list = new IdList();
		list.parse();
		Parser.expectedToken(Fun.SEMICOLON);
		Parser.scanner.nextTok();
	}
	
	public void semantic() {
		list.semanticRefVars();
	}
	
	public void print(int indent) {
		for (int i=0; i<indent; i++) {
			System.out.print("\t");
		}
		System.out.print("reference ");
		list.print();
		System.out.println(";");
	}

	void execute() {
		list.executeRef();
	}
}
