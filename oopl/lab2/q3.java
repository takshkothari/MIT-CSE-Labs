import java.util.*;

class q3{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n, i, k, c=0;
		System.out.println("enter number of elements");
		n = sc.nextInt();
		int a[] = new int[n];	
		System.out.println("enter elements");
		for(i = 0; i < n; i++)
			a[i] = sc.nextInt();
		System.out.println("enter element to be searched");
		k = sc.nextInt();
		for(i = 0; i < n; i++)
		{
			if(a[i]==k)
			{
				c=1;
				break;
			}
		}
		if(c==1)
			System.out.println("element found at position " + i);
		else
			System.out.println("not found");
	}
}