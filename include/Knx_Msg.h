


#ifndef _KNX_MSG_H_
#define _KNX_MSG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define KNX_MDEV_MAX_CUNT              4          /* KNX main side device's number.  */
#define KNXIP_MAX_INTERFACE_NUM        15         /* max. number of interfaces connecting to this client. */

/* device information of buffer. Bit0-3:the source device flag&No.Bit4-7:the destination device flag&No. */
#define KNX_SRC_SIDE_MASK              0x08       /* the mask of the source device in the buffer header. */
#define KNX_SRC_SLAV_DEV               0x00       /* Source:second side device. */
#define KNX_SRC_MAIN_DEV               0x08       /* Source:main side device.   */
#define KNX_DEST_SIDE_MASK             0x80       /* the mask of the destination device in the buffer header. */
#define KNX_DEST_SLAV_DEV              0x00       /* Destination:seconde side device. */
#define KNX_DEST_MAIN_DEV              0x80       /* Destination:main side device.    */
#define KNX_SRC_DEV_NO_MASK            0x07       /* the mask for getting the source device's No.      */
#define KNX_DEST_DEV_NO_MASK           0x70       /* the mask for getting the destination device's No. */
#define KNX_SRC_DEVNO_CLR              0xF8       /* clear the source device No.      */
#define KNX_DEST_DEVNO_CLR             0x8F       /* clear the destination device No. */

/* message information definition. */
#define KNX_MSG_TYPE_MASK             0xC0       /* Mask for msg layer type.bit6-7:layer type.*/
#define KNX_MSG_PHY_LAYER              0x00       /* message for physical layer.  */
#define KNX_MSG_LINK_LAYER             0x40       /* message for link layer.      */
#define KNX_MSG_ROUT_LAYER             0x80       /* message for rout layer.      */
#define KNX_MSG_MGM_LAYER              0xC0       /* message for Mgm layer.       */
#define KNX_MSG_CNT_ID_MASK            0x3F       /* bit4-5:PortNo,bit0-3:connect channel No. */

#define GET_BUFFER_PAYLOAD(pucBuffer)             ((T_KNX_BUFFER_HEADER*)pucBuffer)->pucPayload
#define GET_BUFFER_LENGTH(pucBuffer)              ((T_KNX_BUFFER_HEADER*)pucBuffer)->wLength
#define GET_BUFFER_MSG_INFO(pucBuffer)            ((T_KNX_BUFFER_HEADER*)pucBuffer)->ucMessInfo
#define GET_BUFFER_DEV_NO(pucBuffer)              ((T_KNX_BUFFER_HEADER*)pucBuffer)->ucDevNo
#define GET_BUFFER_ADD_DATA_POINT(pucBuffer)      ((T_KNX_BUFFER_HEADER*)pucBuffer)->aucAddData
#define GET_BUFFER_POOL_ID(pucBuffer)             ((T_BUFFER_HEADER*)pucBuffer)->ucPoolId
#define GET_BUFFER_NEXT(pucBuffer)                ((T_BUFFER_HEADER*)pucBuffer)->pucNext
#define HI_BYTE(wData)                            ((BYTE)(((WORD16)wData >> 8) & 0x00FF))
#define LOW_BYTE(wData)                           ((BYTE)((WORD16)wData & 0x00FF))


#define KNX_MSG_BUFFER_SIZE            128        /* KNX message's buffer size. */
#define NETIP_BUFFER_SIZE              592        /* buffer size for net ip. we make it align to 8.   */

#define TOTAL_KNX_BUFFER_HEADER_LEN  32         /* the lenght from the buffer header to the Knx subnet Msg header.from the next address to Mesage code. */

#define KNX_BUFFER_FOR_KNX           0   /* buffer used for KNX frame dealing.    */
#define KNX_BUFFER_FOR_IP            1   /* buffer used for KNX IP frame dealing. */

/****************************************************
*   结构名：T_IP_DEV_REG
*   描述：  register ip device to KnxIp link layer.
*   参数：  
            BYTE ucSckNo                                                    socket's No,COM_MULTCAST_SCK_NO ~ COM_MULTCAST_SCK_USER_NO.    
            WORD16 wRxBufferNum;                                            buffer number for receiveing.
            WORD16 wTxBufferNum;                                            buffer number for sending.
            WORD16 wBufferSize;                                             every buffer size in byte.
            WORD16 (*pfReceive)(BYTE ucDevNo,BYTE *pucBuffer);              socket receive function,return data length,0-no data.
                BYTE ucDevNo    : socket No,start from 0.
                BYTE *pucBuffer : received data buffer for data saving.
                     *pucBuffer - 6 : saving the source device's IP address[0];
                     *pucBuffer - 5 : saving the source device's IP address[1];
                     *pucBuffer - 4 : saving the source device's IP address[2];
                     *pucBuffer - 3 : saving the source device's IP address[3];
                     *pucBuffer - 2 : saving the source device's port No[0];
                     *pucBuffer - 1 : saving the source device's port No[1];
            WORD16 (*pfSend)(BYTE ucDevNo,BYTE *pucBuffer,WORD16 wLength);  socket send function,return sent data length,0-send failed.
                BYTE ucDevNo    : socket No,start from 0.
                BYTE *pucBuffer : sent data buffer pointer.
                     *pucBuffer - 6 : saving the destination device's IP address[0];
                     *pucBuffer - 5 : saving the destination device's IP address[1];
                     *pucBuffer - 4 : saving the destination device's IP address[2];
                     *pucBuffer - 3 : saving the destination device's IP address[3];
                     *pucBuffer - 2 : saving the destination device's port No[0];
                     *pucBuffer - 1 : saving the destination device's port No[1];
                WORD16 wLength  : sent data length as byte.
*   作者: 
*   其他说明:
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE ucSckNo;                                                 /* socket No,COM_MULTCAST_SCK_NO ~ COM_MULTCAST_SCK_USER_NO. */
    WORD16 wRxBufferNum;                                          /* buffer number for receiveing. */
    WORD16 wTxBufferNum;                                          /* buffer number for sending.    */
    WORD16 wBufferSize;                                           /* every buffer size in byte.    */
    WORD16 (*pfReceive)(BYTE ucDevNo,BYTE *pucBuffer);            /* device receive function,return data length,0-no data.       */
    WORD16 (*pfSend)(BYTE ucDevNo,BYTE *pucBuffer,WORD16 wLength);/* device send function,return sent data length,0-send failed. */
}T_IP_DEV_REG;

/****************************************************
*   结构名：T_KNX_DEV
*   描述：  KNX message device parameter。
*   参数：  
            BYTE ucDevNo           device's physical No.    
            BYTE ucPoolId          device's pool id.        
            BYTE *puInBuffer       device's input buffer.   
            BYTE *puOutBuffer      device's output buffer.  
            WORD16 (*pfReceive)(BYTE ucDevNo,BYTE *pucBuffer);              socket receive function,return data length,0-no data.
                BYTE ucDevNo    : socket No,start from 0.
                BYTE *pucBuffer : received data buffer for data saving.
                     *pucBuffer - 6 : saving the source device's IP address[0];
                     *pucBuffer - 5 : saving the source device's IP address[1];
                     *pucBuffer - 4 : saving the source device's IP address[2];
                     *pucBuffer - 3 : saving the source device's IP address[3];
                     *pucBuffer - 2 : saving the source device's port No[0];
                     *pucBuffer - 1 : saving the source device's port No[1];
            WORD16 (*pfSend)(BYTE ucDevNo,BYTE *pucBuffer,WORD16 wLength);  socket send function,return sent data length,0-send failed.
                BYTE ucDevNo    : socket No,start from 0.
                BYTE *pucBuffer : sent data buffer pointer.
                     *pucBuffer - 6 : saving the destination device's IP address[0];
                     *pucBuffer - 5 : saving the destination device's IP address[1];
                     *pucBuffer - 4 : saving the destination device's IP address[2];
                     *pucBuffer - 3 : saving the destination device's IP address[3];
                     *pucBuffer - 2 : saving the destination device's port No[0];
                     *pucBuffer - 1 : saving the destination device's port No[1];
                WORD16 wLength  : sent data length as byte.
*   作者：       
*   修改记录:
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE ucDevNo;         /* device's physical No.   */
    BYTE ucPoolId;        /* device's rx pool id.    */
    BYTE *pucInBuffer;    /* device's input buffer.  */
    BYTE *pucOutBuffer;   /* device's output buffer. */
    WORD16 (*pfReceive)(BYTE ucDevNo,BYTE *pucBuffer);            /* device receive function. */
    WORD16 (*pfSend)(BYTE ucDevNo,BYTE *pucBuffer,WORD16 wLength);/* device send function.    */
}T_KNX_DEV;

/****************************************************
*   结构名：T_KNX_MSG_SRC
*   描述：  the message source struct。
*   参数：  
            BYTE ucTxPoolId     : sending buffer's pool ID.
            BYTE *pucTxBuffer   : sending buffer's chain.  
            T_KNX_DEV *ptKnxDev : relative KNX device.     
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE ucTxPoolId;     /* sending buffer's pool ID. */
    T_KNX_DEV *ptKnxDev; /* relative KNX device.      */
}T_KNX_MSG_SRC;

/****************************************************
*   结构名：T_INTERFACE_PARA
*   描述：  the parameter of the interface.
*   参数：  见下面结构定义和注释；
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE aucIpAdd[4];                      /* IP address of the interface.                     */
    BYTE aucCtrlPort[2];                   /* control port of the interface.                   */
    BYTE ucMediaType;                      /* media type,02h-TP1,20h-KnxIp.                    */
    BYTE ucProgSts;                        /* program status.0-not in programing,1-programing. */
    BYTE aucPhyAdd[2];                     /* hpysical address,[0]-High,[1]-Low.               */
    BYTE aucInstalId[2];                   /* install ID.[0]-High,[1]-Low                      */
    BYTE aucSerialNo[6];                   /* serial number.                                   */
    BYTE aucDevMulAdd[4];                  /* multicast address,0-192,1-168,2-10,3-118.        */
    BYTE aucDevMacAdd[6];                  /* MAC address,0-the first byte.                    */
    BYTE aucDevName[30];                   /* device name.                                     */
}T_INTERFACE_PARA;

/****************************************************
*   结构名：T_INTERFACE_INFO
*   描述：  the information of getting the interface.
*   参数：  见下面结构定义和注释；
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE ucInterfaceNum;                                            /* the number of interfaces.      */
    T_INTERFACE_PARA tInterfacePara[KNXIP_MAX_INTERFACE_NUM];       /* parameters of every interface. */
}T_INTERFACE_INFO;

/*****************************************************************************************************
*   结构名：T_KNX_APP_CMD
*   描述：  the application send command to KNX-IP core.
*   参数：  
            BYTE ucCmd:                   application command.
                 GROUP_DATA_READ
                 GROUP_DATA_WRITE
                 SEARCH_REQUEST
                 CONNECT_REQUEST
                 DISCONNECT_REQUEST
            BYTE aucDestiGrpAddr[2]:      destination group address.
                 if ucCmd == GROUP_DATA_READ or GROUP_DATA_WRITE then
                    aucDestiGrpAddr[0..1] = destination group address.
                    aucDestGrpAddr[0] is the high part of gropu address.
                 if end.
            BYTE ucLength:                Grp.Obj data length in byte.it should be according to the group
                                          object format.
               Grp.Obj data type   ucLength
                       1bit     -    1byte
                       2bit     -    1byte
                       3bit     -    1byte
                       4bit     -    1byte
                       5bit     -    1byte
                       6bit     -    1byte
                       7bit     -    2bytes
                       1byte    -    2bytes
                       2byte    -    3bytes
                       3byte    -    4bytes
                       4byte    -    5bytes
                       6byte    -    7bytes
                       8byte    -    9bytes
                       10byte   -    11bytes
                       14byte   -    15bytes
            BYTE aucData[16]:             command's data.
                 if ucCmd == CONNECT_REQUEST then
                    aucData[0] = connection type,value is as below:
                                 TUNNEL_CONNECTION
                    aucData[1] = destination device ip address[0].
                    aucData[2] = destination device ip address[1].
                    aucData[3] = destination device ip address[2].
                    aucData[4] = destination device ip address[3].
                    aucData[5] = destination device ip port[0].
                    aucData[6] = destination device ip port[1].
                 else if ucCmd == GROUP_DATA_WRITE
                    aucData[0...15]=group object's data(according to the format of the group object).
                 if end.
*   作者：
*   修改记录：
*   2013-7-24         新增结构；
******************************************************************************************************/
typedef struct
{
    BYTE ucCmd;                  /* application command.       */
    BYTE aucDestiGrpAddr[2];     /* destination group address. */
    BYTE ucLength;               /* data length.               */
    BYTE aucData[16];            /* command's data.            */
}T_KNX_APP_CMD;

/****************************************************
*   结构名：T_KNX_APP_LIST
*   描述：  application command list sturct.
*   参数：  see the below structure define.
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE ucCmdIn;                                       /* index for command input.     */
    BYTE ucCmdInEnd;                                    /* index for command list tail. */
    BYTE ucCmdOut;                                      /* index for command output.    */
    T_KNX_APP_CMD atAppCmdList[MAX_KNX_APP_CMD_NUM];
}T_KNX_APP_LIST;

/*******************************************************************************************************
*   结构名：T_KNX_CORE_EVENT
*   描述：  KNX链接返回事件数据,用于返回命令结果。
*   参数：  BYTE ucCmd:command ID;
                           GROUP_DATA_INDICATION    : receiving a group address data.
                           SEARCH_REQUEST           : return the result of searching request.
                           CONNECT_REQUEST          : return the status of connection request.
                           DISCONNECT_REQUEST       : return the status of disconnection request.
            BYTE ucCnectSt:返回的链接状态，取值如下:
                           if(ucCmd == GROUP_DATA_INDICATION)
                           {
                               ucCnectSt will be:
                                   ROUTING_INDICATION : data is coming from a routing message.
                                   TUNNELING_REQUEST  : data is coming fram a tunnelling message.
                           }
                           else
                           {
                               E_CMD_SUCCESSFUL:successful.
                               E_COMMAND_FAILED:failed.
                           }
            BYTE ucTxSeq : send sequence. 
            BYTE ucRxSeq : receive equence. 
            BYTE ucLength: data length in aucData array.
            BYTE aucData[16]   : data buffer for saving data. 
            BYTE aucDestAddr[2]: destination address,such as group address.
            BYTE aucSrcAddr[2] : source device's address.
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
*******************************************************************************************************/
typedef struct
{
    BYTE ucCmd;         /* command result successful. */
    BYTE ucCmdSt;       /* command result.            */
    BYTE ucTxSeq;       /* send frame sequence.       */
    BYTE ucRxSeq;       /* receive frame sequence.    */
    BYTE ucLength;      /* data length in byte.       */
    BYTE aucData[16];   /* data buffer for saving.    */
    BYTE aucDestAddr[2];/* destination address,such as group address. */
    BYTE aucSrcAddr[2]; /* source device's address.   */
}T_KNX_CORE_EVENT;

/****************************************************
*   结构名：T_KNX_IP_INIT_PARA
*   描述：  Knx Ip初始化参数
*   参数：  见下面结构定义和注释；
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE aucIp[4];                                         /* ip address,high->low           */
    BYTE aucSysMulIp[4];                                   /* system multicast ip address.   */
    BYTE aucInstallMulIp[4];                               /* install multicast ip address.  */
    BYTE aucInstallMulPort[2];                             /* install multicast port.        */
    BYTE aucCtrlPortNo[2];                                 /* control point no.              */
    BYTE aucDataPortNo[2];                                 /* data point no.                 */
    WORD32 (*pfAppCallback)(T_KNX_CORE_EVENT *ptEvent);    /* App call back .                */
    WORD32 (*pfGetTimeMs)(VOID);                           /* get the current time(ms)       */
    WORD32 (*pfGetTimeDelayMs)(WORD32 dwTimeOld);          /* get the diffenence from the given time to the current time in ms. */
}T_KNX_IP_INIT_PARA;

/****************************************************
*   结构名：T_KNX_BUFFER_HEADER
*   描述：  KNX buffer的头部定义。
*   参数：  
*           T_BUFFER_HEADER tBfHeader : buffer header.
*           BYTE *pucPayload          :    payload address.
*           BYTE ucLength;            :    payload length.
*           BYTE ucMessInfo           :    message information.
*           BYTE ucDevNo              :    device's No.
*           BYTE aucAddData[6]        :    additional data.
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
#pragma pack(1)
typedef struct
{
    T_BUFFER_HEADER tBfHeader;    /* buffer header.       */
    WORD16 wLength;               /* payload length.      */
    BYTE   *pucPayload;           /* payload address.     */
    BYTE   ucMessInfo;            /* message information. */
    BYTE   ucDevNo;               /* device's No.         */
    BYTE   aucAddData[6];         /* additional data.     */
}T_KNX_BUFFER_HEADER;
#pragma pack()

/**************************************************************************************************************
* 函数名称：BYTE KnxMsg_GetDevTxPool(BYTE ucDevNo)
* 功能描述：get the device's tx pool id.
* 输入参数：BYTE ucDevNo : Bit3   - side flag;
                           Bit0~2 - device No.
* 返 回 值：BYTE : Tx pool Id.
* 其它说明：this function can be used to get the tx pool Id by the device No.
* 修改日期     版本号     修改人      修改内容
* -------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
***************************************************************************************************************/
BYTE KnxMsg_GetDevTxPool(BYTE ucDevNo);

/**************************************************************************************************************
* 函数名称：VOID Main_MsgProcess(VOID)
* 功能描述：KNX消息处理总入口。
* 输入参数：no.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：
* 修改日期     版本号     修改人      修改内容
* -------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
***************************************************************************************************************/
VOID Main_MsgProcess(VOID);

/**************************************************************************************************************
* 函数名称：VOID Knx_MsgInit(T_KNX_IP_INIT_PARA *ptCorePara)
* 功能描述：KNX message handler initialization.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：
* 修改日期     版本号     修改人      修改内容
* -------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
***************************************************************************************************************/
VOID Knx_MsgInit(T_KNX_IP_INIT_PARA *ptCorePara);

/**************************************************************************
* 函数名称：BYTE* Knx_Buffer_Alloc(BYTE ucPoolId,BYTE ucUseFlg)
* 功能描述：从buffer子池中分配一个buffer用于Knx消息处理。
* 输入参数：BYTE ucPoolId : pool Id.
            BYTE ucUseFlg : KNX_BUFFER_FOR_KNX
                            KNX_BUFFER_FOR_IP
* 输出参数：无
* 返 回 值：NULL  : buffer子池分配失败
                    其他，成功的buffer指针
* 其它说明：(1)KnxIP frame format is as below:
            |sizeof(WORDPTR) for next frame address|1byte for Pool Id|1byte KNX payload length|1byte Knx payload offset|socket No.|Ip&port|data...|
            (2)the return point pints to the buffer header saving the next buffer's address. 
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
BYTE* Knx_Buffer_Alloc(BYTE ucPoolId,BYTE ucUseFlg);

/**************************************************************************
* 函数名称：VOID Knx_Buffer_Chain(BYTE *pucPre,BYTE *pucNext)
* 功能描述：将pucNext链到pucPre buffer后。
* 输入参数：无.
* 输出参数：无
* 返 回 值：无.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
VOID Knx_Buffer_Chain(BYTE *pucPre,BYTE *pucNext);

/**************************************************************************
* 函数名称：VOID KnxIp_Buffer_Free(BYTE ucPoolId,BYTE *pucBuffer)
* 功能描述：release the knxip buffer.
* 输入参数：BYTE ucPoolId : pool Id.
* 输出参数：无
* 返 回 值：NULL  : buffer子池分配失败
                    其他，成功的buffer指针
* 其它说明：In the main,we should check sg_pucWaitForFree cycally to release the
                             buffer.
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
VOID Knx_Buffer_Free(BYTE ucPoolId,BYTE *pucBuffer);

/**************************************************************************************************************
* 函数名称：WORD32 Knx_MsgDev_Reg(BYTE ucSckNo,T_KNX_DEV *ptKnxDev,WORD16 wTxBufNum,WORD16 wBuffLen)
* 功能描述：KNX消息源设备注册接口。
* 输入参数：BYTE ucSckNo        : register device's No.COM_MULTCAST_SCK_NO ~ COM_MULTCAST_SCK_USER_NO.
            T_KNX_DEV *ptKnxDev : discription structure of the register device.
            WORD16 wTxBufNum    : count of buffers for transmitting.
            WORD16 wBuffLen     : buffer size in byte.
* 输出参数：no.
* 返 回 值：SW_OK :successful
            SW_ERR:failed.
* 其它说明：(1)the logical device No. begins with 0.
            (2)the device should be registered in sequence.
* 修改日期     版本号     修改人      修改内容
* -------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
***************************************************************************************************************/
WORD32 Knx_MsgDev_Reg(BYTE ucSckNo,T_KNX_DEV *ptKnxDev,WORD16 wTxBufNum,WORD16 wBuffLen);

/**************************************************************************************************************
* 函数名称：BYTE KnxIp_Application_Cmd(T_KNX_APP_CMD *pAppCmd)
* 功能描述：application request handler.
* 输入参数：T_KNX_APP_CMD *pAppCmd : memory pointer of application command and it's parameter.
* 输出参数：no.
* 返 回 值：E_CMD_SUCCESSFUL :command is sucessful.
            E_COMMAND_FAILED :command is failed.
* 其它说明：we only support send multicast frames by tunnelling.
* 修改日期     版本号     修改人      修改内容
* -------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
***************************************************************************************************************/
BYTE KnxIp_Application_Cmd(T_KNX_APP_CMD *pAppCmd);

/**************************************************************************************************************
* 函数名称：T_INTERFACE_INFO *KnxIp_App_Get_InterfaceInfo(VOID)
* 功能描述：application get the KnxIp interfaces(routers) information connecting to this client.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：T_INTERFACE_INFO *:information structure pointer.
* 其它说明：After sending search request and waiting 10 seconds,we can use this function to get the interfaces 
            information.
* 修改日期     版本号     修改人      修改内容
* -------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
***************************************************************************************************************/
T_INTERFACE_INFO *KnxIp_App_Get_InterfaceInfo(VOID);

/**************************************************************************************************************
* 函数名称：VOID Knx_MsgQuit(VOID)
* 功能描述：release all malloc resources.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：
* 修改日期     版本号     修改人      修改内容
* -------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
***************************************************************************************************************/
VOID Knx_MsgQuit(VOID);

#ifdef __cplusplus
}
#endif

#endif /* _KNX_MSG_H_ */



/* end of file. */


