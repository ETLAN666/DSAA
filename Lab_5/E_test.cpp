#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <vector>


using namespace std;


int main()
{
    //FreqStack tt;
    int temp=0,count=0,t;
    string str="STL";
    string str1= "put-in";
    string str2= "eat";
    string str3= "nsdd";
    str.resize(100); //需要预先分配空间
	scanf("%s", &str[0]);
	puts(str.c_str());
	scanf("%s", &str[0]);
	puts(str.c_str());
    
    /*
    while (!(str==str3)) {
        scanf("%s", &str);
        if (str==str1) {
            scanf("%d", &temp);
            tt.push(temp);
            count++;
        }        
        else if (str == str2) {
            if(count==0)
                printf("pa\n");
            else {
                t = tt.pop();
                printf("%d\n", t);
                count--;
            }
        }
        //else if (str == str3)
            //break;
    }
    */
	return 0;
}
