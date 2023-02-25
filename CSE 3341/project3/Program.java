import java.util.*;

class Program {
	DeclSeq ds;
	StmtSeq ss;
	
	void parse() {
		Parser.expectedToken(Fun.PROGRAM);
		Parser.scanner.nextTok();
		Parser.expectedToken(Fun.LBRACE);
		Parser.scanner.nextTok();
		if (Parser.scanner.currentTok() != Fun.BEGIN) {
			ds = new DeclSeq();
			ds.parse();
		}
		Parser.expectedToken(Fun.BEGIN);
		Parser.scanner.nextTok();
		Parser.expectedToken(Fun.LBRACE);
		Parser.scanner.nextTok();
		ss = new StmtSeq();
		ss.parse();
		Parser.expectedToken(Fun.RBRACE);
		Parser.scanner.nextTok();
		Parser.expectedToken(Fun.RBRACE);
		Parser.scanner.nextTok();
		Parser.expectedToken(Fun.EOS);
	}
	
	void semantic() {
		Parser.scopes = new Stack<HashMap<String, Fun>>();
		Parser.scopes.push(new HashMap<String, Fun>());
		if (ds != null) {
			ds.semantic();
		}
		Parser.scopes.push(new HashMap<String, Fun>());
		ss.semantic();
		Parser.scopes.pop();
	}
	
	void print() {
		System.out.println("program {");
		if (ds != null) {
			ds.print(1);
		}
		System.out.println("\tbegin {");
		ss.print(2);
		System.out.println("\t}");
		System.out.println("}");
	}

	void execute() {
		Executor.init();
		if (ds != null) ds.execute();
		ss.execute();
	}
}
