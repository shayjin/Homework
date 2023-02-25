import java.util.*;

class Parser {
	//scanner is stored here as a static field so it is avaiable to the parse method
	public static Scanner scanner;
	
	//scopes is a data structure for the semantic checks, to verify variables being used are declared and what they were declared as
	public static Stack<HashMap<String, Fun>> scopes;
	
	//helper method for the semantic checks
	//returns Fun.INT or Fun.REF if the string x is the name of a variable that is in scope, returns Fun.ERROR otherwise
	static Fun nestedScopeCheck(String x) {
		Fun match = Fun.ERROR;
		if (!scopes.empty()) {
			HashMap<String, Fun> temp = scopes.pop();
			if (temp.containsKey(x)) {
				match = temp.get(x);
			} else {
				match = nestedScopeCheck(x);
			}
			scopes.push(temp);
		}
		return match;
	}
	
	//helper method for the semantic checks
	//returns Fun.INT or Fun.REF if the string x is the name of a variable declared in the current scope, returns Fun.ERROR otherwise
	static Fun currentScopeCheck(String x) {
		Fun match = Fun.ERROR;
		if (!scopes.empty()) {
			if (scopes.peek().containsKey(x)) {
				match = scopes.peek().get(x);
			}
		}
		return match;
	}
	
	//helper method for handling error messages, used by the parse methods
	static void expectedToken(Fun expected) {
		if (scanner.currentTok() != expected) {
			System.out.println("ERROR: Expected " + expected + ", recieved " + scanner.currentTok());
			System.exit(0);
		}
	}

}
