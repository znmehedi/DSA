#include<bits/stdc++.h>
using namespace std;
struct Cell{
    int x, y, cost;
    Cell(int x, int y, int cost){
        this->x=x;
        this->y=y;
        this->cost=cost;
    }
};
void findPath(int min_cost, vector<vector<bool>> &maze, vector<vector<bool>> &isVisited,
              pair<int, int> &src, pair<int, int> &dest, unordered_map<string, int> &r_p);
int shortDest(vector<vector<bool>> &maze, pair<int, int> &src, pair<int, int> &dest);
bool isValid(vector<vector<bool>> &maze, vector<vector<bool>> &isVisited, int x, int y);
bool isValid_return(vector<vector<bool>> &maze, vector<vector<bool>> &isVisited, int x, int y);
int main(){
    vector<vector<bool>> maze={
//        {1, 1, 1, 1, 0, 1},
//        {1, 0, 0, 1, 1, 1},
//        {1, 1, 0, 1, 0, 1},
//        {0, 1, 1, 1, 1, 1},
//        {1, 0, 1, 0, 1, 0},
//        {0, 1, 1, 1, 1, 1}
//        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
//        { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
//        { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
//        { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
//        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
//        { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
//        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
//        { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
//        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
//        { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },

////
////
////
        {1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
		{0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 1, 0, 0},
		{1, 0, 0, 1, 0, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
		{1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 0, 1, 1, 1}

    };

    pair<int, int>src=make_pair(0, 0);
    pair<int, int>dest=make_pair(8, 5);

    int cost=shortDest(maze, src, dest);
    if(cost==-1)
    cout<<"Not possible"<<endl;
    else
        cout<<"Min cost is = "<<cost<<endl;

    return 0;
}

int shortDest(vector<vector<bool>> &maze, pair<int, int> &src,
               pair<int, int> &dest){

            if(maze.size()==0 || !maze[src.first][src.second]
               || !maze[dest.first][dest.second])
               return -1;

            vector<vector<bool>> isVisited;
            isVisited.resize(maze.size(), vector<bool>(maze[0].size()));


            queue<struct Cell>q;
            unordered_map<string, int> r_p;
            int min_cost=0;

            q.push(Cell(src.first, src.second, min_cost));


            string temp = to_string(src.first);
            temp.append(to_string(src.second));

            r_p.insert({temp, min_cost});

            isVisited[src.first][src.second]=true;
            int row[]={-1, 0, 0, 1};
            int col[]={0, -1, 1, 0};
            int x, y;
            while(!q.empty()){

                x=q.front().x;
                y=q.front().y;
                min_cost=q.front().cost;
                q.pop();

                if(x==dest.first && y==dest.second)
                    {

                        temp = to_string(dest.first);
                        temp.append(to_string(dest.second));
                                r_p.insert({temp, min_cost});
                        break;
                    }

                for(int i=0;i<4;i++){
                    if(isValid(maze, isVisited, x+row[i], y+col[i]))
                        {
                            //isVisited[x+row[i]][y+col[i]]=true;
                            isVisited[x][y]=true;
                            q.push(Cell(x+row[i], y+col[i], min_cost+1));

                            temp = to_string(x+row[i]);
                            temp.append(to_string(y+col[i]));

                                r_p.insert({temp, min_cost+1});
                        }

                }

            }

            findPath(min_cost, maze, isVisited, src, dest, r_p);
            return (min_cost==0)? -1:min_cost;

}
void findPath(int min_cost, vector<vector<bool>> &maze, vector<vector<bool>> &isVisited,
               pair<int, int> &src, pair<int, int> &dest, unordered_map<string, int> &r_p){

            int row[]={-1, 0, 0, 1};
            int col[]={0, -1, 1, 0};

    int x=dest.first;
    int y=dest.second;

    int cost=min_cost;

    vector<pair<int, int>>path;
    path.push_back({x, y});
    isVisited[x][y]=false;
    string temp;

    while(true)
    {
        if(x==src.first && y==src.second)
            break;

        for(int i=0;i<4;i++){

            if(isValid_return(maze, isVisited, x+row[i], y+col[i])){
                temp = to_string(x+row[i]);
                temp.append(to_string(y+col[i]));

                    if(r_p[temp]<min_cost){
                        x=x+row[i];
                        y=y+col[i];
                        isVisited[x][y]=false;
                        min_cost=r_p[temp];
                        path.push_back({x, y});


                    }
               }

        }


    }

        for(int i=path.size()-1;i>=0;i--)
            cout<<path[i].first<<" "<<path[i].second<<endl;

}

bool isValid(vector<vector<bool>> &maze, vector<vector<bool>> &isVisited, int x, int y){
    return (x>=0 && x<maze.size()) && (y>=0 && y<maze[0].size()) &&
            !isVisited[x][y] && maze[x][y];

}

bool isValid_return(vector<vector<bool>> &maze, vector<vector<bool>> &isVisited, int x, int y){

    return (x>=0 && x<maze.size()) && (y>=0 && y<maze[0].size()) &&
            isVisited[x][y] && maze[x][y];

}
