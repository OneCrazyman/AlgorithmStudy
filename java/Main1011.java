import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main1010 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N,M;
        // 반복해서 입력 데이터 읽기
        int T = Integer.parseInt(br.readLine());
//        System.out.println(T);
        for (int i=0; i<T; i++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

//            System.out.println(N + " " +M);
            printNumberOfCase(N,M);
        }
    }

    public static void printNumberOfCase(int n, int m){
        long nr = 1;
        for (long i = 1; i <= n; i++) {
            nr *= i;
        }
        long mnr = 1;
        int j = m;
        for (int i = 0; i < n; i++) {
            mnr *= j--;
        }
        long result = mnr / nr;
        System.out.println(result);
    }
}