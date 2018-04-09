
#include "client.h"
#include "../../includes/WiFiManager/WiFiManager.h"

WiFiManager wifiManager;

void setup() {
    Serial.begin(115200);

    wifiManager.

    wifiManager.autoConnect();
}

void loop() {

}



/**
 *
 */
String header() {
    return @loadhtml("pages/header.html")
}

/**
 *
 */
String index() {
    return header() + @loadhtml("pages/index.html") + footer();
}

/**
 *
 */
String config() {
    return @loadhtml("config.html");
}

/**
 *
 */
String footer() {
    return @loadhtml("pages/footer.html")
}