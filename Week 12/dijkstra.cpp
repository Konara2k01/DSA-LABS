#include <iostream>
#include <vector>

using namespace std;

int getMinVertex(const vector<int>& time, const vector<bool>& visited ){
    int min = INT_MAX, minIdx;
    for(int v=0; v < time.size(); v++){
        if(time[v] <= min && !visited[v]){
            min=time[v];
            minIdx = v;
        }
    }
   return minIdx;
}

bool hasEdge(vector<vector<int>>& graph,int from,int to){
    return graph[from][to] !=0;
}

double calculateAndPrint(vector<int>& time, int src){
   int totalTime =0;

    cout<<"Source City: "<<src<<endl<<endl;
    for(int i=0; i < time.size(); i++){
        int shortestTime = time[i];
        cout << i << "\t" << shortestTime << endl;
        totalTime+=shortestTime;
    }
    double averageTime = (double)totalTime/(time.size()-1);
    cout<<"\nAverage Time: "<<averageTime<<endl<<endl<<endl;
    return averageTime;
}

vector<int> dijkstra(vector<vector<int>>& cityNetwork , int src){
    int noCities = cityNetwork.size();

    vector<int> time(noCities, INT_MAX);
    vector<bool> visited(noCities, false);

    time[src]=0;

    for(int v=0; v < noCities - 1; v++){

        auto currentCity = getMinVertex(time, visited);
        visited[currentCity]=true;

        for(int neighbourCity = 0; neighbourCity < noCities ; neighbourCity++ ){

            auto hasRoad = hasEdge(cityNetwork, currentCity, neighbourCity);

            if(!visited[neighbourCity] && hasRoad) {
                auto currentDist = time[neighbourCity];
                auto newDist = time[currentCity] + cityNetwork[currentCity][neighbourCity];

                if(currentDist>newDist)
                    time[neighbourCity]= newDist;
            }
        }
    }
    return time;
}

void selectTheBestCity(vector<vector<int>>& cityNetwork){
    double minTime = INT_MAX;
    vector<int> bestCities;

    for(int sourceCity = 0; sourceCity < cityNetwork.size(); sourceCity++){
        auto time = dijkstra(cityNetwork, sourceCity);
        auto currentAvgTime = calculateAndPrint(time,sourceCity);
        if(minTime>currentAvgTime){
            bestCities.clear();
            bestCities.push_back(sourceCity);
            minTime = currentAvgTime;
        }
        else if (minTime==currentAvgTime)
            bestCities.push_back(sourceCity);

    }

    cout<<"Best City/ies : ";
    for(auto& city:bestCities)
        cout<<city<<' ';
    cout<<endl;

}


int main() {

    vector<vector<int>> cityNetwork = {{0,10,0,0,15,5},
                                      {10,0,10,30,0,0},
                                      {0,10,0,12,5,0},
                                      {0,30,12,0,0,20},
                                      {15,0,5,0,0,0},
                                      {5,0,0,20,0,0}};


    selectTheBestCity(cityNetwork);



    return 0;
}
