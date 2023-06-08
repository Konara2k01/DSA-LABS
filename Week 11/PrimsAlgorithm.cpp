#include <iostream>
#include <vector>

using namespace std;

int minVertex(vector<int>& distances, vector<bool>& visited){
    int min = INT_MAX;
    int vertex;
    for(int i=0;i<distances.size();i++)
        if(!visited[i] && distances[i] < min){
            vertex = i;
            min = distances[i];
            continue;
        }
    return vertex;
}

int findMinDist( vector<vector<int>>& cityNetwork ,int src){
    int noCities = cityNetwork.size();

    vector<int> parents(noCities);
    vector<int> distances (noCities,INT_MAX);
    vector<bool> visited (noCities, false);

    parents[src] = -1;
    distances[src] = 0;

    for(int i=0;i<noCities-1;i++){

        auto currentCity = minVertex(distances,visited);
        visited[currentCity] = true;

        auto neighbours = cityNetwork[currentCity];

        for(int neighbour = 0 ; neighbour < noCities; neighbour++){
            int edgeDist = cityNetwork[currentCity][neighbour];
            if( edgeDist && !visited[neighbour] && edgeDist < distances[neighbour] ){

                distances[neighbour] = edgeDist;
                parents[neighbour] = currentCity;

            }
        }
    }
    cout<<"Edge\t"<<"Weight\t"<<endl;
    for(int city =0;city<noCities;city++){
        if(city == src) continue;
        cout<<city<<" - "<<parents[city]<<'\t'<< cityNetwork[city][parents[city]]<<endl;
    }
    cout<<endl;



}




int main() {

    vector<vector<int>> cities {{0,3,0,0,0,1},
                                {3,0,2,1,10,0},
                                {0,2,0,3,0,5},
                                {0,1,3,0,5,0},
                                {0,10,0,5,0,4},
                                {1,0,5,0,4,0}};

    findMinDist(cities,0);

    return 0;
}
