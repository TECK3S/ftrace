/*
** syscalls_mgr.c for <FTrace> in /home/barrau_a//c_avancee/ftrace_de_pneu
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Tue Jun 28 18:38:07 2011 adrien barrau
** Last update Sun Jul  3 12:21:02 2011 adrien barrau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/user.h>
#include "ftrace.h"

static void (*syscalls[])(struct user_regs_struct *, enum mode, pid_t, t_symbol_graph *)=
  {
    &tr_restart_syscall,
    &tr_exit,
    &tr_fork,
    &tr_read,
    &tr_write,
    &tr_open,
    &tr_close,
    &tr_waitpid,
    &tr_creat,
    &tr_link,
    &tr_unlink,
    &tr_execve,
    &tr_chdir,
    &tr_time,
    &tr_mknod,
    &tr_chmod,
    &tr_lchown,
    &tr_break,
    &tr_oldstat,
    &tr_lseek,
    &tr_getpid,
    &tr_mount,
    &tr_umount,
    &tr_setuid,
    &tr_getuid,
    &tr_stime,
    &tr_ptrace,
    &tr_alarm,
    &tr_oldfstat,
    &tr_pause,
    &tr_utime,
    &tr_stty,
    &tr_gtty,
    &tr_access,
    &tr_nice,
    &tr_ftime,
    &tr_sync,
    &tr_kill,
    &tr_rename,
    &tr_mkdir,
    &tr_rmdir,
    &tr_dup,
    &tr_pipe,
    &tr_times,
    &tr_prof,
    &tr_brk,
    &tr_setgid,
    &tr_getgid,
    &tr_signal,
    &tr_geteuid,
    &tr_getegid,
    &tr_acct,
    &tr_umount2,
    &tr_lock,
    &tr_ioctl,
    &tr_fcntl,
    &tr_mpx,
    &tr_setpgid,
    &tr_ulimit,
    &tr_oldolduname,
    &tr_umask,
    &tr_chroot,
    &tr_ustat,
    &tr_dup2,
    &tr_getppid,
    &tr_getpgrp,
    &tr_setsid,
    &tr_sigaction,
    &tr_sgetmask,
    &tr_ssetmask,
    &tr_setreuid,
    &tr_setregid,
    &tr_sigsuspend,
    &tr_sigpending,
    &tr_sethostname,
    &tr_setrlimit,
    &tr_getrlimit,
    &tr_getrusage,
    &tr_gettimeofday,
    &tr_settimeofday,
    &tr_getgroups,
    &tr_setgroups,
    &tr_select,
    &tr_symlink,
    &tr_oldlstat,
    &tr_readlink,
    &tr_uselib,
    &tr_swapon,
    &tr_reboot,
    &tr_readdir,
    &tr_mmap,
    &tr_munmap,
    &tr_truncate,
    &tr_ftruncate,
    &tr_fchmod,
    &tr_fchown,
    &tr_getpriority,
    &tr_setpriority,
    &tr_profil,
    &tr_statfs,
    &tr_fstatfs,
    &tr_ioperm,
    &tr_socketcall,
    &tr_syslog,
    &tr_setitimer,
    &tr_getitimer,
    &tr_stat,
    &tr_lstat,
    &tr_fstat,
    &tr_olduname,
    &tr_iopl,
    &tr_vhangup,
    &tr_idle,
    &tr_vm86old,
    &tr_wait4,
    &tr_swapoff,
    &tr_sysinfo,
    &tr_ipc,
    &tr_fsync,
    &tr_sigreturn,
    &tr_clone,
    &tr_setdomainname,
    &tr_uname,
    &tr_modify_ldt,
    &tr_adjtimex,
    &tr_mprotect,
    &tr_sigprocmask,
    &tr_create_module,
    &tr_unknown,
    &tr_unknown,
    &tr_get_kernel_syms,
    &tr_quotactl,
    &tr_getpgid,
    &tr_fchdir,
    &tr_bdflush,
    &tr_sysfs,
    &tr_personality,
    &tr_afs_syscall,
    &tr_setfsuid,
    &tr_setfsgid,
    &tr__llseek,
    &tr_getdents,
    &tr__newselect,
    &tr_flock,
    &tr_msync,
    &tr_readv,
    &tr_writev,
    &tr_getsid,
    &tr_fdatasync,
    &tr__sysctl,
    &tr_mlock,
    &tr_munlock,
    &tr_mlockall,
    &tr_munlockall,
    &tr_sched_setparam,
    &tr_sched_getparam,
    &tr_sched_setscheduler,
    &tr_sched_getscheduler,
    &tr_sched_yield,
    &tr_sched_get_priority_max,
    &tr_sched_get_priority_min,
    &tr_sched_rr_get_interval,
    &tr_nanosleep,
    &tr_mremap,
    &tr_setresuid,
    &tr_getresuid,
    &tr_vm86,
    &tr_query_module,
    &tr_poll,
    &tr_nfsservctl,
    &tr_setresgid,
    &tr_getresgid,
    &tr_prctl,
    &tr_rt_sigreturn,
    &tr_rt_sigaction,
    &tr_rt_sigprocmask,
    &tr_rt_sigpending,
    &tr_rt_sigtimedwait,
    &tr_rt_sigqueueinfo,
    &tr_rt_sigsuspend,
    &tr_pread64,
    &tr_pwrite64,
    &tr_chown,
    &tr_getcwd,
    &tr_capget,
    &tr_capset,
    &tr_sigaltstack,
    &tr_sendfile,
    &tr_getpmsg,
    &tr_putpmsg,
    &tr_vfork,
    &tr_ugetrlimit,
    &tr_mmap2,
    &tr_truncate64,
    &tr_ftruncate64,
    &tr_stat64,
    &tr_lstat64,
    &tr_fstat64,
    &tr_lchown32,
    &tr_getuid32,
    &tr_getgid32,
    &tr_geteuid32,
    &tr_getegid32,
    &tr_setreuid32,
    &tr_setregid32,
    &tr_getgroups32,
    &tr_setgroups32,
    &tr_fchown32,
    &tr_setresuid32,
    &tr_getresuid32,
    &tr_setresgid32,
    &tr_getresgid32,
    &tr_chown32,
    &tr_setuid32,
    &tr_setgid32,
    &tr_setfsuid32,
    &tr_setfsgid32,
    &tr_pivot_root,
    &tr_mincore,
    &tr_madvise,
    &tr_madvise1,
    &tr_getdents64,
    &tr_fcntl64,
    &tr_unknown,
    &tr_gettid,
    &tr_readahead,
    &tr_setxattr,
    &tr_lsetxattr,
    &tr_fsetxattr,
    &tr_getxattr,
    &tr_lgetxattr,
    &tr_fgetxattr,
    &tr_listxattr,
    &tr_llistxattr,
    &tr_flistxattr,
    &tr_removexattr,
    &tr_lremovexattr,
    &tr_fremovexattr,
    &tr_tkill,
    &tr_sendfile64,
    &tr_futex,
    &tr_sched_setaffinity,
    &tr_sched_getaffinity,
    &tr_set_thread_area,
    &tr_get_thread_area,
    &tr_io_setup,
    &tr_io_destroy,
    &tr_io_getevents,
    &tr_io_submit,
    &tr_io_cancel,
    &tr_fadvise64,
    &tr_unknown,
    &tr_exit_group,
    &tr_lookup_dcookie,
    &tr_epoll_create,
    &tr_epoll_ctl,
    &tr_epoll_wait,
    &tr_remap_file_pages,
    &tr_set_tid_address,
    &tr_timer_create,
    &tr_timer_settime,
    &tr_timer_gettime,
    &tr_timer_getoverrun,
    &tr_timer_delete,
    &tr_clock_settime,
    &tr_clock_gettime,
    &tr_clock_getres,
    &tr_clock_nanosleep,
    &tr_statfs64,
    &tr_fstatfs64,
    &tr_tgkill,
    &tr_utimes,
    &tr_fadvise64_64,
    &tr_vserver,
    &tr_mbind,
    &tr_get_mempolicy,
    &tr_set_mempolicy,
    &tr_mq_open,
    &tr_mq_unlink,
    &tr_mq_timedsend,
    &tr_mq_timedreceive,
    &tr_mq_notify,
    &tr_mq_getsetattr,
    &tr_kexec_load,
    &tr_waitid,
    &tr_unknown,
    &tr_add_key,
    &tr_request_key,
    &tr_keyctl,
    &tr_ioprio_set,
    &tr_ioprio_get,
    &tr_inotify_init,
    &tr_inotify_add_watch,
    &tr_inotify_rm_watch,
    &tr_migrate_pages,
    &tr_openat,
    &tr_mkdirat,
    &tr_mknodat,
    &tr_fchownat,
    &tr_futimesat,
    &tr_fstatat64,
    &tr_unlinkat,
    &tr_renameat,
    &tr_linkat,
    &tr_symlinkat,
    &tr_readlinkat,
    &tr_fchmodat,
    &tr_faccessat,
    &tr_pselect6,
    &tr_ppoll,
    &tr_unshare,
    &tr_set_robust_list,
    &tr_get_robust_list,
    &tr_splice,
    &tr_sync_file_range,
    &tr_tee,
    &tr_vmsplice,
    &tr_move_pages,
    &tr_getcpu,
    &tr_epoll_pwait,
    &tr_utimensat,
    &tr_signalfd,
    &tr_timerfd_create,
    &tr_eventfd,
    &tr_fallocate,
    &tr_timerfd_settime,
    &tr_timerfd_gettime,
    &tr_signalfd4,
    &tr_eventfd2,
    &tr_epoll_create1,
    &tr_dup3,
    &tr_pipe2,
    &tr_inotify_init1,
    &tr_preadv,
    &tr_pwritev,
    &tr_rt_tgsigqueueinfo,
    &tr_perf_event_open,
    &tr_recvmsg
  };

static inline int		next_is_int_80(struct user_regs_struct * regs, pid_t pid)
{
  union char_disturbed	eip;

  eip._char = ptrace(PTRACE_PEEKDATA, pid, regs->eip, NULL);
  if ((eip._disturbed[0] == 0xcd && eip._disturbed[1] == 0x80)
      || (eip._disturbed[0] == 0x0f && eip._disturbed[1] == 0x34))
    return (1);
  else
    return (0);
}

static inline int	do_return(struct user_regs_struct * regs, pid_t pid, t_symbol_graph * graph)
{
  t_symbol_graph *	sym;

  if (regs->orig_eax >= 0 && regs->orig_eax <= NUM_SYSCALLS)
    syscalls[regs->orig_eax](regs, RETURN, pid, graph);
  else
    {
      sym = list_back(graph->sub_symbols);
      sprintf(&(sym->debug_info[strlen(sym->debug_info)]), " (?)");
    }
  return (0);
}

static inline int	do_syscall(struct user_regs_struct * regs, pid_t pid, t_symbol_graph * graph)
{
  t_symbol_graph *	sym;
  extern int		symbol_id;

  if (regs->eax >= 0 && regs->eax <= NUM_SYSCALLS)
    syscalls[regs->eax](regs, PARAM, pid, graph);
  else
    {
      sym = malloc(sizeof(*sym));
      sym->id = symbol_id++;
      sym->symbol_name = "???";
      sym->symbol_addr = 0x00000000;
      sym->symbol_type = SYSCALLS;
      sym->debug_info = strdup("Parameters (?)\nReturn (?)");
      sym->sub_symbols = EMPTY;
      list_push_back(&graph->sub_symbols, sym);
    }
  return (1);
}

int		syscalls_mgr(struct user_regs_struct * regs,
			     pid_t pid,
			     t_symbol_graph * graph)
{
  static int	has_ret = 0;

  (void)graph;
  if (has_ret)
    has_ret = do_return(regs, pid, graph);
  if (next_is_int_80(regs, pid))
    {
      has_ret = do_syscall(regs, pid, graph);
      return (1);
    }
  return (0);
}
