import java.io.IOException;

public class Parser {
    private Scanner S;
    private static NodeType prev;

    public Parser(Scanner S) {
        this.S = S;
    }

    private void errorMsg(String expected, String found) {
        System.out.println("\nERROR: Token '" + expected + "' expected but token '" + found + "' found. ");
        System.exit(-1);
    }

    private void errorMsg(String found) {
        System.out.println("\nERROR: Token '" + found + "' found at an unexpected place. ");
        System.exit(-1);
    }

    public ParseTree parse() throws IOException {
        return parseProg();
    }

    private ParseTree parseProg() throws IOException {
        ParseTree parseTree = new ParseTree();

        if (S.currentTok() != Fun.PROGRAM) errorMsg("program", S.currentTok().toString());
        

        parseTree.add(new ParseTree(NodeType.PROGRAM));
        S.nextTok();

        if (S.currentTok() != Fun.LBRACE) errorMsg("{", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.LBRACE));
        S.nextTok();

        parseTree.add(parseDeclSeq(new ParseTree(NodeType.DECLSEQ)));

        if (S.currentTok() != Fun.BEGIN) errorMsg("begin", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.BEGIN));
        S.nextTok();

        if (S.currentTok() != Fun.LBRACE) errorMsg("{", S.currentTok().toString());
        parseTree.add(new ParseTree(NodeType.LBRACE));
        S.nextTok();

        parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));

        if (S.currentTok() != Fun.RBRACE) errorMsg("}", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.RBRACE));
        S.nextTok();


        if (S.currentTok() != Fun.RBRACE) errorMsg("}", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.RBRACE));
        S.nextTok();

        if (S.currentTok() != Fun.EOS) {
            errorMsg(S.currentTok().toString());
        }

        return parseTree;
    }

    private ParseTree parseDeclSeq(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseDecl(new ParseTree(NodeType.DECL)));

        if (S.currentTok() == Fun.INT) parseTree.add(parseDeclSeq(new ParseTree(NodeType.DECLSEQ)));

        return parseTree;
    }

    private ParseTree parseDecl(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        parseTree.add(parseDeclInt(new ParseTree(NodeType.DECLINT)));
        parseTree.add(parseDeclRef(new ParseTree(NodeType.DECLREF)));

        if (parseTree.getChildren().size() == 0) return new ParseTree();

        return parseTree;
    }

    private ParseTree parseDeclInt(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.INT) return new ParseTree();

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(NodeType.INT));
        S.nextTok();

        parseTree.add(parseIdList(new ParseTree(NodeType.IDLIST)));

        if (S.currentTok() != Fun.SEMICOLON) errorMsg(";", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.SEMICOLON));
        S.nextTok();

        return parseTree;
    }
    
    private ParseTree parseIdList(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.ID) errorMsg("id", S.currentTok().toString());

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(NodeType.ID, S.getID()));
        S.nextTok();

        while (S.currentTok() == Fun.COMMA) {
            parseTree.add(new ParseTree(NodeType.COMMA));
            S.nextTok();

            parseTree.add(parseIdList(new ParseTree(NodeType.IDLIST)));
        }

        return parseTree;
    }

    private ParseTree parseDeclRef(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.REF) {
            return new ParseTree();
        }

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(NodeType.REF));
        S.nextTok();

        parseTree.add(parseIdList(new ParseTree(NodeType.IDLIST)));

        if (S.currentTok() != Fun.SEMICOLON) errorMsg(";", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.SEMICOLON));
        S.nextTok();

        return parseTree;
    }

    private ParseTree parseStmtSeq(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        parseTree.add(parseStmt(new ParseTree(NodeType.STMT)));
        
        if (S.currentTok() == Fun.ID || S.currentTok() == Fun.IF || 
            S.currentTok() == Fun.WHILE || S.currentTok() == Fun.WRITE ||
            S.currentTok() == Fun.INT || S.currentTok() == Fun.REF) {
            parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));
        }
        
        return parseTree;
    }

    private ParseTree parseStmt(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseAssign(new ParseTree(NodeType.ASSIGN)));
        parseTree.add(parseIf(new ParseTree(NodeType.IF)));
        parseTree.add(parseLoop(new ParseTree(NodeType.LOOP)));
        parseTree.add(parseOut(new ParseTree(NodeType.OUT)));

        parseTree.add(parseDecl(new ParseTree(NodeType.DECL)));

        return parseTree;
    }

    private ParseTree parseAssign(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.ID) {
            return new ParseTree();
        }

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(NodeType.ID, S.getID()));
        S.nextTok();

        if (S.currentTok() != Fun.ASSIGN) errorMsg("=", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.ASSIGN));
        S.nextTok();

        if (S.currentTok() == Fun.NEW) {
            parseTree.add(new ParseTree(NodeType.NEW));
            S.nextTok();

            if (S.currentTok() != Fun.INSTANCE) errorMsg("instance", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.INSTANCE));
            S.nextTok();

            if (S.currentTok() != Fun.SEMICOLON) errorMsg(";", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.SEMICOLON));
            S.nextTok();

            return parseTree;
        } else if (S.currentTok() == Fun.SHARE) {
            parseTree.add(new ParseTree(NodeType.SHARE));
            S.nextTok();

            if (S.currentTok() != Fun.ID) errorMsg("id", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.ID, S.getID()));
            S.nextTok();

            if (S.currentTok() != Fun.SEMICOLON) errorMsg(";", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.SEMICOLON));
            S.nextTok();

            return parseTree;
        } else {
            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));

            if (S.currentTok() != Fun.SEMICOLON) errorMsg(";", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.SEMICOLON));
            S.nextTok();
        }

        return parseTree;
    }

    private ParseTree parseExpr(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseTerm(new ParseTree(NodeType.TERM)));

        if (S.currentTok() == Fun.ADD) {
            parseTree.add(new ParseTree(NodeType.ADD));
            S.nextTok();

            prev = NodeType.ADD;
            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));
        } else if (S.currentTok() == Fun.SUB) {
            parseTree.add(new ParseTree(NodeType.SUB));
            S.nextTok();

            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));
        } 

        return parseTree;
    }

    private ParseTree parseTerm(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseFactor(new ParseTree(NodeType.FACTOR)));

        if (S.currentTok() == Fun.MULT) {
            parseTree.add(new ParseTree(NodeType.MULT));
            S.nextTok();

            parseTree.add(parseTerm(new ParseTree(NodeType.TERM)));
        }

        return parseTree;
    }

    private ParseTree parseIf(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.IF) {
            return new ParseTree();
        }

        ParseTree parseTree = root;

        parseTree.add(new ParseTree(NodeType.IF));
        S.nextTok();

        parseTree.add(parseCond(new ParseTree(NodeType.COND)));

        if (S.currentTok() != Fun.THEN) errorMsg("then", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.THEN));
        S.nextTok();

        if (S.currentTok() != Fun.LBRACE) errorMsg("{", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.LBRACE));
        S.nextTok();

        parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));

        if (S.currentTok() != Fun.RBRACE) errorMsg("}", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.RBRACE));
        S.nextTok();

        if (S.currentTok() == Fun.ELSE) {
            parseTree.add(new ParseTree(NodeType.ELSE));
            S.nextTok();

            if (S.currentTok() != Fun.LBRACE) errorMsg("{", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.LBRACE));
            S.nextTok();

            parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));

            if (S.currentTok() != Fun.RBRACE) errorMsg("}", S.currentTok().toString());
            
            parseTree.add(new ParseTree(NodeType.RBRACE));
            S.nextTok();
        } 

        return parseTree;
    }

    private ParseTree parseLoop(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.WHILE) {
            return new ParseTree();
        }

        ParseTree parseTree = root;

        parseTree.add(new ParseTree(NodeType.WHILE));
        S.nextTok();

        parseTree.add(parseCond(new ParseTree(NodeType.COND)));

        if (S.currentTok() != Fun.LBRACE) errorMsg("{", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.LBRACE));
        S.nextTok();

        parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));

        if (S.currentTok() != Fun.RBRACE) errorMsg("}", S.currentTok().toString());

        parseTree.add(new ParseTree(NodeType.RBRACE));
        S.nextTok();

        return parseTree;
    }

    private ParseTree parseCond(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        if (S.currentTok() == Fun.NEGATION) {
            parseTree.add(new ParseTree(NodeType.NEGATION));
            S.nextTok();

            if (S.currentTok() != Fun.LPAREN) errorMsg("(", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.LPAREN));
            S.nextTok();

            parseTree.add(parseCond(new ParseTree(NodeType.COND)));

            if (S.currentTok() != Fun.RPAREN) errorMsg(")", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.RPAREN));
            S.nextTok();
        } else {
            parseTree.add(parseCompr(new ParseTree(NodeType.COMPR)));

            if (S.currentTok() == Fun.OR) {
                parseTree.add(new ParseTree(NodeType.OR));
                S.nextTok();
    
                parseTree.add(parseCond(new ParseTree(NodeType.COND)));
            } 
        }

        return parseTree;
    }

    private ParseTree parseOut(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        if (S.currentTok() == Fun.WRITE) {
            parseTree.add(new ParseTree(NodeType.WRITE));
            S.nextTok();
    
            if (S.currentTok() != Fun.LPAREN) errorMsg("(", S.currentTok().toString());
    
            parseTree.add(new ParseTree(NodeType.LPAREN));
            S.nextTok();
    
            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));
    
            if (S.currentTok() != Fun.RPAREN) errorMsg(")", S.currentTok().toString());
    
            parseTree.add(new ParseTree(NodeType.RPAREN));
            S.nextTok();
    
            if (S.currentTok() != Fun.SEMICOLON) errorMsg(";", S.currentTok().toString());
    
            parseTree.add(new ParseTree(NodeType.SEMICOLON));
            S.nextTok();

            return parseTree;
        } else {
            return new ParseTree();
        }
    }

    private ParseTree parseCompr(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));

        if (S.currentTok() == Fun.EQUAL) {
            parseTree.add(new ParseTree(NodeType.EQUAL));
            S.nextTok();

            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));
        } else if (S.currentTok() == Fun.LESS) {
            parseTree.add(new ParseTree(NodeType.LESS));
            S.nextTok();

            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));
        } else if (S.currentTok() == Fun.LESSEQUAL) {
            parseTree.add(new ParseTree(NodeType.LESSEQUAL));
            S.nextTok();

            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));
        } else {
            errorMsg(S.currentTok().toString());
        }

        return parseTree;
    }

    private ParseTree parseFactor(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        if (S.currentTok() == Fun.ID) {
            parseTree.add(new ParseTree(NodeType.ID, S.getID()));
            S.nextTok();
        } else if (S.currentTok() == Fun.CONST) {
            parseTree.add(new ParseTree(NodeType.CONST, S.getCONST() + ""));
            S.nextTok();
        } else if (S.currentTok() == Fun.LPAREN) {
            parseTree.add(new ParseTree(NodeType.LPAREN));
            S.nextTok();

            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));

            if (S.currentTok() != Fun.RPAREN) errorMsg(")", S.currentTok().toString());

            parseTree.add(new ParseTree(NodeType.RPAREN));
            S.nextTok();
        } else if (S.currentTok() == Fun.READ) {
            parseTree.add(new ParseTree(NodeType.READ));
            S.nextTok();

            if (S.currentTok() != Fun.LPAREN) errorMsg("(", S.currentTok().toString());

            S.nextTok();

            if (S.currentTok() != Fun.RPAREN) errorMsg(")", S.currentTok().toString());

            S.nextTok();
        } else {
            errorMsg(prev.toString());
        }

        return parseTree;
    }   
}