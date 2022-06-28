#include <bits/stdc++.h>

using namespace std;

class Dictionary
{
    private:
    map<int,set<string>>maps;
    
    public:
    
    void buildDict(vector<string> words)
    {
        vector<string>::iterator it;
        for(it = words.begin();it!=words.end();it++)
        {
            maps[(*it).length()].insert((*it));
        }
    }
    void addWordToDict(string word)
    {
        maps[word.length()].insert(word);
    }
    bool search(string target)
    {
      set<string>::iterator it;
      for(it=maps[target.length()].begin();it!=maps[target.length()].end();it++)
      {
        if(*it == target)
        {
          return true;
        }
      }
      return false;
    }
    set<string> getWordsAfterReplace(string target) 
    {
        set<string>::iterator it;
        set<string> rer;
      int count;
        for(it=maps[target.length()].begin();it!=maps[target.length()].end();it++)
        {
            count=0;
            string str = *it;
            for(int i=0;i<target.size();i++)
            {
                if(str[i]!=target[i])
                {
                    count++;
                }
            }
            if(count<=1)rer.insert(str);
        }
        return rer;
    }
    set<string> getWordsAfterSwap(string target) 
    {
        set<string>::iterator it;
        set<string> rer;
        for(it=maps[target.length()].begin();it!=maps[target.length()].end();it++)
        {
            for(int i=0;i<target.length()-1;i++)
            {
                string str = target;
                char temp=str[i];
                str[i]=str[i+1];
                str[i+1]=temp;
                if(*it==str) rer.insert(str);
            }
        }
        return rer;
    }
    int maxChangeableWord()
    {
        int max=0;
        for(auto it=maps.begin();it!=maps.end();it++)
        {
            set<string> s = (*it).second;
            for(auto itr=s.begin();itr!=s.end();itr++)
            {
                if(getWordsAfterReplace(*itr).size()>max)
                  max = getWordsAfterReplace(*itr).size();
            }
        }
        return max-1;
    }

    int maxSwappableWord() 
    {
        int max=0;
        for(auto it=maps.begin();it!=maps.end();it++)
        {
            set<string> s = (*it).second;
            for(auto itr=s.begin();itr!=s.end();itr++)
            {
                if(getWordsAfterSwap(*itr).size()>max)
                  max = getWordsAfterSwap(*itr).size();
            }
        }
        return max;
    }    
    
};

int main() 
{
    Dictionary dit;
    vector<string> s;
    int N,Q;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string str;
        cin>>str;
        s.push_back(str);
    }
    dit.buildDict(s);
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        int opcode;
        cin>>opcode;
        if(opcode==1)
        {
            string p;
            cin>>p;
            dit.addWordToDict(p);
        }
        if(opcode==2)
        {
            string p;
            cin>>p;
            if(dit.search(p) == true) cout<<"true";
            else cout<<"false";
            cout<<endl;
        }
        if(opcode==3)
        {
            string p;
            cin>>p;
            set<string> q= dit.getWordsAfterReplace(p);
            if(q.size()==0) cout<<"-1"<<endl;
            else 
            {
                for(auto it = q.begin();it!=q.end();it++)
                {
                    cout<<*it<<" ";
                }
                cout<<endl;
            } 
        }
        if(opcode==4)
        {
            string p;
            cin>>p;
            set<string> q = dit.getWordsAfterSwap(p);
            if(q.size()==0) cout<<"-1"<<endl;
            else
            {
                for(auto it = q.begin();it!=q.end();it++)
                {
                    cout<<*it<<" ";
                }
                cout<<endl;
            }             
        }
        if(opcode==5)
        {
            cout<<dit.maxChangeableWord()<<endl;
        }
        if(opcode==6)
        {
            cout<<dit.maxSwappableWord()<<endl;
        }
    }
    return 0;
}