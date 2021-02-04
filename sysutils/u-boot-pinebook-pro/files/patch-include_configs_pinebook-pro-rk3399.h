--- include/configs/pinebook-pro-rk3399.h.org	2021-02-03 10:52:51.768896000 +0900
+++ include/configs/pinebook-pro-rk3399.h	2021-02-03 10:55:46.407842000 +0900
@@ -8,9 +8,9 @@
 #define __PINEBOOK_PRO_RK3399_H
 
 #define ROCKCHIP_DEVICE_SETTINGS \
-		"stdin=serial,usbkbd\0" \
-		"stdout=serial,vidconsole\0" \
-		"stderr=serial,vidconsole\0"
+	"stdin=serial\0" \
+	"stdout=serial\0" \
+	"stderr=serial\0"
 
 #include <configs/rk3399_common.h>
 
