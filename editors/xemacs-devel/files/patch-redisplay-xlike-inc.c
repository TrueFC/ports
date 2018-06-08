--- src/redisplay-xlike-inc.c.org	2013-08-22 02:43:44.000000000 +0900
+++ src/redisplay-xlike-inc.c	2016-05-11 19:18:28.000000000 +0900
@@ -175,7 +175,7 @@
    the 8-bit versions in computing runs and runes, it would seem.
 */
 
-#if !defined(USE_XFT) && !defined(MULE)
+#if !defined(XEMACS_USE_XFT) && !defined(MULE)
 static int
 separate_textual_runs_nomule (unsigned char *text_storage,
 			      struct textual_run *run_storage,
@@ -196,7 +196,7 @@
 }
 #endif
 
-#if defined(USE_XFT) && !defined(MULE)
+#if defined(XEMACS_USE_XFT) && !defined(MULE)
 /*
   Note that in this configuration the "Croatian hack" of using an 8-bit,
   non-Latin-1 font to get localized display without Mule simply isn't
@@ -230,7 +230,7 @@
 }
 #endif
 
-#if defined(USE_XFT) && defined(MULE)
+#if defined(XEMACS_USE_XFT) && defined(MULE)
 static int
 separate_textual_runs_xft_mule (unsigned char *text_storage,
 				struct textual_run *run_storage,
@@ -277,7 +277,7 @@
 }
 #endif
 
-#if !defined(USE_XFT) && defined(MULE)
+#if !defined(XEMACS_USE_XFT) && defined(MULE)
 /*
   This is the most complex function of this group, due to the various
   indexing schemes used by different fonts.  For our purposes, they
@@ -434,19 +434,19 @@
 		       const Ichar *str, Charcount len,
 		       struct face_cachel *cachel)
 {
-#if defined(USE_XFT) && defined(MULE)
+#if defined(XEMACS_USE_XFT) && defined(MULE)
   return separate_textual_runs_xft_mule (text_storage, run_storage,
 					 str, len, cachel);
 #endif
-#if defined(USE_XFT) && !defined(MULE)
+#if defined(XEMACS_USE_XFT) && !defined(MULE)
   return separate_textual_runs_xft_nomule (text_storage, run_storage,
 					   str, len, cachel);
 #endif
-#if !defined(USE_XFT) && defined(MULE)
+#if !defined(XEMACS_USE_XFT) && defined(MULE)
   return separate_textual_runs_mule (text_storage, run_storage,
 				     str, len, cachel);
 #endif
-#if !defined(USE_XFT) && !defined(MULE)
+#if !defined(XEMACS_USE_XFT) && !defined(MULE)
   return separate_textual_runs_nomule (text_storage, run_storage,
 				       str, len, cachel);
 #endif
@@ -468,7 +468,7 @@
 
   if (!fi->proportional_p)
     return fi->width * run->len;
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
   else if (FONT_INSTANCE_X_XFTFONT (fi))
     {
       static XGlyphInfo glyphinfo;
@@ -580,7 +580,7 @@
 			    int cursor_start, int cursor_width,
 			    int cursor_height)
 {
-#ifndef USE_XFT
+#ifndef XEMACS_USE_XFT
   struct frame *f = XFRAME (w->frame);
 #endif
   Ichar_dynarr *buf;
@@ -793,7 +793,7 @@
 
   if (dl->modeline
       && !EQ (Qzero, w->modeline_shadow_thickness)
-#ifndef USE_XFT
+#ifndef XEMACS_USE_XFT
       /* This optimization doesn't work right with some Xft fonts, which
 	 leave antialiasing turds at the boundary.  I don't know if this
 	 is an Xft bug or not, but I think it is.   See x_output_string. */
@@ -842,7 +842,7 @@
   mask |= XLIKE_GC_FILL;
 
   if (!NILP (font)
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
       /* Only set the font if it's a core font */
       /* the renderfont will be set elsewhere (not part of gc) */
       && !FONT_INSTANCE_X_XFTFONT (XFONT_INSTANCE (font))
@@ -1017,7 +1017,7 @@
   int use_x_font = 1;		/* #### bogus!!
 				   The logic of this function needs review! */
 #endif
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
   Colormap cmap = DEVICE_X_COLORMAP (d);
   Visual *visual = DEVICE_X_VISUAL (d);
   static XftColor fg, bg;
@@ -1035,7 +1035,7 @@
 #define XFT_FROB_LISP_COLOR(color, dim)					\
   xft_convert_color (dpy, cmap, visual,					\
 		     XCOLOR_INSTANCE_X_COLOR (color).pixel, (dim))
-#endif /* USE_XFT */
+#endif /* XEMACS_USE_XFT */
 
   if (width < 0)
     width = XLIKE_text_width (f, cachel, Dynarr_begin (buf),
@@ -1170,7 +1170,7 @@
 
       if (cursor && cursor_cachel && focus && NILP (bar_cursor_value))
 	{
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
 	  fg = XFT_FROB_LISP_COLOR (cursor_cachel->foreground, 0);
 	  bg = XFT_FROB_LISP_COLOR (cursor_cachel->background, 0);
 #endif
@@ -1192,7 +1192,7 @@
 	      ;
 
 	  /* Request a GC with the gray stipple pixmap to draw dimmed text */
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
 	  fg = XFT_FROB_LISP_COLOR (cachel->foreground, 1);
 	  bg = XFT_FROB_LISP_COLOR (cachel->background, 0);
 #endif
@@ -1201,14 +1201,14 @@
 	}
       else
 	{
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
 	  fg = XFT_FROB_LISP_COLOR (cachel->foreground, 0);
 	  bg = XFT_FROB_LISP_COLOR (cachel->background, 0);
 #endif
 	  gc = XLIKE_get_gc (f, font, cachel->foreground, cachel->background,
 			     Qnil, Qnil, Qnil);
 	}
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
       {
 	XftFont *rf = FONT_INSTANCE_X_XFTFONT (fi);
 
@@ -1245,7 +1245,7 @@
 		struct textual_run *run = &runs[i];
 		int rect_width
 		  = XLIKE_text_width_single_run (dpy, cachel, run);
-#ifndef USE_XFTTEXTENTS_TO_AVOID_FONT_DROPPINGS
+#ifndef XEMACS_USE_XFTTEXTENTS_TO_AVOID_FONT_DROPPINGS
 		int rect_height = FONT_INSTANCE_ASCENT (fi)
 				  + FONT_INSTANCE_DESCENT (fi) + 1;
 #else
@@ -1277,7 +1277,7 @@
 			       (XftChar16 *) runs[i].ptr, runs[i].len);
 	  }
       }
-#endif /* USE_XFT */
+#endif /* XEMACS_USE_XFT */
 
 #ifdef THIS_IS_X
       if (use_x_font)
@@ -1426,7 +1426,7 @@
       /* Restore the GC */
       if (need_clipping)
 	{
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
 	  if (!use_x_font)
 	    {
 	      XftDrawSetClip (xftDraw, 0);
@@ -1440,7 +1440,7 @@
 	 the appropriate section highlighted. */
       if (cursor_clip && !cursor && focus && cursor_cachel)
 	{
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
 	  if (!use_x_font)	/* Xft */
 	    {
 	      XftFont *rf = FONT_INSTANCE_X_XFTFONT (fi);
@@ -1477,7 +1477,7 @@
 	      XftDrawSetClip (xftDraw, 0);
 	    }
 	  else			/* core font, not Xft */
-#endif /* USE_XFT */
+#endif /* XEMACS_USE_XFT */
 	    {
 	      XLIKE_RECTANGLE clip_box;
 	      XLIKE_GC cgc;
@@ -1602,7 +1602,7 @@
 	}
     }
 
-#ifdef USE_XFT
+#ifdef XEMACS_USE_XFT
 #undef XFT_FROB_LISP_COLOR
 #endif
 }
