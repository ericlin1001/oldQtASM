
#include "CBasicClient.h"

#include<iostream>
#include<cstring>
#include<vector>
#include<winsock2.h>
#include<cstdlib>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;


#define _CLIENT_TEST
#ifdef CLIENT_TEST
#define Trace(m) cout<<#m"="<<m<<endl;
#else
#define Trace(m) //cout<<#m"="<<m<<endl;
#endif
//
int testCount=0;
#ifdef CLIENT_TEST
#define testTag cout<<"testTag:"<<testCount++<<endl;
#else
#define testTag //cout<<"testTag:"<<testCount++<<endl;
#endif
#define resetTag testCount=0;
//

CBasicClient::CBasicClient(){
        bconn=false;
        WSADATA wsd;
        if(WSAStartup(MAKEWORD(2,2),&wsd)!=0){
                cerr<<"Failed to load WinSock!\n";
        }
        mySock=SOCKET_ERROR;
}

CBasicClient::~CBasicClient(){
        closesocket(mySock);
        WSACleanup();
}
int CBasicClient::init(const char *serverIP,unsigned short  port){
        //try to connect
        mySock=socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
        if(mySock==SOCKET_ERROR){
                cout<<"socket() failed! can't create socket."<<endl;
                mySock=SOCKET_ERROR;
                return -1;
        }
        sockaddr_in serverAddr;
        serverAddr.sin_port=htons(port);
        serverAddr.sin_addr.s_addr=inet_addr(serverIP);
        serverAddr.sin_family=AF_INET;
        if(connect(mySock,(sockaddr *)&serverAddr,sizeof(serverAddr))== SOCKET_ERROR){
                cerr<<"Connect server failed!"<<endl;
                mySock=SOCKET_ERROR;
                return -1;
        }else{
                cerr<<"connect server success!"<<endl;
                bconn=true;
        }
        return 0;
}
void CBasicClient::disConn(){
        bconn=false;
        shutdown(mySock,2);
}
int CBasicClient::sendMess(void* m,int len){
#define _sendMess_test
#ifdef sendMess_test
        cout<<"send bytest:"<<len<<endl;
#endif
        send(mySock,(char *)m,len,0);
        return 0;
}
int CBasicClient::recvMess(void *m,int len){
        int leftLen=len;
        int recvLen=0;
        while(leftLen>0){
                recvLen=recv(mySock,(char *)m,len,0);
                if(recvLen==SOCKET_ERROR){
                        //cerr<<"recv() fialed:"<<WSAGetLastError()<<endl;
                        return MYERROR;
                }
                leftLen-=recvLen;
        }
        return MYSUCCESS;
        //there had better to start a timmer to ensure the server is alive.
}


void CClientTest::print(){
#ifdef CLIENT_TEST
        cout<<" id:"<<id
                <<" name:"<<name
                <<" age:"<<age
                <<endl;
#else
#endif
}
int CClientTest::recvMess(Message &m){
        if(isConnect()){
                if(CBasicClient::recvMess(&m.h,sizeof(m.h))==MYSUCCESS){
                        if(CBasicClient::recvMess(&m.d,m.h.dataLen)==MYSUCCESS){
                                return MYSUCCESS;
                        }
                }
                return MYERROR;
        }
        Test("Error:not connect in recvMess ");
        return MYERROR;
}
int CClientTest::sendMess(Message &m){
        if(isConnect()){
                //m.h.print();
                CBasicClient::sendMess(&m,sizeof(m.h)+m.h.dataLen);
                return MYSUCCESS;
        }
        Test("Error:not connect in sendMess ");
        cout<<"No connection!"<<endl;
        return MYERROR;

}
CClientTest::CClientTest(){
        id=INVALID_ID;
        memset(name,0,sizeof(name));
        hMainSig=CreateEvent(NULL,FALSE,FALSE,NULL);
        hThreadSig=CreateEvent(NULL,FALSE,FALSE,NULL);
}
CClientTest::~CClientTest(){
        CloseHandle(hThread);
}
int CClientTest::start(){
        DWORD dwThread;
        hThread=CreateThread(NULL,0,threadFun,(LPVOID)this,0,&dwThread);
        if(hThread==NULL){
                cerr<<"CreateThread failed!"<<endl;
                return MYERROR;
        }
        return MYSUCCESS;
}
bool CClientTest::isLogin(){
        return id!=INVALID_ID;
}
void CClientTest::pauseThread(){
        SuspendThread(hThread);
}
void CClientTest::resumeThread(){
        ResumeThread(hThread);
}
void CClientTest::lostServer(){
        cout<<"lost the server"<<endl;
        logoff();
}
unsigned long WINAPI CClientTest::threadFun(LPVOID lParam){
        //deal with mess which be receive arbitary
#ifdef CLIENT_TEST
        cout<<"create a thread"<<endl;
#else
#endif
        CClientTest * c=(CClientTest *)lParam;
        Message m;
        while(1){
                if(c->recvMess(m)==MYERROR){
                        c->lostServer();break;
                }
#ifdef CLIENT_TEST
                cout<<"Thread:Recv a mess."<<endl;
#else
#endif
                switch(m.h.type){
                case MT_CHAT:
                        cout<<m.d.chat.prefix<<m.d.chat.text<<endl;


                                if(receiveFun)  {
                                    receiveFun(m.d.chat.prefix,m.d.chat.text);
                                }
                        break;
                default:

#ifdef CLIENT_TEST
                        cout<<"not deal with in thread."<<endl;
#else
#endif
                        memcpy(&c->m,&m,sizeof(m.h)+m.h.dataLen);
                        SetEvent(c->hMainSig);
                        WaitForSingleObject(c->hThreadSig,INFINITE);
                        break;
                }
        }
        return 0;
}

void CClientTest::setReceiveFun(ReceiveFun f){
   receiveFun=f;
}

int CClientTest::login(const char *user,const char *pass){
        if(!isConn()){cout<<"No connect!"<<endl;return MYERROR;}
        if(isLogin()){cout<<"you have logined!"<<endl;return MYSUCCESS;}

        m.h.type=MT_LOGIN;
        m.h.from=getID();
        m.h.to=SERVER_ID;
        //
        strcpy(m.d.login.pass,pass);
        strcpy(m.d.login.user,user);
        //
        m.h.dataLen=m.d.login.len();
        if(sendMess(m)!=MYSUCCESS){
                logoff();
                return MYERROR;
        }
        //recv
        startRecv();
        if(m.h.type==MT_LOGIN){
                if(m.d.login.isSuccess){
                        certification=m.d.login.certification;
                        id=m.d.login.id;
                        Trace(id);
                        cout<<"login success!"<<endl;

                }else{
                        cout<<"login fail"<<endl;

                }
        }else{
                recvWrongMess();
        }
        endRecv();

        if(isLogin()){
                getUserData();
                print();
                cout<<"Your name:"<<name<<endl;
                return MYSUCCESS;
        }else{
                logoff();
                return MYERROR;
        }


}
int CClientTest::getUserData(){
        //update data;
        m.h.type=MT_GETUSERDATA;
        m.h.from=getID();
        m.h.to=SERVER_ID;
        //
        m.d.userData.type=USER_DATA_READ;
        //
        m.h.dataLen=m.d.login.len();
        if(sendMess(m)!=MYSUCCESS){
                return MYERROR;
        }
        //recv
        startRecv();
        if(m.h.type==MT_GETUSERDATA){
                if(m.d.userData.isSuccess){
                        age=m.d.userData.age;
                        strcpy(name,m.d.userData.name);

#ifdef CLIENT_TEST
                        cout<<"updateData success."<<endl;
#else
#endif
                }else{
                        cout<<"updateData fail"<<endl;
                }
        }else{
                recvWrongMess();
        }
        endRecv();
        return 0;
}
int CClientTest::updateUserData(){
        //update data;
        m.h.type=MT_GETUSERDATA;
        m.h.from=getID();
        m.h.to=SERVER_ID;
        //
        m.d.userData.type=USER_DATA_WRITE;
        //
        m.h.dataLen=m.d.login.len();
        if(sendMess(m)!=MYSUCCESS){
                return MYERROR;
        }
        //recv
        startRecv();
        if(m.h.type==MT_GETUSERDATA){
                if(m.d.userData.isSuccess){
                        m.d.userData.age=age;
                        strcpy(m.d.userData.name,name);

#ifdef CLIENT_TEST
                        cout<<"updateData success."<<endl;
#else
#endif

                }else{
                        cout<<"updateData fail"<<endl;

                }
        }else{
                recvWrongMess();
        }
        endRecv();
        return 0;
}
void recvWrongMess(){

#ifdef CLIENT_TEST
        cout<<"recv wrong mess."<<endl;
#else
#endif

}

int CClientTest::getUserDetail(const char *user,ID &getid){
        m.h.type=MT_GETUSERDETAIL;
        m.h.from=getID();
        m.h.to=SERVER_ID;
        //
        strcpy(m.d.userDetail.name,user);
        //
        m.h.dataLen=m.d.userDetail.len();
        if(sendMess(m)!=MYSUCCESS){
              return MYERROR;
        }
        //recv
        startRecv();
        if(m.h.type==MT_GETUSERDETAIL){
                getid=m.d.userDetail.id;

        }else{
                recvWrongMess();

        }
        endRecv();
        return MYSUCCESS;
}
vector<const char *> CClientTest::getUserList(){
        m.h.type=MT_GETUSERLIST;
        m.h.from=getID();
        m.h.to=SERVER_ID;
        //
        testTag;
        SuspendThread(NULL);
        testTag;

        m.d.userList.num=5;
        m.d.userList.from=0;
        //
vector<const char *>userList;
        m.h.dataLen=m.d.userList.len();
        if(sendMess(m)!=MYSUCCESS){
                return userList;
        }

        //recv
        startRecv();
        if(m.h.type==MT_GETUSERLIST){
                cout<<"List:"<<endl;
                Trace(m.d.userList.num);
                Trace(m.d.userList.users[0]);
                for(int i=0;i<m.d.userList.num;i++){
                        cout<<m.d.userList.users[i]<<"\t";
                        userList.push_back(m.d.userList.users[i]);
                        if((i+1)%5==0)cout<<endl;
                }
                cout<<endl;
        }else{
                recvWrongMess();
        }
        endRecv();
        return userList;
}
void CClientTest::logoff(){
        if(isConn()){
                m.h.type=MT_LOGOFF;
                m.h.from=getID();
                m.h.to=SERVER_ID;
                //
                m.h.dataLen=m.d.logoff.len();
                sendMess(m);
        }
        TerminateThread(hThread,0);
        disConn();
        id=INVALID_ID;
        ResetEvent(hMainSig);ResetEvent(hThreadSig);
}
void CClientTest::recvWrongMess(){


#ifdef CLIENT_TEST
                cout<<"recv wrong mess."<<endl;
#else
#endif


}
void CClientTest::sendStr(const char *str,const ID toID){
        //
        m.h.type=MT_CHAT;
        m.h.from=getID();
        //
        m.h.to=toID;
        strncpy(m.d.chat.text,str,MAX_LEN_CHATTEXT);
        m.d.chat.text[MAX_LEN_CHATTEXT]=0;
        //
        m.h.dataLen=m.d.chat.len();
        if(sendMess(m)!=MYSUCCESS){
                return ;
        }
}
CClientTest::ReceiveFun CClientTest::receiveFun;
