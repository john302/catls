# catls

A library allowing cat on Linux to list files in a directory. Just load this in before running cat and you may list all files in the directory with it.

Compilation.

<pre>
  (jcartwright@localhost) 192.168.1.180 Documents  $ gcc read.c -shared -fPIC -o read.so
</pre>

Then use it like this to list files in a folder.

<pre>
(jcartwright@localhost) 192.168.1.180 Documents  $ LD_PRELOAD=./read.so cat /boot

 efi
 grub2
 loader
 vmlinuz-0-rescue-fca48f43858a4c04a0adfb67d27483f7
 initramfs-0-rescue-fca48f43858a4c04a0adfb67d27483f7.img
 initramfs-5.14.0-503.16.1.el9_5.x86_64.img
 vmlinuz-5.14.0-503.21.1.el9_5.x86_64
 System.map-5.14.0-503.21.1.el9_5.x86_64
 config-5.14.0-503.21.1.el9_5.x86_64
 .vmlinuz-5.14.0-503.21.1.el9_5.x86_64.hmac
 symvers-5.14.0-503.21.1.el9_5.x86_64.gz
 initramfs-5.14.0-503.21.1.el9_5.x86_64.img
 System.map-5.14.0-503.22.1.el9_5.x86_64
 .vmlinuz-5.14.0-503.22.1.el9_5.x86_64.hmac
 initramfs-5.14.0-503.22.1.el9_5.x86_64.img
 vmlinuz-5.14.0-503.16.1.el9_5.x86_64
 System.map-5.14.0-503.16.1.el9_5.x86_64
 config-5.14.0-503.16.1.el9_5.x86_64
 .vmlinuz-5.14.0-503.16.1.el9_5.x86_64.hmac
 symvers-5.14.0-503.16.1.el9_5.x86_64.gz
 vmlinuz-5.14.0-503.22.1.el9_5.x86_64
 config-5.14.0-503.22.1.el9_5.x8
</pre>
