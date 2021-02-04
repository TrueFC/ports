--- include/configs/rockchip-common.h.org	2021-02-03 11:08:48.130722000 +0900
+++ include/configs/rockchip-common.h	2021-02-03 11:10:55.291036000 +0900
@@ -17,8 +17,8 @@
 /* First try to boot from SD (index 0), then eMMC (index 1) */
 #if CONFIG_IS_ENABLED(CMD_MMC)
 	#define BOOT_TARGET_MMC(func) \
-		func(MMC, mmc, 0) \
-		func(MMC, mmc, 1)
+		func(MMC, mmc, 1) \
+		func(MMC, mmc, 0)
 #else
 	#define BOOT_TARGET_MMC(func)
 #endif
