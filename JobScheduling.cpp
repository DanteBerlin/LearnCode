#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparator function to sort jobs based on profit
bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit job sequence
void printJobScheduling(vector<Job>& jobs, int n) {
    // Sort jobs based on profit
    sort(jobs.begin(), jobs.end(), compare);

    // To keep track of free time slots
    vector<bool> slot(n, false);

    // To store the result (sequence of jobs)
    vector<int> result;

    // Traverse through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            // If found a free slot, add the job to result and mark the slot as occupied
            if (slot[j] == false) {
                result.push_back(jobs[i].id);
                slot[j] = true;  // Mark slot as occupied
                break;
            }
        }
    }

    // Print the result
    cout << "The sequence of jobs to maximize profit is:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter the details of each job (id, deadline, profit):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    printJobScheduling(jobs, n);

    return 0;
}
