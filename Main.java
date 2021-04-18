public class Main{
	public static void main(String[] args){
		Eratosthenes primeCounter=new Eratosthenes(Integer.parseInt(args[0]));

		primeCounter.Start();
	}
}
