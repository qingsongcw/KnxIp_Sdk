/******************************************************************************
* 版权所有 (C)2013，**********有限公司。
*
* 文件名称：KnxIp_Msg.h
* 文件标识：无
* 内容摘要：knx ip message deal header file.
* 其他说明：
* 当前版本：V1.00
* 作    者：     
* 完成日期：2014年3月18日
*    
* 修改记录1：
*        修改日期：2014年3月18日
*        版 本 号：V1.00
*        修 改 人：     
*        修改内容：创建文件
******************************************************************************/


#ifndef _KNXIP_MSG_H_
#define _KNXIP_MSG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* saving space size for the key word of the buffer.
   KnxIP frame format is as below:
      ______________________________________________________________________________________________________________________________________________
     |                                      |                 |                     |               |                   |          |       |        |
     |sizeof(WORDPTR) for next frame address|1byte for Pool Id|2 byte payload length|payload address|1Byte message info.|socket No.|Ip&port|data... |
     |______________________________________|_________________|_____________________|_______________|___________________|__________|_______|________|
 */

/* reserved space in the KNX buffer for adding the KnxIp header.*/
#define TOTAL_KNX_BUFFER_HEADER_LEN  32         /* the lenght from the buffer header to the Knx subnet Msg header.from the next address to Mesage code. */


/* Service family */
#define KNX_IP_SVR_RSV               (0x01)       /* reserved.    */
#define KNX_IP_CORE_SERVICE          (0x02)       /* core service */
#define KNX_IP_MGM_SERVICE           (0x03)       /* mgm  service */
#define KNX_IP_TUNNEL_SERVICE        (0x04)       /* tunnelling service */
#define KNX_IP_ROUTE_SERVICE         (0x05)       /* routing service    */
#define KNX_IP_REMOTE_LOG            (0x06)       /* remote log service */
#define KNX_IP_REMOTE_CONFG_DIA      (0x07)       /* remote config service   */
#define KNX_IP_OBJ_SVR               (0x08)       /* obj server service      */
#define KNX_IP_SVR_MAX               (0x08)       /* Max. number of service. */


/* Definition about the protocol */
#define KNX_IP_VERSION_10            (0x10)   /* Identifier for KNXnet/IP protocol version 1.0  */
#define KNX_IP_HEADER_SIZE_10        (0x06)   /* Constant size of KNXnet/IP header as defined in protocol version 1.0 */

/* KNX IP header element's position. */
#define KNXIP_HEADER_LEN_POS                 0
#define KNXIP_HEADER_PRT_VER_POS             1
#define KNXIP_HEADER_SVR_POS                 2
#define KNXIP_HEADER_CMD_POS                 3
#define KNXIP_HEADER_LEN_H_POS               4
#define KNXIP_HEADER_LEN_L_POS               5

#define IP_ADDRESS_INFO_LEN                  6


/****************************************************
*   结构名：T_IP_ADDRESS_INFO
*   描述：  Ip的地址信息(address information)
*   参数：  BYTE aucIpAddInfo[IP_ADDRESS_INFO_LEN]:
                                 0-3:ip address,high->low
                                 4-5:port number,high->low
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE aucIpAddInfo[IP_ADDRESS_INFO_LEN];      /* 0-3:ip address,high->low;4-5:port number,high->low */
}T_IP_ADDRESS_INFO;

/*******************************************************************************************
* 函数名称：KNXIP_BOOL KnxIp_Svr_Rsv(BYTE *pucBuffer,BYTE ucTxPoolId)
* 功能描述：Knx Ip 缺省服务处理入口。
* 输入参数：BYTE *pucBuffer:input frame buffer.
            BYTE ucTxPoolId:pool id for transmit buffer.
* 输出参数：无
* 返 回 值：NULL.
* 其它说明：pucBuffer points to the header of the buffer.
* 修改日期        版本号     修改人          修改内容
* -----------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
*******************************************************************************************/
KNXIP_BOOL KnxIp_Svr_Rsv(BYTE *pucBuffer,BYTE ucTxPoolId);

/****************************************************************************************************
* 函数名称：KNXIP_BOOL KnxIp_Msg_Handler(BYTE *pucInBuffer,BYTE ucTxPoolId)
* 功能描述：Knx Ip message处理入口。
* 输入参数：BYTE *pucInBuffer:指向KNX IP报文的头部.
            BYTE ucTxPoolId  :transmit buffer的Pool ID.
* 输出参数：No.
* 返 回 值：BYTE* 返回response的buffer。调用者需要处理传入buffer的释放。
* 其它说明：pucBuffer指向buffer的管理头部。
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
KNXIP_BOOL KnxIp_Msg_Handler(BYTE *pucInBuffer,BYTE ucTxPoolId);


#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_MSG_H_ */



/* end of file. */






