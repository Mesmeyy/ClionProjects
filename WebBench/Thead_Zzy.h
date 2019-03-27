//
// Created by zhuziyu on 19-3-26.
//

#ifndef WEBBENCH_THEAD_ZZY_H
#define WEBBENCH_THEAD_ZZY_H
#include <thread>
#include <vector>
#include <mutex>
#include <map>
#include <queue>
#include "Request_Zzy.h"


typedef  std::thread THread;//线程的别名
typedef  std::vector<std::pair<int,Thread_per> >  VEcpair;
typedef  std::queue<Request_Pack> QUeue;

#define MAX_POOL_NUM 64 //最大线程数 64
#define  INIT_POOL_NUM 4 //最小初始化线程数 4
#define MAX_LIVE_TIME 1800  //30分钟
#define KEEP_ALIVE_TIME 180 //3分钟
#define INIT_LIVE_TIME  10  //10秒

class Thread_per//单个线程类
{
public:
    int Send_bao = 0;//发包数量
    unsigned  int Send_b = 0;//发包bit

    int Recv_bao = 0;//收包数量
    unsigned  int Recv_b = 0;//收包bit数量

    THread thread;//单个线程


    //应该有一个接受缓冲区
};

class Thread_Pack
{
private:
    int Con_num;//连接数量的大小
    int Data_recv_combine;//总共接受数据之和
    int Data_send_combine;//总共发送数据大小之和
    int Sec_data;//每秒发送数据值


public:
    Thread_Pool  Pools;
public:
    bool Set_data_combine();//把i线程的相关数据赋值到总的线程池
    int Get_data_combine();//获取数据总和

};

class Thread_Pool
{
public:
    VEctor vec;

private:
    int Thread_number = INIT_POOL_NUM;//线程个数
    int Live_time = KEEP_ALIVE_TIME;//线程生存时间,单位是秒
public:
    QUeue Queue_request_pack;//任务队列

    Thread_Pool() = default;//默认创建线程池
    Thread_Pool(int thread_num = INIT_POOL_NUM);//指定数目创线程池

    bool Thead_pool_init(int thread_num);//线程池初始化数量大小

    bool Thead_add(int add_num);//添加几个线程
    bool Thead_delete(int index1,int index2);//指定删除index1-index2之间的线程

    int (*Work_thread)(Request_Pack P);//线程真正的工作函数
    int  Thread_do(Request_Pack P);//线程工作函数,返回的是目前已经接收的数据大小
};
#endif //WEBBENCH_THEAD_ZZY_H
