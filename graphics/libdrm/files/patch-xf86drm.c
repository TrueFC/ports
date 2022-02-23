--- xf86drm.c.orig	2021-12-02 07:16:12 UTC
+++ xf86drm.c
@@ -3572,8 +3572,14 @@ static int drmParseSubsystemType(int maj, int min)
             return DRM_BUS_VIRTIO;
      }
     return subsystem_type;
-#elif defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
+#elif defined(__OpenBSD__) || defined(__DragonFly__)
+    
     return DRM_BUS_PCI;
+#elif defined(__FreeBSD__) && defined(__aarch64__)
+    return DRM_BUS_PLATFORM;
+#elif defined(__FreeBSD__)
+    return DRM_BUS_PCI;
+
 #else
 #warning "Missing implementation of drmParseSubsystemType"
     return -EINVAL;
@@ -3611,8 +3617,8 @@ static int get_sysctl_pci_bus_info(int maj, int min, d
     rdev = makedev(maj, min);
     if (!devname_r(rdev, S_IFCHR, dname, sizeof(dname)))
       return -EINVAL;
-
-    if (sscanf(dname, "drm/%d\n", &id) != 1)
+    drmMsg("dname: %s\n",dname);
+    if (sscanf(dname, "dri/card%d\n", &id) != 1)
         return -EINVAL;
     type = drmGetMinorType(maj, min);
     if (type == -1)
@@ -3731,7 +3737,7 @@ drm_public int drmDevicesEqual(drmDevicePtr a, drmDevi
         return memcmp(a->businfo.usb, b->businfo.usb, sizeof(drmUsbBusInfo)) == 0;
 
     case DRM_BUS_PLATFORM:
-        return memcmp(a->businfo.platform, b->businfo.platform, sizeof(drmPlatformBusInfo)) == 0;
+      return 0;//memcmp(a->businfo.platform, b->businfo.platform, sizeof(drmPlatformBusInfo)) == 0;
 
     case DRM_BUS_HOST1X:
         return memcmp(a->businfo.host1x, b->businfo.host1x, sizeof(drmHost1xBusInfo)) == 0;
@@ -4252,7 +4258,33 @@ static int drmParseOFBusInfo(int maj, int min, char *f
     free(name);
 
     return 0;
+#elif defined(__FreeBSD__)
+char * info = malloc(255);
+size_t len = 255;
+ sysctlbyname("dev.panfrost.0.%pnpinfo",info,&len,NULL,0);
+ info[len]='\0';
+
+    char* token = strtok(info, "=");
+
+
+    while (token != NULL) {
+      if(strncmp(token,"name",4)==0) {
+	token = strtok(NULL, " ");
+	strncpy(fullname,token,len);
+	free(info);
+	
+        return 0;
+       
+      }
+      token = strtok(NULL,"=");
+    }
+    
+    strcpy(fullname,devname(makedev(maj,min),S_IFCHR));
+    return 0;
+
+    
 #else
+   
 #warning "Missing implementation of drmParseOFBusInfo"
     return -EINVAL;
 #endif
@@ -4312,7 +4344,9 @@ free:
 
     free(*compatible);
     return err;
-#else
+#elif __FreeBSD__
+    return 0;
+#else    
 #warning "Missing implementation of drmParseOFDeviceInfo"
     return -EINVAL;
 #endif
@@ -4592,13 +4626,14 @@ drm_public int drmGetDevice2(int fd, uint32_t flags, d
     if (subsystem_type < 0)
         return subsystem_type;
 
-    sysdir = opendir(DRM_DIR_NAME);
+    sysdir = opendir("/dev/dri");
     if (!sysdir)
         return -errno;
 
     i = 0;
     while ((dent = readdir(sysdir))) {
         ret = process_device(&d, dent->d_name, subsystem_type, true, flags);
+	drmMsg("%s %d\n",dent->d_name,ret);
         if (ret)
             continue;
 
@@ -4676,13 +4711,14 @@ drm_public int drmGetDevices2(uint32_t flags, drmDevic
     if (drm_device_validate_flags(flags))
         return -EINVAL;
 
-    sysdir = opendir(DRM_DIR_NAME);
+    sysdir = opendir("/dev/dri");
     if (!sysdir)
         return -errno;
 
     i = 0;
     while ((dent = readdir(sysdir))) {
         ret = process_device(&device, dent->d_name, -1, devices != NULL, flags);
+    	drmMsg("MARK ret= %d\n",ret);
         if (ret)
             continue;
 
@@ -4696,7 +4732,7 @@ drm_public int drmGetDevices2(uint32_t flags, drmDevic
         i++;
     }
     node_count = i;
-
+    drmMsg("MARK %d\n",i);
     drmFoldDuplicatedDevices(local_devices, node_count);
 
     device_count = 0;
