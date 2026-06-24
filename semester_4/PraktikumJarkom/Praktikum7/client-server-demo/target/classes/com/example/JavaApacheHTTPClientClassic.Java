package com.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import org.apache.hc.client5.http.classic.methods.HttpGet;
import org.apache.hc.client5.http.impl.classic.CloseableHttpClient;
import org.apache.hc.client5.http.impl.classic.CloseableHttpResponse;
import org.apache.hc.client5.http.impl.classic.HttpClients;
import org.apache.hc.core5.http.HttpEntity;

/** 
 * Blocking I/O 
 */ 
public class JavaApacheHTTPClientClassic { 
    public static void main(String[] args) throws IOException { 
        try (CloseableHttpClient httpclient = HttpClients.createDefault()) { 
            HttpGet httpget = new HttpGet("http://example.com"); 
            try (CloseableHttpResponse response = httpclient.execute(httpget)) { 
                HttpEntity entity = response.getEntity(); 
 
                if (entity != null) { 
                    try (BufferedReader rd = new BufferedReader(new InputStreamReader(entity.getContent()))) {
                        String line; 
                        while ((line = rd.readLine()) != null) { 
                            System.out.println(line); 
                        } 
                    }
                } 
            }
        }
    }
}