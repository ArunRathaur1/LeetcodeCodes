class Solution {
public:
    double maxdiff(double num,double den){
        return (num+1)/(den+1)-(num/den);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int t) {
        priority_queue<pair<double, pair<double, double>>, vector<pair<double, pair<double, double>>>> q;
        int l = classes.size();
        double value = 0;

        for (int i = 0; i < l; i++) {
            double num = classes[i][0];
            double den = classes[i][1];
            q.push({maxdiff(num,den), {num, den}});
        }

        while (t--) {
            auto [ratio, numbers] = q.top();
            q.pop();
            double num = numbers.first + 1;
            double den = numbers.second + 1;
            q.push({maxdiff(num,den), {num, den}});
        }

        while (!q.empty()) {    
            auto[gain,number]=q.top();
            value=value+number.first/number.second;
            q.pop();
        }
        return value / l;
    }
};
