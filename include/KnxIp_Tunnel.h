


#ifndef _KNXIP_TUNNEL_H_
#define _KNXIP_TUNNEL_H_

#ifdef __cplusplus
extern "C" {
#endif



/* offset of the input buffer of tunnelling. */
#define CMD_TNL_REQ_CNECT_ID_POS         7
#define CMD_TNL_REQ_SEQ_NO_POS           8
#define CMD_TNL_REQ_MSG_CODE_POS         10
#define CMD_TNL_MSG_CTRL1_OFFSET         2

/* offset of the ACK of tunnelling. */
#define CMD_TNL_ACK_CNECT_ID_POS         7
#define CMD_TNL_ACK_SEQ_NO_POS           8
#define CMD_TNL_ACK_STS_POS              9






/******************************************************************************************************
* 函数名称：VOID KnxIp_Tunnel_Init(T_KNX_IP_CORE_PARA *ptCoreData)
* 功能描述：Device management initialization.
* 输入参数：BYTE ucPrtNo:Knx ports number.
            T_KNX_IP_CORE_PARA *ptCoreDat:KNX IP core parameter.
* 输出参数：无
* 返 回 值：无
* 其它说明：this function will be called by Knxip_core
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_Tunnel_Init(T_KNX_IP_CORE_PARA *ptCoreData);

/******************************************************************************************************
* 函数名称：KNXIP_BOOL KnxIp_Svr_Tunnel(BYTE *pucInBuffer,BYTE ucSrcPoolId)
* 功能描述：Knx Ip tunnelling 处理入口。
* 输入参数：BYTE *pucInBuffer: point to the header of buffer.
            BYTE ucSrcPoolId : buffer的源pool ID.
* 输出参数：
* 返 回 值：BYTE* 返回response的buffer，返回NULL无response.
            if return NULL,the caller should release the input buffer.
            if return the response buffer,the caller should not release the input buffer.
* 其它说明：pucBuffer指向buffer的头部。
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
KNXIP_BOOL KnxIp_Svr_Tunnel(BYTE *pucInBuffer,BYTE ucSrcPoolId);

/******************************************************************************************************
* 函数名称：VOID KnxIp_Tunnel_DisCnect(BYTE *pucIn,BYTE ucCnectId,T_KNXIP_PORT_PARA *ptPtrPara)
* 功能描述：Device management disconnection handle,set the data for mgm disconnection response.
* 输入参数：BYTE ucCnectId :connection ID
            T_KNXIP_PORT_PARA *ptPtrPara:port's parameter.
* 输出参数：BYTE *pucBuffer:response frame data.
* 返 回 值：VOID
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_Tunnel_DisCnect(BYTE ucCnectId,T_KNXIP_CNECT_PARA *ptPtrPara);

/******************************************************************************************************
* 函数名称：BYTE KnxIp_Svr_Tnl_Req(BYTE *pucInBuffer)
* 功能描述：Knx Ip 生成tunnelling require入口。
* 输入参数：BYTE *pucInBuffer: point to the header of buffer.
* 输出参数：
* 返 回 值：E_COMMAND_FAILED/E_CMD_SUCCESSFUL.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE KnxIp_Svr_Tnl_Req(BYTE *pucInBuffer);




#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_TUNNEL_H_ */



/* end of file. */






