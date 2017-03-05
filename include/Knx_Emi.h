


#ifndef _KNX_SERVICE_H_
#define _KNX_SERVICE_H_

#ifdef __cplusplus
extern "C" {
#endif


/* Destinations of EMI2 codes */
#define EMI2_DEST_MASK                 0xF0        /* Mask to retrieve the destination          */
#define EMI2_DEST_RES_1                0x00        /* Reserved                                  */
#define EMI2_DEST_LL                   0x10        /* Link layer                                */
#define EMI2_DEST_NL                   0x20        /* Network layer                             */
#define EMI2_DEST_TLG                  0x30        /* Transport layer group and poll data       */
#define EMI2_DEST_TLC                  0x40        /* Transport layer device and broadcast data */
#define EMI2_DEST_PLG                  0x50        /* Unused                                    */
#define EMI2_DEST_PLC                  0x60        /* Unused                                    */
#define EMI2_DEST_AL                   0x70        /* Application layer group and poll data     */
#define EMI2_DEST_MGM1                 0x80        /* Management                                */
#define EMI2_DEST_MGM2                 0x90        /* Management                                */
#define EMI2_DEST_PEI                  0xA0        /* PEI (unused here)                         */
#define EMI2_DEST_DBG                  0xB0        /* Debug (unused here)                       */
#define EMI2_DEST_TIMER                0xC0        /* Timer (unused here)                       */
#define EMI2_DEST_USER_1               0xD0        /* User                                      */
#define EMI2_DEST_USER_2               0xE0        /* User                                      */
#define EMI2_DEST_MGM_F                0xF0        /* cEmi management.                          */


/*                                          EMI2     CEMI           IMI1 EMI1*/ 
#define KNX_PRTCL_SRV_MASK                 0xF0   /* EMI service mask.       */

#define EMI2_L_DATA_REQ                    0x11   /* 11H            11H  11H */ 
#define EMI2_PH_DATA_REQ                   0x01   /* -               -    -  */ 
#define EMI2_PH_DATA_CON                   0x1E   /* -               -    -  */ 
#define EMI2_PH_DATA_IND                   0x19   /* -               -    -  */ 
#define EMI2_L_SYSBROADCAST_REQ            0x17   /* -              15H  15H */ 
#define EMI2_L_PLAIN_DATA_REQ              0x10   /* -               -   -   */ 
#define EMI2_L_POLL_DATA_REQ               0x13   /* 13H             -   -   */ 

#define EMI2_L_DATA_CON                    0x2E   /* 2EH            2EH  4EH */ 
#define EMI2_L_DATA_IND                    0x29   /* 29H            29H  49H */ 
#define EMI2_N_DATA_INDIVL_REQ             0x21   /* -               -   -   */ 
#define EMI2_N_DATA_GROUP_REQ              0x22   /* -               -   -   */ 
#define EMI2_N_DATA_BROADCAST_REQ          0x2C   /* -               -   -   */ 
#define EMI2_N_POLL_DATA_REQ               0x23   /* -               -   -   */ 
#define EMI2_L_BUSMON_IND                  0x2B   /* 2BH            29H  49H */ 
#define EMI2_L_SYSBROADCAST_CON            0x26   /* -              2CH  4CH */ 
#define EMI2_L_SYSBROADCAST_IND            0x28   /* -              2DH  4DH */ 
#define EMI2_L_POLL_DATA_CON               0x25   /* 25H             -   -   */ 
#define EMI2_L_METER_INDB                  0x24   /* -               -   -   */ 

#define EMI2_N_DATA_GROUP_CON              0x3E   /* -               -   -   */ 
#define EMI2_N_DATA_GROUP_IND              0x3A   /* -               -   -   */ 
#define EMI2_T_DATA_GROUP_REQ              0x32   /* -              22H  22H */ 
#define EMI2_N_POLL_DATA_CON               0x35   /* -               -   -   */ 
#define EMI2_T_POLL_DATA_REQ               0x33   /* -              -    -   */ 

#define EMI2_N_DATA_INDIVL_CON             0x4E   /* -               -   -   */ 
#define EMI2_N_DATA_INDIVL_IND             0x49   /* -               -   -   */ 
#define EMI2_N_DATA_BROADCAST_CON          0x4F   /* -               -   -   */ 
#define EMI2_N_DATA_BROADCAST_IND          0x4D   /* -               -   -   */ 
#define EMI2_T_CONNECT_REQ                 0x43   /* -              23H  23H */ 
#define EMI2_T_DISCONNECT_REQ              0x44   /* -              24H  24H */ 
#define EMI2_T_DATA_CNECTED_REQ            0x41   /* 41H            21H  21H */ 
#define EMI2_T_DATA_INDIVL_REQ             0x4A   /* 4AH            2AH  2AH */ 
#define EMI2_T_DATA_BROADCAST_REQ          0x4C   /* -              2BH  2BH */ 

#define EMI2_U_VALUE_WRITE_REQ             0x71   /* -              36H  36H */ 
#define EMI2_A_POLL_DATA_REQ               0x73   /* -              -    -   */ 
#define EMI2_U_VALUE_READ_REQ              0x74   /* -              35H  35H */ 
#define EMI2_U_FLAGS_READ_REQ              0x7C   /* -              37H  37H */ 
#define EMI2_T_POLL_DATA_CON               0x75   /* -              -    -   */ 
#define EMI2_A_DATA_GROUP_REQ              0x72   /* -              -    -   */ 
#define EMI2_T_DATA_GROUP_IND              0x7A   /* -              3AH  4AH */ 
#define EMI2_T_DATA_GROUP_CON              0x7E   /* -              3EH  4EH */ 

#define EMI2_M_USER_DATA_INDIVL_REQ        0x81   /* -              -    -   */ 
#define EMI2_M_USER_DATA_CNECTED_REQ       0x82   /* -              31H  31H */ 
#define EMI2_T_CONNECT_CON                 0x86   /* -               -   -   */ 
#define EMI2_T_CONNECT_IND                 0x85   /* -              33H  43H */ 
#define EMI2_T_DISCONNECT_CON              0x88   /* -               -   -   */ 
#define EMI2_T_DISCONNECT_IND              0x87   /* -              34H  44H */ 
#define EMI2_T_DATA_CNECTED_CON            0x8E   /* -               -   -   */ 
#define EMI2_T_DATA_CNECTED_IND            0x89   /* 89H            39H  49H */ 
#define EMI2_T_DATA_BROADCAST_CON          0x8F   /* -               -   -   */ 
#define EMI2_T_DATA_BROADCAST_IND          0x8D   /* -              38H  48H */ 

#define EMI2_T_DATA_INDIVL_CON             0x9C   /* -              3FH  4FH */ 
#define EMI2_T_DATA_INDIVL_IND             0x94   /* 94H            32H  42H */ 
#define EMI2_M_INTERFACEOBJ_DATA_REQ       0x9A   /* -              -    -   */ 

#define EMI2_PC_SET_VALUE_REQ              0xA6   /* -              46H  46H */ 
#define EMI2_PC_GET_VALUE_REQ              0xAC   /* -              4CH  4CH */ 
#define EMI2_PC_GET_VALUE_CON              0xAB   /* -              4BH  4BH */ 
#define EMI2_PEI_IDENTIFY_REQ              0xA7   /* -              -     -  */ 
#define EMI2_PEI_IDENTIFY_CON              0xA8   /* -              -     -  */ 
#define EMI2_PEI_SWITCH_REQ                0xA9   /* -              -     -  */ 

#define EMI2_TM_TIMER_IND                  0xC1   /* -              -     -  */ 

#define EMI2_M_CONNECT_IND                 0xD5   /* -              -    -   */ 
#define EMI2_M_DISCONNECT_IND              0xD7   /* -              -    -   */ 
#define EMI2_M_USER_DATA_CNECTED_CON       0xD1   /* -              -    -   */ 
#define EMI2_M_USER_DATA_CNECTED_IND       0xD2   /* -              59H  49H */ 
#define EMI2_M_USER_DATA_INDIVL_CON        0xDE   /* -              -    -   */ 
#define EMI2_M_USER_DATA_INDIVL_IND        0xD9   /* -              -    -   */ 
#define EMI2_M_INTERFACEOBJ_DATA_CON       0xDC   /* -              -    -   */ 
#define EMI2_M_INTERFACEOBJ_DATA_IND       0xD4   /* -              -    -   */ 

#define EMI2_A_DATA_GROUP_CON              0xEE   /* -              -    -   */ 
#define EMI2_A_DATA_GROUP_IND              0xEA   /* -              -    -   */ 
#define EMI2_A_POLL_DATA_CON               0xE5   /* -              -    -   */ 
#define EMI2_U_VALUE_READ_CON              0xE4   /* -              55H  45H */ 
#define EMI2_U_FLAGS_READ_CON              0xEC   /* -              57H  47H */ 
#define EMI2_U_EVENT_IND                   0xE7   /* -              5DH  4DH */ 

#define CEMI_L_RAW_REQ                     0x10   /*                -    -   */ 
#define CEMI_L_RAW_IND                     0x2D   /*                -    -   */ 
#define CEMI_L_RAW_CON                     0x2F   /*                -    -   */ 

#define CEMI_M_PROPREAD_REQ                0xFC   /*                -    -   */ 
#define CEMI_M_PROPREAD_CON                0xFB   /*                -    -   */ 
#define CEMI_M_PROPWRITE_REQ               0xF6   /*                -    -   */ 
#define CEMI_M_PROPWRITE_CON               0xF5   /*                -    -   */ 
#define CEMI_M_PROPINFO_IND                0xF7   /*                -    -   */ 
#define CEMI_M_FUNCPROPCMD_REQ             0xF8   /*                -    -   */ 
#define CEMI_M_FUNCPROPSTATEREAD_REQ       0xF9   /*                -    -   */ 
#define CEMI_M_FUNCPROPCMD_CON             0xFA   /*                -    -   */ 
#define CEMI_M_FUNCPROPSTATEREAD_CON       0xFA   /*                -    -   */ 
#define CEMI_M_RESET_REQ                   0xF1   /*                -    -   */ 
#define CEMI_M_RESET_IND                   0xF0   /*                -    -   */ 

/* Additional information define. */
#define CEMI_ADDINFO_BMSTS_ID              0x03   /* Busmonitor Error Flags */
#define CEMI_ADDINFO_TIME_ID               0x04   /* Relative timestamp     */
#define CEMI_ADDINFO_EXTIME_ID             0x06   /* Device independent time stamp */

#define CEMI_ADDINFO_TIME_LEN              2      /* Relative timestamp length. */
#define CEMI_ADDINFO_EXTIME_LEN            4      /* Device independent time stamp length. */
#define CEMI_ADDINFO_BMSTS_LEN             1      /* Busmonitor Error Flags length. */


/* error code. */
#define E_CEMI_SVR_UNKNOWN                   0x00  /* Unspecified Error       */
#define E_CEMI_SVR_OUT_OF_RANGE              0x01  /* Out of Range            */
#define E_CEMI_SVR_OUTMAX_RANGE              0x02  /* Out of MaxRange         */
#define E_CEMI_SVR_OUTMIN_RANGE              0x03  /* Out of MinRange         */
#define E_CEMI_SVR_MEM                       0x04  /* Memory Error            */
#define E_CEMI_SVR_READ_ONLY                 0x05  /* Read Only               */
#define E_CEMI_SVR_WRONG_CMD                 0x06  /* Illegal COMMAND         */
#define E_CEMI_SVR_NONE_PROPERTY             0x07  /* Void DP                 */
#define E_CEMI_SVR_DATA_TYPE                 0x08  /* Type Conflict           */
#define E_CEMI_SVR_PROP_INDEX                0x09  /* Prop. Index Range Error */
#define E_CEMI_SVR_NOT_WRITEABLE_TEMP        0x0A  /* Value temporarily not writeable */

#define CEMI_LOACL_OPERATION                 0x01  /* local operation flag. */
#define EMI_REMOTE_OPERATION                 0x00  /* remote operation flag. */

#define CEMI_CTRL1_FT_MASK                   0x80  /* cEmi ctrl1 Ft mask.0-extend,1-std. */
#define CEMI_CTRL1_RPT_MASK                  0x20  /* cEmi ctrl1 Rpt mask,0-rpt,1-do not rpt.*/
#define CEMI_CTRL1_SB_MASK                   0x10  /* cEmi ctrl1 SB mask,0-sys brd,1-brd. */
#define CEMI_CTRL1_PRO_MASK                  0x0C  /* cEmi ctrl1 Priority mask. */
#define CEMI_CTRL1_ACK_MASK                  0x02  /* cEmi ack mask. 0-no ack is req,1-req ack.*/
#define CEMI_CTRL1_CONF_MASK                 0x01  /* cEmi confirm mask,0-no error,1-error. */



#ifdef __cplusplus
}
#endif

#endif /* _KNX_SERVICE_H_ */




// _KNX_SERVICE_H_ END

