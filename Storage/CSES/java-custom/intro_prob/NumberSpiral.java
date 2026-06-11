import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NumberSpiral {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());

            long res = 0, add = 0;

            if (x > y) {
                res = (x - 1) * (x - 1);
                if (x % 2 == 0)
                    add = 2 * x - y;
                else
                    add = y;

            } else {
                res = (y - 1) * (y - 1);
                if (y % 2 == 0)
                    add = x;
                else
                    add = 2 * y - x;

            }

            pw.println(res + add);
        }

        pw.flush();
        pw.close();
        br.close();
    }
}