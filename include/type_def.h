

#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif



/* definitions for tcp/ip */
typedef unsigned int             WORD32;
typedef signed   int             SWORD32;
typedef char                     CHAR;
typedef unsigned char            BYTE;
typedef signed   char            SBYTE;
typedef unsigned short           WORD16;
typedef signed   short           SWORD16;
//typedef unsigned long long int   WORD64;
//typedef signed   long long int   SWORD64;
typedef signed   long int        SWORDPTR; 
typedef unsigned long int        WORDPTR;    /* 32位系统中,长度为4,64位系统中,长度为8 */
/* define the type of vector. */
typedef void (*vector_entry)(void);

#define VOID                     void
typedef SBYTE                    err_t;

#ifndef NULL
    #define NULL ((void *)0)
#endif
#define FALSE                   0            /* Used for boolean */
#define TRUE                    1            /* Used for boolean */

#ifndef TCPIP_DEF
    typedef BYTE    u8_t;
    typedef WORD16  u16_t;
    typedef WORD32  u32_t;
    typedef SBYTE   s8_t;
    typedef SWORD16 s16_t;
#endif /* TCPIP_DEF */

/* definitions for KNX */
// General type defines
typedef unsigned char                KNXIP_BOOL;        //  1 Bit variable





#ifndef KNX_UNUSED_ARG
    #define KNX_UNUSED_ARG(x) (void)x
#endif


#ifdef __cplusplus
}
#endif

#endif /* _TYPE_DEF_H_ */




