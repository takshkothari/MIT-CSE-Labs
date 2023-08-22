import java.util.*;

class q4{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int m, n, i, j;
		System.out.println("enter number of rows and columns of matrix");
		m = sc.nextInt();
		n = sc.nextInt();
		int a[][] = new int[m][n];
		int b[][] = new int[m][n];
		int c[][] = new int[m][n];
		System.out.println("enter elements of first matrix");
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
				a[i][j] = sc.nextInt();
		}

		System.out.println("enter elements of second matrix");
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				b[i][j] = sc.nextInt();
				c[i][j] = a[i][j] + b[i][j];
			}
		}

		System.out.println("resultant matrix");
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
				System.out.print(c[i][j] + "\t");
			System.out.println();
		}
	}
}