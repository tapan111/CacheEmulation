#include<ios>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
string s(argv[1]);
string file(argv[2]);
int p=file.length()-4;
string nfile=file.substr(0,p);
int asso= atoi(argv[3]);
vector<string>result;
if(s=="LRU"){
    list<string> l1;
    set<string> s1;
    set<string> full;
    int access =0;
    int miss =0;
    int capa =0;
    int comp =0; 
         fstream fileHandler(file.c_str());
         fstream output;
         output.open("21116096_"+s+"_"+nfile+"_"+argv[3]+".out",ios::out);
	while (!fileHandler.eof())
        {
        string  x;
        fileHandler >> x;
        if(x=="\0"){
            continue;
        }
        else {
               access++;
          if(s1.size()<asso){
            if(s1.count(x)){
                result.push_back("HIT");
                
                l1.remove(x);
                l1.push_back(x);
            }
            else{
                result.push_back("MISS");
                
                miss++;
                if(full.count(x)){
                  capa++;
                }
                else{comp++;}
                
                l1.push_back(x);
                s1.insert(x);
                full.insert(x);
                
            }

          }
          else if(s1.size()==asso){
               if(s1.count(x)==1){
                  result.push_back("HIT");
                 l1.remove(x);
                 l1.push_back(x);
               }
               else if(s1.count(x)==0){
                
                result.push_back("MISS");
                miss++;
                if(full.count(x)){
                    capa++; 
                    }
                    else{
                      comp++;
                    }
                
                auto it = l1.begin();
                
                l1.push_back(x);
                s1.erase(*it);
                l1.pop_front();
                s1.insert(x);
                full.insert(x);
               }
              
          }
        }
        }
        
       fileHandler.close();
       
       output<<"TOTAL_ACCESSES = "<<access<<endl;
       output<<"TOTAL_MISSES = "<<miss<<endl;
       output<<"COMPULSORY_MISSES = "<<comp<<endl;
       output<<"CAPACITY_MISSES = "<<capa<<endl;
      for(auto x:result){
        output<<x<<endl;
      }
}
else if(s=="OPTIMAL"){
   
    set<string> s2;
    vector<string>input;
    set <string>full1;
    int access1 = 0;
    int miss1 = 0;
    int capa1 = 0;
    int comp1 = 0;
    fstream fileHandler(file.c_str());
         fstream output;
         output.open("21116096_"+s+"_"+nfile+"_"+argv[3]+".out",ios::out);
    
    while (!fileHandler.eof())
         {
        string x;
        fileHandler >> x;
           if(x!="\0")
            input.push_back(x);
           
         }
    fileHandler.close();
    fileHandler.open(file.c_str());
    
    while (!fileHandler.eof())
    {
        string z;
        fileHandler >> z;
        if (z == "\0")
        {
            continue;
        }
        else
        {
            access1++;
            if (s2.size() < asso)
            {
                if (s2.count(z))
                {
                    result.push_back("HIT");
                }
                else
                {
                    
                    result.push_back("MISS");
                    miss1++;
                     comp1++;
                     s2.insert(z);
                    full1.insert(z);
                    
                }
            }
            else
            {
                if (s2.count(z))
                {
                    result.push_back("HIT");
                }
                else
                {
                    result.push_back("MISS");
                    miss1++;
                    if(full1.count(z)){
                    capa1++; 
                    }
                    else{
                      comp1++;
                    }
                    set<string> s4 = s2;
                    vector<string> optimal;
                   for (int i = access1; i <input.size(); i++)
                    {
                        if (s4.count(input[i]))
                        {
                            optimal.push_back(input[i]);
                            
                            s4.erase(input[i]);
                        }
                    }
                  
                    if (s4.size() > 0)
                    {
                        auto it = s4.begin();
                        s2.erase(*it);
                        s2.insert(z);
                        full1.insert(z);
                    }
                    else
                    {
                        s2.erase(optimal.back());
                        s2.insert(z);
                        full1.insert(z);
                    }
                }
            }
        }
    }
    fileHandler.close();
   
       
       output<<"TOTAL_ACCESSES = "<<access1<<endl;
       output<<"TOTAL_MISSES = "<<miss1<<endl;
       output<<"COMPULSORY_MISSES = "<<comp1<<endl;
       output<<"CAPACITY_MISSES = "<<capa1<<endl;
       for(auto x:result){
        output<<x<<endl;
      }
      
    
}
  

    return 0; 
}