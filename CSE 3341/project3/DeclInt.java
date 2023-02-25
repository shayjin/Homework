class DeclInt {
	IdList list;
	
	public void parse() {
		Parser.expectedToken(Fun.INT);
		Parser.scanner.nextTok();
		list = new IdList();
		list.parse();
		Parser.expectedToken(Fun.SEMICOLON);
		Parser.scanner.nextTok();
	}
	
	public void semantic() {
		list.semanticIntVars();
	}
	
	public void print(int indent) {
		for (int i=0; i<indent; i++) {
			System.out.print("\t");
		}
		System.out.print("int ");
		list.print();
		System.out.println(";");
	}

	void execute() {
		list.executeId();
	}
}
