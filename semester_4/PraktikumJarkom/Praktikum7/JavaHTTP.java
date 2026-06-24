import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class JavaHTTP {
    public static void main(String[] args) throws IOException
    {
        System.out.println("Connecting.......");
        URL url = new URL("http://example.com");
        HttpURLConnection con = (HttpURLConnection) url.openConnection();
        System.out.println("Server Respon:");
        System.out.println("Response Code: " + con.getResponseCode());
        BufferedReader in = new BufferedReader(new InputStreamReader(
            con.getInputStream()));
        String line;
        System.out.println("Data Respon:");
        while ((line = in.readLine()) != null) {
            System.out.println(line);
        }
        in.close();
        con.disconnect();
    }
}