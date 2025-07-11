//https://github.com/bokunimowakaru/line/blob/master/esp32/ex01_basic/ex01_basic.ino

#include <WiFi.h>
#include <HTTPClient.h>
 
#define line_ch_id "XX"                         // Channel ID
#define line_ch_pw "XXXXX"   // Channel secret

#define SSID "XX"
#define PASS "XXXX"

String get_token(){
    HTTPClient http;  // HTTP request instance
    if(strcmp(line_ch_id,"0000000000") == 0){  // When line_ch_id is not entered
        Serial.println("ERROR: Pls set line_ch_id and pwd");
        return "";
    }
    String url = "https://api.line.me/oauth2/v3/token";
    String body = "grant_type=client_credentials&";
    body += "client_id=" + String(line_ch_id) + "&";
    body += "client_secret=" + String(line_ch_pw);
    http.begin(url);  // Set the HTTP request destination
    http.addHeader("Content-Type","application/x-www-form-urlencoded");
    int httpCode = http.POST(body);  // Send HTTP
    String token="";
    if(httpCode == 200){
        String S = http.getString();  // Store the HTTP response body (text such as JSON)
        int i = S.indexOf("\"access_token\"");
        if((i>0) && (S.substring(i+15, i+16).equals("\""))){  // Find the "access_token" in the JSON string
            token = S.substring(i+16, i+16+174);
            Serial.println(token);
        }
    }else{
        Serial.println("HTTP ERROR: "+String(httpCode));
    }
    http.end();  // End HTTP communication
    return token;
}

int message_to_line(String message){
    String token = get_token();  // Get a token
    int token_len = token.length();  // The length of the token obtained
    if(token_len != 174){  // Warning when token is too long
        Serial.println("ERROR: Token Length Error; " + String(token_len));
        return 0;
    }
    HTTPClient http;  // HTTP request instance
    String url = "https://api.line.me/v2/bot/message/broadcast";
    Serial.println(url);
    http.begin(url);  // Set the HTTP request destination
    http.addHeader("Content-Type","application/json");
    http.addHeader("Authorization","Bearer " + token);
    String json = "{\"messages\":[{\"type\":\"text\",\"text\":\"";
    json += message + "\"}]}";  // Assign message to json for sending
    Serial.println(json);
    int httpCode = http.POST(json);  // Sending messages over HTTP
    http.end();  // End HTTP communication
    return httpCode;  // HTTP result
}

void setup(){
    Serial.begin(115200);
    Serial.println("LINE Messaging API");

    WiFi.mode(WIFI_STA);  // WiFi to STA mode
    WiFi.begin(SSID,PASS);  // WiFi access point connection
    while(WiFi.status() != WL_CONNECTED){
        Serial.print('.');
        delay(500);
    }
    Serial.println(WiFi.localIP());
}

void loop(){
    message_to_line("orion beer");  // Free Message:200/Month
    delay(10*60*1000);  // 10 minutes
}