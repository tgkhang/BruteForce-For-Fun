import java.util.Scanner;

public class IncreasingArray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; ++i)
            a[i] = scanner.nextInt();

        long res = 0;
        long cur = a[0];

        for (int i = 1; i < n; ++i) {
            if (a[i] < cur)
                res += cur - a[i];
            else
                cur = a[i];
        }

        System.out.println(res);

        scanner.close();
    }
}
