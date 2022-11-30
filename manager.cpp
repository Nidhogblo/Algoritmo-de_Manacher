#include "manager.h"

manager::manager(){}
manager::manager(string Text) {
    text=Text;
    cout<<manchester();
}

string manager::manchester(){
    int  t_len;
    string text2 = "#";
    int x0 , x1;
    int m2 ;

    
    x0 = 0, x1 = 0;
    t_len= text.length();
    m2 = 2*t_len+1;

    vector<int> arr(m2,0);

    for(int i = 0; i < t_len; i++){
        text2.push_back(text[i]);
        text2.push_back('#');
    }
                    
   
  
    for(int i = 1; i < m2; i++){
        int j = 0;
        if(i>=x1)
            j = i+1;            
        else{
            int ii = 2*x0-i;
            arr[i] = min(x1-i,arr[ii]);
            if(ii-arr[ii]<=x0-arr[x0])
                j = x1+1;                
        }

        while(j&&(j<m2)&&(2*i-j>=0)&&(text2[j]==text2[2*i-j]))
            arr[i]++, j++;
        
        if(i+arr[i]>x1)
            x1 = i+arr[i], x0 = i;
    }        
    
    int maxlength = 0;
    int id = 0;
    for(int i = 1; i < m2; i++)
        if(arr[i]>maxlength){
            maxlength = arr[i];
            id = i;
        }
            
    string res;
    for(int j = id-arr[id]+1; j <= id+arr[id]; j+=2)
        res.push_back(text2[j]);

    return res;
}