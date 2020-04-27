#include <list>
#include <iostream>

class Component
{
    public :
    virtual void operation() = 0;
    virtual void add(Component *c){}
    virtual void remove(Component *c){}
    virtual Component *getChild(int i){return 0;}
};

class leaf : public Component
{
    public :
    void operation() override
    {
        std::cout<<"Leaf "<<std::endl;
    }
};

class Composite : public Component
{
    std::list<Component *> m_List;
    public :
    void operation() override
    {
        for(auto it = m_List.begin(); it != m_List.end(); it++)
        {
            (*it)->operation();
        }
    }

    void add(Component *c) override
    {
        m_List.push_back(c);
    }
    void remove(Component *c) override 
    {
        m_List.remove(c);
    }

    Component *getChild(int i ) override
    {
        int ii = 0;
        for (auto it = m_List.begin(); it != m_List.end(); it++, ii++)
        {
            if(i == ii)
                return *it;
        }
        return nullptr;
    }
};

int main()
{
    leaf A, B;

    Composite mComposite;

    mComposite.add(&A);
    mComposite.add(&B);

    mComposite.operation();

    return 0;

}