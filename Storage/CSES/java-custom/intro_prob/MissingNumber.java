import java.util.Scanner;

public class MissingNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long tmp = 0;

        for (int i = 0; i < n-1; i++) {
            tmp += scanner.nextLong();
        }

        long sum = (n + 1) * n / 2;
        System.out.print(sum - tmp);

        scanner.close();
    }
}