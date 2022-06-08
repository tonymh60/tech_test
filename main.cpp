#include <iostream>
#include <vector>
using namespace std;

void inputVector(vector<int>&); // input values into the vector
int testingVector(vector<int>&); // testing the vector whether in descending order
template < typename T > void printVector( const vector< T > & );// display the vector
template < typename T > void print_reverseVector( const vector< T > & );// display the vector in descending order

int main() {
   vector<int> nums; // 0-element vector<int>
   int k, p, q;
   size_t m;

   cout << "Entering the vector elements: "<< endl;
   inputVector(nums);//entering the vector elements
   cout << "Initial order of the vector elements: "<< endl;
   printVector(nums);//printing the vector elements
   if (testingVector(nums)!=-1){
       cout << "\nVector elements in ascending order: "<< endl;
       print_reverseVector(nums);//if vector elements in descending order, print them in ascending order
   }
   else{
        // find the first decrease working from the right
        m=nums.size()-2;
        while ((nums[ m ] > nums[ m+1 ]))
            m=m-1;
        k=nums.size()-1;
        // find the rightmost element numsk with numsm < numsk
        while (nums[ m ] > nums[ k ])
            k=k-1;
        swap(nums[ m ], nums[ k ] );
        p=m+1;
        q=nums.size()-1;
        while (p < q){
            swap(nums[ p ], nums[ q ] );
		    p=p+1;
		    q=q-1;
    	}
        cout << "\nPermutation of the vector elements: "<< endl;
        printVector(nums);// printing the vector elements (the permutation)
   }
   return 0;
}// end main function

// input vector contents
void inputVector(vector<int>& items) {
    int i{0}, number{0};
    // enter first element
    do{
            cout << "i: "<< i << endl;;
            cout << "Enter first element (between 0 and 100, included both): ";
            cin >> number;
    } while((number <= -1)||(number > 100));
    while ((number != EOF)&&(i < 100)){
            items.push_back(number);
            i++;
            do{
                cout << "i: "<< i << endl;;
                cout << "Enter next element (between 0 and 100, included both, -1 to stop entering): ";
                cin >> number;
            } while(((number <= -2)||(number > 100)));
    }

}// end function inputVector

// testing the vector whether in descending order
int testingVector(vector<int>& items){
    int c{0};
    for (size_t m=0; m< items.size()-1;m++) {
        if (items[ m ] > items[ m+1 ]){
            continue;
        }
        else{
            c=-1;
            break;
        }
    }
    return c;
}// end function testingVector

template < typename T > void printVector( const vector< T > &items )
{
   // display vector elements using const_iterator
   for ( auto constIterator = items.cbegin(); constIterator != items.cend(); ++constIterator )
      cout << *constIterator << ' ';
} // end function printVector

      // display vector in reverse order using const_reverse_iterator
template < typename T > void print_reverseVector( const vector< T > &items )
{
      for ( auto reverseIterator = items.crbegin(); reverseIterator!= items.crend(); ++reverseIterator )
      cout << *reverseIterator << ' ';
      cout << endl;
} // end function print_reverseVector
