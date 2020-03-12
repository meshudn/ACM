#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

vector< int > edges[MAX];
vector< int > costs[MAX];

void display_path(int source,int prev[]){
    if(source == 0 || source == 99999) {
       // cout << ">> 1";
        return ;
    }else{
         cout << prev[source] << " >>";
        display_path(prev[source],prev);

    }

}


int main(){

  /*.................
 *
 * Graph input using Vector from STL library
   Data structure : Vector
   author: Meshu Deb Nath
 */

  int N,E,i;
  cin >> N >> E;

  //FILE *input;
  //input = fopen("input.txt","rt");
  //fscanf(input,"%d %d",&N,&E);

  for(i=0;i<E;i++){
    int x,y,z;

    cin >> x >> y >> z;
    //fscanf(input,"%d %d",&x,&y);
    x--;
    y--;
    edges[x].push_back(y);
    //edges[y].push_back(x);

    costs[x].push_back(z);
    //costs[y].push_back(z);
  }
  //fclose(input);

  cout << "***** Input Value ***** " << endl;

 for(int j = 0;j < N;j++){
    int edgeSize = edges[j].size();
    cout << j << "=>";
    for(i = 0;i<edgeSize;i++) cout << edges[j][i] <<"," << costs[j][i] << " ";
    cout << endl;
 }
 cout << "-------------------------" << endl;
  /*.................
 *
 * implementation of bellman ford algorithm
   Data Structure: Graph input by list
   author: Meshu Deb Nath
 */
  int distance[N]; int previous[N];

  for(i=0;i<N;i++){
    distance[i] = 99999;
    previous[i] = 99999;
  }

  distance[0] = 0;

  int u,v,edgeSize;



  for(u=0; u < N-1 ;u++){

    edgeSize = edges[u].size();

    for( i=0 ; i < edgeSize; i++){
        v = edges[u][i];
        if( (distance[u] + costs[u][i] ) < distance[v]){
            previous[v] = u;
            distance[v] = distance[u] + costs[u][i];
        }
    } // end for
  } // end while

  // re relaxing edges for negative cycle
  for(u=0; u < N-1 ;u++){
    edgeSize = edges[u].size();
    for( i=0 ; i < edgeSize; i++){
        v = edges[u][i];
        if( (distance[u] + costs[u][i] ) < distance[v]){
            printf("negative cycle found\n");
        }
    } // end for
  }



  cout << "BFS Traversal result => ";
  for(i=0;i<N;i++)cout << distance[i] <<" ";

  cout << endl;
  cout << 5 << " >> ";
  display_path(4,previous);

  return 0;
}
