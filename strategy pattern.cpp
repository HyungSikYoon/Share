#include <iostream>

class Strategy
{
    public :
    virtual void algorithm() =0;
    
};

class Strategy1 : public Strategy
{
    public :
        void algorithm()
        {
            std::cout<<"strategy1"<<std::endl;
        }
};

class Strategy2 : public Strategy
{
    public :
        void algorithm()
        {
            std::cout<<"strategy2"<<std::endl;
        }
};

class Context
{
    Strategy *m_pStrategy= nullptr;
    public :
    Context(Strategy *strategy)
    {
        m_pStrategy = strategy;
    }
    void operation()
    {
        m_pStrategy->algorithm();
    }
};


int main(void)
{
    std::cout<<"begin"<<std::endl;
    Strategy1 Machine1;
    Context contex(&Machine1);
    contex.operation();
    return 0;
}