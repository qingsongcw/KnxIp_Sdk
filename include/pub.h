/******************************************************************************
* 版权所有 (C)2013，**********有限公司。
*
* 文件名称：pub.h
* 文件标识：无
* 内容摘要：本文件为嵌入式系统软件公共定义。
* 其他说明：
* 当前版本：V1.00
* 作    者：      
* 完成日期：2013年7月24日
*    
* 修改记录1：
*        修改日期：2013年7月24日
*        版 本 号：V1.00
*        修 改 人：      
*        修改内容：新增公共定义.
******************************************************************************/


#ifndef _PUB_H_
#define _PUB_H_

#ifdef __cplusplus
extern "C" {
#endif

/* socket NO. define. */
#define COM_MULTCAST_SCK_NO                    0    /* sokcet for sytem multicast.224.0.23.12 */
#define DATA_POINT_SCK_NO                      1    /* socket for data point.            */
#define CTRL_POINT_SCK0_NO                     2    /* socket for port0's control point. */
#define COM_MULTCAST_SCK_USER_NO               3    /* socket for user mul-address.user defined mul-address. */
#define ERROR_SCK_NO                           0xff /* wrong socket No. */

#define GROUP_DATA_INDICATION        (0x54)
#define GROUP_DATA_READ              (0x55)
#define GROUP_DATA_WRITE             (0x56)
/* eth 2 knx's core service(service code 0x02) command */
#define SEARCH_REQUEST               (0x01)
#define SEARCH_RESPONSE              (0x02)
#define DESCRIPTION_REQUEST          (0x03)
#define DESCRIPTION_RESPONSE         (0x04)
#define CONNECT_REQUEST              (0x05)
#define CONNECT_RESPONSE             (0x06)
#define CONNECTIONSTATE_REQUEST      (0x07)
#define CONNECTIONSTATE_RESPONSE     (0x08)
#define DISCONNECT_REQUEST           (0x09)
#define DISCONNECT_RESPONSE          (0x0A)
#define MAX_CORE_SVR_COMMAND_NUM     (0x0A)

/* service command(service code 0x03). */
#define DEVICE_CONFIGURATION_REQUEST (0x10)
#define DEVICE_CONFIGURATION_ACK     (0x11)

/* service (service code 0x04) command. */
#define TUNNELING_REQUEST            (0x20)
#define TUNNELING_ACK                (0x21)

/* service (service code 0x05) command. */
#define ROUTING_INDICATION           (0x30)
#define ROUTING_LOST_MESSAGE         (0x31)
#define ROUTING_BUSY                 (0x32)

#define REMOTE_DIAGNOSTIC_REQUEST    (0x40)
#define REMOTE_DIAGNOSTIC_RESPONSE   (0x41)
#define REMOTE_BASIC_CONFIG_REQUEST  (0x42)
#define REMOTE_RESET_REQUEST         (0x43)

/* connect type */
#define KNX_IP_CONNECT_NONE          (0x00)
#define DEVICE_MGMT_CONNECTION       (0x03)
#define TUNNEL_CONNECTION            (0x04)
#define REMLOG_CONNECTION            (0x06)
#define REMCONF_CONNECTION           (0x07)
#define OBJSVR_CONNECTION            (0x08)
#define KNX_IP_CONNECT_ALL           (0xff)

/* return code define. */
#define E_CMD_SUCCESSFUL                      0x00        /* command successfully.          */
#define E_COMMAND_FAILED                      0x01        /* command failed.                */
#define E_CONNECT_ACTIVE                      0x02        /* there is an active connection. */
#define E_CONNECT_ID_WRONG                    0x03        /* connection ID wrong.           */
#define E_COMMAND_PARA                        0x04        /* parameter is wrong.            */


/************************** 通用返回码定义 ********************************/
#define SW_OK               ((WORD32)0x00000000)  /* 操作成功 */
#define SW_ERR              ((WORD32)0xffffffff)  /* 操作失败 */
#define SW_INVALID_PARA     ((WORD32)0xfffffffe)  /* 非法参数 */
#define SW_NOT_SUPPORT      ((WORD32)0xfffffffd)  /* 非法操作 */

/******************************* 通用数据结构定义 ***************************/





#ifdef __cplusplus
}
#endif

#endif /* _COMMON_H_ */

/* End-of-file */


