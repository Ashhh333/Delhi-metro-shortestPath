#include<bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const int NUM_STATIONS = 195;
//*************************************DIJSKTRA IMPLEMENTATION******************************************************************************/////////
void IMPLEMENT_dijsktra(int source,int destination,vector<int>&Shortest_Route,int &Time,vector<vector<int>>& distanceMatrix,unordered_map<int,int>&lineMap){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>Distance(NUM_STATIONS,INF);
 vector<int>Path(NUM_STATIONS,0);
pq.push({0,source});
Path[0]=source;
Distance[source]=0;
int chck=0;
int parent_line=0;
while(pq.size()){
        int node=pq.top().second;
        if(node==destination) break;
        int diss=pq.top().first;
        pq.pop();
        for(int i=0;i<NUM_STATIONS;i++){
        int newn=i;
        int newd=distanceMatrix[node][i];
        if(newd!=INF){
          int child_line=lineMap[newn];
           int parent_line=lineMap[Path[node]];
         int posd;
        if(node!=97&&node!=87&&node!=24&&node!=37&&node!=21&&node!=80&&node!=86&&node!=67&&node!=65&&node!=116&&node!=154&&node!=60&&node!=63&&node!=11&&node!=5&&node!=15){
            posd=newd+diss;
            
        }
        else{
            if(parent_line!=child_line){
                if(node==116||node==154)
                        posd=newd+diss+5;
                        else posd=newd+diss+10;
            }
      
        else{ posd=newd+diss;}
        }
        if(Distance[newn]>posd){
        Distance[newn]=posd;
        pq.push({posd,newn});
        Path[newn]=node;
                     } 
            }  
        }
      
}     
int i=destination;Shortest_Route.push_back(destination);
while(i!=source){
Shortest_Route.push_back(Path[i]);
i=Path[i];
}
reverse(Shortest_Route.begin(),Shortest_Route.end());
Time=Distance[destination];
}

//***********************************************************************************************************************************************************//
//**************************************LOADING STATIONS FROM STATIONS.CSV*********************************************************************/////
vector<string> loadStations(const string& filename) {
    vector<string> stations;
    ifstream inFile(filename);
    string line;
    int index = 0;
    while (getline(inFile, line) && index < NUM_STATIONS) {
        if (!line.empty()) {
            stations.push_back( line);
        }
    }
    inFile.close();
    return stations;
}
//******************************************************************************************************************************************************//
///*********************************************LOADING CONNECTIONS AND FORMATION OF DISTANCE_MATRIX*******************************************
void loadConnections(const string& filename, vector<vector<int>>& matrix, const unordered_map<string, int>& stationIndexMap) {
    ifstream inFile(filename);
    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            stringstream ss(line);
            string station1, station2, distanceStr;
            getline(ss, station1, ',');
            getline(ss, station2, ',');
            getline(ss, distanceStr, ',');
             station1.erase(0, station1.find_first_not_of(" \t\n\r\f\v"));
            station1.erase(station1.find_last_not_of(" \t\n\r\f\v") + 1);
            station2.erase(0, station2.find_first_not_of(" \t\n\r\f\v"));
            station2.erase(station2.find_last_not_of(" \t\n\r\f\v") + 1);
            int distance = stoi(distanceStr);
               if (stationIndexMap.find(station1) == stationIndexMap.end()) {
                cerr << "Station " << station1 << " not found in station index map!" << endl;
                continue; // Skip this line
            }
            if (stationIndexMap.find(station2) == stationIndexMap.end()) {
                cerr << "Station " << station2 << " not found in station index map!" << endl;
                continue; // Skip this line
            }
            int idx1 = stationIndexMap.at(station1);
            int idx2 = stationIndexMap.at(station2);
            matrix[idx1][idx2] = distance;
            matrix[idx2][idx1] = distance; // bidirectional connections
        }
    }
    inFile.close();
}
//****************************************************************************************************************************************************************
int main(){
     vector<vector<int>> distanceMatrix(NUM_STATIONS, vector<int>(NUM_STATIONS, INF));

    // Initialize the diagonal to 0 (distance from a station to itself)
    for (int i = 0; i < NUM_STATIONS; ++i) {
       
        distanceMatrix[i][i] = 0;
    }

      vector<string> stations = loadStations("Stations.csv");
        unordered_map<string,int > stationIndexMap;
        unordered_map<int,int>lineMap;
    for (int i = 0; i<=36; ++i) {
        stationIndexMap[stations[i]] = i;//yellow
        lineMap[i]=0;
    }
     for (int i = 37; i<=60; ++i) {
        stationIndexMap[stations[i]] = i;//magenta
        lineMap[i]=1;
    }
      for (int i = 61; i<=96; ++i) {
        stationIndexMap[stations[i]] = i;//pink
        lineMap[i]=2;
    }
      for (int i = 97; i<=146; ++i) {
        stationIndexMap[stations[i]] = i;//blue
        lineMap[i]=3;
    }
      for (int i = 147; i<=172; ++i) {
        stationIndexMap[stations[i]] = i;//red
        lineMap[i]=4;
    }
      for (int i = 173; i<=193; ++i) {
        stationIndexMap[stations[i]] = i;//green
        lineMap[i]=5;
    }



       loadConnections("connections.csv", distanceMatrix, stationIndexMap);
      string source="Dwarka Mor";
      string destination="Shahdara";
      int source_id=stationIndexMap[source];
      int dest_id=stationIndexMap[destination];
       int Time;
      vector<int>Shortest_Route;
      
     IMPLEMENT_dijsktra(source_id,dest_id,Shortest_Route,Time,distanceMatrix,lineMap);

     cout<<"STATIONS"<<"  "<<"LINE_NO"<<endl;;
     for(int i=0;i<Shortest_Route.size();i++){
        cout<<stations[Shortest_Route[i]]<<"  "<<lineMap[Shortest_Route[i]]<<endl;
        for(int j=0;j<5&&i!=Shortest_Route.size()-1;j++){
            cout<<"|"<<endl;;
        }
     }
    cout<<endl;
    cout<<"TRAVEL TIME : "<<Time;

   


}