#include <bits/stdc++.h>
using namespace std;

//Function to sort the array according to smallest value of second element in array
static bool Compare(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
}

//Function to print total activities
void printActivties(vector<pair<int,int>>& arr){
            cout<<"Activities that a single Person Can Select Are : "<<endl;
            for(int i=0;i<arr.size();i++){
                cout<<arr[i].first<<","<<arr[i].second<<endl;
            }
            cout<<endl;
}

//Function to select activities
int activitySelection(vector<int> start, vector<int> end, int n,vector<pair<int,int>>& activties)
{
        //Storing start and end array in a 2d array
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({start[i],end[i]});
        }
    
        //Sorting Array according to ending time 
        sort(arr.begin(),arr.end(),Compare);
    
        //There will be atleast one activity
        int Total_Activity = 1;
    
        //Activity that is ending first
        int endValue = arr[0][1];
        
        //Pushing the first activity
        activties.push_back({arr[0][0],arr[0][1]});
        
        for(int i=1;i<n;i++){
            //if start time of ith activity is greater than ending time of previous taken activity then update ending time, increase the value of activity 
and store the answer in activities array
            if(arr[i][0]>endValue){
                endValue = arr[i][1];
                Total_Activity++;
                activties.push_back({arr[i][0],arr[i][1]});
            }
        }
        
        return Total_Activity;
}

int main() {
    //Adding elements in array of Starting and Ending duration for activity
    vector<int> start = {10,15,30,45,50,65};
    vector<int> end =   {20,25,40,60,55,80};
    
    //Size of the array
    int n = start.size();     //Total activites array that a single person can select
    vector<pair<int,int>> activities;
    
    //Funtion Call for finding total activities to select by single person
    int totalActivity = activitySelection(start,end,n,activities);
    
    //Printing the activities that can select
    cout<<"Total Activities Are : "<< totalActivity <<endl;
    printActivties(activities);
    
    return 0;
}
