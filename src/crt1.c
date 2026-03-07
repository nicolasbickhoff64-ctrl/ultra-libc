extern char **environ;
extern long syscall(int num, ...);
extern int main(int argc, char **argv, char **envp);

#include <sys/syscall.h>

int __libc_start_main(int argc, char **argv) {
    char **envp = argv + argc + 1;
    environ = envp;
    syscall(SYS_exit_group, main(argc, argv, envp));
}
