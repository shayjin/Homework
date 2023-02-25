class Main {
	public static void main(String[] args) {
		// Initialize the scanner with the input file
		Scanner s = new Scanner(args[0]);
		Parser.scanner = s;
		
		Program prog = new Program();
		
		prog.parse();
		
		prog.semantic();
		
		prog.print();

		prog.execute();

		System.out.println(Executor.global);
		System.out.println(Executor.stack);
	}
}
