#include <LWiFi.h>
#include <LWiFiClient.h>

#define WIFI_AP "WLW"        //WiFi AP名稱
#define WIFI_PASSWORD "55555555"  //WiFi密碼
#define WIFI_AUTH LWIFI_WPA  // choose from LWIFI_OPEN, LWIFI_WPA, or LWIFI_WEP.
#define SITE_URL "graph.facebook.com"
#define LIKE_SUBSTRING "\"category\":"
#define BUFFER_SIZE 65536


LWiFiClient c;
char buffer[BUFFER_SIZE];

void setup()
{
    //LTask.begin();
    LWiFi.begin();
    Serial.begin(115200);

    //while(!Serial)delay(100);

    // keep retrying until connected to AP
    Serial.println("Connecting to AP");
    while (0 == LWiFi.connect(WIFI_AP, LWiFiLoginInfo(WIFI_AUTH, WIFI_PASSWORD)))
    {
        delay(1000);
    }

    // keep retrying until connected to website
    Serial.println("Connecting to WebSite");
    while (c.connect(SITE_URL, 80) == 0)
    {
        Serial.println("Re-Connecting to WebSite");
        delay(1000);
    }

    // send HTTP request, ends with 2 CR/LF
    Serial.println("send HTTP GET request");
    c.println("");                      ////////key the http request
    c.println("Host: " SITE_URL);
    c.println("Connection: close");
    c.println();

    // 等候伺服器回應
    Serial.println("waiting HTTP response:");
    while (!c.available())
    {
        delay(100);
    }
}

boolean disconnectedMsg = false;

void loop()
{
    /* 讀取http response */
    int n_bytes = c.read((uint8_t*)buffer, sizeof(buffer));
    if (0 == n_bytes)
    {
        Serial.println("disconnected by server");
        while (1);
    }
    /* 印出結果 */
    Serial.write(buffer);
    Serial.println();

    while (1);
}
