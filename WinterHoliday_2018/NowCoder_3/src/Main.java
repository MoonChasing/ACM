import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
    public static void main(String args[])
    {
        BigInteger[] a= new BigInteger[10005];
        a[1] = new BigInteger("1");
        a[2] = new BigInteger("2");

        for(int i=3; i<=10000; i++)
            a[i] = a[i-1].multiply(new BigInteger(""+i));
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext())
        {
            int n = sc.nextInt();
            System.out.println(a[n]);
        }
    }
}
