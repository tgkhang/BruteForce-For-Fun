import java.util.Scanner;

public class Permutation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        if (n == 1) {
            System.out.print(1);
        } else if (n <= 3) {
            System.out.print("NO SOLUTION");
        } else {
            StringBuilder sb = new StringBuilder();
            
            // Add all even numbers
            for (int i = 2; i <= n; i += 2) {
                sb.append(i).append(" ");
            }
            // Add all odd numbers
            for (int i = 1; i <= n; i += 2) {
                sb.append(i).append(" ");
            }
            
            System.out.print(sb.toString());
        }
        
        scanner.close();
    }
}