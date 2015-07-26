import java.util.*;
class Shuffle_Card
{
	public static void main(String args[])
	{
		int i,j,N=52;
		int card[]=new int[N];
		for(i=0;i<N;i++)
			card[i]=i+1;
		Random rand=new Random();
		for(j=N-1;j>0;j--)
		{
			int r=rand.nextInt(j+1);
			int temp=card[r];
			card[r]=card[j];
			card[j]=temp;
		}
		for(i=0;i<N;i++)
			System.out.println(card[i]);
		/*for(i=0;i<N;i++)
			for(j=i+1;j<N;j++)
			{
				if(card[j]<card[i])
				{
					int l=card[j];
					card[j]=card[i];
					card[i]=l;
				}
			}
		for(i=0;i<N;i++)
			System.out.println(card[i]);*/
	}
}