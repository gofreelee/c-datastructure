/*
走迷宫的一道题，比较有趣的

 */
#include<iostream>
enum{
    up=0,
    down,
    left,
    right
};
/* 
1.检测是否已经到了出口
２．是否是堵死了，如果是，调整方向继续走.
3.正常走
*/
void print(char maze[12][12],int x,int y);
void solve_maze(char maze[12][12],int x,int y,int direction){
        // 检测是否到出口
        if(x==11||y==11){
            print(maze,x,y);
            return;
        }
        print(maze,x,y);
        // 检测是否堵死了
        if(direction==up){
            if(maze[x-1][y]=='#'&&maze[x][y-1]=='#'&&maze[x][y+1]=='#'){
                direction=down;
                solve_maze(maze,x,y,direction);
            }
        }
        else if(direction==down){
            if(maze[x+1][y]=='#'&&maze[x][y-1]=='#'&&maze[x][y+1]=='#'){
                direction=up;
                solve_maze(maze,x,y,direction);
            }
        }
        else if(direction==left){
            if(maze[x][y-1]=='#'&&maze[x+1][y]=='#'&&maze[x-1][y]=='#'){
                direction=right;
                solve_maze(maze,x,y,direction);
            }

        }
        else if(direction==right){
            if(maze[x][y+1]=='#'&&maze[x+1][y]=='#'&&maze[x-1][y]=='#'){
                direction=left;
                solve_maze(maze,x,y,direction);
            }

        }
        if(direction==up){
            if(maze[x][y+1]=='#'&&maze[x][y-1]=='#'){
                solve_maze(maze,x-1,y,direction);
            }
            else if(maze[x][y+1]=='#'&&maze[x][y-1]=='.'){
                direction=left;
                solve_maze(maze,x,y-1,direction);
            }
            else if(maze[x][y+1]=='.'){
                direction=right;
                solve_maze(maze,x,y+1,direction);
            }
        }
        else if(direction==down){
            if(maze[x][y+1]=='#'&&maze[x][y-1]=='#'){
                solve_maze(maze,x+1,y,direction);
            }
            else if(maze[x][y+1]=='#'&&maze[x][y-1]=='.'){
                direction=left;
                solve_maze(maze,x,y-1,direction);
            }
            else if(maze[x][y+1]=='.'){
                direction=right;
                solve_maze(maze,x,y+1,direction);

            }
        }
        else if(direction==left){
            if(maze[x+1][y]=='#'&&maze[x][y-1]=='.'){
                solve_maze(maze,x,y-1,direction);
            }
            else if(maze[x+1][y]=='#'&&maze[x][y-1]=='#'){
                direction=up;
                solve_maze(maze,x-1,y,direction);
            }
            else if(maze[x+1][y]=='.'){
                direction=down;
                solve_maze(maze,x+1,y,direction);
            }
        }
        else if(direction==right){
            if(maze[x+1][y]=='#'&&maze[x][y+1]=='.'){
                //直走
                solve_maze(maze,x,y+1,direction);
            }
            else if(maze[x+1][y]=='#'&&maze[x][y+1]=='#'){
                //上转
                direction=up;
                solve_maze(maze,x-1,y,direction);
            }
            else if(maze[x+1][y]=='.'){
                //下转
                direction=down;
                solve_maze(maze,x+1,y,direction);
            }
        }
            
}
void print(char maze[12][12],int x,int y){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            if(i==x&&j==y){
                std::cout<<' '<<'X';
            }
            else std::cout<<' '<<maze[i][j];
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}

int main(){
    char maze[12][12]={{'#','#','#','#','#','#','#','#','#','#','#','#'},
                       {'#','.','.','.','#','.','.','.','.','.','.','#'},
                       {'.','.','#','.','#','.','#','#','#','#','.','#'},
                       {'#','#','#','.','#','.','.','.','.','#','.','#'},
                       {'#','.','.','.','.','#','#','#','.','#','.','.'},
                       {'#','#','#','#','.','#','.','#','.','#','.','#'},
                       {'#','.','.','#','.','#','.','#','.','#','.','#'},
                       {'#','#','.','#','.','#','.','#','.','#','.','#'},
                       {'#','.','.','.','.','.','.','.','.','#','.','#'},
                       {'#','#','#','#','#','#','.','#','#','#','.','#'},
                       {'#','.','.','.','.','.','.','#','.','.','.','#'},
                       {'#','#','#','#','#','#','#','#','#','#','#','#'}};
    solve_maze(maze,2,1,right);
}