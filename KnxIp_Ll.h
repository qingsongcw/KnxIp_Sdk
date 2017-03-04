/******************************************************************************
* 版权所有 (C)2013，南京**********控制系统有限公司。
*
* 文件名称：KnxIp_Ll.h
* 文件标识：无
* 内容摘要：knx ip core header file.
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


#ifndef _KNXIP_LL_H_
#define _KNXIP_LL_H_

#ifdef __cplusplus
extern "C" {
#endif

#define KNXIP_TX_LOSTMSG_ON       1        /* we need to send RT_LOST_MSG frame.      */
#define KNXIP_TX_LOSTMSG_OFF      0        /* we not need to send RT_LOST_MSG frame. */
#define KNXIP_TX_BUSY_ON          1        /* we need to send RT_BUSY_MSG frame.      */
#define KNXIP_TX_BUSY_OFF         0        /* we not need to send RT_BUSY_MSG frame. */

/******************************************************************************************
* 函数名称：VOID KnxIp_Ll_Init(VOID)
* 功能描述：init. the knx ip link layer parameter.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：no.
* 修改日期     版本号     修改人      修改内容
* ----------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
******************************************************************************************/
VOID KnxIp_Ll_Init(VOID);

/******************************************************************************************
* 函数名称：WORD32 KnxIp_Recv(VOID)
* 功能描述：Receive socket's data in polling way.It will poll all socket in turn.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：this function will insert the input frame into the socket's receiving pool.
* 修改日期     版本号     修改人      修改内容
* ----------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
******************************************************************************************/
VOID KnxIp_Recv(VOID);

/******************************************************************************************
* 函数名称：VOID KnxIp_Send(VOID)
* 功能描述：Send socket's data in polling way.It will poll all socket in turn.
* 输入参数：no.
* 输出参数：no.
* 返 回 值：no.
* 其它说明：
* 修改日期     版本号     修改人      修改内容
* ----------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
******************************************************************************************/
VOID KnxIp_Send(VOID);

/**************************************************************************************************************************
* 函数名称：WORD32 KnxIp_SckReg(T_IP_DEV_REG tIpDevReg)
* 功能描述：向KNX Ip链路层注册Socket，socket号从0开始，按序进行注册。
* 输入参数：T_IP_DEV_REG tIpDevReg:注册的socket设备描述,
                BYTE ucDevNo                                       socket号,COM_MULTCAST_SCK_NO ~ COM_MULTCAST_SCK_USER_NO.    
                WORD16 wRxBufferNum                                用于接收的buffer个数.
                WORD16 wTxBufferNum                                用于发送的buffer个数.
                WORD16 wBufferSize                                 每个buffer的长度.
                WORD16 (*pfReceive)(BYTE ucDevNo,BYTE *pucBuffer)  设备的接收函数
                    BYTE ucDevNo    : socket号,从0开始. 
                    BYTE *pucBuffer : 接收的数据存放的buffer指针.
                WORD16 (*pfSend)(BYTE ucDevNo,BYTE *pucBuffer,WORD16 wLength) 设备的发送函数
                    BYTE ucDevNo    : socket号,从0开始.
                    BYTE *pucBuffer : 发送数据的存放buffer指针.
                    WORD16 wLength  : 发送数据的长度.
* 输出参数：
* 返 回 值：SW_OK ：注册成功；
            SW_ERR：注册失败；
* 其它说明:
* 修改日期     版本号     修改人      修改内容
* -------------------------------------------------------------------------------------------------------------------------
* 2014-03-20   V1.00                   创建
***************************************************************************************************************************/
WORD32 KnxIp_SckReg(T_IP_DEV_REG *ptIpDevReg);





#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_LL_H_ */



/* end of file. */


