#include <iostream>
#include <vector>

using namespace std;

int numinv;

void mergeSort(vector<int>& numvec, int left, int right);
int merge(vector<int>& numvec , int left, int mid, int right);

int countInv(vector<int>& numvec) {
    numinv = 0;
    mergeSort(numvec, 0, numvec.size());
    cout << "Sorted output: ";
    for (auto ele : numvec)
	    cout << ele << " ";
	cout << right << endl;
    return numinv;
    
}

//Sorts the input vector and returns the number of inversions in that vector
void mergeSort(vector<int>& numvec, int left, int right){

    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(numvec, left, mid);
        mergeSort(numvec, (mid+1), right);
        numinv += merge(numvec, left, mid, right);
    }
    
}

int merge(vector<int>& numvec , int left, int mid, int right){
    int invcount = 0;
//temp array
    int temp[right];

    int i = left; 
    int j = mid+1; 
    int k = 0;


while(i <= mid && j <= right ) {
    if(numvec[i] <= numvec[j]) {
        temp[k++] = numvec[i++];
        }
    else {
        temp[k++] = numvec[j++];
        invcount += (mid  -i +1);
    }
}

// add elements left in the first interval
while(i <= mid) {
    temp[k++] = numvec[i++];
}

// add elements left in the second interval
while(j <= right) {
    temp[k++] = numvec[j++];
}

// copy temp to original interval
for(i = left; i <= right; i++) {
    numvec[i] = temp[i - left];
}
    return invcount;
}
