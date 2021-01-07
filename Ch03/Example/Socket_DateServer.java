package Operating_System_21_Winter.Ch03.Example;

import java.net.*;
import java.io.*;

public class Socket_DateServer {
    public static void main(String[] args) {
        try {
            ServerSocket sock = new ServerSocket(6013);
    
            while(true) {
                Socket client = sock.accept();
                PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
    
                pout.println(new java.util.Date().toString());
                client.close();
            }
        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}