#include <iostream>
#include "singleton.hpp"

int main(){
    Singleton::GetInstance().Add("Goodbye, World...");
    return 0;
}
