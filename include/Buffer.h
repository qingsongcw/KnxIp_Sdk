/******************************************************************************
* 版权所有 (C)2013，**********有限公司。
*
* 文件名称：buffer.h
* 文件标识：无
* 内容摘要：缓冲区管理头文件
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


#ifndef _BUFFER_H_
#define _BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Attention:The follow definition should be redefined in BoardCtrl.h according to the realistic scenario. */
#ifndef TOTAL_BUFFER_SIZE
    #define TOTAL_BUFFER_SIZE (2048)   /* the total size of buffer pool. */
#endif

/* MCU_SIZE should be defined in configure.h */
#define DATA_BUF_ADDRESS_ALIGNMENT(x)  ((BYTE*)((((WORDPTR)(x))+MCU_SIZE-1) & (~(MCU_SIZE-1))))  /* align the address of the buffer. */
#define DATA_BUF_SIZE_ALIGNMENT(x)     (((x)+MCU_SIZE-1) & (~(MCU_SIZE-1)))                      /* align the size of the buffer.    */

/* The Max. number of pools. */
#define MAX_BUFFER_POOL_NUM         (16)

/* Pool ID definition. */
#define POOL_ID_NULL              (0)
#define POOL_ID_ERROR             (0xff)
#define SET_POOL_ACLLOC_FLAG      (0x01)    /* set alloc flag.      */
#define CLR_POOL_ACLLOC_FLAG      (0xFE)    /* release aclloc flag. */
#define SET_POOL_FREE_FLAG        (0x02)    /* set free flag.       */
#define CLR_POOL_FREE_FLAG        (0xFD)    /* release free flag.   */
#define SET_POOL_IN_FLAG          (0x04)    /* set input flag.      */
#define CLR_POOL_IN_FLAG          (0xFB)    /* release input flag.  */

/****************************************************
*   结构名：T_BUFFER_MGM
*   描述：  buffer管理结构
*   参数：  
    BYTE    ucUseFlg;              Bit0:alloc Pool's flag
                                   Bit1:free pool's flag
                                   Bit2:In buffer's flag
    BYTE    *pucPoolHeader;        the current free buffer point
    BYTE    *pucPoolEnd;           the current free buffer end  
    BYTE    *pucBufferIn;          the buffer for input         
    BYTE    *pucBufLastIn;         the last in buffer           
*   作者：       
*   说明:
       (1) buffer frame format is as below:
              |sizeof(WORDPTR)|1 byte for pool ID| data ....|
       (2) buffer size shold be >= (Max. data size + sizeof(WORDPTR) + 1)
       (3) the byte for pool ID in frame is defined as below:
              bit0~bit3:the source pool's ID;
              bit4~bit7:the destination pool's ID;
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
typedef struct
{
    BYTE    ucUseFlg;              /* Bit0:alloc Pool's flag,
                                      Bit1:free pool's flag,
                                      Bit2:In buffer's flag;         */
    BYTE    *pucPoolHeader;        /* the current free buffer point. */
    BYTE    *pucPoolEnd;           /* the current free buffer end.   */
    BYTE    *pucBufferIn;          /* the buffer for input.          */
    BYTE    *pucBufLastIn;         /* the last in buffer.            */
}T_BUFFER_MGM;

/****************************************************
*   结构名：T_BUFFER_HEADER
*   描述：  buffer头部
*   参数：  
            BYTE *pucNext : next buffer's address.
            BYTE ucPoolId : buffer's pool ID.
*   修改记录：
*   2013-7-24         新增结构；
****************************************************/
#pragma pack(1)
typedef struct
{
    BYTE *pucNext;     /* next buffer's address */
    BYTE ucPoolId;     /* buffer's pool ID.     */
}T_BUFFER_HEADER;
#pragma pack()

/**************************************************************************
* 函数名称：VOID Buffer_Pool_Init(VOID)
* 功能描述：初始化buffer池。
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
VOID Buffer_Pool_Init(VOID);

/**************************************************************************
* 函数名称：BYTE Buffer_Pool_Alloc(WORD16 wBufferSize,WORD16 wBufferNum)
* 功能描述：从buffer总池中分配一段buffer子池，子池的大小为buffer长度和个数
            的乘积。
* 输入参数：WORD16 wBufferSize : 一个buffer的大小
            WORD16 wBufferNum  : buffer的个数
* 输出参数：无
* 返 回 值：POOL_ID_NULL  : buffer子池分配失败
                            其他为分配成功后的POOL ID
* 其它说明：wBufferSize > sizeof(WORDPTR) + 1
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
BYTE Buffer_Pool_Alloc(WORD16 wBufferSize,WORD16 wBufferNum);

/**************************************************************************
* 函数名称：BYTE* Buffer_Alloc(BYTE ucPoolId)
* 功能描述：从buffer子池中分配一个buffer。
* 输入参数：BYTE ucPoolId : pool Id.
* 输出参数：无
* 返 回 值：NULL  : buffer子池分配失败
                    其他，成功的buffer指针
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
BYTE* Buffer_Alloc(BYTE ucPoolId);

/**************************************************************************
* 函数名称：BYTE* Buffer_Free(BYTE ucPoolId)
* 功能描述：释放一个buffer回pool中。
* 输入参数：BYTE ucPoolId : pool Id.
* 输出参数：无
* 返 回 值：NULL  : buffer子池释放失败
                    释放成功，返回子池首buffer
* 其它说明：存在函数重入的情况下，返回值不能作为buffer池的首地址进行计算。
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
BYTE* Buffer_Free(BYTE ucPoolId,BYTE *pucBuffer);

/**************************************************************************
* 函数名称：BYTE* Buffer_Insert(BYTE ucPoolId,BYTE *pucBuffer)
* 功能描述：向buffer链中插入一个buffer。
* 输入参数：BYTE ucPoolId : pool Id.
            BYTE *pucBuffer:buffer.
* 输出参数：无
* 返 回 值：NULL  : 插入buffer失败
                    插入成功，返回当前buffer池首buffer。
* 其它说明：存在函数重入的情况下，返回值不能作为buffer链的首地址进行计算。
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
BYTE* Buffer_Insert(BYTE ucPoolId,BYTE *pucBuffer);

/**************************************************************************
* 函数名称：BYTE* Buffer_GetHeader(BYTE ucPoolId)
* 功能描述：从buffer链中第一个buffer。
* 输入参数：BYTE ucPoolId : pool Id.
* 输出参数：无
* 返 回 值：NULL  : 获取buffer失败
                    获取成功，返回当前buffer。
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
BYTE* Buffer_Get(BYTE ucPoolId);

/**************************************************************************
* 函数名称：VOID Buffer_Pool_Quit(VOID)
* 功能描述：release all malloc resources.
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：
* 修改日期        版本号     修改人          修改内容
* ------------------------------------------------------------------------
* 2014/03/18       V1.0                        创建  
**************************************************************************/
VOID Buffer_Pool_Quit(VOID);

#ifdef __cplusplus
}
#endif

#endif /* _BUFFER_H_ */



/* end of file. */

