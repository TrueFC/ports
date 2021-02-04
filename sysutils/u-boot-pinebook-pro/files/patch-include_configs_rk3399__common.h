--- include/configs/rk3399_common.h.org	2021-02-03 10:57:02.361486000 +0900
+++ include/configs/rk3399_common.h	2021-02-03 11:07:15.193236000 +0900
@@ -59,9 +59,39 @@
 #ifndef ROCKCHIP_DEVICE_SETTINGS
 #define ROCKCHIP_DEVICE_SETTINGS
 #endif
+ 
+#ifdef CONFIG_CMD_BMP
+#define CONFIG_VIDEO_BMP_RLE8
+#define CONFIG_BMP_16BPP
+#define CONFIG_BMP_24BPP
+#define CONFIG_BMP_32BPP
+#define CONFIG_SPLASH_SCREEN
+#define CONFIG_SPLASH_SCREEN_ALIGN
+#define CONFIG_SYS_VIDEO_LOGO_MAX_SIZE 8192000
+#define CONFIG_VIDEO_BMP_GZIP 1
 
+#ifdef ROCKCHIP_DEVICE_SETTINGS
+#undef ROCKCHIP_DEVICE_SETTINGS
+#define ROCKCHIP_DEVICE_SETTINGS \
+	"stdin=serial\0" \
+	"stdout=serial\0" \
+	"stderr=serial\0"
+#endif
+#endif
+
 #include <config_distro_bootcmd.h>
 #include <environment/distro/sf.h>
+
+#ifdef CONFIG_USE_PREBOOT
+#define PREBOOT_LOAD_LOGO \
+	"ll=1 && " \
+	"load mmc 0 $loadaddr splash.bmp || " \
+	"load mmc 1 $loadaddr splash.bmp || " \
+	"ll=0; " \
+	"test $ll = 1 && bmp display $loadaddr m m || ll=0 "
+
+#define PREBOOT_CMD "led red:standby on; run load_logo;"
+
 #define CONFIG_EXTRA_ENV_SETTINGS \
 	ENV_MEM_LAYOUT_SETTINGS \
 	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
@@ -69,9 +99,24 @@
 	ROCKCHIP_DEVICE_SETTINGS \
 	BOOTENV \
 	BOOTENV_SF \
+	"loadaddr=0x40000000\0" \
+	"load_logo=" PREBOOT_LOAD_LOGO "\0" \
+	"preboot=" PREBOOT_CMD "\0" \
 	"altbootcmd=" \
 		"setenv boot_syslinux_conf extlinux/extlinux-rollback.conf;" \
 		"run distro_bootcmd\0"
+#else
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	ENV_MEM_LAYOUT_SETTINGS \
+	"fdtfile=" CONFIG_DEFAULT_FDT_FILE "\0" \
+	"partitions=" PARTS_DEFAULT \
+	ROCKCHIP_DEVICE_SETTINGS \
+	BOOTENV \
+	BOOTENV_SF \
+	"altbootcmd=" \
+		"setenv boot_syslinux_conf extlinux/extlinux-rollback.conf;" \
+		"run distro_bootcmd\0"
+#endif 
 
 #endif
 
