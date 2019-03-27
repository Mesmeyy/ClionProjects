//
// Created by zhuziyu on 19-3-27.
//

#include "Thead_Zzy.h"
#include <iterator>
#include <algorithm>


using namespace std;
static std::mutex  Mutex;

/*没有写好
bool  Thread_Pack::Set_data_combine()
{
    //对每一个线程都执行总和相加
    vector<pair<int,Thread_per> > ::iterator it;
    for(it = Pools.vec.begin();it != Pools.vec.end();it ++){
        (*it).
    }
}*/


int Thread_Pack::Get_data_combine()
{
    cout << "连接数量大小 : " << Con_num << endl;
    cout << "总共发送的数据总和 : " << Data_send_combine << endl;
    cout << "总共接受的数据总和 : " << Data_recv_combine << endl;
    cout << "每秒的数据访问量 : " << Sec_data << endl;
    return 0;
}

Thread_Pool::Thread_Pool(int thread_num = INIT_POOL_NUM)
{
    if(thread_num < INIT_POOL_NUM || thread_num > MAX_POOL_NUM) {
        if(thread_num < INIT_POOL_NUM) Thead_pool_init(INIT_POOL_NUM);
        if( thread_num > MAX_POOL_NUM) Thead_pool_init(MAX_POOL_NUM);

    }
    else Thead_pool_init(thread_num);
}

bool Thread_Pool::Thead_pool_init(int thread_num)
{
    //创建线程线程实体 = <int i,线程包> ，线程实体构成线程集合
    for(int i = 0;i < thread_num,i++){
        Thread_per tp;
        std::pair<int,Thread_per> temp(i,tp);
        vec.push_back(temp);
    }
    Thread_number = thread_num;
}

bool Thread_Pool::Thead_add(int add_num)
{
    for(int i = 1;i <= add_num;i++){
        int index =
    }
}