//
// Created by zhuziyu on 19-3-26.
//

#ifndef WEBBENCH_REQUEST_ZZY_H
#define WEBBENCH_REQUEST_ZZY_H

#include <iostream>
#include <string>
#include <vector>

typedef std::string STring;//避免使用using namespace std;
typedef std::vector<std::string> VEctor;

//请求包类
class Request_Pack
{
private:
    Request_Head Head;//请求头
    Request_Line Line;
    Request_Content Content;
public:
    Request_Pack() = default;
    Request_Pack(Request_Line Line,Request_Head Head,Request_Content Content);
};

//请求行类
class Request_Line
{
private:
    unsigned  long Request_head_size;
    STring Method;
    STring Url;
    STring Http_version = "HTTP /1.1";
    STring All_line;
public:
    Request_Line() = default;
    Request_Line(STring M,STring U);//M代表方法get或者head,U代表请求的资源url
    Request_Line(STring M,STring U,STring H);//H代表追加的http请求行

    bool Set_method(STring M);//设置方法
    STring Get_method();//获取方法

    bool Set_url(STring U);//设置url
    STring Get_url();//获取url

    STring Get_http_version();//获取http方法
    bool Add_http_line(STring A);//添加请求行中多余内容

    STring All_request_line();
};

//请求头类
class Request_Head
{
private:
  VEctor Vec;
public:
    Request_Head() = default;
    bool Add_head(STring H);//添加一行请求头
    bool  Print_all_head();//获取所有请求头
    STring Get_the_head(STring Tip);//获取指定提示的请求头
    VEctor Get_all_head();//获取指定提示的请求头

};

//请求的内容
class Request_Content
{
private:
    STring Content;
public:
    Request_Content() = default;
    bool Set_content(STring Con);//添加请求内容
    STring Get_content();
};
#endif //WEBBENCH_REQUEST_ZZY_H
