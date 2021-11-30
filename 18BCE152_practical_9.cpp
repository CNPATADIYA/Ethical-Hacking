#include<bits/stdc++.h>
using namespace std;

int n,e,st,en;
map<int,string> mp;
vector<int> attack_graph[100];
vector<vector<int>> paths;
bool vis[100];
void find_path(int v,vector<int> &p){
    if(v==en){
        p.push_back(v);
        paths.push_back(p);
        p.pop_back();
        return;
    }
    p.push_back(v);
    vis[v] = true;
    for(auto &x:attack_graph[v]){
        if(!vis[x]){
            find_path(x,p);
        }
    }
    vis[v] = false; 
    p.pop_back();
}
int main(){
    printf("Enter number of nodes : ");scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s;
        printf("Node %d : ",i);
        cin>>s;
        mp[i] = s;
    }
    printf("\nEnter number of edges : ");scanf("%d",&e);
    printf("Enter %d conncetions : \n",e);
    for(int i=0;i<e;i++){
        int s,d;
        printf("Edge %d : ",i+1);
        scanf("%d%d",&s,&d);
        attack_graph[s].push_back(d);
    }

    printf("\n ++ For Attack Path ++\n");
    printf("Enter source and destination node : ");
    scanf("%d%d",&st,&en);
    printf("\n");
    vector<int> p;
    memset(vis,false,sizeof(vis));
    find_path(st,p);
    if(paths.size()==0) printf("NO path found!!\n");
    else{
        for(auto &x:paths){
            for(auto &y:x){
                cout<<mp[y]<<" ";
            }
            printf("\n");
        }

        printf(" Total %d paths found",paths.size());
    }
    return 0;
}

/*

sample input :


15

(ftp,1,0)
(user,0)
(ftp,2,0)
(ftp_rhosts,0,1)
(ftp_rhosts,0,2)
(rsh,0,1)
(rsh,0,2)
(ftp_rhosts,2,1)
(rsh,2,1)
(sshd_bof,0,1)
(sshd_bof,2,1)
(ftp_rhosts,1,2)
(local_bof,1,1)
(rsh,1,2)
(local_bof,2,2)

22


1 3
1 4
1 5
1 6
1 9
3 5
4 6
5 11
5 12
6 7
6 10
7 8
8 11
8 12
9 11
9 12
9 13
10 11
10 12
10 13
11 13
13 14

1 14
*/