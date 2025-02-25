import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            BigInteger n = new BigInteger(br.readLine());
            if(n.equals(BigInteger.ZERO)) break;
            if (n.remainder(BigInteger.valueOf(42)).equals(BigInteger.ZERO)) {
                System.out.println("PREMIADO");
            } else {
                System.out.println("TENTE NOVAMENTE");
            }
        }

    }
}
