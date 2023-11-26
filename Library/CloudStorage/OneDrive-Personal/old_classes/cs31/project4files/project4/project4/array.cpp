//
//  array.cpp
//  project4
//

#include <iostream>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);


int main(int argc, const char * argv[]) {
    // insert code here...
//    string names[9] = {"james","edward","sean","frank","mary","liz","theresa","mary","tony"};
//    string list1[6] = { "david", "david", "calvin", "jamie", "jilly", "jilly" };
//    string list2[] ={"tony" ,"liz"};
    
    
    string list1[9] = {"james","edward","sean","frank","mary","liz","theresa","mary","tony"};
    string list2[6] = {"justin", "calvin", "brayeden","liz", "samantha", "marissa"};
    string list3[5] = {"edward","sean","frank","mary","liz"};
    
    
    
    
//    assert(split(list1, 9, "abraham") == 0);
//    assert(split(list1, 9, "greg") == 2);
//    assert(split(list1, 9, "kris") == 3);
//    assert(split(list1, 9, "nigel") == 6);
//    assert(split(list1, 0, "xander") == 0);

    
    
    for(int i =0; i < 9; i++){
        cerr << "\"" << list1[i] << "\", ";
    }
    
    
    cerr << "\ntest succeeds, probably\n";
    
    return 0;
}

//  Notwithstanding each function's behavior described below, all functions that
//  return an int must return −1 if they are passed any bad arguments (e.g. a
//  negative array size, or a position that would require looking at the contents of
//  an element past the last element we're interested in). Unless otherwise noted,
//  passing 0 to the function as the array size is not itself an error; it merely
//  indicates the function should examine no elements of the array.



int appendToAll(string a[], int n, string value){
    if(n < 0){      return -1;      }
    
    for(int i = 0; i < n; i++){
        a[i] += value;
    }
    return n;
}

int lookup(const string a[], int n, string target){
    
    for(int i = 0; i < n; i++){
        if (a[i] == target)
            return i;
    }
    
    return -1;
}

int positionOfMax(const string a[], int n){
    if(n <= 0){      return -1;      }
    
    int maxIndex = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
    
}

int rotateLeft(string a[], int n, int pos){
    if(n <= 0 || !(pos < n) || pos < 0){      return -1;      }
    
    
    string temp = a[pos];
    for (int i = pos + 1; i < n; i++ ){
        a[i-1] = a [i];
    }
    a[n-1] = temp;
    
    return pos;
}


int countRuns(const string a[], int n){
    if(n < 0){      return -1;      }
    if (n == 0)
        return 0;

    int numRuns = 1;
    for (int i = 1; i < n; i++){
        if (a[i] != a[i-1])
            numRuns++;
    }
    return numRuns;
}

int flip(string a[], int n){
    if(n < 0){      return -1;      }
    
    for (int i = 0; i < (n+1)/2; i++){
        string temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    return n;
}
int differ(const string a1[], int n1, const string a2[], int n2){
    if(n1 < 0 || n2 < 0){      return -1;      }

    int i = 0;
    for (; i < n1 && i < n2; i++){
        if (a1[i] != a2[i])
            break;
    }
    return i;
}

int subsequence(const string a1[], int n1, const string a2[], int n2){
    if (n2 > n1 || n1 < 0){     return -1;      }
    if (n2 == 0)
        return 0;
    
    for (int i = 0; i < n1; i++){
        bool sequenceFound = false;
        if(a1[i] == a2[0]){
            for (int j = 0; j < n2; j ++){
                sequenceFound = true;
                if (a1[i + j] != a2[j]){
                    sequenceFound = false;
                }
            }
        }
        if(sequenceFound)
            return i;
    }
    return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2){
    if (n2 < 0 || n1 < 0){     return -1;      }
    
    
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            if(a1[i] == a2[j])
                return i;
        }
    }
    
    
    return -1;
}

int split(string a[], int n, string splitter){
    if(n < 0){      return -1;      }

    int i = 0;
    for(int i = 0; i < n; i++){
        if (a[i] > splitter)
            rotateLeft(a, n, i);
    }
    
    for(i = 0; i < n; i++){
        if (a[i] > splitter)
            break;
    }
    
    return i;
}
