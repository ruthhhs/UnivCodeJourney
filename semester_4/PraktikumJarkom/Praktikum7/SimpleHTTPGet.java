import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class SimpleHTTPGet {
    public static void main(String[] args) throws IOException
    {
        String host = "example.com";
        int port = 80;
        Socket socket = new Socket(host, port);
        System.out.println("Mengirim Header");

        // Menyusun dan mengirimkan Header
        String path = "/sample.html";
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(
            socket.getOutputStream(), "UTF8"));
        wr.write("GET " + path + " HTTP/1.1\r\n");
        wr.write("Host: " + host + "\r\n");
        wr.write("\r\n");
        wr.flush();

        // Menerima Response dari server
        System.out.println("Hasil Response:");
        BufferedReader rd = new BufferedReader(new InputStreamReader(
            socket.getInputStream()));
        String line;
        while ((line = rd.readLine()) != null) {
            System.out.println(line);
        }
        wr.close();
        rd.close();
        socket.close();
    }
}