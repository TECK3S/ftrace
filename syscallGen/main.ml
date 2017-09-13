(************************************************)
(*						*)
(*						*)
(*	        Main - SyscallGen		*)
(*	    Made by barrau_a & ngonta_e		*)
(*						*)
(*						*)
(************************************************)

type paramType =
    Cast of (string * string)
  | Fun of (string * string)
  | ErrCast of (paramType * string)
  | ErrFun of (paramType * string)

let allSyscalls =
  [
    ("restart_syscall", [], (Cast ("int", "%i")));
    ("exit", [(Cast ("int", "%i"))], (Cast ("char *)\"\");//", "<void>%s")));
    ("fork", [], (ErrCast ((Cast ("pid_t", "%i")), "-1")));
    ("read", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("size_t", "%u"))], (ErrCast ((Cast ("ssize_t", "%i")), "-1")));
    ("write", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("size_t", "%u"))], (ErrCast ((Cast ("ssize_t", "%i")), "-1")));
    ("open", [(Fun ("p_string", "%s")); (Fun ("p_open_flag", "%s")); (Fun ("p_open_mode", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("close", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("waitpid", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Fun ("p_waitpid_option", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("creat", [(Fun ("p_string", "%s")); (Fun ("p_open_mode", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("link", [(Fun ("p_string", "%s")); (Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("unlink", [(Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("execve", [(Fun ("p_string", "%s")); (Fun ("p_argv", "%s")); (Fun ("p_env", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("chdir", [(Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("time", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mknod", [(Fun ("p_string", "%s")); (Fun ("p_mknod_mode", "%s")); (Fun ("p_mknod_dev", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("chmod", [(Fun ("p_string", "%s")); (Fun ("p_open_mode", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("lchown", [(Fun ("p_string", "%s")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("break", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("oldstat", [(Fun ("p_string", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("lseek", [(Cast ("int", "%i")); (Cast ("unsigned int", "%u")); (Fun ("p_seek_whence", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getpid", [], (Cast ("int", "%i")));
    ("mount", [(Fun ("p_string", "%s")); (Fun ("p_string", "%s")); (Fun ("p_string", "%s")); (Fun ("p_mount_flags", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("umount", [(Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setuid", [(Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getuid", [], (Cast ("unsigned int", "%u")));
    ("stime", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ptrace", [(Fun ("p_ptrace_req", "%s")); (Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("alarm", [(Cast ("unsigned int", "%u"))], (Cast ("unsigned int", "%u")));
    ("oldfstat", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("pause", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("utime", [(Fun ("p_string", "%s")); (Fun ("p_struct_utime", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("stty", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("gtty", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("access", [(Fun ("p_string", "%s")); (Fun ("p_access_mode", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("nice", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ftime", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sync", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("kill", [(Cast ("int", "%i")); (Fun ("p_signal", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rename", [(Fun ("p_string", "%s")); (Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mkdir", [(Fun ("p_string", "%s")); (Fun ("p_open_mode", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rmdir", [(Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("dup", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("pipe", [(Fun ("p_double_int_tab", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("times", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("prof", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("brk", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setgid", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getgid", [], (Cast ("int", "%i")));
    ("signal", [(Fun ("p_signal", "%s")); (Fun ("p_sighandler", "%s"))], (ErrFun ((Fun ("p_sighandler", "%s")), "(int)SIG_ERR")));
    ("geteuid", [], (Cast ("int", "%i")));
    ("getegid", [], (Cast ("int", "%i")));
    ("acct", [(Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("umount2", [(Fun ("p_string", "%s")); (Fun ("p_umount2_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("lock", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ioctl", [(Cast ("int", "%i")); (Fun ("p_ioctl_req", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fcntl", [(Cast ("int", "%i")); (Fun ("p_fcntl_req", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mpx", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setpgid", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ulimit", [(Cast ("int", "%i")); (Cast ("long", "%li"))], (ErrCast ((Cast ("long", "%li")), "-1")));
    ("oldolduname", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("umask", [(Fun ("p_umask_mod", "%s"))], (Fun ("p_umask_mod", "%s")));
    ("chroot", [(Fun ("p_string", "%s"))], (ErrCast((Cast ("int", "%i")), "-1")));
    ("ustat", [(Fun ("p_ustat_dev", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1"))); 
    ("dup2", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getppid", [], (Cast ("int", "%i")));
    ("getpgrp", [], (Cast ("int", "%i")));
    ("setsid", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sigaction", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sgetmask", [], (ErrCast ((Cast ("long", "%li")), "-1")));
    ("ssetmask", [(Cast ("long", "%li"))], (ErrCast ((Cast ("long", "%li")), "-1")));
    ("setreuid", [(Cast ("uid_t", "%i")); (Cast ("uid_t", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setregid", [(Cast ("gid_t", "%i")); (Cast ("gid_t", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sigsuspend", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sigpending", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sethostname", [(Fun ("p_string", "%s")); (Cast ("size_t", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setrlimit", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getrlimit", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getrusage", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("gettimeofday", [(Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("settimeofday", [(Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getgroups", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setgroups", [(Cast ("size_t", "%u")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("select", [(Cast ("int", "%i")); (Fun ("p_struct_array_fd_set", "%s")); (Fun ("p_struct_array_fd_set", "%s")); (Fun ("p_struct_array_timeval", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("symlink", [(Fun ("p_string", "%s")); (Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("oldlstat", [(Fun ("p_string", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("readlink", [(Fun ("p_string", "%s")); (Fun ("p_string", "%s")); (Cast ("size_t", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("uselib", [(Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("swapon", [(Fun ("p_string", "%s")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("reboot", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("readdir", [(Cast ("unsigned int", "%u")); (Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mmap", [(Cast ("void *", "%p")); (Cast ("size_t", "%u")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("void *", "%p")), "-1")));
    ("munmap", [(Cast ("void *", "%p")); (Cast ("size_t", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("truncate", [(Fun ("p_string", "%s")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ftruncate", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fchmod", [(Cast ("int", "%i")); (Fun ("p_fchmod_mod", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fchown", [(Cast ("int", "%i")); (Cast ("uid_t", "%u")); (Cast ("gid_t", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getpriority", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setpriority", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("profil", [(Cast ("void *", "%p")); (Cast ("size_t", "%u")); (Cast ("size_t", "%u")); (Cast ("unsigned int", "%u"))], (Cast ("char *)\"\");//", "<void>%s")));
    ("statfs", [(Fun ("p_string", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fstatfs", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ioperm", [(Cast ("unsigned long", "%li")); (Cast ("unsigned long", "%li")); (Cast ("unsigned long", "%li"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("socketcall", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("syslog", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setitimer", [(Cast ("int", "%i")); (Fun ("p_struct_array_itimerval", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getitimer", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("stat", [(Fun ("p_string", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("lstat", [(Fun ("p_string", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fstat", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("olduname", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("iopl", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("vhangup", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("idle", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("vm86old", [(Fun ("p_vm86old_struct", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("wait4", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Fun ("p_waitpid_option", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("swapoff", [(Fun ("p_string", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sysinfo", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ipc", [(Cast ("unsigned int", "%u")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fsync", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sigreturn", [(Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("clone", [(Cast ("void *", "%p")); (Cast ("void *", "%p")); (Fun ("p_clone_flag", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setdomainname", [(Fun ("p_string", "%s")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("uname", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("modify_ldt", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("adjtimex", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mprotect", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u")); (Fun ("p_mprotect_prot", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sigprocmask", [(Fun ("p_procmask_how", "%s")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("create_module", [(Fun ("p_string", "%s")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("get_kernel_syms", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("quotactl", [(Fun ("p_quota_cmd", "%s")); (Cast ("char", "%c")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getpgid", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fchdir", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("bdflush", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sysfs", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("personality", [(Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("afs_syscall", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setfsuid", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setfsgid", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("_llseek", [(Cast ("unsigned int", "%u")); (Cast ("unsigned int", "%u")); (Cast ("unsigned int", "%u")); (Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getdents", [(Cast ("unsigned int", "%u")); (Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("_newselect", [(Cast ("int", "%i")); (Fun ("p_struct_array_fd_set", "%s")); (Fun ("p_struct_array_fd_set", "%s")); (Fun ("p_struct_array_timeval", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("flock", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("msync", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("readv", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("writev", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getsid", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fdatasync", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("_sysctl", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mlock", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("munlock", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mlockall", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("munlockall", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sched_setparam", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sched_getparam", [(Cast ("pid_t", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sched_setscheduler", [(Cast ("pid_t", "%i")); (Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sched_getscheduler", [(Cast ("pid_t", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sched_yield", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sched_get_priority_max", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sched_get_priority_min", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sched_rr_get_interval", [(Cast ("pid_t", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("nanosleep", [(Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mremap", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u")); (Cast ("unsigned int", "%u")); (Cast ("int", "%i"))], (ErrCast ((Cast ("void *", "%p")), "-1")));
    ("setresuid", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getresuid", [(Cast ("void *", "%p")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("vm86", [(Cast ("unsigned int", "%u")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("query_module", [(Fun ("p_string", "%s")); (Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("unsigned int", "%u")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("poll", [(Cast ("void *", "%p")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("nfsservctl", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setresgid", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getresgid", [(Cast ("void *", "%p")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("prctl", [(Cast ("int", "%i")); (Cast ("unsigned int", "%u")); (Cast ("unsigned int", "%u")); (Cast ("unsigned int", "%u")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rt_sigreturn", [(Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rt_sigaction", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rt_sigprocmask", [(Fun ("p_procmask_how", "%s")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rt_sigpending", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rt_sigtimedwait", [(Cast ("void *", "%p")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rt_sigqueueinfo", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("rt_sigsuspend", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("pread64", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("pwrite64", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("chown", [(Fun ("p_string", "%s")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getcwd", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("void *", "%p")), "0")));
    ("capget", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("capset", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sigaltstack", [(Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("sendfile", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getpmsg", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("putpmsg", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("vfork", [], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ugetrlimit", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("mmap2", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u")); (Fun ("p_mmap2_prot", "%s")); (Fun ("p_mmap2_map", "%s")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("void *", "%p")), "-1")));
    ("truncate64", [(Fun ("p_string", "%s")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("ftruncate64", [(Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("stat64", [(Fun ("p_string", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("lstat64", [(Fun ("p_string", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fstat64", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("lchown32", [(Fun ("p_string", "%s")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getuid32", [], (Cast ("unsigned int", "%u")));
    ("getgid32", [], (Cast ("int", "%i")));
    ("geteuid32", [], (Cast ("int", "%i")));
    ("getegid32", [], (Cast ("int", "%i")));
    ("setreuid32", [(Cast ("uid_t", "%i")); (Cast ("uid_t", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setregid32", [(Cast ("gid_t", "%i")); (Cast ("gid_t", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getgroups32", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setgroups32", [(Cast ("size_t", "%u")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fchown32", [(Cast ("int", "%i")); (Cast ("uid_t", "%u")); (Cast ("gid_t", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setresuid32", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getresuid32", [(Cast ("void *", "%p")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setresgid32", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("getresgid32", [(Cast ("void *", "%p")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("chown32", [(Fun ("p_string", "%s")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setuid32", [(Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setgid32", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setfsuid32", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("setfsgid32", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("pivot_root",  [(Cast ("void *", "%p")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("mincore", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("madvise", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("madvise1", [(Cast ("void *", "%p")); (Cast ("unsigned int", "%u")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("getdents64", [(Cast ("unsigned int", "%u")); (Cast ("void *", "%p")); (Cast ("unsigned int", "%u"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("fcntl64", [(Cast ("int", "%i")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("gettid", [], ErrCast ((Cast ("int", "%i")), "-1"));
    ("readahead", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("size_t", "%u"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("setxattr",  [], (Cast ("char *)\"\");//", "<void>%s")));
    ("lsetxattr", [], (Cast ("char *)\"\");//", "<void>%s")));   
    ("fsetxattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("getxattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("lgetxattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("fgetxattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("listxattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("llistxattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("flistxattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("removexattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("lremovexattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("fremovexattr", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("tkill", [(Cast ("int", "%i")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("sendfile64", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("size_t", "%u"))], ErrCast ((Cast ("ssize_t", "%i")), "-1"));
    ("futex", [(Cast ("void *", "%p")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("int", "%i")); (Cast ("int", "%i"));], ErrCast ((Cast ("int", "%i")), "-1"));
    ("sched_setaffinity", [(Cast ("pid_t", "%i")); (Cast ("size_t", "%u")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("sched_getaffinity", [(Cast ("pid_t", "%i")); (Cast ("size_t", "%u")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("set_thread_area", [(Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("get_thread_area",  [(Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("io_setup", [(Cast ("unsigned int", "%u")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("io_destroy", [(Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("io_getevents", [(Cast ("int", "%i")); (Cast ("long", "%li")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("io_submit", [(Cast ("int", "%i")); (Cast ("long", "%li")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("io_cancel", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("fadvise64", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("exit_group", [(Cast ("int", "%i)"))], (Cast ("char *)\"\");//", "<void>%s")));
    ("lookup_dcookie", [(Cast ("unsigned int", "%u")); (Fun ("p_string", "%s")); (Cast ("unsigned int", "%u"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("epoll_create", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("epoll_ctl", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"));  (Fun ("p_struct_array_epoll_event", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("epoll_wait", [(Cast ("int", "%i")); (Fun ("p_struct_array_epoll_event", "%s")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("remap_file_pages", [(Cast ("void *", "%p")); (Cast ("size_t", "%u")); (Cast ("size_t", "%u")); (Fun ("p_nmap_flag", "%s"))], (ErrCast ((Cast ("long", "%li")), "-1")));
    ("set_tid_address", [(Cast ("void *", "%p"))], (ErrCast ((Cast ("long", "%li")), "-1")));
    ("timer_create", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("timer_settime", [(Cast ("int", "%i")); (Fun ("p_clock_flag", "%s")); (Fun ("p_struct_array_itimerspec", "%s")); (Fun ("p_struct_array_itimerspec", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("timer_gettime", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("timer_getoverrun", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("timer_delete", [(Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("clock_settime", [(Cast ("int", "%i")); (Fun ("p_struct_array_timespec", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("clock_gettime", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("clock_getres", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("clock_nanosleep", [(Cast ("int", "%i")); (Fun ("p_clock_flag", "%s")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("statfs64", [(Fun ("p_string", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fstatfs64", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("tgkill", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("utimes", [(Cast ("void *", "%p")); (Fun ("p_struct_array_timeval", "%s")); ], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fadvise64_64", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("vserver", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("mbind", [(Cast ("void *", "%p")); (Cast ("unsigned long", "%lu")); (Fun ("p_bind_mode", "%s")); (Cast ("void *", "%p")); (Cast ("unsigned long", "%lu")); (Fun ("p_bind_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("get_mempolicy", [(Cast ("void *", "%p")); (Cast ("void *", "%p")); (Cast ("unsigned long", "%lu")); (Cast ("unsigned long", "%lu")); (Fun ("p_set_mempolicy_flags", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("set_mempolicy", [(Fun ("p_set_mempolicy_mode", "%s")); (Cast ("void *", "%p")); (Cast ("unsigned long", "%lu"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("mq_open", [(Fun ("p_string", "%s")); (Fun ("p_open_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("mq_unlink", [(Fun ("p_string", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("mq_timedsend", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("size_t", "%u")); (Cast ("unsigned int", "%u")); (Fun ("p_struct_array_timespec", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("mq_timedreceive", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("size_t", "%u")); (Cast ("void *", "%p")); (Fun ("p_struct_array_timespec", "%s"))], ErrCast ((Cast ("ssize_t", "%i")), "-1"));
    ("mq_notify", [(Cast ("int", "%i")); (Fun ("p_struct_array_sigevent", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("mq_getsetattr", [(Cast ("int", "%i")); (Fun ("p_struct_array_mq_attr", "%s")); (Cast ("void *", "%p"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("kexec_load", [(Cast ("unsigned long", "%lu")); (Cast ("unsigned long", "%lu")); (Cast ("void *", "%p")); (Fun ("p_kexec_load_flag", "%s"))], ErrCast ((Cast ("long", "%li")), "-1"));
    ("waitid", [(Cast ("pid_t", "%i")); (Cast ("pid_t", "%i")); (Cast ("void *", "%p")); (Cast ("int", "%i"))], ErrCast ((Cast ("long", "%li")), "-1"));
    ("unknown", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("add_key", [(Fun ("p_string", "%s")); (Fun ("p_string", "%s")); (Fun ("p_string", "%s")); (Cast ("size_t", "%u")); (Cast ("key_t", "%i"))], ErrCast ((Cast ("key_t", "%i"), "-1")));
    ("request_key", [(Fun ("p_string", "%s")); (Fun ("p_string", "%s")); (Fun ("p_string", "%s")); (Cast ("key_t", "%i"))], ErrCast ((Cast ("key_t", "%i"), "-1")));
    ("keyctl", [(Cast ("int", "%i"))], ErrCast ((Cast ("long", "%li")), "-1"));
    ("ioprio_get", [(Cast ("int", "%i")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("ioprio_set", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("inotify_init", [], ErrCast ((Cast ("int", "%i")), "-1"));
    ("inotify_add_watch", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("unsigned int", "%u"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("inotify_rm_watch", [(Cast ("int", "%i")); (Cast ("unsigned int", "%u"))],  ErrCast ((Cast ("int", "%i")), "-1"));
    ("migrate_pages", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("openat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_open_flag", "%s")); (Fun ("p_open_mode", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("mkdirat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_mkdir_mode", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("mknodat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_mknod_mode", "%s")); (Fun ("p_mknod_dev", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("fchownat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("uid_t", "%i")); (Cast ("gid_t", "%i")); (Fun ("p_chown_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("futimesat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_struct_array_timeval", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("fstatat64" ,[(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("void *", "%p")); (Fun ("p_stat_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("unlinkat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_link_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("renameat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("int", "%i")); (Fun ("p_string", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("linkat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_link_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("symlinkat", [(Fun ("p_string", "%s")); (Cast ("int", "%i")); (Fun ("p_string", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("readlinkat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Cast ("void *", "%p")); (Cast ("size_t", "%u"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("fchmodat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_chmod_mode", "%s")); (Fun ("p_chmod_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("faccessat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_access_mode", "%s")); (Fun ("p_access_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("pselect6", [(Cast ("int", "%i")); (Fun ("p_struct_array_fdset", "%s")); (Fun ("p_struct_array_fdset", "%s")); (Fun ("p_struct_array_fdset", "%s")); (Fun ("p_struct_array_timespec", "%s")); (Fun ("p_struct_array_sigset_t", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("ppoll", [(Fun ("p_struct_array_pollfd", "%s")); (Cast ("size_t", "%u")); (Fun ("p_struct_array_timespec", "%s")); (Fun ("p_struct_array_sigset_t", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));  
    ("unshare", [(Fun ("p_unshare_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("set_robust_list", [(Fun ("p_struct_array_robust_list_head", "%s")); (Cast ("size_t", "%u"))], ErrCast ((Cast ("long", "%li")), "-1"));
    ("get_robust_list", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], ErrCast ((Cast ("long", "%li")), "-1"));
    ("splice", [(Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("int", "%i")); (Cast ("void *", "%p")); (Cast ("size_t", "%u")); (Fun ("p_splice_flag", "%s"))],  ErrCast ((Cast ("ssize_t", "%i")), "-1"));
    ("sync_file_range", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Fun ("p_sunc_file_range_flag", "%s"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("tee", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("size_t", "%u")); (Cast ("size_t", "%u")); (Fun ("p_tee_flag", "%s"))], ErrCast ((Cast ("ssize_t", "%i")), "-1"));
    ("vmsplice", [(Cast ("int", "%i")); (Fun ("p_struct_array_iovec", "%s")); (Cast ("unsigned long", "%lu")); (Fun ("p_vmsplice_flag", "%s"))], ErrCast ((Cast ("ssize_t", "%i")), "-1"));
    ("move_pages", [(Cast ("int", "%i")); (Cast ("unsigned long", "%lu")); (Cast ("void *", "%p")); (Cast ("void *", "%p")); (Cast ("void *", "%p")); (Fun ("p_move_pages_flag", "%s"))], ErrCast ((Cast ("long", "%li")), "-1"));
    ("getcpu", [(Cast ("void *", "%p")); (Cast ("void *", "%p")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("ssize_t", "%i")), "-1")));
    ("epoll_pwait", [(Cast ("int", "%i")); (Fun ("p_struct_array_epoll_event", "%s")); (Cast ("int", "%i")); (Cast ("int", "%i")); (Fun ("p_struct_array_sigset_t", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("utimensat", [(Cast ("int", "%i")); (Fun ("p_string", "%s")); (Fun ("p_struct_array_timespec", "%s")); (Fun ("p_utimensat_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("signalfd", [(Cast ("int", "%i")); (Fun ("p_struct_array_sigset_t", "%s")); (Fun ("p_signalfd_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("timerfd_create", [(Cast ("int", "%i")); (Fun ("p_timerfd_create_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("eventfd", [(Cast ("unsigned int", "%u")); (Fun ("p_eventfd_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("fallocate", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Cast ("int", "%i"))], ErrCast ((Cast ("int", "%i")), "-1"));
    ("timerfd_settime", [(Cast ("int", "%i")); (Fun ("p_timerfd_settime_flag", "%s")); (Fun ("p_struct_array_itimerspec", "%s")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("timerfd_gettime", [(Cast ("int", "%i")); (Cast ("void *", "%p"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("signalfd4", [(Cast ("int", "%i")); (Fun ("p_struct_array_sigset_t", "%s")); (Fun ("p_signalfd_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("eventfd2", [(Cast ("unsigned int", "%u")); (Fun ("p_eventfd_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("epoll_create1", [(Fun ("p_epoll_create1_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("dup3", [(Cast ("int", "%i")); (Cast ("int", "%i")); (Fun ("p_dup3_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("pipe2", [(Fun ("p_int_array", "%s")); (Fun ("p_pipe1_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("inotify_init1", [(Fun ("p_inotify_init1_flag", "%s"))], (ErrCast ((Cast ("int", "%i")), "-1")));
    ("preadv", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("pwritev", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("rt_tgsigqueueinfo", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("perf_event_open", [], (Cast ("char *)\"\");//", "<void>%s")));
    ("recvmsg", [(Cast ("unsigned int", "%u")); (Cast ("void *", "%p")); (Fun ("p_recvmsg_flag", "%s"))], (ErrCast ((Cast ("unsigned int", "%u")), "-1")))
  ]

let header_c = "/*\n** syscalls1.c for <Ftrace> in /u/all/barrau_a/public/ftrace\n**\n** Made by eugene-valentin ngontang-tchiadjie\n** Login   <ngonta_e@epitech.net>\n**\n** Started on  Wed May 11 19:58:13 2011 eugene-valentin ngontang-tchiadjie\n** ast update Thu May 12 20:06:11 2011 eugene-valentin ngontang-tchiadjie\n*/\n\n#include <sys/types.h>\n#include <sys/user.h>\n#include <unistd.h>\n#include <stdio.h>\n#include <signal.h>\n#include <stdlib.h>\n#include \"ftrace.h\"\n#include \"list.h\"\n\n"

let begNameFun = "void	tr_"
let midNameFun = "(struct user_regs_struct * reg,\n      enum mode the_mode,\n      pid_t pid,\n      t_symbol_graph * graph)\n{\n  static int nbChars = 0;\n  t_symbol_graph * sym = NULL;\n  extern int symbol_id;\n\n  (void)pid;\n  (void)reg;\n  if (the_mode == PARAM)\n    {\n      sym = malloc(sizeof(*sym));\n      sym->id = symbol_id++;\n      sym->symbol_name = \""
let endNameFun = "\";\n      sym->symbol_addr = 0x00000000;\n      sym->symbol_type = SYSCALLS;\n      sym->debug_info = malloc(MAX_SYSCALLS_CHAR * sizeof(*sym->debug_info));\n      nbChars = sprintf(sym->debug_info, \"Parameters ("

let endParamFun = ");\n      sym->sub_symbols = EMPTY;\n      list_push_back(&graph->sub_symbols, sym);\n    }\n  else\n    {\n      sym = list_back(graph->sub_symbols);\n      nbChars += sprintf(&(sym->debug_info[nbChars]), \")\\nReturn\");\n      "

let endRetFun = "\n    }\n}\n\n"

let getSysName =  function | (name, _, _)  -> name
  
let getSysParam = function | (_, param, _) -> param
  
let getSysRet =   function | (_, _, ret)   -> ret
 
let open_first () =
  let first_chan = open_out "syscalls1.c"
  in
  let _ = output_string first_chan header_c
  in 
    first_chan

let open_other chan c tl =
  if (c + 1) mod 5 = 0 && List.length tl > 0 then
    let new_chan = open_out ("syscalls" ^ (string_of_int (((c + 1) / 5) + 1)) ^ ".c")
    in
    let _ = output_string new_chan header_c
    in (close_out chan;	new_chan)
  else
    chan

let getReg = function
  | 1 -> "reg->ebx"
  | 2 -> "reg->ecx"
  | 3 -> "reg->edx"
  | 4 -> "reg->esi"
  | 5 -> "reg->edi"
  | 6 -> "reg->ebp"
  | _ -> ""

let print_name channel name = 
  let _ = output_string channel (begNameFun ^ name ^ midNameFun ^ name ^ endNameFun)
  in ()
 
let print_param channel param_list = 
  let par_str nb = function
    | Cast (p, _) -> ("(" ^ p ^ ")" ^ (getReg nb))
    | Fun  (p, _) -> (p ^ "(" ^ (getReg nb) ^ ", pid)")
    | _           -> ""
  and aff_str = function
    | Cast (_, a) -> a
    | Fun  (_, a) -> a
    | _           -> ""
  in
  let rec one_aff_par = function
    | []       -> let _ =
	if List.length param_list > 0 then 
	  output_string channel "\",\n        "
	else
	  output_string channel "\""
      in ()
    | last::[] -> let _ = output_string channel (aff_str last)        in one_aff_par []
    | hd::tl   -> let _ = output_string channel ((aff_str hd) ^ ", ") in one_aff_par tl
  and one_par_par c = function
    | []       -> let _ = output_string channel endParamFun                      in ()
    | last::[] -> let _ = output_string channel (par_str c last)                 in one_par_par (c + 1) []
    | hd::tl   -> let _ = output_string channel ((par_str c hd) ^ ",\n        ") in one_par_par (c + 1) tl
  in
    (one_aff_par param_list; one_par_par 1 param_list)
      
let print_ret channel = function
  | Cast (p, a)              ->
      let _ = output_string channel ("sprintf(&(sym->debug_info[nbChars]), \" (" ^ a ^ ")\", (" ^ p ^ ")reg->eax);" ^ endRetFun)
      in ()
  | Fun (p, a)               ->
      let _ = output_string channel ("sprintf(&(sym->debug_info[nbChars]), \" (" ^ a ^ ")\", " ^ p ^ "(reg->eax, pid));" ^ endRetFun)
      in ()
  | ErrCast (Cast (p, a), e) ->
      let _ = output_string channel ("((int)reg->eax <= " ^ e ^ " ?\n        sprintf(&(sym->debug_info[nbChars]), \"%s\", p_error(reg->eax, pid))\n       : sprintf(&(sym->debug_info[nbChars]), \" (" ^ a ^ ")\", (" ^ p ^ ")reg->eax));" ^ endRetFun)
      in ()
  | ErrFun (Fun (p, a), e)   ->
      let _ = output_string channel ("((int)reg->eax <= " ^ e ^ " ?\n        sprintf(&(sym->debug_info[nbChars]), \"%s\", p_error(reg->eax, pid))\n       : sprintf(&(sym->debug_info[nbChars]), \" (" ^ a ^ ")\", " ^ p ^ "(reg->eax, pid)));" ^ endRetFun)
      in ()
  | _                        -> ()

let print_sys sys channel =
  let _ = print_name channel (getSysName sys)		(* Debut de la fonction *)
  and _ = (print_param channel (getSysParam sys))	(* Ecriture des parametres *)
  and _ = (print_ret channel (getSysRet sys))		(* Ecrite de la valeur de retour et fin de la fonction *)
  in
    print_endline ("Traitement de " ^ (getSysName sys))
      
let rec syscallGen c chan = function
  | []     -> close_out chan
  | hd::tl -> (print_sys hd chan;
	       syscallGen (c + 1) (open_other chan c tl) tl)

let _ =
  if List.length allSyscalls > 0 then
    syscallGen 0 (open_first ()) allSyscalls
