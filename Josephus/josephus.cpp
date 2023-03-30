/*
There are N people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. 

Given the total number of persons N and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. The task is to choose the person in the initial circle that survives.

Input: N = 5 and k = 2
Output: 3
Explanation: Firstly, the person at position 2 is killed, 
then the person at position 4 is killed, then the person at position 1 is killed. 
Finally, the person at position 5 is killed. So the person at position 3 survives. 


Josephus Problem using  Queue :
Approach:
I am using queue data structure, so that i can move the items from one end to another linearly.
we have given ‘K’ the moves we can shift, so after shifting K-1 items to the end of the queue, I am deleting the front element.
On repeating the above step, a stage will come when only one element will be left, this is answer itself.
*/

#include <iostream>
#include <queue> // include the queue library
using namespace std;

int findTheWinner(int n, int k) {

	queue<int> q; // create a queue to store the players

	// add all players to the queue
	int i=1;
	while(i<=n){
		q.push(i);
		i++;
	}

	// loop until there is only one player left in the queue
	while(q.size()!=1){

		// move the first k-1 players from front to back of the
	//queue in circular manner
		int j=1;
		while(j<k){
			int temp=q.front();
			q.push(temp);
			q.pop();
			j++;
		}

		// remove the kth player from the front of the queue and eliminate them
		q.pop();
	}

	// return the last remaining player as the winner of the game
	return q.front();
}

int main() {
	int n=4, k=2; // set n and k to the desired values

	// call the findTheWinner function and store the result in ans
	int ans = findTheWinner(n,k);

	// print the winner to the console
	cout << "The winner is player " << ans << endl;
	return 0; // indicate successful program termination
}
