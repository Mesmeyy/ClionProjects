//
// Created by zhuziyu on 19-3-26.
//

#ifndef WEBBENCH_THEAD_ZZY_H
#define WEBBENCH_THEAD_ZZY_H
#include <thread>
#include <vector>
#include <mutex>
#include "Request_Zzy.h"

typedef  std::thread THread;
typedef  std::mutex MUtex;
#define MAX_POOL_NUM 64 //最大线程数 64
#define  INIT_POOL_NUM 4 //最小初始化线程数 4
#define MAX_LIVE_TIME 1800  //30分钟
#define KEEP_ALIVE_TIME 180 //3分钟
#define INIT_LIVE_TIME  10  //10秒

class Thread_Pack
{
private:
    int Data_combine;//总共数据之和
    int Sec_data;//每秒发送数据值


public:
    Thread_Pool  Pools;
public:
    bool Set_data_combine();//赋值数据总和
    int Get_data_combine();//获取数据总和

    int Get_Sec_data();//获取每秒数据

};

class Thread_Pool
{
private:
    static MUtex Mut;
    int Thread_number = INIT_POOL_NUM;//线程个数
    int Live_time = KEEP_ALIVE_TIME;//线程生存时间,单位是秒
public:
    Thread_Pool() = default;//默认创建线程池
    Thread_Pool(int thread_num = INIT_POOL_NUM);//指定数目创进程池
    bool Thead_pool_init(int thread_num);//线程池初始化数量大小
private:
    bool run(int thread_num);
    int (*Work_thread)(Request_Pack P);//线程真正的工作函数
    int  Thread_do(Request_Pack P);//线程工作函数


};




#endif //WEBBENCH_THEAD_ZZY_H
