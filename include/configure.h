


#ifndef _CONFIGURE_H_
#define _CONFIGURE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MCU_SIZE                             4
#ifdef TOTAL_BUFFER_SIZE
    #undef TOTAL_BUFFER_SIZE
#endif
#define MAX_KNX_APP_CMD_NUM                  128          /* max. number of application command */
#define TOTAL_BUFFER_SIZE                    131072       /* 128k */
#define KNX_IPV4_CTRL_ENDPOINT               (60080)      /* control point port number */
#define KNX_IPV4_DATA_ENDPOINT               (60081)      /* data point port number    */
#define KNX_IPV4_DATA_PORT_H                 (KNX_IPV4_DATA_ENDPOINT >> 8)
#define KNX_IPV4_DATA_PORT_L                 (KNX_IPV4_DATA_ENDPOINT & 0xFF)
#define KNX_IPV4_CTRL_PORT_H                 (KNX_IPV4_CTRL_ENDPOINT >> 8)
#define KNX_IPV4_CTRL_PORT_L                 (KNX_IPV4_CTRL_ENDPOINT & 0xff)  /* we should guarantee that Overflow will no happen when the low port No. adds 4. */
#define KNX_SYS_MUL_ADDR                      "224.0.23.12"
#define KNX_USER_MUL_ADDR                     "224.0.23.18"

#ifdef __cplusplus
}
#endif

#endif /* _CONFIGURE_H_ */



/* end of file. */

