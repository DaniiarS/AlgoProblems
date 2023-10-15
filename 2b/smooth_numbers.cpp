#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iterator>

int main(){
    int n;
    std:: cin >> n;
    std:: map< int, std:: vector<std:: string> > smoothNums;

    smoothNums.insert( std::pair< int, std::vector<std:: string> >(1, {"1", "2", "3", "4", "5", "6", "7", "8", "9"} ) );
    std:: map< int, std:: vector< std:: string > >:: iterator itr;
    
    int amount[n];
    amount[0] = smoothNums.at( 1 ).size();
    itr = smoothNums.begin();
    int size;

    for( int i = 0; i < n - 1; i++  ){
        std:: vector< std::string > nums;
        size = ( itr -> second ).size();

        for( int j = 0; j < size; j++ ){

            if( (itr -> second)[j].back() == '0' ){
                for( int k = 0; k < 2; k++ ){
                    char digit = '0' + k;
                    std:: string char_to_string;
                    char_to_string.push_back( digit );
                    nums.push_back( (itr -> second)[j] + char_to_string );
                }
            }
            else if( (itr -> second)[j].back() == '9' ){
                for( int k = 0; k < 2; k++ ){
                    char digit = '9' - k;
                    std:: string char_to_string;
                    char_to_string.push_back( digit );
                    nums.push_back( (itr -> second)[j] + char_to_string );
                }
            }
            else{
                for( int k = 0; k < 3; k++ ){
                    char digit = ( itr -> second )[j].back() + k - 1;
                    std:: string char_to_string;
                    char_to_string.push_back( digit );
                    nums.push_back( (itr -> second )[j] + char_to_string );
                }
            }

        }
        amount[ itr -> first ] = nums.size();
        smoothNums.insert( std:: pair< int, std:: vector< std:: string> >( (itr -> first) + 1, nums ));
        (itr->second).clear();
        itr++;
    }


    std:: cout << amount[n - 1];
}