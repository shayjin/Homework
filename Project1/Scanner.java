import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class Scanner {
	public BufferedReader reader;
	public Fun currToken;
	public String idVal;
	public int constVal;
	public final String SYMBOLS = ";(),=!<+-*{}";
	
	// Constructor should open the file and find the first token
	Scanner(String filename) throws IOException {
		reader = new BufferedReader(new FileReader(filename));
		nextTok();
	}

	// nextTok should advance the scanner to the next token
	public void nextTok() throws IOException {
		int charInt = reader.read();
		char token = (char) charInt;
		
		while (Character.isWhitespace(token)) {
			charInt = reader.read();
			token = (char) charInt;
		} 

		String varToken = Character.toString(token);

		if (charInt == -1) {
			this.currToken = Fun.EOS;
		} else {
			switch (varToken) {
				case ";": currToken = Fun.SEMICOLON; break;
				case "(": currToken = Fun.LPAREN; break;
				case ")": currToken = Fun.RPAREN; break;
				case ",": currToken = Fun.COMMA; break;
				case "=": {
					reader.mark(1);
					token = (char) reader.read();
	
					if (token == '=') {
						currToken = Fun.EQUAL; 
					} else {
						currToken = Fun.ASSIGN; 
						reader.reset();
					}
	
					break;
				}
				case "!": currToken = Fun.NEGATION; break; 
				case "<": {
					reader.mark(1);
					token = (char) reader.read();
	
					if (token == '=') {
						currToken = Fun.LESSEQUAL; 
					} else {
						currToken = Fun.LESS; 
						reader.reset();
					}
	
					break;
				}
				case "+": currToken = Fun.ADD; break;
				case "-": currToken = Fun.SUB; break;
				case "*": currToken = Fun.MULT; break;
				case "{": currToken = Fun.LBRACE; break;
				case "}": currToken = Fun.RBRACE; break;
				default: {
					// Number Case
					if (Character.isDigit(token)) {
						reader.mark(1);
						token = (char) reader.read();

						while (Character.isDigit(token) && charInt != -1) {
							varToken += token;
							reader.mark(1);
							charInt = reader.read();

							if (charInt != -1) {
								token = (char) charInt;
							}
						}
						
						try {
							currToken = Fun.CONST;
							this.constVal = Integer.parseInt(varToken);

							if (this.constVal > 255) {
								throw new NumberFormatException();
							}

							reader.reset();
						} catch (NumberFormatException err){
							currToken = Fun.ERROR;
							System.out.println("ERROR: Constant " + varToken + " is too large. ");
						}
					} else if (Character.isAlphabetic(token)) {
						reader.mark(1);
						charInt = reader.read();
						token = (char) charInt;

						boolean assigned = true;
		
						while (!Character.isWhitespace(token) && !SYMBOLS.contains(token + "") && 
								(Character.isAlphabetic(token) || Character.isDigit(token)) && charInt != -1) {
							varToken += token;

							reader.mark(1);
							charInt = reader.read();

							if (charInt == -1) {
								break;
							}
							
							token = (char) charInt;
						}

						switch (varToken) {
							case "program": currToken = Fun.PROGRAM; break;
							case "begin": currToken = Fun.BEGIN; break;
							case "end": currToken = Fun.END; break;
							case "new": currToken = Fun.NEW; break;
							case "int": currToken = Fun.INT; break;
							case "reference": currToken = Fun.REF; break;
							case "inst": currToken = Fun.INSTANCE; break;
							case "if": currToken = Fun.IF; break;
							case "then": currToken = Fun.THEN; break;
							case "else": currToken = Fun.ELSE; break;
							case "while": currToken = Fun.WHILE; break;
							case "or": currToken = Fun.OR; break;
							case "and": currToken = Fun.AND; break;
							case "read": currToken = Fun.READ; break;
							case "write": currToken = Fun.WRITE; break;
							case "share": currToken = Fun.SHARE; break;
							default: assigned = false; break;
						}
						
						if (SYMBOLS.contains(token + "") || !(Character.isAlphabetic(token) || Character.isDigit(token))) {
							reader.reset();
						}

						// ID
						if (!assigned) {
							currToken = Fun.ID;
							this.idVal = varToken;
						} else {
							reader.reset();
						}
					} else {
						currToken = Fun.ERROR;
						System.out.println("ERROR: " + token + " is not a valid input. ");
					}
				}
			}
		}
	}

	// currentTok should return the current token
	public Fun currentTok() {
		return this.currToken;
	}

	// If the current token is ID, return the string value of the identifier
	// Otherwise, return value does not matter
	public String getID() {
		return this.idVal;
	}

	// If the current token is CONST, return the numerical value of the constant
	// Otherwise, return value does not matter
	public int getCONST() {
		return this.constVal;
	}

}