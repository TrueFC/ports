--- src/console-xlike-inc.h.org	2013-08-22 02:43:45.000000000 +0900
+++ src/console-xlike-inc.h	2016-05-11 19:18:28.000000000 +0900
@@ -111,10 +111,10 @@
    it clearer that something else is going on. --ben */
 
 #if defined (THIS_IS_X) && defined (HAVE_XFT)
-#define USE_XFT
-#define USE_XFT_MENUBARS
-#define USE_XFT_TABS
-#define USE_XFT_GAUGES
+#define XEMACS_USE_XFT
+#define XEMACS_USE_XFT_MENUBARS
+#define XEMACS_USE_XFT_TABS
+#define XEMACS_USE_XFT_GAUGES
 #endif
 
 /***************************************************************************/
