// CPP program to find minimum number of
// elements such that their sum is greater
// than sum of remaining elements of the array.
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

// function to find minimum elements needed.
int minElements(int arr[], int n)
{
	// calculating HALF of array sum
	int Sum = 0;
	for (int i = 0; i < n; i++)
		Sum = Sum + arr[i];
	

	// sort the array in descending order.
	sort(arr, arr + n, greater<int>());

	int res = 0, curr_sum = 0;
	for (int i = 0; i < n; i++) {

		curr_sum += arr[i];
		Sum-=arr[i];
		res++;

		// current sum greater than sum
		if (curr_sum > Sum)		
			return res;
	}
	return res;
}

// Driver function
int main()
{
	int arr[] = {3, 1, 7, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minElements(arr, n) << endl;
	return 0;
}
