//
// Created by zhuziyu on 19-3-26.
//
#include "Request_Zzy.h"

using namespace std;

Request_Pack::Request_Pack(Request_Line L,Request_Head H,Request_Content C)
{
    Line = L;
    Head = H;
    Content = C;
}


Request_Line::Request_Line(STring M,STring U)
{
    Method = M;
    Url = U;

    All_line = Method + Url + Http_version;
}
Request_Line::Request_Line(STring M,STring U,STring H)
{
    Method = M;
    Url = U;
    Http_version += H;

    All_line = Method + Url + Http_version;

    Request_head_size = Method.size() + Url.size() + Http_version.size();
}
bool Request_Line::Set_method(STring M)
{
    Method = M;
    return true;
}
STring Request_Line::Get_method()
{
    if(!Method.size()) return "";
    return Method;
}

bool Request_Line::Set_url(STring U)
{
    Url = U;
    return  true;
}

STring Request_Line::Get_url()
{
    if(!Url.size()) return "NOT FIND REQUEST LINE";
    return Url;
}
STring Request_Line::Get_http_version()
{
    return Http_version;
}
bool Request_Line::Add_http_line(STring A)
{
    if(Http_version.size() < Http_version.size() + A.size()){
        Http_version += A;
        return  true;
    }
    return false;
}
STring Request_Line::All_request_line()
{
    return All_line;
}

bool Request_Head::Add_head(STring H)
{
    if(H.size())
    Vec.push_back(H);
}

bool  Request_Head::Print_all_head()
{
    if(Vec.size()){
        for(auto item : Vec)
            cout << item << endl;
    }else return false;
}

STring Request_Head::Get_the_head(STring Tip)
{
    if(Vec.size()){
        for(auto item :Vec)
            if(item.find(Tip) != STring::npos) return item;
    }

    string temp = "NOT FIND THE" + Tip +"HEAD";
    return temp;
}

VEctor Request_Head::Get_all_head()
{
    return Vec;
}

bool Request_Content::Set_content(STring Con)
{
    if(Con.size()){
        Content = Con;
        return true;
    }
    return false;
}

STring Request_Content::Get_content()
{
    return Content;
}



