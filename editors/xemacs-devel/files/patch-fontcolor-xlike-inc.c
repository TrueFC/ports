--- src/fontcolor-xlike-inc.c.org	2013-08-22 02:43:44.000000000 +0900
+++ src/fontcolor-xlike-inc.c	2016-05-11 19:18:28.000000000 +0900
@@ -140,7 +140,7 @@
   fixup_internal_substring (nonreloc, reloc, offset, &the_length);
   the_nonreloc += offset;
 
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
   if (stage == STAGE_FINAL)
     {
       Display *dpy = DEVICE_X_DISPLAY (d);
@@ -264,7 +264,7 @@
   return result;
 }
 
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
 /* #### debug functions: find a better place for us */
 const char *FcResultToString (FcResult r);
 const char *
@@ -694,7 +694,7 @@
 }
 #undef DECLARE_DEBUG_FONTNAME
 
-#endif /* USE_XFT */
+#endif /* XEMACS_USE_XFT */
 
 /* find a font spec that matches font spec FONT and also matches
    (the registry of) CHARSET. */
@@ -711,7 +711,7 @@
   DECLARE_EISTRING (ei_xlfd_without_registry);
   DECLARE_EISTRING (ei_xlfd);
 
-#ifdef USE_XFT 
+#ifdef XEMACS_USE_XFT 
   result = xft_find_charset_font (font, charset, stage);
   if (!NILP (result)) 
     {
