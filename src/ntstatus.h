#ifndef EPOLL_NTSTATUS_H_
#define EPOLL_NTSTATUS_H_

#include "win.h"

#ifndef _NTDEF_
typedef LONG NTSTATUS;
typedef NTSTATUS* PNTSTATUS;
#endif

#ifndef NT_SUCCESS
#define NT_SUCCESS(status) (((NTSTATUS)(status)) >= 0)
#endif

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS ((NTSTATUS) 0x00000000L)
#endif

#ifndef STATUS_WAIT_0
#define STATUS_WAIT_0 ((NTSTATUS) 0x00000000L)
#endif

#ifndef STATUS_WAIT_1
#define STATUS_WAIT_1 ((NTSTATUS) 0x00000001L)
#endif

#ifndef STATUS_WAIT_2
#define STATUS_WAIT_2 ((NTSTATUS) 0x00000002L)
#endif

#ifndef STATUS_WAIT_3
#define STATUS_WAIT_3 ((NTSTATUS) 0x00000003L)
#endif

#ifndef STATUS_WAIT_63
#define STATUS_WAIT_63 ((NTSTATUS) 0x0000003FL)
#endif

#ifndef STATUS_ABANDONED
#define STATUS_ABANDONED ((NTSTATUS) 0x00000080L)
#endif

#ifndef STATUS_ABANDONED_WAIT_0
#define STATUS_ABANDONED_WAIT_0 ((NTSTATUS) 0x00000080L)
#endif

#ifndef STATUS_ABANDONED_WAIT_63
#define STATUS_ABANDONED_WAIT_63 ((NTSTATUS) 0x000000BFL)
#endif

#ifndef STATUS_USER_APC
#define STATUS_USER_APC ((NTSTATUS) 0x000000C0L)
#endif

#ifndef STATUS_KERNEL_APC
#define STATUS_KERNEL_APC ((NTSTATUS) 0x00000100L)
#endif

#ifndef STATUS_ALERTED
#define STATUS_ALERTED ((NTSTATUS) 0x00000101L)
#endif

#ifndef STATUS_TIMEOUT
#define STATUS_TIMEOUT ((NTSTATUS) 0x00000102L)
#endif

#ifndef STATUS_PENDING
#define STATUS_PENDING ((NTSTATUS) 0x00000103L)
#endif

#ifndef STATUS_SEVERITY_SUCCESS
#define STATUS_SEVERITY_SUCCESS 0x0
#endif

#ifndef STATUS_SEVERITY_INFORMATIONAL
#define STATUS_SEVERITY_INFORMATIONAL 0x1
#endif

#ifndef STATUS_SEVERITY_WARNING
#define STATUS_SEVERITY_WARNING 0x2
#endif

#ifndef STATUS_SEVERITY_ERROR
#define STATUS_SEVERITY_ERROR 0x3
#endif

#ifndef FACILITY_NTWIN32
#define FACILITY_NTWIN32 0x7
#endif

/* This is not the NTSTATUS_FROM_WIN32 that the DDK provides, because the
 * DDK got it wrong!
 */
#ifdef NTSTATUS_FROM_WIN32
#undef NTSTATUS_FROM_WIN32
#endif
#define NTSTATUS_FROM_WIN32(error)                                      \
  ((NTSTATUS)(error) <= 0                                               \
       ? ((NTSTATUS)(error))                                            \
       : ((NTSTATUS)(((error) &0x0000FFFF) | (FACILITY_NTWIN32 << 16) | \
                     ERROR_SEVERITY_WARNING)))

#endif /* EPOLL_NTSTATUS_H_ */
