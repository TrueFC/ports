--- src/emacs.c.org	2016-05-10 11:02:37.336223000 +0900
+++ src/emacs.c	2016-05-10 11:04:54.066045000 +0900
@@ -585,7 +585,11 @@
 
 /* Number of bytes of writable memory we can expect to be able to get:
    Leave this as an unsigned int because it could potentially be 4G */
+#ifdef _RLIM_T_DECLARED
+rlim_t lim_data;
+#else
 unsigned long lim_data;
+#endif
 
 /* WARNING!
 
