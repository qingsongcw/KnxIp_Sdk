


#ifndef _KNX_AL_H_
#define _KNX_AL_H_

#ifdef __cplusplus
extern "C" {
#endif


/* APCI information define. */
#define AL_GROUP_VAL_READ                     0x0000        /* 00 0000 0000 */
#define AL_GROUP_VAL_RESP                     0x0040        /* 00 0100 0000 */
#define AL_GROUP_VAL_WRITE                    0x0080        /* 00 1000 0000 */

#define AL_PHY_ADDR_WRITE                     0x00C0        /* 00 1100 0000 */
#define AL_PHY_ADDR_READ                      0x0100        /* 01 0000 0000 */
#define AL_PHY_ADDR_RESP                      0x0140        /* 01 0100 0000 */

#define AL_ADC_READ                           0x0180        /* 01 1000 0000 */
#define AL_ADC_RESP                           0x01C0        /* 01 1100 0000 */

#define AL_MEMORY_READ                        0x0200        /* 10 0000 0000 */
#define AL_MEMORY_RESP                        0x0240        /* 10 0100 0000 */
#define AL_MEMORY_WRITE                       0x0280        /* 10 1000 0000 */

#define AL_USER_MSG                           0x02C0        /* 10 1100 0000 */
#define AL_USER_MEM_READ                      0x02C0        /* 10 1100 0000 */
#define AL_USER_MEM_RESP                      0x02C1        /* 10 1100 0001 */
#define AL_USER_MEM_WRITE                     0x02C2        /* 10 1100 0010 */
#define AL_USER_MEM_BIT_WRITE                 0x02C4        /* 10 1100 0100 */

#define AL_USER_FACTORY_INFO_READ             0x02C5        /* 10 1100 0101 */
#define AL_USER_FACTORY_INFO_RESP             0x02C6        /* 10 1100 0110 */

#define AL_FUNC_COMMAND                       0x02C7        /* 10 1100 0111 */
#define AL_FUNC_STAT_READ                     0x02C8        /* 10 1100 1000 */
#define AL_FUNC_STAT_RESP                     0x02C9        /* 10 1100 1001 */

#define AL_USER_MSG_RESERVED_START            0x02CA        /* 10 1100 1010 */
#define AL_USER_MSG_RESERVED_END              0x02F7        /* 10 1111 0111 */

#define AL_USER_MSG_MANUFACT_START            0x02F8        /* 10 1111 1000 */
#define AL_USER_MSG_MANUFACT_END              0x02FE        /* 10 1111 1110 */

#define AL_DEV_DESCRIPTOR_READ                0x0300        /* 11 0000 0000 */
#define AL_DEV_DESCRIPTOR_RESP                0x0340        /* 11 0100 0000 */
#define AL_RESTART                            0x0380        /* 11 1000 0000 */

#define AL_OPEN_RTTABLE_REQ                   0x03C0        /* 11 1100 0000 */
#define AL_READ_RTTABLE_REQ                   0x03C1        /* 11 1100 0001 */
#define AL_READ_RTTABLE_RESP                  0x03C2        /* 11 1100 0010 */
#define AL_WRITE_RTTABLE_REQ                  0x03C3        /* 11 1100 0011 */
#define AL_READ_RTMEM_REQ                     0x03C8        /* 11 1100 1000 */
#define AL_OPEN_RTMEM_RESP                    0x03C9        /* 11 1100 1001 */
#define AL_WRITE_RTMEM_REQ                    0x03CA        /* 11 1100 1010 */
#define AL_READ_RTSTATUS_REQ                  0x03CD        /* 11 1100 1101 */
#define AL_READ_RTSTATUS_RESP                 0x03CE        /* 11 1100 1110 */
#define AL_WRITE_RTSTATUS_REQ                 0x03CF        /* 11 1100 1111 */

#define AL_MEMORY_BIT_WRITE                   0x03D0        /* 11 1101 0000 */
#define AL_AUTHORIZE_REQ                      0x03D1        /* 11 1101 0001 */
#define AL_AUTHORIZE_RES                      0x03D2        /* 11 1101 0010 */
#define AL_KEY_WRITE_REQ                      0x03D3        /* 11 1101 0011 */
#define AL_KEY_WRITE_RES                      0x03D4        /* 11 1101 0100 */

#define AL_PROP_VALUE_READ                    0x03D5        /* 11 1101 0101 */
#define AL_PROP_VALUE_RESP                    0x03D6        /* 11 1101 0110 */
#define AL_PROP_VALUE_WRITE                   0x03D7        /* 11 1101 0111 */
#define AL_PROP_DESC_READ                     0x03D8        /* 11 1101 1000 */
#define AL_PROP_DESC_RESP                     0x03D9        /* 11 1101 1001 */

#define AL_NET_PARAM_READ                     0x03DA        /* 11 1101 1010 */
#define AL_NET_PARAM_READ_RESP                0x03DB        /* 11 1101 1011 */
#define AL_NET_PARAM_WRITE                    0x03E4        /* 11 1110 0100 */

#define AL_PHY_ADDR_SER_NUM_READ              0x03DC        /* 11 1101 1100 */
#define AL_PHY_ADDR_SER_NUM_RESP              0x03DD        /* 11 1101 1101 */
#define AL_PHY_ADDR_SER_NUM_WRITE             0x03DE        /* 11 1101 1110 */

#define AL_SERV_INFO_WRITE                    0x03DF        /* 11 1101 1111 */

#define AL_DOMAINADDR_WRITE                   0x03E0        /* 11 1110 0000 */
#define AL_DOMAINADDR_READ                    0x03E1        /* 11 1110 0001 */
#define AL_DOMAINADDR_RESP                    0x03E2        /* 11 1110 0010 */
#define AL_DOMAINADDR_SELECTIVE_READ          0x03E3        /* 11 1110 0011 */

#define AL_LINK_READ                          0x03E5        /* 11 1110 0101 */
#define AL_LINK_RESP                          0x03E6        /* 11 1110 0110 */
#define AL_LINK_WRITE                         0x03E7        /* 11 1110 0111 */

#define AL_GROUP_PROP_VALUE_READ              0x03E8        /* 11 1110 1000 */
#define AL_GROUP_PROP_VALUE_RESP              0x03E9        /* 11 1110 1001 */
#define AL_GROUP_PROP_VALUE_WRITE             0x03EA        /* 11 1110 1010 */
#define AL_GROUP_PROP_VALUE_INFO              0x03EB        /* 11 1110 1011 */

/* we do not support system broadcast,so in p2p condition,
   if (APCI >= 0x02C0)
      we confirm that APCI has 10 bits.
   else 
      APCI has 4bits. */
#define AL_P2P_APCI_UP4_ESC                   0x02C0        /* 10 11 00 0000 */

#define DEV_DESCRIPTOR_TYPE                   0x00
#define DEV_DESC_ERROR                        0x3F
#define APCI_ESCAPE                           0xC0
#define APCI_MASK                             0xF0



#ifdef __cplusplus
}
#endif

#endif /* _KNX_AL_H_ */



/* End of file */

