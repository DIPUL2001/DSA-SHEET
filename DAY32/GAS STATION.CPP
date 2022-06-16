 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current=0;
        int gas_cost=0,fuel_cost=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            gas_cost+=gas[i];
        }
        for(int i=0;i<cost.size();i++){
            fuel_cost+=cost[i];
        }
        if(gas_cost<fuel_cost)return -1;
        
        for(int i=0;i<gas.size();i++){
            current+=(gas[i]-cost[i]);
            if(current<0){
                start=i+1;
                current=0;
                
            }
        }
        return start;
    }