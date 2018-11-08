#include <iostream>
#include <mutex>

using namespace std;

class singleton{
private:
    static singleton* instance;
    static mutex singletonMutex;

    //私有构造,禁止复制
    singleton(){}
    singleton(const singleton&);
    singleton& operator=(const singleton&);
public:
    static singleton& getInstance(){
        if(instance==nullptr){
            singletonMutex.lock();
            if(instance==nullptr){
                try{
                    instance=new singleton();
                } catch(exception e){//实现异常安全
                    singletonMutex.unlock();
                }
            }
            singletonMutex.unlock();
        }
        return *instance;
    }
};
singleton* singleton::instance=nullptr;
mutex singleton::singletonMutex;

int main(int argc, char const *argv[])
{
    cout<<&singleton::getInstance()<<endl;
    cout<<&singleton::getInstance()<<endl;
    return 0;
}
