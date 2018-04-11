#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webapp.h"

ESP8266WebServer server(80);

void setup()
{
    Serial.begin(115200);
    WiFi.begin(@dotenv("WIFI_SSID"), @dotenv("WIFI_PASSWORD"));

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Waiting to connect...");
    }

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", [](){index();});
    server.on("/info", [](){info();});

    server.on("/app.js", [](){app_js();});
    server.on("/style.css", [](){style_css();});

    server.begin();
    Serial.println("Server listening");
}

void loop() {
    server.handleClient();
}

void index() {
    server.send(200, "text/plain", String() + WEBAPP_HEADER + WEBAPP_INDEX + WEBAPP_FOOTER);
}

void info() {
    server.send(200, "text/plain", String() + WEBAPP_HEADER + WEBAPP_INFO + WEBAPP_FOOTER);
}

void app_js() {
    server.send(200, "text/plain", WEBAPP_APP_JS);
}

void style_css() {
    server.send(200, "text/plain", WEBAPP_STYLE_CSS);
}
