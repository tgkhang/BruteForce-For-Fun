import java.util.Scanner;

public class Repeatitions {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();

        char c = s.charAt(0);
        long cur = 1, res = 1;

        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) != c) {
                c = s.charAt(i);
                cur = 1;
            } else
                cur++;

            res = Math.max(res, cur);
        }

        System.out.println(res);
        scanner.close();
    }
}