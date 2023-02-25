class Decl implements Stmt {
	DeclInt declInt;
	DeclRef declRef;
	
	public void parse() {
		if (Parser.scanner.currentTok() == Fun.INT) {
			declInt = new DeclInt();
			declInt.parse();
		} else {
			declRef = new DeclRef();
			declRef.parse();
		}
	}
	
	public void semantic() {
		if (declInt != null) {
			declInt.semantic();
		} else {
			declRef.semantic();
		}
	}
	
	public void print(int indent) {
		if (declInt != null) {
			declInt.print(indent);
		} else {
			declRef.print(indent);
		}
	}

	public void execute() {
		if (declInt != null) declInt.execute();
		else if (declRef != null) declRef.execute();
	}
}
