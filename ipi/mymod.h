#ifndef _UAPILINUX_MYMOD_H
#define _UAPILINUX_MYMOD_H

#include <linux/types.h>

#define MYMOD_MAGIC 0xa6

#define MYMOD_A _IO( MYMOD_MAGIC, 0 )
#define MYMOD_B _IO( MYMOD_MAGIC, 1 )

#endif /* _UAPILINUX_MYMOD_H */
