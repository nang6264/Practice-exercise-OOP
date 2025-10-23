#include<iostream>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;
class CIntArray {
private: 
	int* m_Array; 
	int m_Length;
public:
	void InputArray();
	void OutputArray();
	CIntArray Remove();
	CIntArray Remove(int);
	CIntArray Remove(int, int);
	CIntArray Replace(int, int);
	CIntArray AddHead(int);
	CIntArray AddTail(int);
	CIntArray Insert(int, int);
	int Max();
	int Min();
	CIntArray Ascending();
	CIntArray Decreasing();
	bool IsSymmetry();
	CIntArray MoveForward();
	CIntArray MoveForward(int);
	CIntArray MoveBehind();
	CIntArray MoveBehind(int);
	CIntArray Invert();
	int Appearance(int);
 };
// Input array
void CIntArray::InputArray() {
	int n; 
	cin >> n; 
	this->m_Length = n;
	this->m_Array = new int[n];
	// create array of size n  , random  array[i] = (-99 to 99);
	for (int i = 0; i < n; i++) {
		this->m_Array[i] = rand() % 199 - 99;
	}
}

// Output array
void CIntArray::OutputArray() {
	cout << "Array: ";
	for (int i = 0; i < this->m_Length; i++) {
		cout << this->m_Array[i] << " ";
	}
}

// Remove duplicate elements
CIntArray CIntArray::Remove() {
	unordered_set<int> s;// create unordered set to store unique elements
	for(int i=0;i<this->m_Length;i++){
		s.insert(this->m_Array[i]);
	}
	int newLength = s.size();
	CIntArray newArray;
	newArray.m_Length = newLength;
	newArray.m_Array = new int[newLength];
	int index = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		newArray.m_Array[index++] = *it;// copy unique elements to new array
	}
	delete[] this->m_Array;
	return newArray;
}

// Remove element at index
CIntArray CIntArray::Remove(int index) {
	int* newArray = new int[this->m_Length - 1];
	for(int i=0,j=0;i<this->m_Length;i++){
		if(i!=index){
			newArray[j++]=this->m_Array[i];
		}
	}
	CIntArray result;
	result.m_Length = this->m_Length - 1;
	result.m_Array = newArray;
	delete[] this->m_Array;
	delete[] newArray;
	return result;
}

// Remove elements from index with length
CIntArray CIntArray :: Remove(int length , int index ){
	if(length>this->m_Length - index){
		length = this->m_Length - index;
	}
	int* newArray = new int[this->m_Length - length];
	int j = 0;
	for (int i = 0; i < this->m_Length; i++) {
		if(i < index || i >= index + length) {
			newArray[j++] = this->m_Array[i];
		}
	}
	CIntArray result;
	result.m_Length = this->m_Length - length;
	result.m_Array = newArray;
	delete[] this->m_Array;
	delete[] newArray;
	return result;
}

// Replace element at index with value
CIntArray CIntArray::Replace(int oldElement, int newElement) {
	for(int i=0;i<this->m_Length;i++){
		if(this->m_Array[i]==oldElement){
			this->m_Array[i]=newElement;
		}
	}
	return *this;
}

// Add element at head
CIntArray CIntArray::AddHead(int element) {
	int *newArray = new int[this->m_Length + 1];
	newArray[0] = element;
	for(int i=0;i<this->m_Length;i++){
		newArray[i+1]=this->m_Array[i];
	}
	CIntArray result;
	result.m_Length = this->m_Length + 1;
	result.m_Array = newArray;
	delete[] this->m_Array;
	delete[] newArray;
	return result;
}

// Add element at tail
CIntArray CIntArray::AddTail(int element) {
	int *newArray = new int[this->m_Length + 1];
	for(int i=0;i<this->m_Length;i++){
		newArray[i]=this->m_Array[i];
	}
	newArray[this->m_Length] = element;
	CIntArray result;
	result.m_Length = this->m_Length + 1;
	result.m_Array = newArray;
	delete[] this->m_Array;
	delete[] newArray;
	return result;


}

// Insert element at index
CIntArray CIntArray::Insert(int element , int index) {
	int* newArray = new int[this->m_Length + 1];
	int j = 0;
	for (int i = 0; i < this->m_Length + 1; i++) {
		if (i == index) {
			newArray[i] = element;
		}
		else {
			newArray[i] = this->m_Array[j++];
		}
	}
	CIntArray result;
	result.m_Length = this->m_Length + 1;
	result.m_Array = newArray;
	delete[] this->m_Array;
	delete[] newArray;
	return result;


}

// Get maximum element
int CIntArray::Max() {
	int maxElement = this->m_Array[0];
	for(int i=1;i<this->m_Length;i++){
		if(this->m_Array[i]>maxElement){
			maxElement=this->m_Array[i];
		}
	}
	return maxElement;
}

// Get minimum element
int CIntArray::Min() {
	int minElement = this->m_Array[0];
	for(int i=1;i<this->m_Length;i++){
		if(this->m_Array[i]<minElement){
			minElement=this->m_Array[i];
		}
	}
	return minElement;

}

// Sort array in ascending order
CIntArray CIntArray::Ascending() {
	int* newArray = new int[this->m_Length];
	for(int i=0;i<this->m_Length;i++){
		newArray[i]=this->m_Array[i];
	}
	sort(newArray, newArray + this->m_Length);
	delete[] this->m_Array;
	this->m_Array = newArray;
	this->m_Length = this->m_Length;
	return *this;
}
// Sort array in decreasing order
CIntArray CIntArray::Decreasing() {
	int* newArray = new int[this->m_Length];
	for (int i = 0; i < this->m_Length; i++) {
		newArray[i] = this->m_Array[i];
	}
	sort(newArray, newArray + this->m_Length, greater<int>());
	delete[] this->m_Array;
	this->m_Array = newArray;
	this->m_Length = this->m_Length;
	return *this;
}

// Check if array is symmetric
bool CIntArray::IsSymmetry() {
	for(int i=0;i<this->m_Length/2;i++){
		if(this->m_Array[i]!=this->m_Array[this->m_Length - i - 1]){
			return false;
		}
	}
	return true;

}

// Move elements forward by one position
CIntArray CIntArray::MoveForward() {
	int* newArray = new int[this->m_Length - 1];
	int j = 0;
	for(int i=1;i<this->m_Length;i++){
		newArray[j++]=this->m_Array[i];
	}
	this->m_Array = newArray;
	this->m_Length = this->m_Length - 1;
	return *this;
}

// Move elements forward by n positions
CIntArray CIntArray::MoveForward(int n) {
	if (n> this->m_Length) {
		this->m_Array = nullptr;
		this->m_Length = 0;
	}
	else {
		int* newArray = new int[this->m_Length - n];
		int j = 0;
		for (int i = n; i < this->m_Length; i++) {
			newArray[j++] = this->m_Array[i];
		}
		this->m_Array = newArray;
		this->m_Length = this->m_Length - n;
		delete[]newArray;
	}
	return *this;
	
}

// Move elements backward by one position
CIntArray CIntArray::MoveBehind() {
	int* newArray = new int[this->m_Length - 1];
	int j = 0;
	for(int i=0;i<this->m_Length - 1;i++){
		newArray[j++]=this->m_Array[i];
	}
	this->m_Array = newArray;
	this->m_Length = this->m_Length - 1;
	return *this;
}

// Move elements backward by n positions
CIntArray CIntArray::MoveBehind(int n) {
	if (n > m_Length) {
		this->m_Array = nullptr;
		this->m_Length = 0;
	
	}
	else {
		int* newArray = new int[m_Length - n];
		int j = 0;
		for (int i = 0; i < m_Length - n; i++) {
			newArray[j++] = this->m_Array[i];
		}
		this->m_Array = newArray;
		this->m_Length = m_Length - n;
		delete[]newArray;
	}
	return *this;

}

// Invert the array
CIntArray CIntArray::Invert() {
	int* newArray = new int[this->m_Length];
	for(int i=0;i<this->m_Length;i++){
		newArray[i]=this->m_Array[this->m_Length - i - 1];
	}
	this->m_Array = newArray;
	delete[] newArray;
	return *this;
}

// Count appearances of a value
int CIntArray::Appearance(int element) {
	int count = 0;
	for(int i=0;i<this->m_Length;i++){
		if(this->m_Array[i]==element){
			count++;
		}
	}
	return count;
}
