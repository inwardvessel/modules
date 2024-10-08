#ifndef _UAPILINUX_MYMOD_H
#define _UAPILINUX_MYMOD_H

#include <linux/types.h>

#define MYMOD_MAGIC 0xa6

#define MYMOD_MUTEX_LOCK _IO( MYMOD_MAGIC, 0 )
#define MYMOD_MUTEX_UNLOCK _IO( MYMOD_MAGIC, 1 )
#define MYMOD_SPIN_LOCK _IO( MYMOD_MAGIC, 2 )
#define MYMOD_SPIN_UNLOCK _IO( MYMOD_MAGIC, 3 )
#define MYMOD_CALLBACK_GOOD _IO( MYMOD_MAGIC, 4 )
#define MYMOD_CALLBACK_BAD_BLOCKING _IO( MYMOD_MAGIC, 5 )
#define MYMOD_CALLBACK_BAD_NONBLOCKING _IO( MYMOD_MAGIC, 6 )

#endif /* _UAPILINUX_MYMOD_H */
