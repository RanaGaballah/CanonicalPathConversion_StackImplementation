#include<iostream>
#include<string>
using namespace std;
const int max_size=100;

class stack{
    int top;
    string items[max_size];
public:
    stack()
    {
        top=-1;
    }
    void push(string x)
    {
        if(top>=max_size-1)
        {
            cout << "stack is full\n";
        }
        else
        {
           top++;
           items[top]=x;
        }

    }
    bool IsEmpty()
    {
        return top == -1;
    }

    int stack_size()
    {
        return top+1;
    }
    void pop()
    {
        if(IsEmpty())
        {
            cout << "stack is empty \n";
        }
        else
        {
            top--;
        }
    }
    string get_top()
    {

    if (!IsEmpty())
    {
        return items[top];
    }
    else
    {
        cout << "stack is Empty\n";
    }

    }
    void print()
    {
        for(int i=0;i<=top;i++)
            cout << items[i]<<" ";
    }

};
string canonical_path(string exp)
{
    stack s;
    string directory;
    string ans;
    int expLengh = exp.length();
    ans.append("/");
    for (int i = 0; i < expLengh; i++)
    {
        directory.clear();
        while (exp[i] == '/')
        {
            i++;
        }
        while ((i<expLengh)&&(exp[i]!='/'))
        {
            directory.push_back(exp[i]);
            i++;
        }
        if (directory.compare("..") == 0) {
            if (!s.IsEmpty())
                s.pop();
        }
        else if (directory.compare(".")==0)
            continue;
        else if (directory.length() != 0)
        {
            s.push(directory);
        }
    }
    stack s2;
    while (!s.IsEmpty())
    {
        s2.push(s.get_top());
        s.pop();
    }
    while (!s2.IsEmpty())
    {
        string temp = s2.get_top();
        if (s2.stack_size() != 1)
        {
           ans.append(temp+"/");
        }
        else
        {
            ans.append(temp);
        }
        s2.pop();
    }
    return ans;
}
int main()
{
   string x1="/home/";
   string x2="/../";
   string x3="/home//foo/";
   cout << "First test case : " << canonical_path(x1)<<"\n";
   cout << "Second test case : " << canonical_path(x2)<<"\n";
   cout << "Third test case : " << canonical_path(x3)<<"\n";
}

