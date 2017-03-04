/******************************************************************************
* 版权所有 (C)2013，南京**********控制系统有限公司。
*
* 文件名称：Knx_Frame.h
* 文件标识：无
* 内容摘要：本文件定义了knx的帧格式。
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

#ifndef _KNX_FRAME_H_
#define _KNX_FRAME_H_

#ifdef __cplusplus
extern "C" {
#endif


/* offset of every byte in KNX ex-frame. */
#define POS_LENGTH                        (sizeof(WORDPTR)+1)            /* frome the buffer begine.Msg-code~(chksum-1) */
#define KNX_FIXED_FRAME_LEN               10                             /* the left byts number except the data. */
/* Definition of position at the beginning of the payload of a buffer. */
#define POS_MESSAGE_CODE                  0                              /* frome the KNX payload begine.      */
#define POS_ADDITIONAL_LEN                1                              /* position of additional length.     */
#define POS_CONTROL                       2                              /* position of control byte.Currently,we have no additional data.*/
#define POS_EX_CONTROL                    3                              /* position of ex-control byte.       */
#define POS_SRC_ADDR_H                    4                              /* position of source address H.      */
#define POS_SRC_ADDR_L                    5                              /* position of source address L.      */
#define POS_DES_ADDR_H                    6                              /* position of destination address H. */
#define POS_DES_ADDR_L                    7                              /* position of destination address L. */
#define POS_DATA_LENGTH                   8                              /* position of data length.           */
#define POS_TPDU_APCI                     9                              /* position of tpdu & apci byte.      */
#define POS_APCI_DATA0                    10                             /* position of APCI & data0.          */
#define POS_DATA0                         11                             /* position of data0.                 */
#define POS_DATA1                         12                             /* position of data1.                 */
#define POS_DATA2                         13                             /* position of data2.                 */
#define POS_DATA3                         14                             /* position of data3.                 */
#define POS_ADDITIONAL_DATA               2                              /* position of additional data.       */

/* define physical address operation service key words. */
#define KNX_PHYADDR_W_APDU_LEN            3
#define KNX_PHYADDR_R_APDU_LEN            1
#define POS_PHYADDR_H                     11
#define POS_PHYADDR_L                     12

/* define serial-No service key words. */
#define KNX_SERNO_ADDR_APDU_RLEN          7
#define KNX_SERI_ADDR_RESP_LEN            11
#define KNX_SERNO_ADDR_APDU_WLEN          13
#define POS_SERI_ADDR_NO_0                11
#define POS_SERI_ADDR_NO_1                12
#define POS_SERI_ADDR_NO_2                13
#define POS_SERI_ADDR_NO_3                14
#define POS_SERI_ADDR_NO_4                15
#define POS_SERI_ADDR_NO_5                16
#define POS_SERI_ADDR_H                   17
#define POS_SERI_ADDR_L                   18

/* define memory service key words. */
#define KNX_MEM_OP_FIXEC_LEN              3
#define POS_MEM_CUNT                      10
#define POS_MEM_ADDR_H                    11
#define POS_MEM_ADDR_L                    12
#define POS_MEM_DATA_1                    13
#define POS_MEM_DATA_2                    14
#define POS_MEM_DATA_3                    15
#define POS_MEM_DATA_4                    16
#define POS_MEM_DATA_5                    17
#define POS_MEM_DATA_6                    18
#define POS_MEM_DATA_7                    19
#define POS_MEM_DATA_8                    20
#define POS_MEM_DATA_9                    21
#define POS_MEM_DATA_10                   22
#define KNXMSG_MEM_CUNT_MASK              0x3F
#define KNX_MEM_MAX_CUNT                  12              /* according to the standard frame format. */

/* define function service key words. */
#define POS_FUNC_OBJID                    11
#define POS_FUNC_PROPID                   12
#define POS_FUNC_DATA0                    13

/* define device descriptor service key words. */
#define POS_DEVDESC_ID                    10
#define POS_DEVDESC_DATA0                 11
#define POS_DEVDESC_DATA1                 12
#define KNXMSG_DEVDESC_APDU_LEN           1
#define KNX_DEVDESC_MASK                  0x3F                           /* mask for getting the descriptor type. */

/* Authentification service key words.  */
#define KNX_AUTH_APDU_LEN                 6
#define POS_AUTH_FIX0                     11
#define POS_AUTH_LEVEL                    11
#define POS_AUTH_KEY0                     12
#define POS_AUTH_KEY1                     13
#define POS_AUTH_KEY2                     14
#define POS_AUTH_KEY3                     15

/* network parameter service key words. */
#define KNX_LINEST_APDU_LEN               5
#define KNX_SNA_APDU_LEN                  5
#define POS_NETPARA_OBJID_H               11
#define POS_NETPARA_OBJID_L               12
#define POS_NETPARA_PROPID                13
#define POS_NETPARA_TESTINFO              14
#define POS_NETPARA_VALUE                 14
#define POS_NETPARA_SNA_RESULT            15

/* define property service key words. */
#define KNXPRO_APDU_LEN                   5
#define KNXPRO_DESC_APDU_LEN              4
#define KNXPRO_RESP_FIXED_LEN             7
#define KNXPRO_DESC_RESP_LEN              8
#define POS_OBJECT_INDEX                  11
#define POS_PROP_ID                       12
#define POS_PROP_INDEX                    13
#define POS_ELEMENT_NUM                   13                             /* high 4 bits is the number. */
#define POS_ELEM_START_H                  13
#define POS_ELEM_START_L                  14                             /* low 8 bits of start index. */
#define POS_PROP_TYPE                     14
#define POS_MAX_NUM_ELEM_H                15
#define POS_ELEMENTS_0                    15
#define POS_MAX_NUM_ELEM_L                16
#define POS_ELEMENTS_1                    16
#define POS_PROP_ACCESS                   17
#define POS_ELEMENTS_2                    17
#define POS_ELEMENTS_3                    18
#define POS_ELEMENTS_4                    19
#define POS_ELEMENTS_5                    20
#define POS_ELEMENTS_6                    21
#define POS_ELEMENTS_7                    22
#define POS_ELEMENTS_8                    23
#define POS_ELEMENTS_9                    24
#define KNXPRO_ELEM_NUMB_MASK             0xF0
#define KNXPRO_STARTINDEX_HI_MASK         0x0F

#define POS_PROPFUNC_RETCODE              15        /* function's return code */
#define POS_PROPFUNC_SVRID                16        /* function's service id */
#define POS_PROPFUNC_SVRINFO0             17        /* function's service infomation */

/* define load control service key words. */
#define POS_LOAD_EVENT                    15
#define POS_SEGMENT_EVENT                 16

#define POS_START_ADDR_HI                 17
#define POS_START_ADDR_LO                 18
#define POS_SEG_LENGTH_HI                 19
#define POS_SEG_LENGTH_LO                 20
#define POS_SEG_ACCESS                    21
#define POS_SEG_MEM_TYPE                  22
#define POS_SEG_FLAGS                     23

#define POS_SEG_PTR_HI                    17
#define POS_SEG_PTR_LO                    18
#define POS_PEI_TYPE                      19
#define POS_MANFACT_HI                    20
#define POS_MANFACT_LO                    21
#define POS_APP_ID_HI                     22
#define POS_APP_ID_LO                     23
#define POS_APP_VERSION                   24

#define POS_APP_INIT_HI                   17
#define POS_APP_INIT_LO                   18
#define POS_APP_SAVE_HI                   19
#define POS_APP_SAVE_LO                   20
#define POS_SP_HANDER_HI                  21
#define POS_SP_HANDER_LO                  22

#define POS_INT_OB_PTR_HI                 17
#define POS_INT_OB_PTR_LO                 18
#define POS_INT_OB_COUNT                  19

#define POS_APP_CALLB_HI                  17
#define POS_APP_CALLB_LO                  18
#define POS_CO_DESCR_HI                   19
#define POS_CO_DESCR_LO                   20
#define POS_CO_SEG0_HI                    21
#define POS_CO_SEG0_LO                    22
#define POS_CO_SEG1_HI                    23
#define POS_CO_SEG1_LO                    24

#define POS_MCB_TYPE_OWNER                5
#define POS_MCB_CRC                       6

/* define property function service key word. */
#define KNXFUNC_APDU_LEN                  3
#define POS_PFUNC_ELEM_0                  13
#define POS_PFUNC_ELEM_1                  14
#define POS_PFUNC_ELEM_2                  15
#define POS_PFUNC_ELEM_3                  16
#define POS_PFUNC_ELEM_4                  17
#define POS_PFUNC_ELEM_5                  18
#define POS_PFUNC_ELEM_6                  19
#define POS_PFUNC_ELEM_7                  20
#define POS_PFUNC_ELEM_8                  21
#define POS_PFUNC_ELEM_9                  22

#define POS_FUNC_RETCODE                  13       /* the position of function's return code */
#define POS_FUNC_SVRID                    14       /* the position of function's ID */
#define POS_FUNC_SVRINFO0                 15       /* the position of function's service info */

#define CEMI_SVR_POS_MCODE                0        /* message code              */
#define CEMI_SVR_POS_OBJHI                1        /* object type high          */
#define CEMI_SVR_POS_OBJLW                2        /* object type low           */
#define CEMI_SVR_POS_OBJINDEX             3        /* object index              */
#define CEMI_SVR_POS_PROPID               4        /* property ID               */
#define CEMI_SVR_POS_ELEMCUNT             5        /* count of element          */
#define CEMI_SVR_POS_ELEMSTART            6        /* start position of element */
#define CEMI_SVR_POS_DATA0                7        /* the first data            */
#define CEMI_SVR_POS_PROPFUNC_RET         7        /* property func return position */
                                                   
#define CEMI_SVR_POS_FUNC_DATA0           5        /* first function data position     */
#define CEMI_SVR_POS_FUNC_RET             5        /* return code position of function */
#define CEMI_SVR_POS_FUNC_RET_DATA0       6        /* first data of function return.   */

/* define ADC service key words. */
#define KNX_ADC_APDU_LEN                  2
#define ADC_PORT_MASK                     0x3F

/* filter table parameters's position in the frame */
#define KNX_RTTABLE_APDU_LEN                 4
#define KNX_RTMEM_MAX_DATA                   21
#define KNX_RTFUNC_APDU_LEN                  1
#define POS_FILTER_LEN                       11       /* length position in the frame. */
#define POS_FILTER_FUNC                      11       /* function in the frame.        */
#define POS_FILTER_ADDH                      12       /* high address position in the frame. */
#define POS_FILTER_ADDL                      13       /* low address position in the frame. */
#define POS_FILTER_DATA0                     14       /* first data in the frame. */
#define POS_FILTER_DATA1                     15       /* first data in the frame. */
#define POS_FILTER_DATA2                     16       /* first data in the frame. */

/* network parameter service position in the frame. */
#define POS_NTWK_OBJID_H                     11       /* object id high byte in network parameter service. */
#define POS_NTWK_OBJID_L                     12       /* object id low byte position. */
#define POS_NTWK_PROP_ID                     13       /* property id position in this service. */
#define POS_NTWK_TEST_INFO                   14       /* test information. */

/* Bus monitor frame position definition. */
#define POS_MONIT_MSG_CODE                0        /* frome the KNX payload begine.      */
#define POS_MONIT_ADTNAL_LEN              1        /* position of additional length.     */
#define POS_MONIT_STS_TYPEID              2        /* Additional Info status type ID.    */
#define POS_MONIT_STS_LEN                 3        /* Additional Info status length.     */
#define POS_MONIT_STATUS                  4        /* Additional Info status data.       */
#define POS_MONIT_TIME_ID                 5        /* Additional Info time type ID.      */
#define POS_MONIT_TIME_LEN                6        /* Additional Info time length.       */
#define POS_MONIT_TIME_H                  7        /* Additional Info time data.         */
#define POS_MONIT_TIME_L                  8       
#define POS_MONIT_RAW_CTRL                9        /* Bus monitor's raw frame's contorl. */
#define KNX_MAX_PROP_VALUE_LEN            10       /* Max. length of frame op-data. */


/* Mask for getting the first 2 bits of APCI. */
#define HIGH_APCI_2BITS_MASK              0x03

#define KNX_STANDARD_FRAME_MAX_LEN   22     /* max. standard frame length excluding checksum. */
#define KNX_STANDARD_BUFFER_MAX_LEN  25     /* Max. standard buffer length exluding checksum. */

/* standard frame address type mask. */
#define KNX_FRAME_P2P_MASK           0x80   /* Address type,Bit7(AT):0-Phy/1Gr. */
#define KNX_STANDARD_ADDR_TYPE_MASK  0x80   /* Address type,Bit7(AT):0-Phy/1Gr. */
#define KNX_STANDARD_FRAME_P2P       0x00
#define KNX_STANDARD_FRAME_GRP       0x80
/* Extended frame address type mask. */
#define KNX_EXTENDED_ADDR_TYPE_MASK 0x8c    /* Address type,bit7(AT):0-Phy/1-gr bit2:1 */
#define KNX_EXTENDED_FRAME_P2P       0x00    /* extended frame with individual address */
#define KNX_EXTENDED_FRAME_GRP       0x80    /* extended frame with group address      */
#define KNX_EXTENDED_FRAME_LTE       0x84    /* LTE frame                              */
/* repeat. */
#define KNX_FRAME_REPT_MASK          0x20   /* repeat frame flag mask. */
#define KNX_FRAME_NOT_REPEAT_FLAG    0x20   /* Not a repeat frame.     */
/* priority */
#define KNX_FRAME_PRIORITY_MASK      0x0C   /* priority mask. */
#define KNX_FRAME_PRIORITY_SYS       0x00   /* system priority. */
#define KNX_FRAME_PRIORITY_URG       0x08   /* urgent priority. */
#define KNX_FRAME_PRIORITY_NRM       0x04   /* normal priority. */
#define KNX_FRAME_PRIORITY_LOW       0x0C   /* low priority.    */
#define CTRL_ERROR                   0x01   /* control error bit. */

#define KNXMSG_MEM_READ_APDU_LEN     3

/**********链路层相关定义***************/
/* Frame ex/std type mask */
#define LL_FRAME_TYPE_MASK          0xD3    /* 1101 1100 */
#define LL_FRAME_STANDARD_MASK       0x90    /* standard frame mask.    */
#define LL_FRAME_EXTENDED_MASK       0x10    /* extended frame mask.    */
/* Assemble frame type */
#define LL_FRAME_TYPE_FLAG_MASK      0x30                                                /* mask for frame detail. */
#define LL_FRAME_STANDARD_FLG        0x10
#define LL_FRAME_EXTENDED_FLG        0x20
#define LL_STANDARD_P2P_FRAME        (KNX_STANDARD_FRAME_P2P | LL_FRAME_STANDARD_FLG)    /* 0x10:P2P standard frame.  Bit7:0-Phy,Bit5Bit4:01-Standard. */
#define LL_STANDARD_GRP_FRAME        (KNX_STANDARD_FRAME_GRP | LL_FRAME_STANDARD_FLG)    /* 0x90:Group standard frame.Bit7:1-Grp,Bit5Bit4:01-Standard. */
#define LL_EXTENDED_P2P_FRAME        (KNX_EXTENDED_FRAME_P2P | LL_FRAME_EXTENDED_FLG)    /* 0x20:P2P extended frame.  Bit7:0-Phy,Bit5Bit4:10-Extended. */
#define LL_EXTENDED_GRP_FRAME        (KNX_EXTENDED_FRAME_GRP | LL_FRAME_EXTENDED_FLG)    /* 0xA0:Group extended frame.Bit7:1-Grp,Bit5Bit4:10-Extended. */
#define LL_EXTENDED_LTE_FRAME        (KNX_EXTENDED_FRAME_LTE | LL_FRAME_EXTENDED_FLG)    /* 0xA4:LTE extended frame.             */
#define LL_FRAME_ADDR_TYPE_MASK      0x80                                                /* Bit7:0-Phy,1-Grp                     */
#define LL_UNKNOWN_FRAME             (0xFF)                                              /* Unknown frame.                       */
#define LL_REASSEMBLE_DESTADDR_TYPE  (0x00020000)

/* Getting frames key words. */
#define GET_DESTI_ADDR(pucPayload)       ((pucPayload[POS_DES_ADDR_H]<<8)|pucPayload[POS_DES_ADDR_L])
#define GET_DEST_ADDR_H(pucPayload)      (pucPayload[POS_DES_ADDR_H])
#define GET_DEST_ADDR_L(pucPayload)      (pucPayload[POS_DES_ADDR_L])
#define GET_HOP_CUNT(pucPayload)         (pucPayload[POS_EX_CONTROL] & 0x70)
#define HOP_CUNT_SUB_1(pucPayload)       (pucPayload[POS_EX_CONTROL] -= 0x10)
#define HOP_CUNT_ADD_1(pucPayload)       (pucPayload[POS_EX_CONTROL] += 0x10)
#define GET_SRC_ADDR(pucPayload)         ((pucPayload[POS_SRC_ADDR_H]<<8)|pucPayload[POS_SRC_ADDR_L])
#define GET_SRC_ADDR_H(pucPayload)       (pucPayload[POS_SRC_ADDR_H])
#define GET_SRC_ADDR_L(pucPayload)       (pucPayload[POS_SRC_ADDR_L])
#define GET_FRAME_TPDU(pucPayload)       (pucPayload[POS_TPDU_APCI])
#define GET_10BITS_APCI(pucPayload)      (((pucPayload[POS_TPDU_APCI] & HIGH_APCI_2BITS_MASK)<<8)|((pucPayload[POS_APCI_DATA0]<APCI_ESCAPE)?(pucPayload[POS_APCI_DATA0]&APCI_MASK):pucPayload[POS_APCI_DATA0]))
#define GET_4BITS_APCI(pucPayload)       (((pucPayload[POS_TPDU_APCI] & HIGH_APCI_2BITS_MASK)<<8)|(pucPayload[POS_APCI_DATA0] & 0xC0))
#define GET_APDU_LENGTH(pucPayload)      (pucPayload[POS_DATA_LENGTH])
#define GET_PRIORITY_CLASS(pucPayload)   (pucPayload[POS_CONTROL] & KNX_FRAME_PRIORITY_MASK)

/* property service. */
#define GET_PROP_NO_OF_ELEM(pucPayload)  (pucPayload[POS_ELEMENT_NUM] >> 4)
#define GET_PROP_START_INDEX(pucPayload) (((WORD16)(pucPayload[POS_ELEM_START_H] & KNXPRO_STARTINDEX_HI_MASK) << 8) + pucPayload[POS_ELEM_START_L])
#define GET_PROP_READ_ACCESS(ucAcc)      ((ucAcc & 0xF0) >> 4)
#define GET_PROP_WRITE_ACCESS(ucAcc)     (ucAcc & 0x0F)

#define GET_LOCAL_PROP_NO_OF_ELEM(pucPayload)  (pucPayload[CEMI_SVR_POS_ELEMCUNT]>>4)
#define GET_LOCAL_PROP_START_INDEX(pucPayload) (((WORD16)(pucPayload[CEMI_SVR_POS_ELEMCUNT] & KNXPRO_STARTINDEX_HI_MASK)<<8)+pucPayload[CEMI_SVR_POS_ELEMSTART])

#ifdef __cplusplus
}
#endif

#endif /* _KNX_FRAME_H_ */


// _KNX_FRAME_H_

