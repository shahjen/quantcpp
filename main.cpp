#include "vanilla_option.h"
int main()
{
    const VanillaOption* obj;
    std::cout<<obj->calc_call_price()<<std::endl;
    return 0;
}