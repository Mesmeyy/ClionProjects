//
// Created by zhuziyu on 19-3-27.
//

#include "Thead_Zzy.h"
#include <mutex>

static std::mutex  Mutex;
static std::lock_guard<std::mutex> guard(Mutex);

bool  Thread_Pack::Set_data_combine()
{
    //访问当前左右线程


}
