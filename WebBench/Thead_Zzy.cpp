//
// Created by zhuziyu on 19-3-27.
//

#include "Thead_Zzy.h"
#include <mutex>

using namespace std;
static std::mutex  Mutex;


bool  Thread_Pack::Set_data_combine(int i)
{
    //访问当前左右线程
    map<int ,Thread_per>::iterator L_it;
    L_it = Pools.Map_thread.find(i);
    if(L_it == Pools.Map_thread.end()) {
        cout << "The " << i << " Thread " << "is not found"<<endl;
        return false;
    }
    Mutex.lock();
    Con_num += L_it -> second.Send_bao;
    Data_send_combine = L_it -> second.Send_b;
    Data_recv_combine = L_it -> second.Recv_b;
    //没有计算每一秒的数据
    Mutex.unlock();
}

int Thread_Pack::Get_data_combine()
{
    cout << "连接数量大小 : " << Con_num << endl;
    cout << "总共发送的数据总和 : " << Data_send_combine << endl;
    cout << "总共接受的数据总和 : " << Data_recv_combine << endl;
    cout << "每秒的数据访问量 : " << Sec_data << endl;
    return 0;
}

Thread_Pool::Thread_Pool(int thread_num = INIT_POOL_NUM)
