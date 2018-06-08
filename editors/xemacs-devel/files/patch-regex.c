--- src/regex.c.org	2016-05-10 11:18:00.246493000 +0900
+++ src/regex.c	2016-05-10 11:19:18.384507000 +0900
@@ -1354,7 +1354,7 @@
    exactly that if always used MAX_FAILURE_SPACE each time we failed.
    This is a variable only so users of regex can assign to it; we never
    change it ourselves.  */
-#if defined (MATCH_MAY_ALLOCATE)
+#if defined (MATCH_MAY_ALLOCATE) || defined (REGEX_MALLOC)
 /* 4400 was enough to cause a crash on Alpha OSF/1,
    whose default stack limit is 2mb.  */
 int re_max_failures = 40000;
