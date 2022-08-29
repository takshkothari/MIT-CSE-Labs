import java.util.*;

class q1{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n, i, j;
		System.out.println("enter number of elements");
		n = sc.nextInt();
		int a[] = new int[n];
		System.out.println("enter elements");
		for(i = 0; i < n; i++)
			a[i] = sc.nextInt();
		for(i = 0; i < n-1; i++)
		{
			for(j=0; j < n-1-i; j++)
			{
				if(a[j] > a[j+1])
				{
					int t = a[j];
					a[j] = a[j+1];
					a[j+1] = t;
				}
			}
		}
		System.out.println("sorted array is:");
		for(i = 0; i < n; i++)
			System.out.print(a[i] + "\t");
	}
}