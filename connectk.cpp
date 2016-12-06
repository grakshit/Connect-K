//Running format is: <object file> <ip of server> <port no>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
#include <bits/stdc++.h>
/* Added Code */
#include <time.h> 
#include <sys/time.h> 
/* */

#define FOR(i,n) for (int i = 0; i < n; i++)
#define PB push_back
using namespace std;

int N, M, K, player;
vector<string> board;
vector<string> board1;


double time_left = 0;

void update2(int n,char c)
{
    for(int i = 0; i < N; i++)
        if(board1[i][n] == '.')
        {
            board1[i][n] = c;
            return;
        }
}



void update(int n, int player)
{
    for(int i = 0; i < N; i++)
        if(board[i][n] == '.')
        {
            if(player == 1)
              board[i][n] = 'X';
            else
              board[i][n] = 'O';
            return;
        }
}
bool isTerminal(string []);

bool isempty(string node []){
for (int i =0; i<N; i++){

	for (int j =0; j<M; j++){if(node[i][j]!='.') return false;}	


}
	return true;
}


bool isTerminal(string node []){
for (int i =0; i<N; i++){

	for (int j =0; j<M; j++){if(node[i][j]=='.') return false;}	


}
	return true;
}

pair<int,int> score(string node [])
{
    int arr[2] = {0, 0};
    int k = K;
    for(int i = 0; i < 0 + N; i++)
    {
        for(int j=0;j<M;j++)
        {
            if(node[i][j] == '.')
                continue;
            int l_k = 0;
            // diagonally upwards
            for(;l_k < k && j+l_k< M && i-l_k>=0; l_k++)
            {
                if(node[i][j] != node[i - l_k][j + l_k])
                    break;
            }
            if(l_k == k)
                arr[node[i][j] == 'O']++;

            l_k = 0;
            // rightside
            for(;l_k < k && j+l_k< M; l_k++)
            {
                if(node[i][j] != node[i][j + l_k])
                    break;
            }
            if(l_k == k)
                arr[node[i][j] == 'O']++;          

            l_k = 0;
            // diagonally downwards
            for(;l_k < k && j+l_k< M && i+l_k<N; l_k++)
            {
                if(node[i][j] != node[i + l_k][j + l_k])
                    break;
            }
            if(l_k == k)
                arr[node[i][j] == 'O']++;

            l_k = 0;
            // downwards
            for(;l_k < k &&  i+l_k<N; l_k++)
            {
                if(node[i][j] != node[i + l_k][j])
                    break;
            }
            if(l_k == k)
                arr[node[i][j] == 'O']++;
        }
    }

    return make_pair(arr[0], arr[1]);
}

int score_2(string node  [])
{
    int arr[2] = {0, 0};
    int k = K;
    for(int i = 0; i < N; i++)
    {
        for(int j=0;j<M;j++)
        {
            if(node[i][j] == '.')
                continue;
            int l_k = 0;
            int check = 0;
            // diagonally upwards
            for(;l_k < k && j+l_k< M && i-l_k>=0; l_k++)
            {
                if(node[i][j] != node[i - l_k][j + l_k]){
                	if (node[i - l_k][j + l_k] == '.'){check = 1;}
                    break;
                }
            }
            if(l_k == k-1 && check ==1){
                arr[node[i][j] == 'O']++;
            }

            l_k = 0;
            check =0 ;
            // rightside
            for(;l_k < k && j+l_k< M; l_k++)
            {
                if(node[i][j] != node[i][j + l_k]){
                	if (node[i][j + l_k] == '.'){check =1;}
                    break;
                }
            }
            if(l_k == k-1 && check ==1){
                arr[node[i][j] == 'O']++;          
            }

            l_k = 0;
            check = 0;
            // diagonally downwards
            for(;l_k < k && j+l_k< M && i+l_k<N; l_k++)
            {
                if(node[i][j] != node[i + l_k][j + l_k]){
                	if (node[i + l_k][j + l_k] == '.'){check = 1;}
                    break;
                }
            }
            if(l_k == k-1 && check ==1 ){
                arr[node[i][j] == 'O']++;
            }

            l_k = 0;
            check =0;
            // downwards
            for(;l_k < k &&  i+l_k<N; l_k++)
            {
                if(node[i][j] != node[i + l_k][j]){
                	if (node[i + l_k][j] == '.') {check =1;}
                    break;
                }
            }
            if(l_k == k-1 && check ==1){
                arr[node[i][j] == 'O']++;
            }
        }
    }

    return (arr[0]-arr[1]);
}

int abs1(int x){
if(x<0){return -1*x;}
return x;
}


int evals1(string node){

int arr[2] = {0,0};
int cnt = 0;int cntx,cnto;cntx = cnto = 0;int k = 0;
while(node[k]){
if(node[k]=='.'){++cnt;}
if(node[k]=='O'){
if(cnt!=0){cnto = cnto+cnt;

}

if(cntx!=0){

cntx = cntx+cnt;if(cntx>=K){arr[0] = arr[0]+cntx-K+1;}
cntx = 0;
}
cnt = 0;
++cnto;
if(cnto>=K){++arr[1];}
}


if(node[k]=='X'){
if(cnt!=0){cntx = cntx+cnt;

}

if(cnto!=0){

cnto = cnto+cnt;

if(cnto >= K){arr[1] = arr[1]+cnto-K+1;}cnto = 0;
}
cnt = 0;
++cntx;
if(cntx>=K){++arr[0];}
}

++k;

}

return arr[0]-arr[1];
}




pair<int,int> score_4(string node  [])
{
    int arr[2] = {0, 0};int ans = 0;

for(int i = 0;i < M;++i){

string s1 = "";int cnt = 0;int cntx,cnto;int k = i;
for(int j = 0;j < N;++j){if(node[j][k]!='.'){s1.append(1,node[j][k]);}}


//ans=ans+abs1((M/2)-2-abs1(i-M/2))*evals1(s1);
}






for(int i = 0;i < N;++i){

string s1 = "";int cnt = 0;int cntx,cnto;int k = i;
for(int j = 0;j < M;++j){s1.append(1,node[k][j]);}

ans=ans+evals1(s1);
}

for(int i = 0;i < N;++i){
int k = i;string s1 = "";
for(int j = 0;j < M && k < N ;++j){s1.append(1,node[k][j]);++k;}
ans=ans+evals1(s1);

s1 = "";k = i;
for(int j = 0;j  < M && k >= 0 ;++j){s1.append(1,node[k][j]);--k;}
ans=ans+evals1(s1);


}


for(int i = 0;i < N;++i){


int k = i;string s1 = "";
for(int j = M-1;j >=0 && k < N ;--j){s1.append(1,node[k][j]);++k;}
ans=ans+evals1(s1);

s1 = "";k = i;
for(int j = M-1;j  >=0 && k >= 0 ;--j){s1.append(1,node[k][j]);--k;}
ans=ans+evals1(s1);


}




return make_pair(ans,0);
}



int pow1(int a,int b){return a*b;}

int evals(string node){

int arr[2] = {0,0};
int cnt = 0;int cntx,cnto;cntx = cnto = 0;int k = 0;
while(node[k]){
if(node[k]=='.'){++cnt;}
if(node[k]=='O')
{
if(cnt!=0){cnto = cnto+cnt;

}

if(true){

cntx = cntx+cnt;
//arr[0] = arr[0]+pow(2,cntx);
if(cntx>=K){arr[0] = arr[0]+pow1(2,cntx);}
else{arr[0] = arr[0]-pow1(2,cntx);}
cntx = 0;
}
cnt = 0;
++cnto;
//if(cnto>=K){++arr[1];}
}


if(node[k]=='X'){
if(cnt!=0){cntx = cntx+cnt;

}

if(true){

cnto = cnto+cnt;

//arr[1] = arr[1]+pow(2,cntx);
if(cnto>=K){arr[1] = arr[1]+pow1(2,cnto);}
else{arr[1] = arr[1]-pow1(2,cnto);}

cnto = 0;
}
cnt = 0;
++cntx;
//if(cntx>=K){++arr[0];}
}





++k;

}


if(true){

cnto = cnto+cnt;
//arr[1] = arr[1]+pow(2,cntx);
if(cnto>=K){arr[1] = arr[1]+pow1(2,cnto);}
else{arr[1] = arr[1]-pow1(2,cnto);}
cnto = 0;

}



if(true){

cntx = cntx+cnt;//arr[0] = arr[0]+pow(2,cntx);
if(cntx>=K){arr[0] = arr[0]+pow1(2,cntx);}
else {arr[0] = arr[0]-pow1(2,cntx);}
cntx = 0;

}


return arr[0]-arr[1];
}




pair<int,int> score_3(string node  [])
{
    int arr[2] = {0, 0};int ans = 0;

for(int i = 0;i < M;++i){

string s1 = "";int cnt = 0;int cntx,cnto;int k = i;
for(int j = 0;j < N;++j){if(node[j][k]!='.'){s1.append(1,node[j][k]);}}


ans=ans+evals(s1);
}

for(int i = M/2-1;i <= M/2+1;++i){

string s1 = "";int cnt = 0;int cntx,cnto;int k = i;
for(int j = 0;j < N;++j){if(node[j][k]!='X'){++cntx;}if(node[j][k]!='O'){++cnto;}}
int sign = 0;

if((cntx-cnto)>0){sign = 1;}else if((cntx-cnto)<0){sign = -1;}

//ans=ans+pow(2,cntx-cnto);
}







for(int i = 0;i < N;++i){

string s1 = "";int cnt = 0;int cntx,cnto;int k = i;
for(int j = 0;j < M;++j){s1.append(1,node[k][j]);}

ans=ans+evals(s1);
}

for(int i = 0;i < N;++i){
int k = i;string s1 = "";
for(int j = 0;j < M && k < N ;++j){s1.append(1,node[k][j]);++k;}
ans=ans+evals(s1);

s1 = "";k = i;
for(int j = 0;j  < M && k >= 0 ;++j){s1.append(1,node[k][j]);--k;}
ans=ans+evals(s1);


}


for(int i = 0;i < N;++i){


int k = i;string s1 = "";
for(int j = M-1;j >=0 && k < N ;--j){s1.append(1,node[k][j]);++k;}
ans=ans+evals(s1);

s1 = "";k = i;
for(int j = M-1;j  >=0 && k >= 0 ;--j){s1.append(1,node[k][j]);--k;}
ans=ans+evals(s1);


}




return make_pair(ans,0);
}




//string [] child;
vector< vector<string> > finalsteps;

int cnt;

float alphabeta(string child  [], int depth, float alpha, float beta, bool maximizingPlayer,bool x1,int a[],int tx,bool quis){	

if (depth == tx){++cnt;}
if (depth == tx || isTerminal(child)) {pair<int,int> x = (score(child));int x3 = 0;//(score_2(child));
pair<int,int> x4 = (score_3(child));
pair<int,int> x6 = score_4(child);
if((x6.first > 3*x4.first ||  x6.second > 3*x4.second) && quis){
quis = false;
if(M>=13){depth-=0;return 1*(x.first-x.second)+0*x3+1*(x4.first-x4.second);}
if(M>=10){depth-=2;}
else{depth-=3;}
}
else{ return 1*(x.first-x.second)+0*x3+1*(x4.first-x4.second);}

}



		
	
	if (maximizingPlayer){

		float m1 = -1;int j = 0;
	        for (int i=a[j];j<M;i = a[j]){		
		++j;
		int isterm = 1;int k;
		for ( k=0; k<N; k++){if (child[k][i]=='.'){child[k][i]='X'; isterm=0; break;}}
		if(isterm == 1){
		if(k!=N){child[k][i] = '.';}
		continue;}


//if (isterm==1){if(isTerminal(child)) {pair<int,int> x = (score(child)); return x.first-x.second;}}

float temp = alphabeta(child, depth+1, alpha, beta, false,false,a,tx,quis); 
if(temp>alpha){alpha = temp;m1 = i;}
if(k!=N){child[k][i] = '.';}
if (beta <= alpha){  break;}


}	
if(x1==true){cout << "m1 is " << m1 << endl;return m1;}return alpha; 
	}
	else{
		float m1 = -1;int i = 0;
	        for (int j=a[0];i<M;j = a[i]){
		++i;
		int isterm = 1;int k;
		for (k=0; k<N; k++){if (child[k][j]=='.'){child[k][j]='O'; isterm=0; break;}}
		if (isterm==1){
		if(k!=N){child[k][j] = '.';}
		continue;}

//if (isterm==1){if(isTerminal(child)) {pair<int,int> x = (score(child)); return x.first-x.second;}}

float temp = alphabeta(child, depth+1, alpha, beta, true,false,a,tx,quis); 
if(temp<beta){beta = temp;m1 = j;}
if(k!=N){child[k][j] = '.';}
if (beta <= alpha){  break;}


	}
if(x1){return m1;}
return beta;	
}
}


int safe()
{
  
	int iSecret;
	vector<int> v;
  for(int j = 0; j< M; j++)
  {
      if(board[N-1][j] == '.')
      {
        v.push_back(j);
      }
  }
  int temp = rand();
  iSecret = temp%v.size();
  update(v[iSecret], player);
  return v[iSecret];
}


int moves  = 0;
int nextMove()
{
moves+=1;
if(M%2==1){
if(board1[N-1][M/2]=='.'){

int x = M/2;
update(M/2,player);
  update2(M/2,'X');
  return x;


}}

if(M%2==0){
if(board1[N-1][M/2]=='.'){

int x = M/2;
update(M/2,player);
  update2(M/2,'X');
  return x;


}
else
if(board1[N-1][M/2-1]=='.'){

int x = M/2-1;
update(M/2-1,player);
  update2(M/2-1,'X');
  return x;


}




}



cout << "started\n";
cnt = 0;
int *a = new int[M];

if(M%2==0){
int k = 0;
for(int j = 0;j<(M/2);++j){
a[k] = (M/2)+j;
a[k+1] = (M/2)-1-j;
k = k+2;
}

}
else{
a[0] = (M/2);
int k = 1;
for(int j = 0;j<(M/2);++j){
a[k] = (M/2)+1+j;
a[k+1] = (M/2)-1-j;
k = k+2;
}


}
string *str = new string [M];

for(int i = 0;i<N;++i)
{
str[i] = "";
str[i] = board1[i];
}

//for(int i = 0;i< N;++i){cout << board1[i] << "xb\n";}
//for(int i = 0;i< M;++i){cout << a[i] << "xc\n";}

int tx;
if(2*moves> (3*N*M/4)){
if(player==1){tx = 6;}
else{tx = 6;}
}
else
if(2*moves > N*M/5){
if(player==1){tx = 6;}
else{tx = 6;}
}
else
{
if(player==1){tx = 3;}
else{tx = 3;}
}

if(M>=10){if(2*moves> (4*N*M/5)){
if(player==1){tx = 6;}
else{tx = 6;}
}
else
if(2*moves > 2*N*M/5){
if(player==1){tx = 4;}
else{tx = 4;}
}
else
{
if(player==1){tx = 4;}
else{tx = 4;}
}}



if(M>=13){if(2*moves> (4*N*M/5)){
if(player==1){tx = 4;}
else{tx = 4;}
}
else
if(2*moves > 2*N*M/5){
if(player==1){tx = 4;}
else{tx = 4;}
}
else
{
if(player==1){tx = 4;}
else{tx = 4;}
}}





  int x  = (int)alphabeta( str ,0, -100000, 100000,true,true,a,tx,true );

cout << "x is " << x << "\n" ;
cout << "cnt is " << cnt << "\n" ;
//for(int i = 0;i< N;++i){cout << str[i] << "xa\n";}

if(board1[N-1][x]!='.' && x>=0 && x < M){cout << "error\n";x = safe();return x;}
cout << "end\n";
update(x,player);
  update2(x,'X');
  return x;


/*
  for(int j = 0; j< M; j++)
  {
    for(int i = 0; i<N; i++)
      if(board[i][j] == '.')
      {
	       board[i][j] = 'O';
           cout << j << endl;
        return j;
      }
  }
  */





}





int main(int argc, char *argv[])
{
	srand (time(NULL));
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    char sendBuff[1025];
    struct sockaddr_in serv_addr; 

    if(argc != 3)
    {
        printf("\n Usage: %s <ip of server> <port no> \n",argv[0]);
        return 1;
    } 

    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2])); 

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    } 

    cout<<"Connect(N,M,K) will start"<<endl;

    memset(recvBuff, '0',sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
    recvBuff[n] = 0;
    sscanf(recvBuff, "%d", &N);

    cout<<"N: "<<N<<endl;
    memset(recvBuff, '0',sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
    recvBuff[n] = 0;
    sscanf(recvBuff, "%d", &M);

    cout<<"M: "<<M<<endl;
    memset(recvBuff, '0',sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
    recvBuff[n] = 0;
    sscanf(recvBuff, "%d", &K);    
    
    cout<<"K: "<<K<<endl;

/* Added code */
    int TL;
    memset(recvBuff, '0',sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
    recvBuff[n] = 0;
    sscanf(recvBuff, "%d", &TL);    
    
    cout<<"Time Limit: "<<TL<<endl;    
    time_left = TL;

/* */

    memset(recvBuff, '0',sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff)-1);
    recvBuff[n] = 0;
    sscanf(recvBuff, "%d", &player);  

    cout<<"Player "<<player<<endl;

    string temp = "";string temp1 = "";
    for(int j = 0; j< M; j++)
        {temp += ".";temp1+= ".";}
    FOR(i, N)
       { board.PB(temp);board1.PB(temp);}

    if(player == 1)
    {
        //cout << "hello" << endl;
        memset(sendBuff, '0', sizeof(sendBuff)); 
        int temp = nextMove();
        //cout << "temp" << endl;
        snprintf(sendBuff, sizeof(sendBuff), "%d", temp);
        write(sockfd, sendBuff, strlen(sendBuff));
    }

    while(1)
    {
        int nextColumn;

        memset(recvBuff, '0',sizeof(recvBuff));
        n = read(sockfd, recvBuff, sizeof(recvBuff)-1);

        /* Added Code */
        struct timeval  tv1, tv2;
        gettimeofday(&tv1, NULL);
        /* */

        recvBuff[n] = 0;
        sscanf(recvBuff, "%d", &nextColumn);
        //cout << "Rec: "<< nextColumn << endl;
        if(player == 1)
	         update(nextColumn, 2);
        else 
          update(nextColumn, 1);

	    cout << nextColumn << endl;
update2(nextColumn,'O');
        memset(sendBuff, '0', sizeof(sendBuff)); 
        int temp = nextMove();
        //cout << "temp" << endl;
        snprintf(sendBuff, sizeof(sendBuff), "%d", temp);

        /** Added Code */
        gettimeofday(&tv2, NULL);
        double time_spent = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
        time_left -= time_spent;
        /* */

        write(sockfd, sendBuff, strlen(sendBuff));
    }

    return 0;
}
