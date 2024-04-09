package silver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // 반복해서 입력 데이터 읽기
        String str;
        while ((str = reader.readLine()) != null) {
            System.out.println(str);

        }
    }
}