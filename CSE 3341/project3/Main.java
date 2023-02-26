class Main {
	public static void main(String[] args) {
		// Initialize the scanner with the input file
		Scanner s = new Scanner(args[0]);
		Scanner input = new Scanner(args[1]);
		Parser.scanner = s;
		Executor.scanner = input;
		
		Program prog = new Program();
		
		prog.parse();
		
		prog.semantic();
		

		prog.execute();
	}
}
