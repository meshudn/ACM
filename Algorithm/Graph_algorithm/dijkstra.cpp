#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

vector< int > edges[MAX];
vector< int > costs[MAX];

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
    edges[y].push_back(x);

    costs[x].push_back(z);
    costs[y].push_back(z);
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
 * implementation of BFS
   Data structure : Queue
   author: Meshu Deb Nath
 */
  priority_queue <int> Q; int distance[N];

  for(i=0;i<N;i++){
    distance[i] = 99999;
  }

  Q.push( 0 );
  distance[0] = 0;

  int u,v,edgeSize;



  while( ! Q.empty() ){
    u = Q.top();
    Q.pop();

    edgeSize = edges[u].size();
    for( i=0 ; i < edgeSize; i++){
        v = edges[u][i];
        if( (distance[u] + costs[u][i] ) < distance[v]){
            Q.push( v );
            distance[v] = distance[u] + costs[u][i];
        }
    } // end for
  } // end while

  cout << "BFS Traversal result => ";
  for(i=0;i<N;i++)cout << distance[i] <<" ";

  return 0;
}
