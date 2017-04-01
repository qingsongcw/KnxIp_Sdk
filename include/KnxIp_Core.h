


#ifndef _KNXIP_CORE_H_
#define _KNXIP_CORE_H_

#ifdef __cplusplus
extern "C" {
#endif






/* service version */
#define KNX_NET_IP_CORE_VER          (0x01)
#define KNX_NET_IP_MGT_VER1          (0x01)
#define KNX_NET_IP_MGT_VER11         (0x11)   /* supporting cEMI server's transport layer. */
#define KNX_NET_IP_TUNNEL_VER        (0x01)
#define KNX_NET_IP_ROUTE_VER         (0x01)

/* Tunnelling connection layer */
#define TUNNEL_LINKLAYER             (0x02)  /* Establish a Data Link Layer tunnel to the KNX network. */
#define TUNNEL_RAW                   (0x04)  /* Establish a raw tunnel to the KNX network. */
#define TUNNEL_BUSMONITOR            (0x80)  /* Establish a Busmonitor tunnel to the KNX network. */

#define KNX_NET_CONNECT_ACT_FLG      (0x01)  /* the connection is active */

/* commond err code */
#define E_NO_ERROR                   (0x00)  /* Operation successful  */
#define E_HOST_PROTOCOL_TYPE         (0x01)  /* The requested host protocol is not supported by the KNXnet/IP device. */
#define E_VERSION_NOT_SUPPORTED      (0x02)  /* The requested protocol version is not supported by the KNXnet/IP device.*/ 
#define E_SEQUENCE_NUMBER            (0x04)  /* The received sequence number is out of order.*/
                                     
/* connection response */
#define E_CONNECTION_ID              (0x21)  /* The KNXnet/IP Server device cannot find an active data connection with the specified ID. */
#define E_CONNECTION_TYPE            (0x22)  /* The KNXnet/IP Server device does not support the requested connection type. */ 
#define E_CONNECTION_OPTION          (0x23)  /* The KNXnet/IP Server device does not support one or more requested connection options. */ 
#define E_NO_MORE_CONNECTIONS        (0x24)  /* The KNXnet/IP Server device cannot accept the new data connection because its maximum 
                                                amount of concurrent connections is already used. */
#define E_DATA_CONNECTION            (0x26)  /* The KNXnet/IP Server device detects an error concerning the data connection with the specified ID. */
#define E_KNX_CONNECTION             (0x27)  /* The KNXnet/IP Server device detects an error concerning the KNX connection with the specified ID */
#define E_TUNNELING_LAYER            (0x29)  /* The KNXnet/IP Server device does not support the requested KNXnet/IP Tunnelling layer.*/

/* Description code used in description Information Block */
#define DEVICE_INFO                  (0x01)      /* Device information e.g. KNX medium.       */ 
#define SUPP_SVC_FAMILIES            (0x02)      /* Service families supported by the device. */ 
#define IP_CONFIG                    (0x03)      /* IP configuration      */
#define IP_CUR_CONFIG                (0x04)      /* current configuration */
#define KNX_ADDRESSES                (0x05)      /* KNX addresses         */
#define MFR_DATA                     (0xFE)      /* DIB structure for further data defined by device manufacturer. */
#define DESC_NOT_USED                (0xFF)      /* Not used.                                                      */

/* host protocol code */
#define IPV4_UDP                     (0x01)      /* IPV4 */
#define IPV4_TCP                     (0x02)      /* IPV6 */

/* media type */
#define KNX_TP1_MEDIA                (0x02)
#define KNX_PL_MEDIA                 (0x04)
#define KNX_RF_MEDIA                 (0x10)
#define KNX_IP_MEDIA                 (0x20)

/* timeout constant */
#define SEARCH_REQUEST_TIMEOUT               (10000)/* s wait for 10 seconds for seartch_responses.    */
#define CONNECT_REQUEST_TIMEOUT              (10000)/* s KNXnet/IP Client shall wait for 10 seconds for a 
                                                         CONNECT_RESPONSE frame from KNXnet/IP Server. */ 
#define CONNECTIONSTATE_REQUEST_TIMEOUT      (10000)/* s KNXnet/IP Client shall wait for 10 seconds for a
                                                         CONNECTIONSTATE_RESPONSE frame from KNXnet/IP Server.  */
#define DEVICE_CONFIGURATION_REQUEST_TIMEOUT (10000)/* s KNXnet/IP Client shall wait for 10 seconds for a 
                                                         DEVICE_CONFIGURATION_RESPONSE frame from KNXnet/IP Server.  */
#define TUNNELING_REQUEST_TIMEOUT            (1000) /* s KNXnet/IP Client shall wait for 1 second for a 
                                                         TUNNELING_ACK response on a TUNNELING_REQUEST frame from KNXnet/IP Server.  */
#define CONNECTION_ALIVE_TIME                (120000)/* s If the KNXnet/IP Server does not receive a heartbeat \
                                                         request within 120 seconds of the last correctly received message frame, \
                                                         the server shall terminate the connection by sending a DISCONNECT_REQUEST to
                                                         the client’s control endpoint. */
#define CONNECT_STATUS_CYCLE                 (50000) /* 20 seconds every heart beat. */
    /* The start port number for control&data endpoint. */
#define KNX_IP_PORT_NUMBER                   (3671)        /* port number used for tcp/ip */
#define KNX_IP_PORT_NUM_HI                   0x0E
#define KNX_IP_PORT_NUM_LOW                  0x57
#define KNX_IP_MUL_IP                        (0xe000170c)  /* 224.0.23.12 */
#define KNX_IP_CONNECT_CHANNEL               (0x01)        /* the start connect channel no. */


#define KNX_SERIAL_NUMBER_LENGTH             (6)
#ifndef NETIF_MAX_HWADDR_LEN
  #define NETIF_MAX_HWADDR_LEN               (6U)
#endif
#define KNX_DEV_FRIEND_NAME_LENGTH           (30)


#define KNX_IP_DEV_DIB_LEN                   (128)    /* the length of device's description. */
#define KNX_IP_DEV_HW_DIB_LEN                (0x36)
#define KNX_IP_ROUTER_SVRFAM_LEN             (0x0a)

/* IP method */
#define KNX_NETIP_IP_METH_MANU               (1)
#define KNX_NETIP_IP_METH_BOOTP              (2)
#define KNX_NETIP_IP_METH_DHCP               (4)
#define KNX_NETIP_IP_METH_AUTO               (8)
#define KNX_NETIP_IP_METH_DHCP_BIT           (0x02)

#define TNL_HEART_BEAT_TIMER_CUNT            0xc0          /* 120s */
#define MGM_HEART_BEAT_TIMER_CUNT            0x0c
#define HEART_BIT_TIMER_UNIT                 10000         /* heart bit timer is 10s */

#define QUEUE_OVERFLOW_TO_IP                 1
#define QUEUE_OVERFLOW_TO_KNX                2
#define MSG_TRANSMIT_TO_IP                   3
#define MSG_TRANSMIT_TO_KNX                  4

/* the offset from the begin of the buffer. */
#define CMD_HPAI_LENGTH_POS                  6
#define CMD_PROTOCOL_CODE_POS                7
#define CMD_HPAI_IP_POS                      8
#define CMD_HPAI_PORT_POS                    12

/* offset of the DIB from the DIB buffer. */
#define CMD_DIB_LEN_POS                      0
#define CMD_DIB_DESCRIP_POS                  1
#define CMD_DIB_MEDIA_POS                    2
#define CMD_DIB_DEV_STS_POS                  3
#define CMD_DIB_KNX_ADDRES_H_POS             4
#define CMD_DIB_KNX_ADDRES_L_POS             5
#define CMD_DIB_KNX_PRJ_H_POS                6
#define CMD_DIB_KNX_PRJ_L_POS                7
#define CMD_DIB_SERIAL_NO_POS                8
#define CMD_DIB_MULTI_IP_POS                 14
#define CMD_DIB_MAC_POS                      18
#define CMD_DIB_NAME_POS                     24
#define CMD_DIB_NAME_LENGTH                  30

/* offset of the Ip configure from the IP info buffer. */
#define CMD_IP_LEN_POS                       0
#define CMD_IP_DESCRIP_POS                   1
#define CMD_IP_IP_ADDRESS_POS                2
#define CMD_IP_SUBNET_MASK_POS               6
#define CMD_IP_DEFAULT_GWAY_POS              10
#define CMD_IP_CAPABILITY_POS                14
#define CMD_IP_IP_ASSIGN_METHOD_POS          15

/* offset of the current IP configure from the current IP info buffer. */
#define CMD_CIP_LEN_POS                       0
#define CMD_CIP_DESCRIP_POS                   1
#define CMD_CIP_IP_ADDRESS_POS                2
#define CMD_CIP_SUBNET_MASK_POS               6
#define CMD_CIP_DEFAULT_GWAY_POS              10
#define CMD_CIP_DHCP_SVR_POS                  14
#define CMD_CIP_IP_ASSIGN_METHOD_POS          18
#define CMD_CIP_RESERVED                      19

/* offset for connect request frame. */
#define CMD_CNECT_CTRL_IP_POS                 8
#define CMD_CNECT_CTRL_PORT_POS               12
#define CMD_CNECT_DATA_PRTCL_CODE_POS         15
#define CMD_CNECT_DATA_IP_POS                 16
#define CMD_CNECT_DATA_PORT_POS               20
#define CMD_CNECT_TYPE_CODE_POS               23
#define CMD_CNECT_TUNNEL_LAYER_POS            24

/* offset for connection response frame. */
#define CMD_CNECT_RESP_CHNL_ID_POS            6
#define CMD_CNECT_RESP_STATUS_POS             7
#define CMD_CNECT_RESP_DHPAI_LEN_POS          8
#define CMD_CNECT_RESP_DHPAI_CODE_POS         9
#define CMD_CNECT_RESP_DHPAI_IP_POS           10
#define CMD_CNECT_RESP_DHPAI_PORT_POS         14
#define CMD_CNECT_RESP_CRD_POS                16

/* offset for connection_status cmd frame. */
#define CMD_CNTSTS_CNECT_ID_POS               6
#define CMD_CNTSTS_PRTCL_CODE_POS             9
#define CMD_CNTSTS_CHPAI_POS                  10

/* offset for connection_status response. */
#define CMD_CNTSTS_RESP_ID_POS                6
#define CMD_CNT_STS_RESP_STS_POS              7

/* offset for discnect cmd frame. */
#define CMD_DISCNECT_CHNL_ID_POS              6
#define CMD_DISCNECT_PRTCL_CODE_POS           9
#define CMD_DISCNECT_CHPAI_IP_POS             10
#define CMD_DISCNECT_CHPAI_PORT_POS           14

/* offset for connection_status response. */
#define CMD_DISCNECT_RESP_ID_POS              6
#define CMD_DISCNECT_STS_RESP_STS_POS         7

/* information length define. */
#define CNECT_TUNNEL_INFO_LENGTH              4
#define CNECT_MGM_INFO_LENGTH                 2


#define MAX_KNX_PORT_NUMBER                   1
#define MAX_KNXIP_CNECT_NUM                   7

/* connect is active flag */
#define KNX_IP_CNECT_IDEL                     0x00
#define KNX_IP_CNECT_ACTIVE                   0x01       /* connection is active.            */
#define KNX_IP_CNECT_ACK_CHK                  0x02       /* should check the ACK overtime.   */
#define KNX_IP_CNECT_REQUIRING                0x04       /* connection requiring,waiting for response. */
#define KNX_IP_CNECT_ACK_REPT_FLG             0x08       /* ACK is wrong or overtime,should send again. */
#define KNX_IP_SEARCH_REQUIRING               0x10       /* search requiring,waiting for response.     */
#define KNX_IP_CNECTST_REQUIRING              0x20       /* connection status requiring,waiting for response. */
#define KNX_IP_CNECTDATA_RXTX_FLG             0x40       /* connection data rxtx control flag.                */
#define KNX_IP_DISCNECT_REQUIRING             0x80       /* disconnection requiring.waiting for response.     */

#define KNX_PORT_MODE_MASK                    0x80       /* Bit7:0-normal mode,1-busmonitor mode.       */
#define KNX_CHNL_CNECT_CUNT_MASK              0x70       /* port attribute:bit4-6 for channel connection counter. */
#define KNX_MGM_CNECT_CUNT_MASK               0x07       /* port attribute:bit0-2 for Mgm connection counter.     */

#define KNX_IP_SEARCH_TOTAL_LEN               14
#define KNX_IP_DISCRPT_TOTAL_LEN              14
#define KNX_IP_CNECT_TOTAL_LEN                24
#define KNX_IP_CNECTSTS_TOTAL_LEN             16
#define KNX_IP_DISCNECT_TOTAL_LEN             16

/* Defines for config flags */
#define CO_PRIORITY                0x03    /* Priority class for the object              */
#define CO_COMM_ENABLE             0x04    /* Object in enabled for communication        */
#define CO_READ_ENABLE             0x08    /* Object value can be read via bus           */
#define CO_WRITE_ENABLE            0x10    /* Object value can be written via bus        */
#define CO_COMM_SEG1               0x20    /* Memory offset (only DM0012 & DM0021)       */
#define CO_TRANS_ENABLE            0x40    /* Object is enabled to send                  */
#define CO_UPDATE_ENABLE           0x80    /* Object accepts values from response frames */


#define KNXIP_CTRL_POINT           0x00    /* control point flag. */
#define KNXIP_DATA_POINT           0x01    /* data point flag.    */
#define KNXIP_USER_MULTI_POINT     0x02    /* data point flag.    */



/****************************************************
*   结构名：T_KNXIP_CNECT_PARA
*   描述：  Knx Ip连接参数
*   参数：  见下面结构定义和注释；
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE ucCnectFlg;         /* KNX_IP_CNECT_ACTIVE or KNX_IP_CNECT_IDEL */
    BYTE aucCnectType;       /* connection type:Mgm or tunnel.           */
    BYTE ucCnectId;          /* connection ID.             */
    BYTE aucCtrlIp[4];       /* control endpoint ip.       */
    BYTE aucCtrlPrt[2];      /* control endpoint port No.  */
    BYTE aucDataIp[4];       /* data endpoint ip.          */
    BYTE aucDataPrt[2];      /* data endpoint port No.     */
    BYTE ucRxSeqCunt;        /* receive sequence No.       */
    BYTE ucTxSeqCunt;        /* send sequence No.          */
    BYTE ucCnectSt;          /* status of the connection.  */
    BYTE *pucTxBuff;         /* Tx buffer                  */
    BYTE *pucTxEnd;          /* Tx buffer chain's tail.    */
    WORD32 wAckTime;         /* the start waiting ACK time.*/
    WORD32 wSearchTime;      /* the start waiting search response time. */
    WORD32 wHeartTime;       /* the start waiting heart beat time.      */
    BYTE aucAddAddr[2];      /* additional address. */
}T_KNXIP_CNECT_PARA;

/****************************************************
*   结构名：T_KNX_IP_CORE_PARA
*   描述：  Knx Ip core 参数
*   参数：  见下面结构定义和注释；
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE aucIp[4];                                /* ip address.High->low. */
    BYTE aucSysMulIp[4];                          /* system multicast ip address.  */
    BYTE aucInstallMulIp[4];                      /* install multicast ip address. */
    BYTE aucInstallMulIpPort[2];                   /* install multicast ip port.    */
    BYTE aucCtrlPortNo[2];                        /* control point no.     */
    BYTE aucDataPortNo[2];                        /* data point no.        */
    WORD32 (*pfAppCallback)(T_KNX_CORE_EVENT *ptCntEvent); /* application call back handler when disconnection happens. */
    WORD32 (*pfGetTimeMs)(VOID);                  /* get the current time(ms) */
    WORD32 (*pfGetTimeDelayMs)(WORD32 dwTimeOld); /* get the diffenence from the given time to the current time in ms. */
    T_KNXIP_CNECT_PARA tCnectPara;                /* port parameter.       */
}T_KNX_IP_CORE_PARA;

/****************************************************
*   结构名：T_KNXIP_CNECT_REQ_PARA
*   描述：  input parameter for knxip connection establish.
*   参数：
*   作者：       
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE ucCntType;                             /* connection type:Mgm or tunnel.                  */
    BYTE aucDestIp[4];                          /* destination control point ip address.High->low. */
    BYTE aucCtrlPortNo[2];                      /* control point port no.                          */
}T_KNXIP_CNECT_REQ_PARA;

/******************************************************************************************************
* 函数名称：VOID KnxIp_Init_Core(T_KNX_IP_INIT_PARA *ptCorePara)
* 功能描述：Knx Ip core 初始化。
* 输入参数：T_KNX_IP_INIT_PARA *ptCorePara
                               ->ucKnxPrtNum:KNX端口的个数
                               ->aucIp[4]   :本机IP地址
* 输出参数：无
* 返 回 值：无
* 其它说明：无
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_Init_Core(T_KNX_IP_INIT_PARA *ptCorePara);

/******************************************************************************************************
* 函数名称：BYTE KnxIp_Svr_Core(BYTE *pucInBuffer,BYTE ucSrcPoolId)
* 功能描述：Knx Ip core 处理入口。
* 输入参数：BYTE *pucInBuffer  : point to the header of the buffer.
            BYTE ucSrcPoolId   : buffer的源pool ID.
* 输出参数：
* 返 回 值：BYTE* 返回response的buffer，返回NULL无response。调用者需要处理传入buffer的释放。
* 其它说明：pucBuffer指向input buffer的管理头部。
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE KnxIp_Svr_Core(BYTE *pucInBuffer,BYTE ucSrcPoolId);

/****************************************************************************************************
* 函数名称：BYTE KnxIp_Core_Req_Search(BYTE ucTxPoolId)
* 功能描述：Knx Ip core search require command set handler.
* 输入参数：BYTE ucTxPoolId :pool ID for transmitting.
* 输出参数：
* 返 回 值：return E_CMD_SUCCESSFUL/E_COMMAND_FAILED/E_CONNECT_ACTIVE.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE KnxIp_Core_Req_Search(BYTE ucTxPoolId);

/****************************************************************************************************
* 函数名称：BYTE *KnxIp_Core_Read_CnectOut(VOID)
* 功能描述：获取KNX IP连接通道的输出报文。
* 输入参数：
* 输出参数：
* 返 回 值：待处理的buffer链首地址.NULL表示无待处理buffer。
* 其它说明：返回一个待发送的buffer链。
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE *KnxIp_Core_Read_CnectOut(VOID);

/****************************************************************************************************
* 函数名称：BYTE KnxIp_Core_Req_Connect(BYTE ucTxPoolId,T_KNXIP_CNECT_REQ_PARA *ptCntReqPara)
* 功能描述：Knx Ip core connect require command set handler.
* 输入参数：BYTE ucTxPoolId :pool ID for transmitting.
            T_KNXIP_CNECT_REQ_PARA *ptCntReqPara:point to the connection parameter.
* 输出参数：
* 返 回 值：return E_COMMAND_FAILED/E_CMD_SUCCESSFUL/E_CONNECT_ACTIVE/E_COMMAND_PARA.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE KnxIp_Core_Req_Connect(BYTE ucTxPoolId,T_KNXIP_CNECT_REQ_PARA *ptCntReqPara);

/****************************************************************************************************
* 函数名称：BYTE KnxIp_Core_Req_Discnt(BYTE ucTxPoolId)
* 功能描述：Knx Ip core disconnect require命令处理入口。
* 输入参数：BYTE ucTxPoolId :pool ID for transmitting.
* 输出参数：
* 返 回 值：return  E_COMMAND_FAILED/E_CMD_SUCCESSFUL/E_CONNECT_ACTIVE/E_COMMAND_PARA.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE KnxIp_Core_Req_Discnt(BYTE ucTxPoolId);

/****************************************************************************************************
* 函数名称：BYTE KnxIp_Core_Req_CnectStus(BYTE ucCnectId,BYTE ucTxPoolId)
* 功能描述：Knx Ip core connect status require命令处理入口。
* 输入参数：BYTE ucCnectId  :connection ID.
            BYTE ucTxPoolId :pool ID for transmitting.
* 输出参数：
* 返 回 值：return  E_COMMAND_FAILED/E_CMD_SUCCESSFUL/E_CONNECT_ACTIVE/E_COMMAND_PARA.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE KnxIp_Core_Req_CnectStus(BYTE ucCnectId,BYTE ucTxPoolId);

/****************************************************************************************************
* 函数名称：VOID KnxIp_Core_RunProcess(VOID)
* 功能描述：the main loop of knxip core.
* 输入参数：none.
* 输出参数：none.
* 返 回 值：none.
* 其它说明：none.
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_Core_RunProcess(VOID);

/*****************************************************************
* 函数名称：VOID KnxIp_Frame_Extract(BYTE *pucBuffer,BYTE ucFlag)
* 功能描述：extract the frame data.
* 输入参数：BYTE *pucBuffer:frame buffer pointer.
            BYTE ucFlag    :ROUTING_INDICATION/TUNNELING_REQUEST
* 输出参数：none.
* 返 回 值：none.
* 其它说明：none.
* 修改日期        版本号     修改人          修改内容
* ---------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
*****************************************************************/
VOID KnxIp_Frame_Extract(BYTE *pucBuffer,BYTE ucFlag);

/***************************************************************************************************
* 函数名称：WORD32 KnxIp_GrpValue_Read(BYTE *pucGrpAddr,BYTE ucTxPoolId)
* 功能描述：read a group address value.
* 输入参数：BYTE *pucGrpAddr:group address pointer.
            BYTE ucTxPoolId :tx pool id.
* 输出参数：none.
* 返 回 值：SW_OK/SW_ERR.
* 其它说明：none.
* 修改日期        版本号     修改人          修改内容
* -------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
***************************************************************************************************/
BYTE KnxIp_GrpValue_Read(BYTE *pucGrpAddr,BYTE ucTxPoolId);

/***************************************************************************************************
* 函数名称：BYTE KnxIp_GrpValue_Write(BYTE *pucGrpAddr,BYTE ucLen,BYTE *pucData,BYTE ucTxPoolId)
* 功能描述：read a group address value.
* 输入参数：BYTE *pucGrpAddr:group address pointer.
            BYTE ucLen      :data lenght in byte.
            BYTE *pucData   :data pointer.
            BYTE ucTxPoolId :tx pool id.
* 输出参数：none.
* 返 回 值：SW_OK/SW_ERR.
* 其它说明：none.
* 修改日期        版本号     修改人          修改内容
* -------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
***************************************************************************************************/
BYTE KnxIp_GrpValue_Write(BYTE *pucGrpAddr,BYTE ucLen,BYTE *pucData,BYTE ucTxPoolId);

/******************************************************************************************************
* 函数名称：T_INTERFACE_INFO *KnxIp_Core_GetInterface(VOID)
* 功能描述：return the KnxIp interfaces(routers) information connecting to this client.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：T_INTERFACE_INFO * pointer pointing to the information structure.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
T_INTERFACE_INFO *KnxIp_Core_GetInterface(VOID);

/******************************************************************************************************
* 函数名称：VOID KnxIp_Core_SetRemoteIP(BYTE ucFlag,BYTE *pucBuffer)
* 功能描述：set remote device's ip address and port into buffer.
* 输入参数：BYTE ucFlag:KNXIP_CTRL_POINT/KNXIP_DATA_POINT
            BYTE *pucBuffer:buffer pointer.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_Core_SetRemoteIP(BYTE ucFlag,BYTE *pucBuffer);

#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_CORE_H_ */



/* end of file. */






