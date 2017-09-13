/*
** utilities1.c for <FTrace> in /home/barrau_a//c_avancee/ftrace
** 
** Made by adrien barrau
** Login   <barrau_a@epitech.net>
** 
** Started on  Fri Jun 24 16:13:44 2011 adrien barrau
** Last update Fri Jul  1 10:49:59 2011 adrien barrau
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/user.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <errno.h>
#include "ftrace.h"

static t_errno	the_errors[]=
  {
    {E2BIG,           "E2BIG",           "Argument list too long"},
    {EACCES,          "EACCES",          "Permission denied"},
    {EADDRINUSE,      "EADDRINUSE",      "Address already in use"},
    {EADDRNOTAVAIL,   "EADDRNOTAVAIL",   "Address not available"},
    {EAFNOSUPPORT,    "EAFNOSUPPORT",    "Address family not supported"},
    {EAGAIN,          "EAGAIN",          "Resource temporarily unavailable"},
    {EALREADY,        "EALREADY",        "Connection already in progress"},
    {EBADE,           "EBADE",           "Invalid exchange"},
    {EBADF,           "EBADF",           "Bad file descriptor"},
    {EBADFD,          "EBADFD",          "File descriptor in bad state"},
    {EBADMSG,         "EBADMSG",         "Bad message"},
    {EBADR,           "EBADR",           "Invalid request descriptor"},
    {EBADRQC,         "EBADRQC",         "Invalid request code"},
    {EBADSLT,         "EBADSLT",         "Invalid slot"},
    {EBUSY,           "EBUSY",           "Device or resource busy"},
    {ECANCELED,       "ECANCELED",       "Operation canceled"},
    {ECHILD,          "ECHILD",          "No child processes"},
    {ECHRNG,          "ECHRNG",          "Channel number out of range"},
    {ECOMM,           "ECOMM",           "Communication error on send"},
    {ECONNABORTED,    "ECONNABORTED",    "Connection aborted"},
    {ECONNREFUSED,    "ECONNREFUSED",    "Connection refused"},
    {ECONNRESET,      "ECONNRESET",      "Connection reset"},
    {EDEADLK,         "EDEADLK",         "Resource deadlock avoided"},
    {EDEADLOCK,       "EDEADLOCK",       "Resource deadlock avoided"},
    {EDESTADDRREQ,    "EDESTADDRREQ",    "Destination address required"},
    {EDOM, "EDOM", "Mathematics argument out of domain of function"},
    {EDQUOT,          "EDQUOT",          "Disk quota exceeded"},
    {EEXIST,          "EEXIST",          "File exists"},
    {EFAULT,          "EFAULT",          "Bad address"},
    {EFBIG,           "EFBIG",           "File too large"},
    {EHOSTDOWN,       "EHOSTDOWN",       "Host is down"},
    {EHOSTUNREACH,    "EHOSTUNREACH",    "Host is unreachable"},
    {EIDRM,           "EIDRM",           "Identifier removed"},
    {EILSEQ,          "EILSEQ",          "Illegal byte sequence"},
    {EINPROGRESS,     "EINPROGRESS",     "Operation in progress"},
    {EINTR,           "EINTR",           "Interrupted function call"},
    {EINVAL,          "EINVAL",          "Invalid argument"},
    {EIO,             "EIO",             "Input/output error"},
    {EISCONN,         "EISCONN",         "Socket is connected"},
    {EISDIR,          "EISDIR",          "Is a directory"},
    {EISNAM,          "EISNAM",          "Is a named type file"},
    {EKEYEXPIRED,     "EKEYEXPIRED",     "Key has expired"},
    {EKEYREJECTED,    "EKEYREJECTED",    "Key was rejected by service"},
    {EKEYREVOKED,     "EKEYREVOKED",     "Key has been revoked"},
    {EL2HLT,          "EL2HLT",          "Level 2 halted"},
    {EL2NSYNC,        "EL2NSYNC",        "Level 2 not synchronized"},
    {EL3HLT,          "EL3HLT",          "Level 3 halted"},
    {EL3RST,          "EL3RST",          "Level 3 halted"},
    {ELIBACC,         "ELIBACC", "Cannot access a needed shared library"},
    {ELIBBAD,         "ELIBBAD", "Accessing a corrupted shared library"},
    {ELIBMAX, "ELIBMAX", "Attempting to link in too many shared libraries"},
    {ELIBSCN,         "ELIBSCN",         "lib section in a.out corrupted"},
    {ELIBEXEC, "ELIBEXEC", "Cannot exec a shared library directly"},
    {ELOOP,           "ELOOP",           "Too many levels of symbolic links"},
    {EMEDIUMTYPE,     "EMEDIUMTYPE",     "Wrong medium type"},
    {EMFILE,          "EMFILE",          "Too many open files"},
    {EMLINK,          "EMLINK",          "Too many links"},
    {EMSGSIZE,        "EMSGSIZE",        "Message too long"},
    {EMULTIHOP,       "EMULTIHOP",       "Multihop attempted"},
    {ENAMETOOLONG,    "ENAMETOOLONG",    "Filename too long"},
    {ENETDOWN,        "ENETDOWN",        "Network is down"},
    {ENETRESET,       "ENETRESET",       "Connection aborted by network"},
    {ENETUNREACH,     "ENETUNREACH",     "Network unreachable"},
    {ENFILE,          "ENFILE",          "Too many open files in system"},
    {ENOBUFS,         "ENOBUFS",         "No buffer space available"},
 {ENODATA, "ENODATA", "No message is available on the STREAM head read queue"},
    {ENODEV,          "ENODEV",          "No such device"},
    {ENOENT,          "ENOENT",          "No such file or directory"},
    {ENOEXEC,         "ENOEXEC",         "Exec format error"},
    {ENOKEY,          "ENOKEY",          "Required key not available"},
    {ENOLCK,          "ENOLCK",          "No locks available"},
    {ENOLINK,         "ENOLINK",         "Link has been severed"},
    {ENOMEDIUM,       "ENOMEDIUM",       "No medium found"},
    {ENOMEM,          "ENOMEM",          "Not enough space"},
    {ENOMSG,          "ENOMSG",          "No message of the desired type"},
    {ENONET,          "ENONET",          "Machine is not on the network"},
    {ENOPKG,          "ENOPKG",          "Package not installed"},
    {ENOPROTOOPT,     "ENOPROTOOPT",     "Protocol not available"},
    {ENOSPC,          "ENOSPC",          "No space left on device"},
    {ENOSR,           "ENOSR",           "No STREAM resources"},
    {ENOSTR,          "ENOSTR",          "Not a STREAM"},
    {ENOSYS,          "ENOSYS",          "Function not implemented"},
    {ENOTBLK,         "ENOTBLK",         "Block device required"},
    {ENOTCONN,        "ENOTCONN",        "The socket is not connected"},
    {ENOTDIR,         "ENOTDIR",         "Not a directory"},
    {ENOTEMPTY,       "ENOTEMPTY",       "Directory not empty"},
    {ENOTSOCK,        "ENOTSOCK",        "Not a socket"},
    {ENOTSUP,         "ENOTSUP",         "Operation not supported"},
    {ENOTTY, "ENOTTY", "Inappropriate I/O control operation"},
    {ENOTUNIQ,        "ENOTUNIQ",        "Name not unique on network"},
    {ENXIO,           "ENXIO",           "No such device or address"},
    {EOPNOTSUPP,      "EOPNOTSUPP",      "Operation not supported on socket"},
    {EOVERFLOW, "EOVERFLOW", "Value too large to be stored in data type"},
    {EPERM,           "EPERM",           "Operation not permitted"},
    {EPFNOSUPPORT,    "EPFNOSUPPORT",    "Protocol family not supported"},
    {EPIPE,           "EPIPE",           "Broken pipe"},
    {EPROTO,          "EPROTO",          "Protocol error"},
    {EPROTONOSUPPORT, "EPROTONOSUPPORT", "Protocol not supported"},
    {EPROTOTYPE,      "EPROTOTYPE",      "Protocol wrong type for socket"},
    {ERANGE,          "ERANGE",          "Result too large"},
    {EREMCHG,         "EREMCHG",         "Remote address changed"},
    {EREMOTE,         "EREMOTE",         "Object is remote"},
    {EREMOTEIO,       "EREMOTEIO",       "Remote I/O error"},
    {ERESTART, "ERESTART", "Interrupted system call should be restarted"},
    {EROFS,           "EROFS",           "Read-only file system"},
    {ESHUTDOWN, "ESHUTDOWN", "Cannot send after transport endpoint shutdown"},
    {ESPIPE,          "ESPIPE",          "Invalid seek"},
    {ESOCKTNOSUPPORT, "ESOCKTNOSUPPORT", "Socket type not supported"},
    {ESRCH,           "ESRCH",           "No such process"},
    {ESTALE,          "ESTALE",          "Stale file handle"},
    {ESTRPIPE,        "ESTRPIPE",        "Streams pipe error"},
    {ETIME,           "ETIME",           "Timer expired"},
    {ETIMEDOUT,       "ETIMEDOUT",       "Connection timed out"},
    {ETXTBSY,         "ETXTBSY",         "Text file busy"},
    {EUCLEAN,         "EUCLEAN",         "Structure needs cleaning"},
    {EUNATCH,         "EUNATCH",         "Protocol driver not attached"},
    {EUSERS,          "EUSERS",          "Too many users"},
    {EWOULDBLOCK,     "EWOULDBLOCK",     "Operation would block"},
    {EXDEV,           "EXDEV",           "Improper link"},
    {EXFULL,          "EXFULL",          "Exchange full"}
  };

char *		p_error(int reg, pid_t pid __attribute__((unused)))
{
  static char	buffer[MAX_SYSCALLS_CHAR];
  int		c = 0;
  int		num_err = reg * -1;

  while (c < NB_ERRNO)
    {
      if (num_err == the_errors[c].num)
	{
	  sprintf(buffer, " (-1 %s (%s))",
		  the_errors[c].name,
		  the_errors[c].desc);
	  break;
	}
      c++;
    }
  return (buffer);
}

static char *	spec_chars[]=
  {
    "\\a",
    "\\b",
    "\\t",
    "\\n",
    "\\v",
    "\\f",
    "\\r"
  };

char * p_string(int reg, pid_t pid)
{
  static char		buffer[STRSIZE * 4 + 6];
  int			c = 0;
  union char_disturbed	the_char;
  int			nchars = 0;

  nchars = sprintf(&(buffer[nchars]), "\"");
  while (c < STRSIZE)
    {
      if ((the_char._char = ptrace(PTRACE_PEEKDATA, pid, (reg + c), NULL))
	  == (unsigned int)-1
	  || the_char._disturbed[0] == 0)
	break;
      if (the_char._disturbed[0] >= 32 && the_char._disturbed[0] <= 126)
	nchars += sprintf(&(buffer[nchars]), "%c", the_char._disturbed[0]);
      else if (the_char._disturbed[0] >= 7 && the_char._disturbed[0] <= 13)
	nchars += sprintf(&(buffer[nchars]), "%s",
			  spec_chars[the_char._disturbed[0] - 7]);
      else
	nchars += sprintf(&(buffer[nchars]), "\\%o", the_char._disturbed[0]);
      c++;
    }
  nchars += sprintf(&(buffer[nchars]), "\"");
  if (c == 32)
    nchars += sprintf(&(buffer[nchars]), "...");
  return (buffer);
}

static t_open_flags	op_flags[]=
  {
    {O_RDONLY,    "O_RDONLY",    ""},
    {O_WRONLY,    "O_WRONLY",    ""},
    {O_RDWR,      "O_RDWR",      ""},
    {O_APPEND,    "O_APPEND",    ""},
    {O_ASYNC,     "O_ASYNC",     ""},
    {O_CLOEXEC,   "O_CLOEXEC",   ""},
    {O_CREAT,     "O_CREAT",     ""},
    {O_DIRECTORY, "O_DIRECTORY", ""},
    {O_EXCL,      "O_EXCL",      ""},
    {O_NOCTTY,    "O_NOCTTY",    ""},
    {O_NOFOLLOW,  "O_NOFOLLOW",  ""},
    {O_NONBLOCK,  "O_NONBLOCK",  ""},
    {O_NDELAY,    "O_NDELAY",    ""},
    {O_SYNC,      "O_SYNC",      ""},
    {O_TRUNC,     "O_TRUNC",     ""}
  };

char *		p_open_flag(int reg, pid_t pid)
{
  static char	buffer[NB_OPEN_FLAG * 15];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_OPEN_FLAG)
    {
      if ((reg & op_flags[c].num) == op_flags[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", op_flags[c].name);
	}
      c++;
    }
  return (buffer);
}

char * p_open_mode(int reg, pid_t pid)
{
  static char	buffer[NB_OPEN_MODE * 15];

  (void)pid;
  if (reg)
    sprintf(buffer, "%#3o", reg);
  else
    sprintf(buffer, "0");
  return (buffer);
}

static t_waitpid_option	wa_opt[]=
  {
    {WNOHANG, "WNOHANG", ""},
    {WSTOPPED, "WSTOPPED", ""},
    {WCONTINUED, "WCONTINUED", ""}
  };

char *	p_waitpid_option(int reg, pid_t pid)
{
  static char	buffer[NB_WAIT_OPT * 15];
  int		c = 0;
  int		nchars = 0;

  (void)pid;
  while (c < NB_WAIT_OPT)
    {
      if ((reg & wa_opt[c].num) == wa_opt[c].num)
	{
	  if (nchars)
	    nchars += sprintf(&(buffer[nchars]), "|");
	  nchars += sprintf(&(buffer[nchars]), "%s", wa_opt[c].name);
	}
      c++;
    }
  if (!nchars)
    nchars += sprintf(&(buffer[nchars]), "0");
  return (buffer);
}
