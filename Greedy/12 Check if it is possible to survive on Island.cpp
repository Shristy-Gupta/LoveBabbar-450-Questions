class Solution{
public:
    int minimumDays(int S, int N, int M){
        
        //S – Number of days you are required to survive.
        //N – The maximum unit of food you can buy each day.
       //M – Unit of food required each day to survive.
        if(M>N){
            return -1;
        }
        //On the 7th day you cannot buy anything
        int number_of_sunday=S/7;
        int number_of_buy=S-number_of_sunday;
        int survival_food_needed=M*S;
        int per_day_we_can_buy=ceil((double)survival_food_needed/N);
        if(per_day_we_can_buy<=number_of_buy){
            return per_day_we_can_buy;
        }
        return -1;
        
    }
};
