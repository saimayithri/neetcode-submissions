class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair <int,int>> p(n);
        for(int i=0;i<n;i++)
        {
            p[i].first=position[i]; p[i].second=speed[i];
            
        }
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());

        vector<float>time(n,0);
        for(int i=0;i<n;i++)
        {
            time[i] =(float)(target - p[i].first  )/ (float)p[i].second;


        }
        float prevTime=time[0]; int fleets=1;
        for(int i=1;i<n;i++)
        {
            if(time[i]>prevTime)
            {
                fleets++;prevTime=time[i];
            }



        }
        return fleets;





        
        
    }
};
