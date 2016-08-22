#ifndef CLIENTDLL_H
#define CLIENTDLL_H
#define DLLFILE
#ifdef DLLFILE
#include "clientDll_global.h"
#else
#define CLIENTDLLSHARED_EXPORT __declspec(import)
#endif
#include<iostream>
#include<cstring>
#include<vector>
#include<winsock2.h>
#include<cstdlib>
#include<string.h>
#include<string>
#include<fstream>
#include<vector>
#include "../definedMess.h"
using namespace std;

class CLIENTDLLSHARED_EXPORT CBasicClient{
public:
        bool isConn(){return bconn;}
        bool isConnect(){return bconn;}
        void disConn();
        CBasicClient();
        ~CBasicClient();
        int init(const char *serverIP,unsigned short  port);
protected:
        int sendMess(void* m,int len);
        int recvMess(void *m,int len);
protected:
        SOCKET mySock;
        bool bconn;
};

class CLIENTDLLSHARED_EXPORT CClientTest:public CBasicClient{
protected:
        ID id;
        int age;
        char name[MAX_LEN_SHOWNAME];
        HANDLE hThread;
        HANDLE hMainSig;
        HANDLE hThreadSig;
private:
        Message m;
        int certification;
public:
typedef void (*ReceiveFun)(const char *,const char *);
        static ReceiveFun receiveFun;
        static void setReceiveFun(ReceiveFun f);
        void print();
        int recvMess(Message &m);
        int sendMess(Message &m);
        CClientTest();
        ~CClientTest();
        int start();
        bool isLogin();
        void pauseThread();
        void resumeThread();
        void lostServer();
        static unsigned long WINAPI threadFun(LPVOID lParam);
        void startRecv(){WaitForSingleObject(hMainSig,INFINITE);}
        void endRecv(){SetEvent(hThreadSig);}
        char *getName(){return name;}
        ID getID(){return id;}
        int getAge(){return age;}
        int login(const char *user,const char *pass);
        int getUserData();
        int updateUserData();
        void recvWrongMess();
        int getUserDetail(const char *user,ID &getid);
        vector<const char *> getUserList();
        void logoff();
        void sendStr(const char *str,const ID toID);
};
#endif
