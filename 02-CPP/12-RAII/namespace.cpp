#include <iostream>

namespace payment
{
    void paypal(){
        std::cout << "payment namespace: PayPal payment method!" << std::endl;
    }
    void fawry(){
        std::cout << "payment namespace: Fawry payment method!" << std::endl;
    }
    void wallet(){
        std::cout << "payment namespace: Wallet payment method!" << std::endl;
    }


} // namespace payment

void paypal(){
    std::cout << "standalone function: PayPal payment method!" << std::endl;
}
void fawry(){
        std::cout << "standalone function: Fawry payment method!" << std::endl;
    }
    void wallet(){
        std::cout << "standalone function: Wallet payment method!" << std::endl;
    }



int main(int argc, char const *argv[])
{

    namespace ps = payment;
    ps::wallet();
    paypal();
    fawry();
    

    return 0;
}
