#ifndef _UAPILINUX_MYMOD_H
#define _UAPILINUX_MYMOD_H

#include <linux/types.h>

#define MYMOD_MAGIC 0xa6

#define MYMOD_LOCK _IO( MYMOD_MAGIC, 0 )
#define MYMOD_UNLOCK _IO( MYMOD_MAGIC, 1 )
#define MYMOD_IPI_GOOD _IO( MYMOD_MAGIC, 2 )
#define MYMOD_IPI_BAD _IO( MYMOD_MAGIC, 3 )

#endif /* _UAPILINUX_MYMOD_H */
