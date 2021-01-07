package Operating_System_21_Winter.Ch03.Example;

import java.net.*;
import java.io.*;

public class Socket_DateClient {
    public static void main(String[] args) {
        try {
            Socket sock = new Socket("127.0.0.1", 6013);
            InputStream in = sock.getInputStream();
            BufferedReader bin = new BufferedReader(new InputStreamReader(in));

            String line;
            while((line = bin.readLine()) != null) {
                System.out.println(line);
            }

            sock.close();
        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}
