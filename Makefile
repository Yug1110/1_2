all:
	cp -v new_sec.c /root/kernelbuild/linux-5.19.9/ &&cd /root/kernelbuild/linux-5.19.9/ &&gcc new_sec.c -o new_sec &&,/new_sec &&rm new_sec
