    #include<vector>   
    #include<stack>   
    #include<queue>   
    #include<iostream>   
    #include<bits/stdc++.h>      
    using namespace std;      
    stack<char>p;queue<char>q;      
    char s[10000];     
    char ss[10000] ;  
    int advance(char ch);      
    void work();      
    void calcu();      
    int main(){      
        memset(s,0,sizeof s);      
        gets(s);   
        strcpy(ss,s);  
        // cout << ss << endl;  
        int a[4] ;  
        // while(gets(s)){  
        for (int i =0; i <4;i++)  
          
        {  
            strcpy(s,ss);  
            if(i ==0)  
                for (int j =0;j< strlen(s);j ++)  
            {  
            if(s[j]=='P') s[j] = '0';  
            if(s[j]=='Q') s[j] = '0';  
            }       
            if(i ==1)  
                for (int j =0;j< strlen(s);j ++)  
            {  
            if(s[j]=='P') s[j] = '0';  
            if(s[j]=='Q') s[j] = '1';  
            }  
            if(i ==2)  
                for (int j =0;j< strlen(s);j ++)  
            {  
            if(s[j]=='P') s[j] = '1';  
            if(s[j]=='Q') s[j] = '0';  
            }  
            if(i ==3)  
                for (int j =0;j< strlen(s);j ++)  
            {  
            if(s[j]=='P') s[j] = '1';  
            if(s[j]=='Q') s[j] = '1';  
            }     
            while(!q.empty())q.pop();      
            while(!p.empty())p.pop();      
            work();calcu();    
            char e = p.top();   
            if (e == '0') a[i] = 0;  
            else if (e == '1') a[i] =1;  
            // cout << e << endl;      
        // }  
        }  
        int result = 0;  
        for (int i =0;i< 4;i++) result += a[i];  
        if (result == 0) cout << 0 << endl;  
            else if (result == 4) cout << 1 << endl;  
                else  cout << 2 << endl;      
          
        return 0;      
    }      
    int advance(char ch)      
    { //定义优先级，!>*>|      
        if (ch=='-')return 3;      
            else if (ch=='*')return 2;      
            else if (ch=='|')return 1;      
        return 0;      
        }      
    void work(){      
        int length=strlen(s);      
        for(int i=0;i<length;i++)      
        {      
            char ch=s[i];      
            // cout << ch;  
            if (ch!=' '){//等于空格直接跳过      
                if (ch=='1'||ch=='0')      
                    q.push(ch);//数值直接入队      
                else if (advance(ch)){//如果是括号则会跳过4      
                if(p.empty()){p.push(ch);continue;}//注意栈为空的时候下列规则不适用，会出错，需要单独讨论      
                if (ch=='-'&&p.top()=='-'){      
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
        //  cout << endl;        
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
                  if (ch=='-'){      
                      int a=p.top();      
                      if (a!='-'){p.pop();p.push('1'+'0'-a);}      
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