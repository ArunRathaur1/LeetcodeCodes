class Solution {
public:
    bool static customsort(pair<double, pair<double, double>> a, pair<double, pair<double, double>> b) {
        double num1 = a.second.first;
        double den1 = a.second.second;
        double val1=num1/den1;
        double value1 = (num1 + 1) / (den1 + 1);
        double num2 = b.second.first;
        double den2 = b.second.second;
        double val2=num2/den2;
        double value2 = (num2 + 1) / (den2 + 1);
        return value1-val1 < value2-val2;
    }
    
    double maxAverageRatio(vector<vector<int>>& classes, int t) {
        priority_queue<pair<double, pair<double, double>>, vector<pair<double, pair<double, double>>>, decltype(&customsort)> q(customsort);
        int l = classes.size();
        double value = 0;

        // Push the initial classes and their ratios into the priority queue
        for (int i = 0; i < l; i++) {
            double num = classes[i][0];
            double den = classes[i][1];
            double p = num / den;
            q.push({p, {num, den}});
        }

        // Perform the t operations
        while (t--) {
            auto [ratio, numbers] = q.top();
            q.pop();
            double num = numbers.first + 1;
            double den = numbers.second + 1;
            double p = num / den;
            q.push({p, {num, den}});
        }

        // Calculate the final average ratio
        while (!q.empty()) {
            value += q.top().first;
            q.pop();
        }
        return value / l;
    }
};
