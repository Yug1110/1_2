#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define kernel_2d_memcpy 451

int main()
{
    long sys_call_status;

    sys_call_status = syscall(kernel_2d_memcpy);

    if (!sys_call_status)
    {
        printf("Successfully invoked system call 451\n");
    }

    return 0;
}
