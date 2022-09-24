#include <iostream>


void solve(int num)
{
    std::string res = "";
    if(num==0)
    {
        std::cout<<"NULL\n";
        return;
    }

    if(num%2==0)
        res+="EVEN";
    else
        res+="ODD";
    if(num>0)
        res+=" POSITIVE\n";
    else
        res+=" NEGATIVE\n";

    std::cout<<res;
}

int main() {

    int n = 0;
    std::cin >> n;

    while(n>0)
    {
        int num = 0;
        std::cin>>num;
        solve(num);
        n--;
    }

    return 0;
}
