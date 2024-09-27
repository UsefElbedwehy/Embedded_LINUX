#include <iostream>
#include <algorithm>
#include <numeric>
#include <ostream>
#include <utility>
#include <vector>
#include <string>
// author: Usef Elbedwehy
// date: Thu 26 Sep 2024
// session: ALgorithm
// session number: 11
// content -> Algorithm:
//              -Existence Queries
//              -Finding / Locating Elements
//              -Comparing Ranges
//              -Binary Search
//              -Max / Min
//              -Iterator Range


int main(int argc, char const *argv[])
{

    // // // for_each   ------------------------------------------------------
    //before increment
    std::cout << "Before: ";
    std::vector<int> numbers{55,33,66,22,88,11,44};
    std::for_each(numbers.begin(),numbers.end(),[](int i){std::cout << i << " ";});
    std::cout << std::endl;
    //process: increment
    std::for_each(numbers.begin(),numbers.end(),[](int& i){ i++; });
    //after increment
    std::cout << "After : " ;
    std::for_each(numbers.begin(),numbers.end(),[](int i){std::cout << i << " ";});
    std::cout << std::endl;
    //sum
    struct Sum
    {
        void operator()(int i){sum +=i;}
        int sum{0};
    };
    Sum s = std::for_each(numbers.begin(),numbers.end(),Sum());
    std::cout << "Sum   : "<< s.sum << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // all_of any_of none_of ------------------------------------------------------
    std::vector<int> v1{1,2,3,4,5,6,7,8};
    std::vector<int> v2{2,4,6,8,10,12,14};
    std::vector<int> v3{1,3,5,7,9,11,13};
    //check even numbers
    std::cout << "all even? " <<std::all_of(v1.begin(),v1.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "all even? " <<std::all_of(v2.begin(),v2.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "all even? " <<std::all_of(v3.begin(),v3.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "------------" << std::endl;
    std::cout << "any even? " <<std::any_of(v1.begin(),v1.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "any even? " <<std::any_of(v2.begin(),v2.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "any even? " <<std::any_of(v3.begin(),v3.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "------------" << std::endl;
    std::cout << "none even? " <<std::none_of(v1.begin(),v1.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "none even? " <<std::none_of(v2.begin(),v2.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "none even? " <<std::none_of(v3.begin(),v3.end(),[](int i){return i%2==0;}) << std::endl; 
    std::cout << "------------" << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // find find_if find_if_not ------------------------------------------------------
    v1 = {11,21,31,4,5,6,7,8};
    v2 = {21,41,61,8,10,12,14};
    v3 = {11,3,51,71,92,11,13};
    std::cout <<  "find if not even: " << *std::find_if_not(v1.begin(),v1.end(),[](int i){return i%2==0;}) << std::endl;
    std::cout <<  "find if not even: " << *std::find_if_not(v2.begin(),v2.end(),[](int i){return i%2==0;}) << std::endl;
    std::cout <<  "find if not even: " << *std::find_if_not(v3.begin(),v3.end(),[](int i){return i%2==0;}) << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout <<  "find if even: " << *std::find_if(v1.begin(),v1.end(),[](int i){return i%2==0;}) << std::endl;
    std::cout <<  "find if even: " << *std::find_if(v2.begin(),v2.end(),[](int i){return i%2==0;}) << std::endl;
    std::cout <<  "find if even: " << *std::find_if(v3.begin(),v3.end(),[](int i){return i%2==0;}) << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout <<  "find even: " << *std::find(v1.begin(),v1.end(),31) << std::endl;
    std::cout <<  "find even: " << *std::find(v2.begin(),v2.end(),31) << std::endl;
    std::cout <<  "find even: " << *std::find(v3.begin(),v3.end(),31) << std::endl;
    std::cout << "---------------" << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // count count_if  ------------------------------------------------------
    std::vector<int> v4{12,13,14,12,12,115,15,16,12};
    std::cout << "count of 12 in v4  : " << std::count(v4.begin(),v4.end(),12) << std::endl;
    std::cout << "count if even in v4: " << std::count_if(v4.begin(),v4.end(),[](int i){return ((i % 2) == 0);}) << std::endl;
    
    std::cout << std::string(30,'-') << std::endl;
    // // // mismatch  ------------------------------------------------------
    std::vector<int> v5{12,13,14,15,16,17};
    std::vector<int> v6{12,13,9,8,7,6};
    auto it = std::mismatch(v5.begin(),v5.end(),v6.begin());
    std::cout << "[1]First: " << *it.first << "   &  [1]second: " << *it.second << std::endl;
    it = std::mismatch(v5.begin(),v5.end(),v6.begin(),[](int x,int y){return x!=y;});
    std::cout << "[2]First: " << *it.first << "   &  [2]second: " << *it.second << std::endl;
    it = std::mismatch(v5.begin(),v5.end(),v6.begin(),v6.end());
    std::cout << "[3]First: " << *it.first << "   &  [3]second: " << *it.second << std::endl;
    it = std::mismatch(v5.begin(),v5.end(),v6.begin(),v6.end(),[](int x,int y){return x!=y;});
    std::cout << "[4]First: " << *it.first << "   &  [4]second: " << *it.second << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // search  ------------------------------------------------------
    v5 = {12,13,14,15,16,17};
    v6 = {112,113,9,8,7,6};
    std::cout << "search: " << *std::search(v5.begin(),v5.end(),v6.begin(),v6.end()) << std::endl;
    std::cout << "end: " << *v5.end() << std::endl;
    v5 = {12,13,14,15,16,17};
    v6 = {14,15,16,17};
    std::cout << "search: " << *std::search(v5.begin(),v5.end(),v6.begin(),v6.end()) << std::endl;
    std::cout << "end: " << *v5.end() << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // copy copy_if  ------------------------------------------------------
    std::cout << "----- using < copy > ----- " << std::endl;
    std::cout << "v6 : ";
    std::for_each(v6.begin(),v6.end(),[](int i){std::cout << i << " ";});
    std::cout << std::endl;
    std::vector<int> res(v6.size());
    std::copy(v6.begin(),v6.end(),res.begin());
    std::cout << "res: ";
    std::for_each(res.begin(),res.end(),[](int i){std::cout << i << " ";});
    std::cout << std::endl;
    std::cout << "----- using < copy_if > ----- " << std::endl;
    std::vector<int> res2(v6.size());
    std::copy_if(v6.begin(),v6.end(),res2.begin(),[](int i){return i%2==0;});
    std::for_each(res2.begin(),res2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // move  ------------------------------------------------------
    std::cout << "----- using < move > ----- " << std::endl;
    std::vector<int> mv1{1,2,3,4,5};
    std::vector<int> mv2;
    std::move(mv1.begin(),mv1.end(),std::back_inserter(mv2));
    std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // swap  ------------------------------------------------------
    std::cout << "----- using < swap > ----- " << std::endl;
    mv1 = {2,3,5,6,8}; 
    std::swap(mv1,mv2);
    std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // copy_n  ------------------------------------------------------
    std::cout << "----- using < copy_n > ----- " << std::endl;
    std::copy_n(mv2.begin(),2,mv1.begin());
    std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // fill  ------------------------------------------------------
    std::cout << "----- using < fill > ----- " << std::endl;
    std::fill(mv2.begin(),mv2.end(),4);
    std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // fill_n  ------------------------------------------------------
    std::cout << "----- using < fill_n > ----- " << std::endl;
    std::fill_n(mv2.begin(),2,5);
    std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;


    std::cout << std::string(30,'-') << std::endl;
    // // // transform  ------------------------------------------------------
    std::cout << "----- using < transform > ----- " << std::endl;
    std::transform(mv1.begin(),mv1.end(),mv2.begin(),[](int i){return i*2;});
    std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // generate  ------------------------------------------------------
    std::cout << "----- using < generate > ----- " << std::endl;
    std::generate(mv2.begin(),mv2.end(),[n=0]() mutable {return n+=11;;});
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // remove remove_if  ------------------------------------------------------
    std::cout << "----- using < remove remove_if > ----- " << std::endl;
    auto itu = std::remove(mv2.begin(), mv2.end(), 33);
    std::cout << *itu << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;
    auto itu2 = std::remove_if(mv2.begin(), mv2.end(), [](int i){return i==22;});
    std::cout << *itu2 << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // remove_copy remove_copy_if  ------------------------------------------------------
    mv1 = {11,22,33,44,55};
    mv2 = {66,77,88,22,33};
    std::cout << "----- using < remove_copy remove_copy_if > ----- " << std::endl;
        std::cout << "----- using < remove remove_if > ----- " << std::endl;
    itu = std::remove_copy(mv2.begin(), mv2.end(),mv1.begin(), 55);
    std::cout << *itu << std::endl;
        std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;
    itu2 = std::remove_if(mv2.begin(), mv2.end(), [](int i){return i==88;});
    std::cout << *itu2 << std::endl;
        std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;


    std::cout << std::string(30,'-') << std::endl;
    // // // replace replace_if  ------------------------------------------------------
    std::cout << "----- using < replace replace_if > ----- " << std::endl;
    std::replace(mv2.begin(),mv2.end(),33,44);
     std::cout << "mv1: " ;
    std::for_each(mv1.begin(),mv1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "mv2: " ;
    std::for_each(mv2.begin(),mv2.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl << "&mv1: " << &mv1 << "    &mv2: " << &mv2 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // equal  ------------------------------------------------------
    if(std::equal(mv1.begin(),mv1.end(),mv2.begin())) {
        std::cout << "they are equal;" << std::endl;
    }else{
        std::cout << "they are not equal;" << std::endl;
    }

    std::cout << std::string(30,'-') << std::endl;
    // // // lower_bound upper_bound  ------------------------------------------------------
    // must be sorted
    std::vector<int> sr1{9,2,8,4,6,3,7};
    //sort
    std::sort(sr1.begin(),sr1.end());
    //print sr1
    std::cout << "sr1: " ;
    std::for_each(sr1.begin(),sr1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;     
    int val = 3;
    //lower_bound 
    auto sr_lw_bd = std::lower_bound(sr1.begin(),sr1.end(),val);
    std::cout << "lower bound: " << *sr_lw_bd << std::endl;

    //upper_bound 
    auto sr_up_bd = std::upper_bound(sr1.begin(),sr1.end(),val);
    if(sr_up_bd != sr1.end()){
        std::cout << "upper bound: " << *sr_up_bd << std::endl;
    }else{
        std::cout << "upper bound: End!!!!" << std::endl;
    }

    std::cout << std::string(30,'-') << std::endl;
    // // // binary_search  ------------------------------------------------------
    auto sss = std::binary_search(sr1.begin(),sr1.end(),val);
    if(sss != 0){
        std::cout << "Found -> " << val  << std::endl;
    }else{
        std::cout << "Not found -> " << val << std::endl;
    }

        std::cout << std::string(30,'-') << std::endl;
    // // // include  ------------------------------------------------------
    mv1 = {1,2,3,4,5,6,7,8,9,10};
    mv2 = {3,4,5,6,7,8};
    if(std::includes(mv1.begin(),mv1.end(),mv2.begin(),mv2.end())){
        std::cout << "Included... :)" << std::endl;
    }else{
        std::cout << "Not included." << std::endl;
    }

    std::cout << std::string(30,'-') << std::endl;
    // // // min_element and max_element  ------------------------------------------------------
    std::cout << "Max element: " << *std::max_element(mv1.begin(),mv1.end()) << std::endl;
    std::cout << "Min element: " << *std::min_element(mv1.begin(),mv1.end()) << std::endl;

    std::cout << "Max number: " << std::max(3,4) << std::endl;

    std::cout << "The diff between max and max element: " << std::endl;
    std::cout << "std::max         -> return the max number." << std::endl;
    std::cout << "std::max_element -> return an iterator to the max element." << std::endl;

    auto mm_it = std::minmax_element(mv1.begin(),mv1.end());
    std::cout << "using minmax_element: " << std::endl;
    std::cout << "The min_element: " << *mm_it.first << std::endl;
    std::cout << "The max_element: " << *mm_it.second << std::endl;
    std::cout << "using minmax: " << std::endl;
    std::cout << "The min number: "  << std::minmax(3,2).first << std::endl;
    std::cout << "The max number: " << std::minmax(3,2).second << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    // // // iota  ------------------------------------------------------    
    std::cout << "sr1 before iota: " ;
    std::for_each(sr1.begin(),sr1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    val = 9;
    std::iota(sr1.begin(), sr1.end(), val);
    std::cout << "sr1 after iota : " ;
    std::for_each(sr1.begin(),sr1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;

    // // // accumulate  ------------------------------------------------------    
    std::cout << "sr1 before accumulate: " ;
    std::for_each(sr1.begin(),sr1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    val = 0;
    auto r = std::accumulate(sr1.begin(),sr1.end(),val);
    std::cout << "sr1 after accumulate : " ;
    std::for_each(sr1.begin(),sr1.end(),[](int i){std::cout << i << " " ;});
    std::cout << std::endl;
    std::cout << "accumulation: " << r << " with initial " << val << std::endl;

    return 0;
}
