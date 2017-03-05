/*****************************************************************************************
* (C) Copyright 2017 .
*
* File Name        : KnxIp_Sdk_Demo.c
*
* File Description : this file shows how to use KnxIp SDK. You can reference this file to 
                     creat your own application file.
*
* Other Description: this file is base on window OS.
*
* Version          : 1.00
*
* Author           : 
*
* Data             : 2017.3.1
*
* Modification Rec.:
*   Modify Data    : 2017.3.1
*   Operator       :
*   Version        : 1.00
*   Action         : Creation.
*
*****************************************************************************************/

/* you can include your own header file here. */

#include "type_def.h"          /* common data type define.           */
#include "configure.h"         /* application configuration file.    */
#include "pub.h"               /* public macro or data define.       */
#include "buffer.h"            /* SDK buffer pool management define. */
#include "Knx_Msg.h"           /* message handling define.           */
#include "KnxIp_Ll.h"          /* link layer data define.            */
#include "KnxIp_Msg.h"         /* knxip message handling define.     */
#include "KnxIp_core.h"        /* knxip core handling define.        */

/* define global variables. */
SOCKET g_atSock[4]={0,0,0,0};       /* we need 4 sockets used for ethernet data transceiving.
                                      [0]:for knx system multicast;
                                      [1]:for data point;
                                      [2]:for control point;
                                      [3]:for project define multicast,if only use knx system multicast,this socket may not be creat. */
WORD32 g_dw50MsCounter = 0;         /* 50ms timer counter.SDK needs a timer to get time for management.so the application software need 
                                       to creat a timer for timing.this variable used to count the timer period. */
int  g_i50MsTimerId    = 0;         /* ID for 50ms timer. */
int  g_i100MsTimerId   = 0;         /* ID for 100ms timer. this timer used for calling SDK periodically. */

static T_INTERFACE_INFO *g_ptKnxIpInterFaceInfo = NULL; /* for saving the searching information of knxip router. */



/*** Step 1 ******************************  configure some parameters ************************************/

/* In file configure.h
(1) define MCU_SIZE               : setting this macro value according to the CPU.
(2) define MAX_KNX_APP_CMD_NUM    : SDK have a command queue,it keeps the command sent by application.this macro
                                    defines the max. number of the command can be kept by SDK.
(3) define TOTAL_BUFFER_SIZE      : SDK have a buffer pool used for frames handling.this macro defines the memory
                                    size used by buffer pool.
(4) define KNX_IPV4_CTRL_ENDPOINT : KnxIp control point's port number used for connection management.this port number
                                    can be defined in static way by setting this macro value.application software can
                                    also generate a control point's port number dynamically.
(5) define KNX_IPV4_DATA_ENDPOINT : KnxIp data point's port number used for communication object data transceiving,this
                                    port number can be defined in static way by setting this macro value.application 
                                    software can also generate a data point's port number dynamically.
(6) define KNX_USER_MUL_ADDR      : this macro defines the practical used ethernet multicast address,application can
                                    get the practical multicast address dynamically.
*/


/*** Step 2 ******************************  creat some necessary functions ************************************/

/*****************************************************************************************************
* function name   : void CALLBACK Timer50Ms_Count(UINT uId,UINT uMsg,DWORD dUser,DWORD dW1,DWORD dW2)
* Description     : the function entry of 50ms timer task.it will count the 50ms period time.
* Input parameter : this function need no parameter.
* Output parameter: no.
* Return          : no.
* Other description: it will be called periodically by 50ms timer.
* Modify date     Ver.     Modifier      Action
* ----------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
void CALLBACK Timer50Ms_Count(UINT uId,UINT uMsg,DWORD dUser,DWORD dW1,DWORD dW2)
{
    g_dw50MsCounter++;        /* count the 50ms period time. */
}

/*****************************************************************************************************
* function name   : void CALLBACK KnxIpSdk_Process(UINT uId,UINT uMsg,DWORD dUser,DWORD dW1,DWORD dW2)
* Description     : SDK process task.this function will call the SDK entry to start the SDK function.
* Input parameter : do not need parameters.
* Output parameter: no.
* Return          : no.
* Other description: it will be called periodically by 100ms timer.
* Modify date     Ver.     Modifier      Action
* ----------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
void CALLBACK KnxIpSdk_Process(UINT uId,UINT uMsg,DWORD dUser,DWORD dW1,DWORD dW2)
{
    Main_MsgProcess();         /* SDK entry in sdk library. */
}

/*****************************************************************************************************
* function name   : void App_Creat_50Ms_Task(void)
* Description     : this function creat the 50ms timer and start the 50ms counting task.
* Input parameter : no.
* Output parameter: no.
* Return          : no.
* Other description:
* Modify date     Ver.     Modifier      Action
* ----------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
void App_Creat_50Ms_Task(void)
{
    if(0 == g_i50MsTimerId)
    {
        g_i50MsTimerId = timeSetEvent(50,1,Timer50Ms_Count,0,TIME_PERIODIC);  /* creat a 50ms period task,it will call Timer50Ms_Count periodically. */
    }
}

/*****************************************************************************************************
* function name   : void App_Creat_Sdk_Task(void)
* Description     : this function creat SDK task running in 100ms period.
* Input parameter : no.
* Output parameter: no.
* Return          : no.
* Other description:
* Modify date     Ver.     Modifier      Action
* -----------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
void App_Creat_Sdk_Task(void)
{
    if(0 == g_i100MsTimerId)
    {
        g_i100MsTimerId = timeSetEvent(100,1,KnxIpSdk_Process,0,TIME_PERIODIC); /* creat a 100ms period task,it will call KnxIpSdk_Process perildically. */
    }
}

/*****************************************************************************************************
* function name   : WORD32 App_Get_Time(void)
* Description     : this function returns the time in ms.
* Input parameter : no.
* Output parameter: no.
* Return          : WORD32 : the current time in ms.
* Other description: SDK needs to get time to calculate the relative time difference.this function can
                     get the time starting from the application software initialization.
                     this function will be register into SDK by application software.
* Modify date     Ver.     Modifier      Action
* ----------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
WORD32 App_Get_Time(void)
{
    return (g_dw50MsCounter * 50);       /* need not to consider the data overflow. */
}

/*****************************************************************************************************
* function name   : WORD32 App_Get_TimeDelayMs(WORD32 dwOldTm)
* Description     : this function returns the time difference between the dwOldTm and the current time.
* Input parameter : WORD32 dwOldTm : the old time.
* Output parameter: no.
* Return          : WORD32 : time difference.
* Other description: this function will be register into SDK by application software.
* Modify date     Ver.     Modifier      Action
* ----------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
WORD32 App_Get_TimeDelayMs(WORD32 dwOldTm)
{
    WORD32 dwTm,dwTimDif;

    dwTm = g_dw50MsCounter * 50;                         /* calculate the current time. */
    if(dwTm >= dwOldTm)                                  /* whether time is overflow ? */
    {
        dwTimDif = (dwTm - dwOldTm);
    }
    else
    {
        dwTimDif = 0xffffffff - dwOldTm + dwTm + 1;
    }
    
    return dwTimDif;
}

/*****************************************************************************************************
* function name   : WORD16 App_Socket_Rx(BYTE ucSckNo,BYTE *pucBuffer)
* Description     : socket data receive function designed by application.
* Input parameter : BYTE ucSckNo    : socket index of g_atSock.
                    BYTE *pucBuffer : pointer of data buffer for saving data.
* Output parameter: no.
* Return          : WORD16 : the length of received data as byte.0 means that there is no data recevied.
* Other description:this function will be registered into SDK by application software.SDK will get the
                    ethernet frames by calling this function.
* Modify date     Ver.     Modifier      Action
* ---------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
WORD16 App_Socket_Rx(BYTE ucSckNo,BYTE *pucBuffer)
{
    WORD16 wLength = 0;

    if(0 != g_atSock[ucSckNo])                                                                      /* if the socket was created. */
    {
        wLength = (WORD16)recvfrom(g_atSock[ucSckNo],(char*)pucBuffer,KNX_MSG_BUFFER_SIZE,0,NULL,0);/* call recvfrom function to get ethernet frame. socket works in nonblock. */
    }

    return wLength;
}

/***************************************************************************************************************
* function name   : WORD16 App_Socket_Tx(BYTE ucSckNo,BYTE *pucBuffer,WORD16 wLength)
* Description     : socket data transmit fucntion designed by application.
* Input parameter : BYTE ucSckNo    : socket index of g_atSock.
                    BYTE *pucBuffer : pointer of data buffer for transmited data.
                    WORD16 wLength  : the length of transmited data as byte.
* Output parameter: no.
* Return          : WORD16 : the length of transmited data as byte.0 means that transmit is failed.
* Other description:(1)this function will be registered into SDK by application software.SDK will send
                       ethernet frames by calling this funcion.
                    (2)pucBuffer points to the payload of a frame waiting to be send.the destination
                       IP address and destination port number can be get according to the follow specification.
                       The example IP address is "192.168.10.100",port number is 0x0e57
                           *(pucBuffer-6) = 192;
                           *(pucBuffer-5) = 168;
                           *(pucBuffer-4) = 10;
                           *(pucBuffer-3) = 100;
                           *(pucBuffer-2) = 0x0e;
                           *(pucBuffer-1) = 0x57;
* Modify date     Ver.     Modifier      Action
* -------------------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
***************************************************************************************************************/
WORD16 App_Socket_Tx(BYTE ucSckNo,BYTE *pucBuffer,WORD16 wLength)
{
    BYTE *pucIpData = pucBuffer - 6;
    WORD16 wSendLen = 0,wPort;
    WORD32 dwIp;
    struct sockaddr_in tDestAddr;
    int iLen = sizeof(struct sockaddr_in);

    if(0 == g_atSock[ucSckNo])                            /* if the socket was created. */
    {
        return wSendLen;
    }
    wPort = (*(pucBuffer-2) << 8) + *(pucBuffer-1);       /* make the destination port number. */
    dwIp  = (*(pucIpData+3)<<24);                         /* make the destination IP address.  */
    dwIp += (*(pucIpData+2)<<16);
    dwIp += (*(pucIpData+1)<<8);
    dwIp += *(pucIpData);
    tDestAddr.sin_family      = AF_INET;                  /* set socket send parameters. */
    tDestAddr.sin_port        = htons(wPort);
    tDestAddr.sin_addr.s_addr = dwIp;
    wSendLen = (WORD16)sendto(g_atSock[ucSckNo],(char*)pucBuffer,wLength,0,(struct sockaddr *)&tDestAddr,iLen);    /* call sendto function to send data. */

    return wSendLen;
}

/*****************************************************************************************************
* function name   : WORD32 App_CallBack(T_KNX_CORE_EVENT *ptEvent)
* Description     : application callback function,it processes the reponse of SDK.when application send 
                    command to SDK, SDK will call this callback handler to make a response to application.
* Input parameter : T_KNX_CORE_EVENT *ptEvent.
                      BYTE ucCmd:command ID;
                           GROUP_DATA_INDICATION    : receiving a group address data.
                           SEARCH_REQUEST           : return the result of searching request.
                           CONNECT_REQUEST          : return the status of connection request.
                           DISCONNECT_REQUEST       : return the status of disconnection request.
                      BYTE ucCnectSt:command status;
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
* Output parameter: no.
* Return          : SW_OK : OK.
                    SW_ERR: WRONG.
* Other description: This function will be registered into SDK. SDK will call this function to give
                     a response to application software in running.
* Modify date     Ver.     Modifier      Action
* ---------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
WORD32 App_CallBack(T_KNX_CORE_EVENT *ptEvent)
{
    /* here is only an example, the programer should add the actual function code at here. */
    
    switch(ptEvent->ucCmd)
    {
        case SEARCH_REQUEST:
        {
            /* we get the knxip router information by KnxIp_Core_GetInterface. */
            g_ptKnxIpInterFaceInfo = KnxIp_Core_GetInterface();
            /* application can get all knxip routers information at here,and choose one of it for working. */
            break;
        }
        case GROUP_DATA_INDICATION:
        {
            /* application can get communication object value at here. and to some job about it. */
            break;
        }
        case CONNECT_REQUEST:
        {
            /* application can check the connection status and do the job according it. */
            if(ptEvent->ucCmdSt==E_CMD_SUCCESSFUL)
            {
                /* connection was established..... */
            }
            else
            {
                /* establish connection failed.... */
            }
            break;
        }
        case DISCONNECT_REQUEST:
        {
            /* connection disconnect is failed or successful? what job will be done? */
            break;
        }
    }
    
    return SW_OK;
}

/*** Step 3 ******************************  creat application functions ************************************/

/*****************************************************************************************************
* function name   : void Application_Start_Init(void)
* Description     : application initialize function.
* Input parameter : no.
* Output parameter: no.
* Return          : no.
* Other description: Application's initialization entry,how to run it depends on the application.
* Modify date     Ver.     Modifier      Action
* ---------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
void Application_Start_Init(void)
{
    BYTE ucIndex;
    WSADATA wsaData;
    WORD sockVersion = MAKEWORD(2,2);
    struct sockaddr_in t_SocketInfo;
    struct ip_mreq tMulReq;
    T_KNX_IP_INIT_PARA tCorePara;
    T_IP_DEV_REG tIpDevReg;
    
    /* clear some variables. */
    g_dw50MsCounter = 0;
    g_i50MsTimerId  = 0;
    g_i100MsTimerId = 0;
    for(ucIndex=0;ucIndex<4;ucIndex++)
    {
        g_atSock[ucIndex] = 0;
    }
    /* initialize socket. */
    if(WSAStartup(sockVersion, &wsaData)==0)         /* creat environmet. */
    {
        /* creat each socket. */
        g_atSock[COM_MULTCAST_SCK_NO]      = socket(AF_INET,SOCK_DGRAM,0);          /* only for demo, do not check the returned result of socket function. next is the same. */
        g_atSock[CTRL_POINT_SCK0_NO]       = socket(AF_INET,SOCK_DGRAM,0);
        g_atSock[DATA_POINT_SCK_NO]        = socket(AF_INET,SOCK_DGRAM,0);
        g_atSock[COM_MULTCAST_SCK_USER_NO] = socket(AF_INET,SOCK_DGRAM,0);          /* if only use the knx system multicat IP address,this socket may not be created. */
	/* bind control point socket. */
        memset(&t_SocketInfo, 0, sizeof(t_SocketInfo));
        t_SocketInfo.sin_family      = AF_INET;
	t_SocketInfo.sin_port        = htons(KNX_IPV4_CTRL_ENDPOINT);
	t_SocketInfo.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(g_atSock[CTRL_POINT_SCK0_NO],(struct sockaddr *)&t_SocketInfo,sizeof(sockaddr));
        
	/* bind data point socket. */
        memset(&t_SocketInfo, 0, sizeof(t_SocketInfo));
        t_SocketInfo.sin_family      = AF_INET;
	t_SocketInfo.sin_port        = htons(KNX_IPV4_DATA_ENDPOINT);
	t_SocketInfo.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(g_atSock[DATA_POINT_SCK_NO],(struct sockaddr *)&t_SocketInfo,sizeof(sockaddr));
        
	/* bind system multicast socket. */
        memset(&t_SocketInfo, 0, sizeof(t_SocketInfo));
        t_SocketInfo.sin_family      = AF_INET;
	t_SocketInfo.sin_port        = htons(KNX_IP_PORT_NUMBER);
	t_SocketInfo.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(g_atSock[COM_MULTCAST_SCK_NO],(struct sockaddr *)&t_SocketInfo,sizeof(sockaddr));
	/* join this socket to the system multicast group. */
        tMulReq.imr_interface.S_un.S_addr = htonl(INADDR_ANY);
	tMulReq.imr_multiaddr.S_un.S_addr = inet_addr(KNX_SYS_MUL_ADDR);
	setsockopt(g_atSock[COM_MULTCAST_SCK_NO],IPPROTO_IP,IP_ADD_MEMBERSHIP,(char*)&tMulReq,sizeof(tMulReq));        
        
	/* bind user multicast socket.if only use the knx system multicat IP address,this step can not be done. */
        int wTmp;
        wTmp = 1;
        setsockopt(g_atSock[COM_MULTCAST_SCK_USER_NO],SOL_SOCKET,SO_REUSEADDR,(char*)&wTmp,sizeof(wTmp));

        memset(&t_SocketInfo, 0, sizeof(t_SocketInfo));
        t_SocketInfo.sin_family      = AF_INET;
	t_SocketInfo.sin_port        = htons(KNX_IP_PORT_NUMBER);
	t_SocketInfo.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(g_atSock[COM_MULTCAST_SCK_USER_NO],(struct sockaddr *)&t_SocketInfo,sizeof(sockaddr));

	/* join this socket to the application multicast group. */
        tMulReq.imr_interface.S_un.S_addr = htonl(INADDR_ANY);
	tMulReq.imr_multiaddr.S_un.S_addr = inet_addr(KNX_USER_MUL_ADDR);
	setsockopt(g_atSock[COM_MULTCAST_SCK_USER_NO],IPPROTO_IP,IP_ADD_MEMBERSHIP,(char*)&tMulReq,sizeof(tMulReq));

        /* set non block. */
        ioctlsocket(g_atSock[COM_MULTCAST_SCK_NO],FIONBIO,&wNoBlock);
        ioctlsocket(g_atSock[CTRL_POINT_SCK0_NO],FIONBIO,&wNoBlock);
        ioctlsocket(g_atSock[DATA_POINT_SCK_NO],FIONBIO,&wNoBlock);
        ioctlsocket(g_atSock[COM_MULTCAST_SCK_USER_NO],FIONBIO,&wNoBlock);

        /* initialize the buffer pool. */
	Buffer_Pool_Init();                                                     /* SDK function. */
	/* initialize the link layer. */
	KnxIp_Ll_Init();                                                        /* SDK function. */
	/* initialize the knxip layer. */
        tCorePara.aucCtrlPortNo[0]     = HI_BYTE(KNX_IPV4_CTRL_ENDPOINT);
        tCorePara.aucCtrlPortNo[1]     = LOW_BYTE(KNX_IPV4_CTRL_ENDPOINT);
	tCorePara.aucDataPortNo[0]     = HI_BYTE(KNX_IPV4_DATA_ENDPOINT);
	tCorePara.aucDataPortNo[1]     = LOW_BYTE(KNX_IPV4_DATA_ENDPOINT);
        tCorePara.aucInstallMulPort[0] = KNX_IP_PORT_NUM_HI; 
        tCorePara.aucInstallMulPort[1] = KNX_IP_PORT_NUM_LOW; 
        for(ucIndex = 0;ucIndex<4;ucIndex++)
	{
    	    tCorePara.aucIp[ucIndex]           = ....;                          /* fill the host ip address.                         */
    	    tCorePara.aucInstallMulIp[ucIndex] = ....;                          /* fill the application define multicast ip address. */
   	    tCorePara.aucSysMulIp[ucIndex]     = ....;                          /* fill the knx system multicast ip address.         */
	}
        tCorePara.pfAppCallback    = App_CallBack;                              /* register application callback.            */
        tCorePara.pfGetTimeDelayMs = App_Get_TimeDelayMs;                       /* register time difference getting handler. */
	tCorePara.pfGetTimeMs      = App_Get_Time;                              /* register time getting handler.            */
	Knx_MsgInit(&tCorePara);                                                /* initialize the SDK message layer.SDK function.*/
        /* register every socket to knxip core. */
        tIpDevReg.pfReceive    = App_Socket_Rx;                                 /* register the socket receive function entry.  */
        tIpDevReg.pfSend       = App_Socket_Tx;                                 /* register the socket transmit function entry. */
        tIpDevReg.ucSckNo      = COM_MULTCAST_SCK_NO;                           /* socket index.           */
        tIpDevReg.wBufferSize  = KNX_MSG_BUFFER_SIZE;                           /* buffer size:128 bytes.  */
        tIpDevReg.wRxBufferNum = 100;                                           /* receive buffer number.  */
        tIpDevReg.wTxBufferNum = 100;                                           /* transmit buffer number. */
        KnxIp_SckReg(&tIpDevReg);                                               /* SDK function.           */

        tIpDevReg.pfReceive    = App_Socket_Rx;
        tIpDevReg.pfSend       = App_Socket_Tx;
        tIpDevReg.ucSckNo      = DATA_POINT_SCK_NO;
        tIpDevReg.wBufferSize  = KNX_MSG_BUFFER_SIZE;
        tIpDevReg.wRxBufferNum = 100;
        tIpDevReg.wTxBufferNum = 100;
        KnxIp_SckReg(&tIpDevReg);

        tIpDevReg.pfReceive    = App_Socket_Rx;
        tIpDevReg.pfSend       = App_Socket_Tx;
        tIpDevReg.ucSckNo      = CTRL_POINT_SCK0_NO;
        tIpDevReg.wBufferSize  = KNX_MSG_BUFFER_SIZE;
        tIpDevReg.wRxBufferNum = 100;
        tIpDevReg.wTxBufferNum = 100;
        KnxIp_SckReg(&tIpDevReg);

        tIpDevReg.pfReceive    = App_Socket_Rx;
        tIpDevReg.pfSend       = App_Socket_Tx;
        tIpDevReg.ucSckNo      = App_Socket_Tx;
        tIpDevReg.wBufferSize  = KNX_MSG_BUFFER_SIZE;
        tIpDevReg.wRxBufferNum = 100;
        tIpDevReg.wTxBufferNum = 100;
        KnxIp_SckReg(&tIpDevReg);
        
        /* start 50ms timer task. */
        App_Creat_50Ms_Task();
        /* start SDK task. */
        App_Creat_Sdk_Task();
        
        
        /* next : application can creat itself task. */
        /*** Application task creat..... **/
    }

    return;
}

/*****************************************************************************************************
* function name   : void App_Task_Entry(void)
* Description     : this function is an example model for application design.it's function is do the job
                    of application.
* Input parameter : no.
* Output parameter: no.
* Return          : no.
* Other description:this function may be called periodically or not.
* Modify date     Ver.     Modifier      Action
* ---------------------------------------------------------------------------------------------------
* 2017-03-01      V1.00                 Creation
******************************************************************************************************/
void App_Task_Entry(void)
{
    BYTE ucRet;
    T_KNX_APP_CMD tKnxAppCmd;
    
    /* Application's job add here.............. */
    
    /* next we establish a model for SDK command. we assume a variable named g_ucAppCmd, this variable
       will be filled in an application command. how to define and fill this variable are defined by
       application designer. In the application, we will check which command is filled in g_ucAppCmd,
       and then do some job about it. */
    swithc(g_ucAppCmd)
    {
        case router_searching_command:         /* router_searching_command just describes the meaning of the command,not a practical macro define.next cases is same to it. */
        {
            /* we got a router searching command, we send a router search command to SDK. */
            tKnxAppCmd.ucCmd = SEARCH_REQUEST;
            ucRet = KnxIp_Application_Cmd(&tKnxAppCmd);      /* send a SEARCH_REQUEST command to SDK. T_KNX_APP_CMD is defined in Knx_Msg.h, please refer it for detailed information aboute KnxIp_Application_Cmd. */
            if(E_COMMAND_FAILED == ucRet)
            {
                /* if sending is failed,Application may need to do something.please add it here. */
            }
            /* if sending is successful, SDK gives a response to application by calling App_CallBack after 10 seconds. */
            
            break;
        }
        case establish_connection_command:
        {
            /* we got a command needing to establish a connection with a knxip router. */
            tKnxAppCmd.ucCmd      = CONNECT_REQUEST;
            tKnxAppCmd.aucData[0] = TUNNEL_CONNECTION;
            tKnxAppCmd.ucLength   = 7;
            for(ucIndex=0;ucIndex<6;ucIndex++)
            {
                if(ucIndex<4)
                {
                    tKnxAppCmd.aucData[ucIndex+1] = ....;       /* destination knxip router's ip address. */
                }
                else
                {
                    tKnxAppCmd.aucData[ucIndex+1] = .....;      /* destination knxip router's control point port number. */
                }
            }
            ucRet = KnxIp_Application_Cmd(&tKnxAppCmd);
            if(E_COMMAND_FAILED == ucRet)
            {
                /* if sending is failed,Application may need to do something.please add it here. */
            }
            /* if sending is successful, SDK will give a response describing the connection status by calling App_CallBack. the longest time for waiting response is 10 seconds. */
            
            break;
        }
        case disconnect_command:
        {
            /* we got a command want to disconnect the current connection. */
            tKnxAppCmd.ucCmd    = DISCONNECT_REQUEST;
            tKnxAppCmd.ucLength = 0;
            ucRet = KnxIp_Application_Cmd(&tKnxAppCmd);
            if(E_COMMAND_FAILED == ucRet)
            {
                /* if sending is failed,Application may need to do something.please add it here. */
            }
            /* if sending is successful, SDK will give a response to application by calling App_CallBack. application can check the status by the response. result's waiting time is 1 second. */
            
            break;
        }
        case group_data_read:
        {
            /* application wants to read a group address's data. */
            tKnxAppCmd.ucCmd              = GROUP_DATA_READ;
            tKnxAppCmd.ucLength           = 0;
            tKnxAppCmd.aucDestiGrpAddr[0] = (BYTE)(wGrpAddr>>8);
            tKnxAppCmd.aucDestiGrpAddr[1] = (BYTE)wGrpAddr;
            ucRet = KnxIp_Application_Cmd(&tKnxAppCmd);
            if(E_COMMAND_FAILED == ucRet)
            {
                /* if sending is failed,Application may need to do something.please add it here. */
            }
            /* if send is successful, SDK will give a data response to application by calling App_CallBack if the destination group address is right. on the contrary, if the destination
               group address is not right, there is no any data response. */
            
            break;
        }
        case group_data_write:
        {
            /* applicatin wants to write data to a group address. */
            tKnxAppCmd.ucCmd              = GROUP_DATA_WRITE;
            tKnxAppCmd.aucDestiGrpAddr[0] = (BYTE)(wGrpAddr>>8);
            tKnxAppCmd.aucDestiGrpAddr[1] = (BYTE)wGrpAddr;
            tKnxAppCmd.ucLength           = (BYTE)wLen;
             for(ucIndex=0;ucIndex < wLen;ucIndex++)
            {
                tKnxAppCmd.aucData[ucIndex] = ...........;              /* fill the application data into the command structure tKnxAppCmd. */
            }
            ucRet = KnxIp_Application_Cmd(&tKnxAppCmd);
            if(E_COMMAND_FAILED == ucRet)
            {
                /* if sending is failed,Application may need to do something.please add it here. */
            }
            /* writing has no reponse, Application can check the writing result by reading the data of the destination group address. */
            
            break;
        }
    }
    
    return;
}

/*** Step 4 ******************************  quit application software ************************************/

/*  if application software quit,we should do jobs as below:
(1) closing sockets;
(2) releasing timers;
(3) calling Buffer_Pool_Quit() to release the resource of buffer pool.
(4) calling Buffer_Pool_Quit() to release the sdk management resource.
*/





/* end of file. */
