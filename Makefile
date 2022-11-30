all: 
	cp -v new_sec.c /root/new_kernel/linux-5.19.9/ &&cd /root/new_kernel/linux-5.19.9/ &&gcc new_sec.c -o process &&./process &&rm process
