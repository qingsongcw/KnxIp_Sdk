


#ifndef _KNXIP_MGM_H_
#define _KNXIP_MGM_H_

#ifdef __cplusplus
extern "C" {
#endif


/* offset for Mgm request frame. */
#define CMD_MGM_REQUEST_CHNLID_POS              7
#define CMD_MGM_REQUEST_SEQNO_POS               8
#define CMD_MGM_REQUEST_MSGCODE_POS             10

/* offset for Mgm ACK frame. */
#define CMD_MGM_ACK_CHNLID_POS                  7
#define CMD_MGM_ACK_SEQNO_POS                   8
#define CMD_MGM_ACK_STS_POS                     9


/* overtime for MGM. */
#define KNX_SUBNET_DOWN_TIME                    5         /* KNX subnet down time 5s. */
#define KNX_IPNET_DOWN_TIME                     5         /* IP net down time 5s.     */







/******************************************************************************************************
* 函数名称：KNXIP_BOOL KnxIp_Svr_Mgm(BYTE *pucInBuffer,BYTE ucSrcPoolId)
* 功能描述：Knx Ip management 处理入口。
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
KNXIP_BOOL KnxIp_Svr_Mgm(BYTE *pucInBuffer,BYTE ucSrcPoolId);

/******************************************************************************************************
* 函数名称：VOID KnxIp_Mgm_Init(T_KNX_IP_CORE_PARA *ptCoreData)
* 功能描述：Device management initialization.
* 输入参数：T_KNX_IP_CORE_PARA *ptCoreDat:KNX IP core parameter.
* 输出参数：无
* 返 回 值：无
* 其它说明：this function will be called by Knxip_core
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_Mgm_Init(T_KNX_IP_CORE_PARA *ptCoreData);

/******************************************************************************************************
* 函数名称：VOID KnxIp_Mgm_DisCnect(BYTE ucCnectId,T_KNXIP_PORT_PARA *ptPtrPara)
* 功能描述：Device management disconnection handle,set the data for mgm disconnection response.
* 输入参数：BYTE ucCnectId :connection ID
            T_KNXIP_PORT_PARA *ptPtrPara:port's parameter.
* 输出参数：
* 返 回 值：VOID
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
VOID KnxIp_Mgm_DisCnect(BYTE ucCnectId,T_KNXIP_CNECT_PARA *ptPtrPara);

/******************************************************************************************************
* 函数名称：BYTE KnxIp_Svr_Mgm_Req(BYTE *pucInBuffer)
* 功能描述：Knx Ip 生成management require入口。
* 输入参数：BYTE *pucInBuffer: point to the header of buffer.
* 输出参数：
* 返 回 值：E_COMMAND_FAILED/E_CMD_SUCCESSFUL.
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ----------------------------------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建 
******************************************************************************************************/
BYTE KnxIp_Svr_Mgm_Req(BYTE *pucInBuffer);




#ifdef __cplusplus
}
#endif

#endif /* _KNXIP_MGM_H_ */



/* end of file. */






