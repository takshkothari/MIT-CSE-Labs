import java.util.*;

class q2{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n, i, k, x;
		System.out.println("enter number of elements");
		n = sc.nextInt();
		int a[] = new int[n+1];		
		System.out.println("enter elements");
		for(i = 0; i < n; i++)
			a[i] = sc.nextInt();

		System.out.println("enter position at which element has to be added and its value");
		k = sc.nextInt();
		x = sc.nextInt();

		for(i = n; i > k; i--)
			a[i] = a[i-1];
		a[k] = x;
		System.out.println("new array is:");
		for(i = 0; i < n+1; i++)
			System.out.print(a[i] + "\t");
	
		System.out.println("\nenter position from which element has to be deleted");
		k = sc.nextInt();
		for(i = 0; i < n+1; i++)
		{
			if (i>k) 
				a[i-1] = a[i];
		}
		System.out.println("new array is:");
		for(i = 0; i < n; i++)
			System.out.print(a[i] + "\t");
	}
}
