--- src/mem-limits.h.org	2016-05-10 11:15:29.136319000 +0900
+++ src/mem-limits.h	2016-05-10 11:14:46.011634000 +0900
@@ -78,7 +78,11 @@
 static POINTER data_space_start;
 
 /* Number of bytes of writable memory we can expect to be able to get */
+#ifdef _RLIM_T_DECLARED
+extern rlim_t lim_data;
+#else
 extern unsigned long lim_data;
+#endif
 
 /* The implementation of get_lim_data() is very machine dependent. */
 
