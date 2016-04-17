# Lab 4

## 目標一: 溫溼度感應顯示器
`LDHT_Sensor` 這是溫濕度感測器的範例

記得型號和接的 pin 腳要對

Hint: 記得要先呼叫 `dht.read()` 才會將資料讀進來！

之後 `dht.readTemperature()` 才會有值

## 目標二: 三軸加速計步器

如果是 v1.2b ，請使用 [MMA7660FC library](https://github.com/mcauser/Grove-3Axis-Digital-Accelerometer-1.5g-MMA7660FC)

如果是 v1.3 請使用 [ ADXL345 library](
https://github.com/Seeed-Studio/Seeed_Accelerometer_ADXL345_g)

### ADXL345_demo_code


這邊是三軸加速度感應器 v1.3 的範例，他是使用 ADXL345


他會讀x, y, z 三軸的加速度

請去判斷三軸加速器時會有什麼變化

注意：請檢查一下你的三軸加速度感應器的版本，如果是 v1.2，請去參考 library 裡的範例


## 目標三: 利用 LinkIt ONE WiFi 上網擷取資訊
### WifiWebClient
這邊是Wifi連線的範例

會先看到 `Connecting to AP`，表示他正在連 AP

如果成功連上 AP 的話，會看到 `Connecting to WebSite`，表示說他開始去連網站

之後就可以在 Serial Monitor 上看到跟 `www.google.com` 正在傳訊息


### Wifi_Get_FB_sample
目標三所需要的檔案在此

請去填

1. WIFI_AP

1. WIFI_PASSWORD

1. SITE_URL

1. HTTP Request (在`setup()`裡)
