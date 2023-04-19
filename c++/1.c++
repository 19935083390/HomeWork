    #include<vector>   
    #include<stack>   
    #include<queue>   
    #include<iostream>   
    #include<bits/stdc++.h>      
    using namespace std;      
    stack<char>p;queue<char>q;      
    char s[10000];      
    int advance(char ch);      
    void work();      
    void calcu();      
    int main(){      
        memset(s,0,sizeof s);      
        gets(s);   
        // while(gets(s)){             
            while(!q.empty())q.pop();      
            while(!p.empty())p.pop();      
            work();calcu();    
            char e = p.top();   
            // cout << "Result" <<endl;   
            cout << e << endl;    
            // printf("%c\n",p.top());     
        // }      
        return 0;      
    }      
    int advance(char ch)      
    { //定义优先级，!>*>|      
        if (ch=='!')return 3;      
            else if (ch=='*')return 2;      
            else if (ch=='|')return 1;      
        return 0;      
        }      
    void work(){      
        int length=strlen(s);      
        for(int i=0;i<length;i++)      
        {      
            char ch=s[i];      
            if (ch!=' '){//等于空格直接跳过      
                if (ch=='1'||ch=='0')      
                    q.push(ch);//数值直接入队      
                else if (advance(ch)){//如果是括号则会跳过4      
                if(p.empty()){p.push(ch);continue;}//注意栈为空的时候下列规则不适用，会出错，需要单独讨论      
                if (ch=='!'&&p.top()=='!'){      
                    p.pop();//两个连续的！直接 抵消      
                    continue;      
                }      
                while (!p.empty()&&p.top()!='(' && advance(p.top())>=advance(ch))      
                    {q.push(p.top());p.pop();}      
                    p.push(ch);      
                    }      
                else if (ch=='(')      
                    p.push(ch);      
                else if (ch==')'){      
                while (p.top()!='(')//先按照括号内优先级依次入队，保证是先运算括号内的，不被后面的式子影响，同时注意不要包含括号！      
                    {q.push(p.top());p.pop();}      
                        p.pop();      
                }     
            }      
        }      
            while (!p.empty())      
            {q.push(p.top());p.pop();}//剩余元素全部入队成后缀表达式                
            return;      
    }      
    void calcu()      
          {      
              char a,b,c,ch;      
              while(!q.empty()){      
                  ch=q.front();      
                //   cout << ch <<" ";   
                  if (ch=='!'){      
                      int a=p.top();      
                      if (a!='!'){p.pop();p.push('1'+'0'-a);}      
                  }      
                  else if(ch=='*'){      
                      a=p.top();p.pop();b=p.top();p.pop();      
                      if (b!=a)p.push('0');      
                      else if(b==a)p.push(a);      
                      else {p.push(b);p.push(a);}      
                  }      
                  else if (ch=='|'){      
                      a=p.top();p.pop();b=p.top();p.pop();      
                      if (b!=a)p.push('1');      
                      else if(b==a)p.push(a);      
                      else {p.push(b);p.push(a);}      
                  }      
                  else p.push(ch);      
                  q.pop();      
              }      
              return;      
          }  