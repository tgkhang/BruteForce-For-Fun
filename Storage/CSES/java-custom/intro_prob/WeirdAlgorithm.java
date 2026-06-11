import java.util.Scanner;

public class WeirdAlgorithm {

    public static void solve (long n)
    {
        System.out.print(n + " ");
        while(n != 1)
        {
            if(n%2 ==0 ){
                n = n/2;
            }
            else{
                n = (3*n+1);
            }
            System.out.print(n + " ");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        solve(n);
        scanner.close();
    }
}