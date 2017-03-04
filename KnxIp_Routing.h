/******************************************************************************
* 版权所有 (C)2013，**********有限公司。
*
* 文件名称：KnxIp_Routing.h
* 文件标识：无
* 内容摘要：knx ip route header file.
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


#ifndef _KNXIP_ROUTING_H_
#define _KNXIP_ROUTING_H_

#ifdef __cplusplus
extern "C" {
#endif




/* route control command define. */
#define KNXIP_ROUTE_ENABLE           (0x01)
#define KNXIP_ROUTE_DISABLE          (0x00)

/* frame length */
#define ROUTING_BUSY_LENGTH           0x0C
#define ROUTING_LOSTMSG_LENGTH        0x0A

/* define parameter for routing. */
#define TX_RTBUSY_THRESHOLD_P2P      5
#define TX_RTBUSY_THRESHOLD_P2ALL    10

/* define time for busy frame count operation. */
#define BUSY_CUNT_INC                10    /* 10ms */
#define BUSY_CUNT_DEC                5     /* 5ms  */

/* routing frame position define. */
#define CMD_RT_INDI_MSGCODE_POS      6
#define CMD_RT_MSG_CTRL1_OFFSET      2

/* lost message command. */
#define CMD_RT_LOSTMSG_DEVST_POS     7
#define CMD_RT_LOSTMSG_NUM_H_POS     8
#define CMD_RT_LOSTMSG_NUM_L_POS     9

/* busy command. */
#define CMD_RT_BUSY_DEVST_POS        7
#define CMD_RT_BUSY_WAITTM_H_POS     8
#define CMD_RT_BUSY_WAITTM_L_POS     9
#define CMD_RT_BUSY_CTRL_H_POS       10
#define CMD_RT_BUSY_CTRL_L_POS       11


/******************************************************************************************************
* 函数名称：VOID KnxIp_RtBusy_Req(BYTE *pucInBuffer)
* 功能描述：creat Knx Ip routing busy require.
* 输入参数：BYTE *pucInBuffer  : point to the header of the buffer.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：the caller should set the buffer's destination device's number and the source device number.
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_RtBusy_Req(BYTE *pucInBuffer);


/******************************************************************************************************
* 函数名称：KNXIP_BOOL KnxIp_Svr_Route(BYTE *pucInBuffer,BYTE ucTxPoolId)
* 功能描述：Knx Ip routing handler.
* 输入参数：BYTE *pucInBuffer  : point to the header of the buffer.
            BYTE ucTxPoolId   : buffer的源pool ID.
* 输出参数：
* 返 回 值：BYTE* 返回response的buffer，返回NULL无response。调用者需要处理传入buffer的释放。
* 其它说明：pucBuffer指向input buffer的管理头部。
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
KNXIP_BOOL KnxIp_Svr_Route(BYTE *pucInBuffer,BYTE ucTxPoolId);

/******************************************************************************************************
* 函数名称：VOID KnxIp_RouteCtrl(VOID)
* 功能描述：Control routing function working according to the resume time.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：This function should be called periodically.
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                       创建 
******************************************************************************************************/
VOID KnxIp_RouteCtrl(VOID);

/******************************************************************************************************
* 函数名称：BYTE *KnxIp_GetRtMgmDownFrame(VOID)
* 功能描述：get routing management down frames.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：NULL / freme buffer pointer.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE *KnxIp_GetRtMgmDownFrame(VOID);

/******************************************************************************************************
* 函数名称：KNXIP_BOOL KnxIp_Svr_Route_Req(BYTE *pucInBuffer)
* 功能描述：creat Knx Ip routing indication require.
* 输入参数：BYTE *pucInBuffer  : point to the header of the buffer.
* 输出参数：no.
* 返 回 值：TRUE : route it successfully.
            FALSE: route it failed(can not route it).
* 其它说明：the caller should set the buffer's destination device's number and the source device number.
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
KNXIP_BOOL KnxIp_Svr_Route_Req(BYTE *pucInBuffer);

/******************************************************************************************************
* 函数名称：VOID KnxIp_Route_Init(T_KNX_IP_CORE_PARA *ptCoreData)
* 功能描述：routing function initialization.
* 输入参数：T_KNX_IP_CORE_PARA *ptCoreDat:KNX IP core parameter.
* 输出参数：无
* 返 回 值：无
* 其它说明：this function will be called by Knxip_core
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_Route_Init(T_KNX_IP_CORE_PARA *ptCoreData);







#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_ROUTING_H_ */



/* end of file. */






