#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int nbooks;
int nlibs;
int ndays;

vector<int> scores;        //lookup table for book scores
vector<vector<int>> libs;  //library attributes {nbooks,nsignup,nship}
vector<vector<int>> books; // {lib_id,{vector of book id's in the lib}}
vector<pair<int,int>> sortedspan;

void solve()
{
    vector<int> id;
    vector<vector<int>> book_ids;
    for(int it=0;it<sortedspan.size();it++)
    {
        int i=sortedspan[it].first;
        id.pb(i);
        ndays -= libs[i][1];
        if (ndays <= 0)
            break;
        int cap = libs[i][2], book_cnt = libs[i][0];
        int tot_book_pos = cap * ndays;
        vector<int> temp;
        int j = 0;
        while (tot_book_pos > 0 && book_cnt > 0)
        {
            temp.pb(books[i][0]);
            books[i].erase(books[i].begin());
            tot_book_pos--;
            book_cnt--;
        }
        book_ids.pb(temp);
    }

    cout << book_ids.size() << endl;
    for (int i = 0; i < book_ids.size(); i++)
    {
        cout << id[i] << " " << book_ids[i].size() << endl;
        for (auto item : book_ids[i])
        {
            cout << item << " ";
        }
        cout << endl;
    }
}
bool sortinrev(const pair<int,int> &a,const pair<int,int>&b)
{
    return(a.second<b.second);
}
bool sortinrev2(const pair<int,int> &a,const pair<int,int>&b)
{
    int val1=libs[a.first][1]-(libs[a.first][0]*libs[a.first][2]);
    int val2=libs[a.first][1]-(libs[b.first][0]*libs[b.first][2]);
    return val1>val2;
}
void read()
{
    cin >> nbooks >> nlibs >> ndays;

    for (int i = 0; i < nbooks; i++)
    {
        int x;
        cin >> x;
        scores.pb(x);
    }
    

    for (int i = 0; i < nlibs; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        sortedspan.pb(make_pair(i,y)); 
        libs.pb({x, y, z});

        vector<int> temp;

        for (int j = 0; j < x; j++)
        {
            int xxx;
            cin >> xxx;
            temp.pb(xxx);
        }

        books.pb(temp);
    }
    sort(sortedspan.begin(),sortedspan.end(),sortinrev);
    sort(sortedspan.begin(),sortedspan.end(),sortinrev2);
   /* for (int i=0; i<n; i++) 
    { 
 
        cout << sortedspan[i].first << " " 
             << sortedspan[i].second << endl; 
    } */
    
}

signed main()
{
    read();
    solve();
    return 0;
}

