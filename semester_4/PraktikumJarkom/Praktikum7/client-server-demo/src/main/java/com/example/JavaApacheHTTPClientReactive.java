package com.example;

import java.io.IOException;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import org.apache.hc.client5.http.async.methods.SimpleHttpRequest;
import org.apache.hc.client5.http.async.methods.SimpleHttpResponse;
import org.apache.hc.client5.http.impl.async.CloseableHttpAsyncClient;
import org.apache.hc.client5.http.impl.async.HttpAsyncClients;

/** 
 * Non Blocking I/O 
 */ 
public class JavaApacheHTTPClientReactive { 
    public static void main(String[] args) throws IOException, InterruptedException, ExecutionException { 
        // Membuat HTTP async client 
        try (CloseableHttpAsyncClient client = HttpAsyncClients.createDefault()) { 
            client.start(); 
            // Membuat permintaan GET ke example.com 
            SimpleHttpRequest request = SimpleHttpRequest.create("GET", "http://example.com"); 
            
            // Mengeksekusi request secara asynchronous dan menunggu hasilnya 
            Future<SimpleHttpResponse> future = client.execute(request, null); 
            
            // Mendapatkan response 
            SimpleHttpResponse response = future.get();
            System.out.println("Response status: " + response.getCode());
            if (response.getBody() != null) {
                System.out.println("Response body: " + response.getBodyText());
            }
        }
    }
}