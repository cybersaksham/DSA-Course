/*
You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.
A queue is maintained for buying the tickets and every person has attached with a priority (an integer, 1 being the lowest priority). The tickets are sold in the following manner -
1. The first person (pi) in the queue asked to comes out.
2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).
Giving a ticket to a person takes exactly 1 minutes and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.
Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.

Input Format :
Line 1 : Integer N (Total number of people standing in queue)
Line 2 : Integer k (index of your priority)
Line 3 : Priorities of every person (n space separated integers)
*/

#include <iostream>
#include <queue>
using namespace std;

int getMyTime(queue<int> &persons, int n, int k) {
    priority_queue<int> pq;
    for(int i=0; i<n; i++) {
        int a = persons.front();
        pq.push(a);
        persons.pop();
        persons.push(a);
    }

    int time = 0;

    for(int i=0; i<=k; i++) {
        int a = persons.front();
        persons.pop();
        if(i < k) {
            if(a == pq.top()) {
                pq.pop();
                time++;
                n--;
            }
            else {
                persons.push(a);
            }
        }
        else {
            if(a == pq.top()) time++;
            else {
                persons.push(a);
                i = -1;
                k = n - 1;
            }
        }
    }

    return time;
}

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> persons;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        persons.push(a);
    }

    cout << getMyTime(persons, n, k) << endl;

    return 0;
}