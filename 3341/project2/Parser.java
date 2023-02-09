import java.io.IOException;
import java.text.ParseException;

import org.w3c.dom.Node;

public class Parser {
    private Scanner S;
    private static NodeType prev;

    public Parser(Scanner S) {
        this.S = S;
    }

    public ParseTree parse() throws IllegalStateException, IOException {
        return parseProg();
    }

    public ParseTree parseProg() throws IllegalStateException, IOException {
        ParseTree parseTree = new ParseTree();

        if (S.currentTok() != Fun.PROGRAM) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.PROGRAM));
        S.nextTok();

        if (S.currentTok() != Fun.LBRACE) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.LBRACE));
        S.nextTok();

        parseTree.add(parseDeclSeq(new ParseTree(NodeType.DECLSEQ)));

        if (S.currentTok() != Fun.BEGIN) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.BEGIN));
        S.nextTok();

        if (S.currentTok() != Fun.LBRACE) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.LBRACE));
        S.nextTok();

        parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));

        if (S.currentTok() != Fun.RBRACE) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.RBRACE));
        S.nextTok();


        if (S.currentTok() != Fun.RBRACE) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.RBRACE));
        S.nextTok();

        if (S.currentTok() != Fun.EOS) {
            throw new IllegalStateException("error msg");
        }

        return parseTree;
    }

    public ParseTree parseDeclSeq(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseDecl(new ParseTree(NodeType.DECL)));

        if (S.currentTok() == Fun.INT) {
            parseTree.add(parseDeclSeq(new ParseTree(NodeType.DECLSEQ)));
        }

        return parseTree;
    }

    public ParseTree parseDecl(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        parseTree.add(parseDeclInt(new ParseTree(NodeType.DECLINT)));
        parseTree.add(parseDeclRef(new ParseTree(NodeType.DECLREF)));

        if (parseTree.getChildren().size() == 0) {
            return new ParseTree();
        }

        return parseTree;
    }

    public ParseTree parseDeclInt(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.INT) {
            return new ParseTree();
        }

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(NodeType.INT));
        S.nextTok();

        parseTree.add(parseIdList(new ParseTree(NodeType.IDLIST)));

        if (S.currentTok() != Fun.SEMICOLON) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.SEMICOLON));
        S.nextTok();

        return parseTree;
    }
    
    public ParseTree parseIdList(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.ID) {
            throw new IllegalStateException("error msg");
        }

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

    public ParseTree parseDeclRef(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.REF) {
            return new ParseTree();
        }

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(NodeType.REF));
        S.nextTok();

        parseTree.add(parseIdList(new ParseTree(NodeType.IDLIST)));

        if (S.currentTok() != Fun.SEMICOLON) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.SEMICOLON));
        S.nextTok();

        return parseTree;
    }

    public ParseTree parseStmtSeq(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        parseTree.add(parseStmt(new ParseTree(NodeType.STMT)));
        
        if (S.currentTok() != Fun.RBRACE) {
            parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));
        }
        
        return parseTree;
    }

    public ParseTree parseStmt(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseAssign(new ParseTree(NodeType.ASSIGN)));
        parseTree.add(parseIf(new ParseTree(NodeType.IF)));
        parseTree.add(parseLoop(new ParseTree(NodeType.LOOP)));
        parseTree.add(parseOut(new ParseTree(NodeType.OUT)));

        parseTree.add(parseDecl(new ParseTree(NodeType.DECL)));

        return parseTree;
    }

    public ParseTree parseAssign(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.ID) {
            return new ParseTree();
        }

        ParseTree parseTree = root;
        parseTree.add(new ParseTree(NodeType.ID, S.getID()));
        S.nextTok();

        if (S.currentTok() != Fun.ASSIGN) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.ASSIGN));
        S.nextTok();

        if (S.currentTok() == Fun.NEW) {
            parseTree.add(new ParseTree(NodeType.NEW));
            S.nextTok();

            if (S.currentTok() != Fun.INSTANCE) {
                throw new IllegalStateException("error msg");
            } 

            parseTree.add(new ParseTree(NodeType.INSTANCE));
            S.nextTok();

            if (S.currentTok() != Fun.SEMICOLON) {
                throw new IllegalStateException("error msg");
            }

            parseTree.add(new ParseTree(NodeType.SEMICOLON));
            S.nextTok();

            return parseTree;
        } else if (S.currentTok() == Fun.SHARE) {
            parseTree.add(new ParseTree(NodeType.SHARE));
            S.nextTok();

            if (S.currentTok() != Fun.ID) {
                throw new IllegalStateException("error msg");
            }

            parseTree.add(new ParseTree(NodeType.ID, S.getID()));
            S.nextTok();

            if (S.currentTok() != Fun.SEMICOLON) {
                throw new IllegalStateException("error msg");
            }

            parseTree.add(new ParseTree(NodeType.SEMICOLON));
            S.nextTok();

            return parseTree;
        } else {
            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));

            if (S.currentTok() != Fun.SEMICOLON) {
                throw new IllegalStateException("error msg");
            }

            parseTree.add(new ParseTree(NodeType.SEMICOLON));
            S.nextTok();
        }

        return parseTree;
    }

    public ParseTree parseExpr(ParseTree root) throws IOException {
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

    public ParseTree parseTerm(ParseTree root) throws IOException {
        ParseTree parseTree = root;
        parseTree.add(parseFactor(new ParseTree(NodeType.FACTOR)));

        if (S.currentTok() == Fun.MULT) {
            parseTree.add(new ParseTree(NodeType.MULT));
            S.nextTok();

            parseTree.add(parseTerm(new ParseTree(NodeType.TERM)));
        }

        return parseTree;
    }

    public ParseTree parseIf(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.IF) {
            return new ParseTree();
        }

        ParseTree parseTree = root;

        parseTree.add(new ParseTree(NodeType.IF));
        S.nextTok();

        parseTree.add(parseCond(new ParseTree(NodeType.COND)));

        if (S.currentTok() != Fun.THEN) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.THEN));
        S.nextTok();

        if (S.currentTok() != Fun.LBRACE) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.LBRACE));
        S.nextTok();

        parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));

        if (S.currentTok() != Fun.RBRACE) {
            throw new IllegalStateException("error msg");
        } 

        parseTree.add(new ParseTree(NodeType.RBRACE));
        S.nextTok();

        if (S.currentTok() == Fun.ELSE) {
            parseTree.add(new ParseTree(NodeType.ELSE));
            S.nextTok();

            if (S.currentTok() != Fun.LBRACE) {
                throw new IllegalStateException("error msg");
            }
            
            parseTree.add(new ParseTree(NodeType.LBRACE));
            S.nextTok();

            parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));

            if (S.currentTok() != Fun.RBRACE) {
                throw new IllegalStateException("error msg");
            }
            
            parseTree.add(new ParseTree(NodeType.RBRACE));
            S.nextTok();
        } 

        return parseTree;
    }

    public ParseTree parseLoop(ParseTree root) throws IOException {
        if (S.currentTok() != Fun.WHILE) {
            return new ParseTree();
        }

        ParseTree parseTree = root;

        parseTree.add(new ParseTree(NodeType.WHILE));
        S.nextTok();

        parseTree.add(parseCond(new ParseTree(NodeType.COND)));

        if (S.currentTok() != Fun.LBRACE) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.LBRACE));
        S.nextTok();

        parseTree.add(parseStmtSeq(new ParseTree(NodeType.STMTSEQ)));

        if (S.currentTok() != Fun.RBRACE) {
            throw new IllegalStateException("error msg");
        }

        parseTree.add(new ParseTree(NodeType.RBRACE));
        S.nextTok();



        return parseTree;
    }

    public ParseTree parseCond(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        if (S.currentTok() == Fun.NEGATION) {
            parseTree.add(new ParseTree(NodeType.NEGATION));
            S.nextTok();

            if (S.currentTok() != Fun.LPAREN) {
                throw new IllegalStateException("error msg");
            }

            parseTree.add(new ParseTree(NodeType.LPAREN));
            S.nextTok();

            parseTree.add(parseCond(new ParseTree(NodeType.COND)));

            if (S.currentTok() != Fun.RPAREN) {
                throw new IllegalStateException("error msg");
            } 

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

    public ParseTree parseOut(ParseTree root) throws IOException {
        ParseTree parseTree = root;

        if (S.currentTok() == Fun.WRITE) {
            parseTree.add(new ParseTree(NodeType.WRITE));
            S.nextTok();
    
            if (S.currentTok() != Fun.LPAREN) {
                throw new IllegalStateException("error msg");
            }
    
            parseTree.add(new ParseTree(NodeType.LPAREN));
            S.nextTok();
    
            parseTree.add(parseExpr(new ParseTree(NodeType.EXPR)));
    
            if (S.currentTok() != Fun.RPAREN) {
                throw new IllegalStateException("error msg");
            }
    
            parseTree.add(new ParseTree(NodeType.RPAREN));
            S.nextTok();
    
            if (S.currentTok() != Fun.SEMICOLON) {
                throw new IllegalStateException("error msg");
            }
    
            parseTree.add(new ParseTree(NodeType.SEMICOLON));
            S.nextTok();

            return parseTree;
        } else {
            return new ParseTree();
        }
    }

    public ParseTree parseCompr(ParseTree root) throws IOException {
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
            throw new IllegalStateException("error msg");
        }

        return parseTree;
    }

    public ParseTree parseFactor(ParseTree root) throws IOException {
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

            if (S.currentTok() != Fun.RPAREN) {
                throw new IllegalStateException("error msg");
            }

            parseTree.add(new ParseTree(NodeType.RPAREN));
            S.nextTok();
        } else if (S.currentTok() == Fun.READ) {
            parseTree.add(new ParseTree(NodeType.READ));
            S.nextTok();

            if (S.currentTok() != Fun.LPAREN) {
                throw new IllegalStateException("error msg");
            }

            S.nextTok();

            if (S.currentTok() != Fun.RPAREN) {
                throw new IllegalStateException("error msg");
            }

            S.nextTok();
        } else {
            throw new IllegalStateException(prev + " is in an unexpected place. ");
        }

        return parseTree;
    }   

}