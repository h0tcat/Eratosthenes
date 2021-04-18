import java.util.ArrayList;

public class Eratosthenes{

	private int N=10000;
	private ArrayList<Integer> primeList;
	private ArrayList<Integer> removedList;

	public Eratosthenes(int N){
		this.N=N;
		primeList=new ArrayList<Integer>(N);
		removedList=new ArrayList<Integer>(N);

		for(int i=2;i<=this.N;i++)
			primeList.add(i);
	}
	
	public void Start(){

		primeList.removeIf(m -> (m % 2)==0);
		primeList.add(0,2);

		for(int i=3;i<=this.N;i+=2){
			
			if(removedList.indexOf(i)==-1){
				final int j=i;
				primeList.stream().filter(m -> m % j==0).forEach(x ->{
					removedList.add(x);
				});
				primeList.removeIf(m -> m % j==0);
				primeList.add(i);
				
			}
		}

		System.out.println(primeList);
		System.out.printf("Prime number sum : %d\n",primeList.size());
	}
}
