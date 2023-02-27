class Id {
	String identifier;
	
	void parse() {
		Parser.expectedToken(Fun.ID);
		identifier = Parser.scanner.getID();
		Parser.scanner.nextTok();
	}
	
	// Called to check if the identifier has been declared
	void semantic() {
		if (Parser.nestedScopeCheck(identifier)==Fun.ERROR) {
			System.out.println("ERROR: No matching declaration found: " + identifier);
			System.exit(0);
		}
	}
	
	//Called by IdList semantic functions to check for doubly declared variables
	void doublyDeclared() {
		if (Parser.currentScopeCheck(identifier)!=Fun.ERROR) {
			System.out.println("ERROR: Doubly declared variable detected: " + identifier);
			System.exit(0);
		}
	}
	
	//Called by IdList semantic functions to add the variable to the scopes data structure in Parser
	void addToScopes(Fun type) {
		Parser.scopes.peek().put(identifier, type);
	}
	
	//Called by Assign semantic function to check the declared type of the variable
	Fun checkType() {
		return Parser.nestedScopeCheck(identifier);
	}
	
	void print() {
		System.out.print(identifier);
	}

	void allocateId() {
		Interpretor.allocate(identifier, 0);
		Interpretor.allocateOnHeap(identifier);
	}

	void allocateRef() {
		Interpretor.allocate(identifier);
	}

	void assignRef() {
		Interpretor.allocateOnHeap(identifier);
	}

	void assignShare(Id val) {
		Interpretor.allocateShare(identifier, val.identifier); 
	}

	void assignExpr(Expr expr) {
		Interpretor.assign(identifier, expr.execute());
	}

	void allocateOnHeap() {
		Interpretor.allocateOnHeap(identifier);
	}

	int returnId() {
		return Interpretor.search(identifier);
	}
}
