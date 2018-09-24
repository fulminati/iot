#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "iot.h"

ESP8266WebServer server(80);

void setup()
{
    Serial.begin(@config(baud));
    WiFi.begin(@getenv("WIFI_SSID"), @getenv("WIFI_PASSWORD"));

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Waiting to connect...");
    }

    Serial.println("IP address: " + WiFi.localIP());

    server.on("/",          [](){index();});
    server.on("/info",      [](){info();});

    server.on("/iot.js",    [](){js();});
    server.on("/iot.css",   [](){css();});

    server.begin();
    Serial.println("Server listening");
}

void loop() {
    server.handleClient();
}

void index() {
    server.send(
        200,
        "text/plain",
        String()
            + WEBAPP_HEADER
            + WEBAPP_INDEX
            + WEBAPP_FOOTER
    );
}

void info() {
    server.send(200, "text/plain", String() + WEBAPP_HEADER + WEBAPP_INFO + WEBAPP_FOOTER);
}

void js() {
    server.send(200, "text/plain", WEBAPP_APP_JS);
}

void css() {
    server.send(200, "text/plain", WEBAPP_STYLE_CSS);
}
