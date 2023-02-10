
#include"../include/log/Timestamp.hpp"
#include"../include/log/LogMessage.hpp"
#include"../include/log/LogCommon.hpp"
#include"../include/log/Logger.hpp"
#include"../include/log/LogFile.hpp"

#include<iostream>

using namespace std;

tulun::LogFile *plog = nullptr;
void writefile(const string &info)
{
    plog->append(info);
}
void flushfile()
{
    plog->flush();
}
int main()
{
    plog = new tulun::LogFile("yhping",1024*10*64);// 640k;
    tulun::Logger::setOutput(writefile);
    tulun::Logger::setFlush(flushfile);

    for(int i = 0;i<10000000;++i)
    {
        LOG_INFO<<"yhping main "<<i;
    }
    return 0;
}
#if 0 
int main()
{
    tulun::Logger::setLogLevel(tulun::LOG_LEVEL::TRACE);
    LOG_TRACE<<"yhping TRACE";
    LOG_DEBUG<<"main DEBUG";
    LOG_INFO<<" main INFO";
    LOG_WARN<<" main WARN";
    LOG_ERROR<<" main ERROR";
    return 0;
}


void fun(int age)
{
    //tulun::Logger log(tulun::LOG_LEVEL::INFO,__FILE__,__func__,__LINE__);
   // log.stream()<<"yheping hello";
   if(age >= 0 && age <= 20)
   {
        LOG_FATAL<<"age error : "<<age;
        //tulun::Logger(tulun::LOG_LEVEL::FATAL,__FILE__,__func__,__LINE__).stream()
   }

}
int main()
{
    fun(10);

    cout<<"main end ..."<<endl;
}

int main()
{
    tulun::LogMessage logmess(tulun::LOG_LEVEL::INFO,__FILE__,__func__,__LINE__);
    logmess<<"yhping log system";
    cout<<logmess.toString()<<endl;
    return 0;
}



int main()
{
    tulun::MicroTimestamp mit = tulun::MicroTimestamp::now();
    cout<<mit.toString()<<endl;
    cout<<mit.toFormattedString()<<endl;
    return 0;
}
#endif 